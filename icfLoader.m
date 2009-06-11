#import "icfLoader.h"
#import "icfPlugin.h"


@implementation icfLoader
 
/**
 * Do hooking work as soon as class is loaded
 */
+ (void) load
{
    // If we got here, we are our own input manager. Let's install ourselves
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(installPlugin:) name:NSApplicationWillFinishLaunchingNotification object:nil];
}


/*
 * Installs itself by hooking necessary functions
 */
+ (void) installPlugin:(NSNotification*)_notification
{
	NSString* applicationName = [[NSBundle mainBundle] bundleIdentifier];
	
	BOOL installAsScheduler = FALSE;
	
	// Verify against the iCal scheduler
    if( [applicationName isEqualToString: @"com.apple.iCal.helper"] )
        installAsScheduler = true;
    
	// Check if this is really the right application
	if( !installAsScheduler && ![applicationName isEqualToString: @"com.apple.iCal" ] )
		return;

	// Next, check for proper version range of iCal
	int icalVersion = [[[NSBundle mainBundle] objectForInfoDictionaryKey: @"CFBundleVersion"] intValue];
	 
	const int minVersion = 1055;
	const int maxVersion = 1069;
	
	if( icalVersion < minVersion )
	{
		[icfPlugin 
            errorAlert: [NSString stringWithFormat: @"iCal(v%d) is not supported by iCalFix %@(%@).", icalVersion,
                [[icfPlugin sharedInstance] marketingVersion], 
                [[icfPlugin sharedInstance] bundleVersion]
            ]
            withDetails: @"Your version of iCal seems out of date. Please update to the newest version."];
				
		return;
	}
	if( icalVersion > maxVersion )
	{
		[icfPlugin 
            errorAlert: [NSString stringWithFormat: @"iCal(v%d) is not supported by iCalFix %@(%@).", icalVersion,
                [[icfPlugin sharedInstance] marketingVersion], 
                [[icfPlugin sharedInstance] bundleVersion]
                ]
           withDetails: @"Your version of iCalFix seems out of date. Please update to the newest version."];
				
		return;
	}
    
	// And finally, install iCalFix
	[icfPlugin installAsScheduler: installAsScheduler ];
}
@end
