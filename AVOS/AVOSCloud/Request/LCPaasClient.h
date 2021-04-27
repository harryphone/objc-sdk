//
//  LCPaasClient.h
//  paas
//
//  Created by Zhu Zeng on 2/25/13.
//  Copyright (c) 2013 AVOS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LCConstants.h"
#import "LCACL.h"
#import "UserAgent.h"

static NSString *const USER_AGENT = @"LeanCloud-Objc-SDK/" SDK_VERSION;

FOUNDATION_EXPORT NSString *const LCHeaderFieldNameId;
FOUNDATION_EXPORT NSString *const LCHeaderFieldNameKey;
FOUNDATION_EXPORT NSString *const LCHeaderFieldNameSign;
FOUNDATION_EXPORT NSString *const LCHeaderFieldNameSession;
FOUNDATION_EXPORT NSString *const LCHeaderFieldNameProduction;

@interface LCPaasClient : NSObject

+(LCPaasClient *)sharedInstance;

@property (nonatomic, readwrite, copy) NSString * applicationId;
@property (nonatomic, readwrite, copy) NSString * clientKey;
@property (nonatomic, readonly, copy) NSString * apiVersion;
@property (nonatomic, readwrite, copy) NSString * applicationIdField;
@property (nonatomic, readwrite, copy) NSString * applicationKeyField;
@property (nonatomic, readwrite, copy) NSString * sessionTokenField;
@property (nonatomic, readwrite, strong) LCUser * currentUser;
@property (nonatomic, readwrite, strong) LCACL * defaultACL;
@property (nonatomic, readwrite) BOOL currentUserAccessForDefaultACL;

@property (nonatomic, readwrite, assign) NSTimeInterval timeoutInterval;

@property (nonatomic, readwrite, strong) NSMutableDictionary * subclassTable;

// only for cloud code yet
@property (nonatomic, assign) BOOL productionMode;

@property (nonatomic, assign) BOOL isLastModifyEnabled;

@property (nonatomic, strong) NSLock *lock;

-(void)clearLastModifyCache;

- (LCACL *)updatedDefaultACL;

+(NSMutableDictionary *)batchMethod:(NSString *)method
                               path:(NSString *)path
                               body:(NSDictionary *)body
                         parameters:(NSDictionary *)parameters;

+(void)updateBatchMethod:(NSString *)method
                    path:(NSString *)path
                    dict:(NSMutableDictionary *)dict;

- (void)getObject:(NSString *)path
   withParameters:(NSDictionary *)parameters
            block:(LCIdResultBlock)block;

- (void)getObject:(NSString *)path
   withParameters:(NSDictionary *)parameters
           policy:(LCCachePolicy)policy
      maxCacheAge:(NSTimeInterval)maxCacheAge
            block:(LCIdResultBlock)block;

-(void)putObject:(NSString *)path
  withParameters:(NSDictionary *)parameters
    sessionToken:(NSString *)sessionToken
           block:(LCIdResultBlock)block;

-(void)postBatchObject:(NSArray *)parameterArray block:(LCArrayResultBlock)block;
-(void)postBatchObject:(NSArray *)parameterArray headerMap:(NSDictionary *)headerMap eventually:(BOOL)isEventually block:(LCArrayResultBlock)block;

-(void)postBatchSaveObject:(NSArray *)parameterArray headerMap:(NSDictionary *)headerMap eventually:(BOOL)isEventually block:(LCIdResultBlock)block;

-(void)postObject:(NSString *)path
  withParameters:(NSDictionary *)parameters
           block:(LCIdResultBlock)block;

-(void)postObject:(NSString *)path
   withParameters:(NSDictionary *)parameters
       eventually:(BOOL)isEventually
            block:(LCIdResultBlock)block ;

-(void)deleteObject:(NSString *)path
     withParameters:(NSDictionary *)parameters
              block:(LCIdResultBlock)block;

- (void)deleteObject:(NSString *)path
      withParameters:(NSDictionary *)parameters
          eventually:(BOOL)isEventually
               block:(LCIdResultBlock)block;

- (NSString *)absoluteStringFromPath:(NSString *)path parameters:(NSDictionary *)parameters;

-(BOOL)addSubclassMapEntry:(NSString *)parseClassName
               classObject:(Class)object;
-(Class)classFor:(NSString *)parseClassName;

// offline
// TODO: never called this yet!
- (void)handleAllArchivedRequests;

#pragma mark - Network Utils

/*!
 * Get signature header field value.
 */
- (NSString *)signatureHeaderFieldValue;

- (NSMutableURLRequest *)requestWithPath:(NSString *)path
                                  method:(NSString *)method
                                 headers:(NSDictionary *)headers
                              parameters:(NSDictionary *)parameters;

- (void)performRequest:(NSURLRequest *)request
               success:(void (^)(NSHTTPURLResponse *response, id responseObject))successBlock
               failure:(void (^)(NSHTTPURLResponse *response, id responseObject, NSError *error))failureBlock;

- (void)performRequest:(NSURLRequest *)request
               success:(void (^)(NSHTTPURLResponse *response, id responseObject))successBlock
               failure:(void (^)(NSHTTPURLResponse *response, id responseObject, NSError *error))failureBlock
                  wait:(BOOL)wait;

@end
