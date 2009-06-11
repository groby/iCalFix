#import "icfPreferences.h"
#import "icfPlugin.h"

@implementation icfPreferences

/**
 * There's only one instance of our preferences handler
 */
+ (icfPreferences*) sharedInstance
{
    static icfPreferences* preferences = nil;
    if (preferences == nil)
        preferences = [[icfPreferences alloc] init];

    return preferences;
}

- (id) init 
{
	[super init];

	userDefaults = [[NSUserDefaults alloc] init]; // We allocate our own userdefaults here. Using standardUserDefaults ends up in apples iCal defaults
	[userDefaults addSuiteNamed:ICF_IDENTIFIER];
	
	return self;
}

- (void) dealloc 
{
	[userDefaults release];
	[super dealloc];
}


- (void)registerDefaults:(NSDictionary*)appDefaults
{
	NSDictionary *userPrefs = [userDefaults persistentDomainForName:ICF_IDENTIFIER];
	if ( userPrefs ) 
	{
		// Merge appDefaults with userPrefs. userPrefs take precedence
		NSMutableDictionary *mergedDefaults = [appDefaults mutableCopy];
		[mergedDefaults addEntriesFromDictionary: userPrefs];
		[userDefaults setPersistentDomain: mergedDefaults forName: ICF_IDENTIFIER];

	    [userDefaults registerDefaults:mergedDefaults];
	    [userDefaults synchronize];

		[mergedDefaults release];
	} else 
	{
		// We have no user defaults, so we just make the applications defaults the users defaults
		[userDefaults setPersistentDomain: appDefaults forName: ICF_IDENTIFIER];
	}
	// We don't need to synchronize - it seems setPersistentDomain does that for us.
}

- (id)objectForKey:(NSString*) aKey
{
	return [userDefaults objectForKey: aKey];
}

- (void)setObject:(id)value forKey:(NSString *)defaultName
{
	// We need to use CFPreferences here, because otherwise we'll still end
	// up in apples ical preferences. Why? Presumably the NSUserDefaults setObject:forKey
	// always uses the app domain, for whatever reason. Anyways - that's the way the bird flies around here
	CFPreferencesSetAppValue((CFStringRef)defaultName			/* key */,
							 (CFPropertyListRef)value /* value */,
							 (CFStringRef)ICF_IDENTIFIER) /* application ID */;\

	// Now we bonk it out to disk
	CFPreferencesAppSynchronize((CFStringRef)ICF_IDENTIFIER);
	
	// and resync it back to our own preferences
	[userDefaults synchronize];
}
@end
