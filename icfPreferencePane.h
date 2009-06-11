#import <Cocoa/Cocoa.h>
#import "icfPreferences.h"

@interface icfPreferencePane : NSObject
{
    IBOutlet NSPopUpButton *advanceTimeUnit;

    IBOutlet NSPopUpButton* allDayAdvanceTimeUnit;
    IBOutlet NSTextField*   allDayWarningTime;
    
    IBOutlet NSPopUpButton *alarmSounds;
    IBOutlet NSTextField *buildLabel;
    IBOutlet NSTextField *warningTime;
    IBOutlet NSView *prefView;
}
- (IBAction)setAdvanceTime:(id)sender;
- (IBAction)setSound:(id)sender;
- (IBAction)donate:(id)sender;

+ (icfPreferencePane*) sharedInstance;

- (id)init;
- (void) awakeFromNib;
- (void) loadPreferences: (icfPreferences*)prefs;

- (NSArray*) viewNames;

- (NSView*) viewForPaneWithIdentifiers:(NSString *)aName;
- (NSString*)labelForPaneWithIdentifiers:(NSString*)fp8;


@end
