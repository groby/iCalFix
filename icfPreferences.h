#import <Cocoa/Cocoa.h>

@interface icfPreferences : NSObject
{
	NSUserDefaults 			*userDefaults;
}

+ (icfPreferences*) sharedInstance;

- (id)init;

- (void)registerDefaults:(NSDictionary*)defaults;
- (id)objectForKey:(NSString*)aKey;
- (void)setObject:(id)value forKey:(NSString *)defaultName;

@end
