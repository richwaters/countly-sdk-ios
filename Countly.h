
// Countly.h
//
// This code is provided under the MIT License.
//
// Please visit www.count.ly for more information.

#import <Foundation/Foundation.h>

#import "CountlyDB.h"

@class CountlyEventQueue;

@interface Countly : NSObject
{
	double unsentSessionLength;
	NSTimer *timer;
	double lastTime;
	BOOL isSuspended;
    CountlyEventQueue *eventQueue;
}

@property(nonatomic,retain)  id<CountlyDB> countlyDB ;  // R.A.W.

+ (instancetype)sharedInstance;


#ifndef COUNTLY_DISABLE_COREDATA  // R.A.W.

- (void)start:(NSString *)appKey withHost:(NSString *)appHost;
- (void)startOnCloudWithAppKey:(NSString *)appKey;


#endif

- (void)resume;
- (void)suspend;
- (void)exit;


- (void)recordEvent:(NSString *)key count:(int)count;

- (void)recordEvent:(NSString *)key count:(int)count sum:(double)sum;

- (void)recordEvent:(NSString *)key segmentation:(NSDictionary *)segmentation count:(int)count;

- (void)recordEvent:(NSString *)key segmentation:(NSDictionary *)segmentation count:(int)count sum:(double)sum;

- (void)recordUserDetails:(NSDictionary *)userDetails;
        extern NSString* const kCLYUserName;
        extern NSString* const kCLYUserUsername;
        extern NSString* const kCLYUserEmail;
        extern NSString* const kCLYUserOrganization;
        extern NSString* const kCLYUserPhone;
        extern NSString* const kCLYUserGender;
        extern NSString* const kCLYUserPicture;
        extern NSString* const kCLYUserPicturePath;
        extern NSString* const kCLYUserBirthYear;
        extern NSString* const kCLYUserCustom;

@end

@interface Countly(NoTimer)
-(void) flushEvents;
- (void)recordEvent:(NSString *)key segmentation:(NSDictionary *)segmentation count:(int)count timestamp:(time_t)timeStamp;
- (void)startNoTimer:(NSString *)appKey withHost:(NSString *)appHost  countlyDb:(id<CountlyDB>)countlyDB;
@end





