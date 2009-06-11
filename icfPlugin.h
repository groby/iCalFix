#import <Growl/GrowlApplicationBridge.h>

#import "CALCore/API.h"

#define ICF_STRING_TABLE @"iCalFix"
#define ICF_IDENTIFIER @"com.robertblum.iCalFix"


@interface icfPlugin: NSObject <GrowlApplicationBridgeDelegate>
{
    BOOL        loaded;
    CALAlarm*   defaultAlarm;
}


- (NSString*) nibName;
- (NSString*) bundleVersion;
- (NSString*) marketingVersion;
- (BOOL) isLoaded;
- (void) setLoaded:(BOOL)_loaded;

- (void)        setDefaultAlarm:(CALAlarm*)defaultTrigger;
- (CALAlarm*)   getDefaultAlarm;

// Growl support
- (NSDictionary *) registrationDictionaryForGrowl;
- (NSString *) applicationNameForGrowl;

+ (void)installAsScheduler:(BOOL)_asScheduler;
+ (icfPlugin*)sharedInstance;
+ (void) errorAlert:(NSString*)_message withDetails:(NSString*)_details, ...;

@end

