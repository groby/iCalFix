#import "CALCore/CALPreferencesGeneralPaneController.h"

@interface icfCALPreferencesGeneralPaneController: CALPreferencesGeneralPaneController
{
    
}

+ (void) load;
- (NSString*)labelForPaneWithIdentifiers:(NSString*)paneIdentifier;
- (NSView*)viewForPaneWithIdentifiers:(NSString*)paneIdentifier;

@end
