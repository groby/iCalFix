#import <Cocoa/Cocoa.h>


@interface icfLoader : NSObject 
{

}

+ (void) load;
+ (void) installPlugin:(NSNotification*)_notification;
@end
