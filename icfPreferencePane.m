#import "icfPreferencePane.h"
#import "icfPreferences.h"
#import "icfPlugin.h"

#define ICF_PREFPANE_NIBNAME	@"icfPreferencePane.nib"	// Name of the nib for pane UI
#define ICF_PREFPANE_NAME       @"5iCalFix"

static void LocalizePopup( NSPopUpButton* popup, NSArray* entries )
{
    [popup removeAllItems];
    
	NSEnumerator* enumerator = [entries objectEnumerator];
	NSString *nonLocalizedString;
	
	while( nonLocalizedString = [enumerator nextObject] )
	{
		NSString* localizedString = NSLocalizedString (nonLocalizedString, nil);	
		
		if( localizedString == nil )
		{
			NSLog(@"Couldn't localize string '%@'", nonLocalizedString );
			localizedString = nonLocalizedString;
		}
		[popup addItemWithTitle: localizedString];
	}
    
}

static int timeUnitToSeconds( int unitIndex )
{
	switch( unitIndex )
	{
		case 0: return 60; 
		case 1: return 3600; 
		case 2: return 86400; 
		case 3: return -60;
		case 4: return -3600;
		default:return 60; 
	}
	
	
}
@implementation icfPreferencePane

/**
 * When the preferences get awoken from the NIB, we'll do most of our UI modifications
 */
- (void) awakeFromNib
{
	// this happens once, so we'll just handle that here
	[buildLabel setStringValue:[NSString stringWithFormat:[buildLabel stringValue], 
		[[icfPlugin sharedInstance] marketingVersion], 
		[[icfPlugin sharedInstance] bundleVersion]]];

	// -- Initialize time unit combo box, localize the strings -- //
    LocalizePopup( advanceTimeUnit, [NSArray arrayWithObjects:
							@"minutes before",
							@"hours before",
							@"days before",
							nil] );

	LocalizePopup( allDayAdvanceTimeUnit, [NSArray arrayWithObjects:
					@"minutes before",
					@"hours before",
					@"days before",
					@"minutes after",
					@"hours after",
					nil] );

	// -- build list of alarm sounds -- //
	// Let's build our alarm sounds menu by looking for all Library/Sounds directories and collecting from there
	[alarmSounds removeAllItems];
	[alarmSounds addItemWithTitle: @"- none -"];

	// Find all Library directories. Systemwide, user specific, etc.
	NSArray *libraryPaths = NSSearchPathForDirectoriesInDomains (NSLibraryDirectory,
	                                                    		 NSAllDomainsMask, YES);
	
	NSString 		*path;
	NSEnumerator 	*pathEnum 	= [libraryPaths objectEnumerator];
	while( path = [pathEnum nextObject] )
	{
		NSDirectoryEnumerator *fileEnum = 
			[[NSFileManager defaultManager] enumeratorAtPath: 
				[path stringByAppendingPathComponent: @"Sounds"]];


		NSString *file;
		while( file = [fileEnum nextObject] )
            [alarmSounds addItemWithTitle: [file stringByDeletingPathExtension]];
	}	
}


/**
 * Initialize an instance
 * 
 * Handles all the one-time setup the prefs pane needs - collect alarm sounds, localize
 * strings using iCals localization data, etc.
 */
- (id) init 
{
	[super init];
	return self;
}

/**
 * Get a list of all preferences we offer
 * NB - the return value is automatically autorelease, since by convention
 * factory methods return autorelease objects.
 */
- (NSArray*) viewNames
{
	return [NSArray arrayWithObject: ICF_PREFPANE_NAME ];
}


/**
 * Obtain our actual preference pane
 */
- (NSView*) viewForPaneWithIdentifiers:(NSString *)aName
{
	if( ![aName isEqualToString: ICF_PREFPANE_NAME] )
	    return nil;

	[self loadPreferences:[icfPreferences sharedInstance]];
	return prefView;
}

/**
 * Get a label for our pane
 */
- (NSString*)labelForPaneWithIdentifiers:(NSString*)aName
{
	if( [aName isEqualToString: ICF_PREFPANE_NAME] )
	    return @"iCalFix";

	return nil;	
}


/**
 * There's only one instance of our preference pane
 */
+ (icfPreferencePane*) sharedInstance
{
    static icfPreferencePane* prefsPane = nil;
    if (prefsPane == nil)
	{
        prefsPane = [[icfPreferencePane alloc] init];

    	// Load our nib file. Can we do this during init?
  		[NSBundle loadNibNamed: ICF_PREFPANE_NIBNAME owner: prefsPane];
	}

    return prefsPane;
}

static void setAlarmTime( NSPopUpButton* unitPopup, NSTextField* warningTime, icfPreferences* prefs, NSString* prefsKey )
{
	int advanceWarning = [[prefs objectForKey: prefsKey] intValue];
	int timeUnit = 0;
	if( advanceWarning < 0 )
	{
		advanceWarning = - advanceWarning;
		if ( advanceWarning % 3600 == 0 )
		{
			timeUnit = 4;
			advanceWarning /=3600;
		}
		else
		{
			timeUnit = 3;
			advanceWarning /= 60;
		}		
		
	}
	else
	{
		if( advanceWarning %86400 == 0 )
		{
			timeUnit = 2;
			advanceWarning /= 86400;
		}
		else if ( advanceWarning % 3600 == 0 )
		{
			timeUnit = 1;
			advanceWarning /=3600;
		}
		else
		{
			timeUnit = 0;
			advanceWarning /= 60;
		}		
	}
	[unitPopup selectItemAtIndex: timeUnit];
	[warningTime setIntValue: advanceWarning];
	
}

/**
 * load our pane with a set of preferences
 */
- (void)loadPreferences: (icfPreferences*)prefs
{
	setAlarmTime( advanceTimeUnit, warningTime, prefs, @"Advance Warning" );
	setAlarmTime( allDayAdvanceTimeUnit, allDayWarningTime, prefs, @"Allday Advance Warning" );
	
	[alarmSounds selectItemWithTitle: [prefs objectForKey: @"Alarm Sound"]];
	if( [alarmSounds selectedItem] == nil )
		[alarmSounds selectItemAtIndex: 0];
}

- (IBAction)setAdvanceTime:(id)sender
{
	int alarmTime = [warningTime intValue] * timeUnitToSeconds( [advanceTimeUnit indexOfSelectedItem] );	
	
	NSString* prefsValue = [NSString stringWithFormat: @"%d", alarmTime];	
	[[icfPreferences sharedInstance] setObject: prefsValue forKey: @"Advance Warning"];
	
	int allDayAlarmTime = [allDayWarningTime intValue] * timeUnitToSeconds( [allDayAdvanceTimeUnit indexOfSelectedItem] );	
	prefsValue = [NSString stringWithFormat: @"%d", allDayAlarmTime];	
	[[icfPreferences sharedInstance] setObject: prefsValue forKey: @"Allday Advance Warning"];
}

- (IBAction)setSound:(id)sender
{
	NSString* alarmSound = @"";
	
	if( [alarmSounds indexOfSelectedItem] > 0 )
		alarmSound = [alarmSounds titleOfSelectedItem];

	[[icfPreferences sharedInstance] setObject: alarmSound forKey: @"Alarm Sound"];
}

- (IBAction)donate:(id)sender
{
	[[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:@"https://www.paypal.com/xclick/business=r.blum%40gmx.net&item_name=iCalFix+Development&no_shipping=1&no_note=1&tax=0&currency_code=USD"]];
}


@end
