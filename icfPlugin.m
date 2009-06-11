#import "icfPlugin.h"
#import "icfPreferences.h"

#import "CALCore/CALOccurrence.h" 

#define ICF_PREF_PLIST_KEY_ADVANCE_WARNING          @"Advance Warning"
#define ICF_PREF_PLIST_KEY_ALARM_SOUND              @"Alarm Sound"

/**
 * Create a new alarm, according to user preferences
 */
CALAlarm* CreateAlarm( CALEvent* event )
{
    CALAlarmTrigger* trigger = [CALAlarmTrigger trigger];
    
    int seconds = -[[[icfPreferences sharedInstance] objectForKey: ICF_PREF_PLIST_KEY_ADVANCE_WARNING] intValue];
    
    if( [event isFullDayEvent] )
        seconds = -[[[icfPreferences sharedInstance] objectForKey: @"Allday Advance Warning"] intValue];
    
    [trigger setDuration: [CALDuration durationWithSeconds: seconds]];
    
    // Try to obtain the 'default' alarm - i.e. whatever the user set last
	// @TODO - this needs to be switchable based on preferences
    CALAlarm *customAlarm = nil; //[[iCalFix sharedInstance] getDefaultAlarm];
    
	// If we couldn't find one, let's create a new one
    if( customAlarm == nil )
    {
		NSString* alarmSound = [[icfPreferences sharedInstance] objectForKey: ICF_PREF_PLIST_KEY_ALARM_SOUND];
		
		// If we don't have an alarm sound, make it a standard alarm
        if( alarmSound == nil || [alarmSound isEqual: @"" ] )
        {
            customAlarm = [CALDisplayAlarm alloc];
            [customAlarm initWithTrigger: trigger];
        }
        else
        {
			// We have sound, so make a sound alarm
            customAlarm = [CALSoundAlarm alloc];
            [customAlarm initWithTrigger: trigger];
            NSURL* url = [[NSURL alloc] initWithString: [alarmSound stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding] ];
            [(CALSoundAlarm*)customAlarm setURL: url];
            [url release];    
        }
    }
    
    // Mark this as an "ICF" alarm
    [customAlarm setProperty: [CALProperty propertyWithName: @"X-ICF-AUTOALARM" withValue: @"TRUE"]];
    
    return customAlarm;
}

/**
 * Add an iCalFix alarm to an event
 */
void AddCustomAlarm( CALEvent* event )
{
    // If we don't have an alarm yet, we'll add one!        
    if( ![event hasAlarms] )
    {
        CALAlarm* alarm = CreateAlarm( event );
        [event addAlarm: alarm];
        [alarm release];
    }
}

@interface CALMainController (RBCALMainController)
- (void) _rb_postEventCreationStuff:(id)fp8 withEdition:(BOOL)fp12;
@end


@implementation CALMainController (RBCALMainController)

- (void)_rb_postEventCreationStuff:(id)fp8 withEdition:(BOOL)fp12;
{
    NSObject* object=fp8;
    
	// If we do have a calender event created, let's add an alarm to it
    if( [object isKindOfClass: [CALEvent class] ] )
    {
        CALEvent* event = (CALEvent*)object;        
        AddCustomAlarm( event );
    }
    
    
    // call the "super" method - this method doesn't exist until runtime
    return [self _rb_postEventCreationStuff: object withEdition: fp12 ];
}


@end


@interface CALEvent (ICF_CALEvent)
- (void) setScriptingProperties:(NSDictionary *)properties; // This one is without icf_ prefix since we override an NSObject method here that's not defined by CALEvent
- (void) commit;
- (void) icf_setFullDayEvent:(BOOL)fullday;
@end

@implementation CALEvent( ICF_CALEvent )

/**
 * Log if we're switching full day events on/off
 */
- (void) icf_setFullDayEvent:(BOOL)fullday
{
    if( [self hasAlarms] )
    {
        
        CALAlarm* alarm = [[self alarms] objectAtIndex: 0];
        CALAlarmTrigger* trigger = [alarm trigger];
        
        // If the alarm has a trigger and is one of our automatically created ones,
        // we want to modify the time the trigger fires.
        if( trigger && [alarm hasProperty: @"X-ICF-AUTOALARM" ] )
        {
            int seconds = -[[[icfPreferences sharedInstance] objectForKey: ICF_PREF_PLIST_KEY_ADVANCE_WARNING] intValue];

            if( fullday )
                seconds = -[[[icfPreferences sharedInstance] objectForKey: @"Allday Advance Warning"] intValue];
            [trigger setDuration: [CALDuration durationWithSeconds: seconds]];
        }
    }
    [self icf_setFullDayEvent: fullday ];
}

/**
 * This hooks scripted events - whenever the scripting properties are updated
 * we're adding our custom events. This is needed since that doesn't go through 'postEventCreationStuff'
 */
- (void)setScriptingProperties:(NSDictionary *)properties
{
    [super setScriptingProperties: properties];
    AddCustomAlarm( self );
}

/**
 * This gets called whenever an event is comitted to the DB
 * 
 * Here, we copy whatever the user selected and make it our default alarm
 */
- (void) commit
{
    // Make a copy of the current alarm if the user has updated it
    if( [self hasAlarms] )
    {
        CALAlarm* alarm = [[self alarms] objectAtIndex: 0];
        if( [alarm dirty] )
        {
            [[icfPlugin sharedInstance] setDefaultAlarm: alarm];
        }
    }
    [super commit];
}

@end

static NSString *g_EventAlarm = @"iCal Alarm";

@interface icfNotificationLogger:  NSObject
{
}
+ (void)init;
+ (void) logNotification:(NSNotification*)notification;
@end

@implementation icfNotificationLogger

+(void)init
{
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(logNotification:) name:nil object:nil];
}

+ (void) logNotification:(NSNotification*)notification
{
    NSString* name = [notification name];

    if( ![name isEqualToString:@"CALAlarmsTriggeredNotification"] )
        return;
        
    NSDictionary* contents=[notification userInfo];
    

    ///@TODO - iterate over all alarms we get
    NSArray* alarms = [contents valueForKey:@"CALAlarmsTriggeredAlarmsKey"];
    
    if( [alarms count]==0 )
        return;
    
    // The above are guaranteed of the right type. We should probably check if the alarms are CALOccurrences. If not, just growl about an unknown alarm
    CALOccurrence* occurrence =[alarms objectAtIndex: 0];
    
    CALAlarm* alarm = nil;
    if( [[occurrence entity] isKindOfClass: [CALAlarm class]] )
        alarm = [occurrence entity];
    
    // And again, check if the occurrence entity is an alarm - otherwise growl based on the occurrence only
    //NSLog( @"Alarm:%@", alarm );

    if( [[alarm originEntity] isKindOfClass: [CALEvent class]] )
    {
        CALEvent* event = [alarm originEntity];
        [GrowlApplicationBridge notifyWithTitle:@"ICal Alarm!" description:[event desc] notificationName:g_EventAlarm iconData:nil priority:0 isSticky:false clickContext:nil];
    }
}
@end

@implementation icfPlugin

/**
* Most of the hard installation work - loading frameworks, swizzling methods, you name it
 */ 
+ (void) installAsScheduler:(BOOL)_asScheduler
{
	NS_DURING

    // Make sure we actually have an instance of our plugin
    icfPlugin* plugin = [icfPlugin sharedInstance];
    
    NSBundle* pluginBundle = [NSBundle bundleForClass: [plugin class]];
    if( pluginBundle == nil )
        NSLog( @"Bundle not found");
    
    // load growl framework - we'll need it
    NSString *growlPath = [[pluginBundle privateFrameworksPath]
	stringByAppendingPathComponent:@"Growl.framework"];
    
    NSBundle *growlBundle = [NSBundle bundleWithPath:growlPath];
    if (growlBundle && [growlBundle load]) {
        // Register ourselves as a Growl delegate
        [GrowlApplicationBridge setGrowlDelegate:plugin ];
        
    } else {
        NSLog(@"Could not load Growl.framework");
    }    
    

	// Hooks for the main iCal only
    if( !_asScheduler )
	{
	
        MethodSwizzle([CALMainController class],
                  @selector(checkEntityCreationIsValid),
                  @selector(_rb_checkEntityCreationIsValid));
    
        MethodSwizzle([CALMainController class],
                  @selector(postEventCreationStuff:withEdition:),
                  @selector(_rb_postEventCreationStuff:withEdition:));

        MethodSwizzle([CALEvent class],
                  @selector(setFullDayEvent:),
                  @selector(icf_setFullDayEvent:));
    }
    

	// @TODO - we need to read from a different file than iCalFix.plist - previous
	// users have made their changes there, and we can't install yet another iCalFix.plist
	// without overwriting their changes
	NSDictionary* plistDefaults = [ [NSDictionary alloc] initWithContentsOfFile:
										[ pluginBundle pathForResource:@"icfDefaults" ofType:@"plist" ] ];

	[[icfPreferences sharedInstance] registerDefaults: plistDefaults];

    [plistDefaults release];

   	NS_HANDLER
		NSLog(@"load exception %@: %@", [localException name], [localException reason]);
		[icfPlugin errorAlert:NSLocalizedStringFromTableInBundle(@"An error occurred loading iCalFix.", ICF_STRING_TABLE, [NSBundle bundleWithIdentifier:ICF_IDENTIFIER], @"Error alert primary message") withDetails:[localException reason]];
	NS_ENDHANDLER

	// Let the world know we're loaded
    NSLog(@"iCalFix %@ (Build %@) -- installed", 	
		[[icfPlugin sharedInstance] marketingVersion], 
		[[icfPlugin sharedInstance] bundleVersion]
	);
    
    [icfNotificationLogger init]; 
}

/** 
 * Register all Growl messages
 */
- (NSDictionary *) registrationDictionaryForGrowl
{
    NSArray *notifications;
    notifications = [NSArray arrayWithObject: g_EventAlarm];
    
    NSDictionary *dict;
    
    dict = [NSDictionary dictionaryWithObjectsAndKeys:
        notifications, GROWL_NOTIFICATIONS_ALL,
        notifications, GROWL_NOTIFICATIONS_DEFAULT, nil];
    
    return (dict);
}

- (NSString *) applicationNameForGrowl
{
    return @"iCal";
}

/**
 * Obtain the main .nib file name, stored in the Info.plist
 */
- (NSString*) nibName
{
	return [[NSBundle bundleWithIdentifier:ICF_IDENTIFIER] objectForInfoDictionaryKey: @"NSMainNibFile"];
}


/**
 * Get the short version
 */
- (NSString*) version
{
	return [[NSBundle bundleWithIdentifier:ICF_IDENTIFIER] objectForInfoDictionaryKey: @"CFBundleShortVersionString"];
}

/**
 * Get the bundle version
 */
- (NSString*) bundleVersion
{
	return [[NSBundle bundleWithIdentifier:ICF_IDENTIFIER] objectForInfoDictionaryKey: @"CFBundleVersion"];
}

/**
 * Get the 'official' version #
 */
- (NSString*) marketingVersion
{
	return [[NSBundle bundleWithIdentifier:ICF_IDENTIFIER] 
		objectForInfoDictionaryKey: @"CFBundleShortVersionString"];
}


/**
 * @return the single static instance of the plugin object
 */
+ (icfPlugin*) sharedInstance
{
    static icfPlugin* plugin = nil;
    if (plugin == nil)
        plugin = [[icfPlugin alloc] init];

    return plugin;
}

+ (void) errorAlert:(NSString*)_message withDetails:(NSString*)_details, ...
{
	va_list ap;
	va_start(ap, _details);
    
	NSString* detailsFormatted = [[[NSString alloc] initWithFormat:_details arguments:ap] autorelease];
	va_end(ap);
    
	NSBeginAlertSheet(
                      _message,         // sheet message
                      nil,              // default button label
                      nil,              // alternate button label
                      nil,              // no third button
                      nil,              // window sheet is attached to
                      self,             // we'll be our own delegate
                      nil,              // did-end selector
                      nil,              // no need for did-dismiss selector
                      nil,              // context info
                      detailsFormatted,	// additional text
                      nil);             // no parameters in message
}

- (void) setDefaultAlarm:(CALAlarm*)_defaultAlarm
{
    [defaultAlarm release];
    defaultAlarm = [_defaultAlarm copy];
}

- (CALAlarm*) getDefaultAlarm
{
    return [defaultAlarm retain];
}

- (void) setLoaded:(BOOL)_loaded
{
	loaded = _loaded;
}

- (BOOL) isLoaded
{
	return loaded;
}
@end
