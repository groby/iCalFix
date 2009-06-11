#import "icfCALPreferencesGeneralPaneController.h"

#import "icfPreferencePane.h"
#import "icfPlugin.h"


#define ICAL_KNOWN_PANE_NAME @"3advanced" //TODO this is duplicated


@implementation icfCALPreferencesGeneralPaneController

/**
 * Handle initial class load
 *
 * Overrides existing preference pane manager (i.e. iCalFix's) so we can hook our 
 * preference pane into it
 */
+ (void) load
{
	[icfCALPreferencesGeneralPaneController poseAsClass:[CALPreferencesGeneralPaneController class]];
}

- (NSString*)labelForPaneWithIdentifiers:(NSString*)paneIdentifier
{
	NSString* result = [super labelForPaneWithIdentifiers: paneIdentifier];
	if( result == nil )
		result = [[icfPreferencePane sharedInstance] labelForPaneWithIdentifiers: paneIdentifier];
    
    if( result == nil )
    {
		NSLog( @"Couldn't retrieve pane label");
        result = @"UNKNOWN";
    }
    
    return result;
}


// This maps an NSString tp an NSView. I s'pose it comes from awakeFromNIB?
- (NSView*)viewForPaneWithIdentifiers:(NSString*)paneIdentifier
{
	NSView* result = [super viewForPaneWithIdentifiers: paneIdentifier];
	if( result == nil )
        result = [[icfPreferencePane sharedInstance] viewForPaneWithIdentifiers: paneIdentifier];
    
    if( result == nil )
    {
		NSLog( @"Couldn't get pane, substituting a known pane");
        result = [super viewForPaneWithIdentifiers: ICAL_KNOWN_PANE_NAME ];
    }
    
    return result;
}

- (NSImage*)imageForPaneWithIdentifiers:(NSString*)paneIdentifier
{
	NSImage* result = [super imageForPaneWithIdentifiers: paneIdentifier];
	// If there is no image, we blatantly assume it's iCalFix
	if( result == nil )
	{
        NSBundle* bundle= [NSBundle bundleForClass:[[icfPlugin sharedInstance]class]];
        result = [[NSImage alloc] initByReferencingFile:[bundle pathForResource:@"pref_icalfix" ofType:@"tif"]];
	}
	return result;
}



@end
