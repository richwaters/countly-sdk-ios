// CountlyDB.h
//
// This code is provided under the MIT License.
//
// Please visit www.count.ly for more information.


#import <Foundation/Foundation.h>

#ifdef COUNTLY_DISABLE_COREDATA
#define NSManagedObject NSObject
#else
#import <CoreData/CoreData.h>
#endif

@protocol CountlyDB <NSObject>   // R.A.W.

-(void)createEvent:(NSString*) eventKey count:(double)count sum:(double)sum segmentation:(NSDictionary*)segmentation timestamp:(NSTimeInterval)timestamp;
-(void)addToQueue:(NSString*)postData;
-(void)deleteEvent:(NSManagedObject*)eventObj;
-(void)removeFromQueue:(NSManagedObject*)postDataObj;
-(NSArray*) getEvents;
-(NSArray*) getQueue;
-(NSUInteger)getEventCount;
-(NSUInteger)getQueueCount;
//- (void)saveContext;
-(void) saveObject:(NSObject *)obj ; 

@end


#ifndef COUNTLY_DISABLE_COREDATA

@interface CountlyDB : NSObject <CountlyDB>  // R.A.W.

- (void)saveContext;


/*
@interface CountlyDB : NSObject

+(instancetype)sharedInstance;

-(void)createEvent:(NSString*) eventKey count:(double)count sum:(double)sum segmentation:(NSDictionary*)segmentation timestamp:(NSTimeInterval)timestamp;
-(void)addToQueue:(NSString*)postData;
-(void)deleteEvent:(NSManagedObject*)eventObj;
-(void)removeFromQueue:(NSManagedObject*)postDataObj;
-(NSArray*) getEvents;
-(NSArray*) getQueue;
-(NSUInteger)getEventCount;
-(NSUInteger)getQueueCount;
- (void)saveContext;
 */

@end

#endif
