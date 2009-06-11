#import "CALCore/CALPreferencesPanesController.h"
#import "icfCALPreferencesPaneController.h"

#import "icfPreferencePane.h"
#import "icfPlugin.h"

#define ICAL_KNOWN_PANE_NAME @"3advanced"

/**
 * This class provides a mapping from a pane name to a CALPreferencesGeneralPaneController
 *
 * I've got no idea why we need a dictionary for this - presumably, we can have different
 * GeneralPaneControllers for different panes. Or something.
 */
@implementation icfCALPreferencesPanesController : CALPreferencesPanesController

/**
 * Handle initial class load
 *
 * Overrides existing preference pane manager (i.e. iCalFix's) so we can hook our 
 * preference pane into it
 */
+ (void) load
{
	[icfCALPreferencesPanesController poseAsClass:[CALPreferencesPanesController class]];
}


/**
 * Initialize with a dictionary of panes. We mix our preference panes in and give them the 
 * same GeneralPaneController.
 *
 * That seems to work fine, but maybe we'll need to create our own pane controller for
 * really advanced things. Not sure...
 */
- (id)initWithPanes:(NSDictionary*)panes
{
    NSMutableDictionary* newDictionary = [NSMutableDictionary dictionaryWithDictionary: panes];
    
	// Retrieve a pane controller from a known pane. Technically, this could change, so
	// we *should* use an enumerator. But once Apple starts renaming panes, there will 
	// probably be other changes
    id oldPaneController = [newDictionary objectForKey: ICAL_KNOWN_PANE_NAME ];

	// Register that pane controller for all preference panes we provide
    NSArray* newPaneNames = [[icfPreferencePane sharedInstance] viewNames];
	NSEnumerator* nameEnum = [newPaneNames objectEnumerator];
	NSString* paneName;
	while( paneName = [nameEnum nextObject] )
	{
	    [newDictionary setObject: oldPaneController forKey: paneName ];		
	}

	// And hand the collection of all those pane/controller pairs to the orginal class
    return [super initWithPanes: newDictionary];
}

@end

