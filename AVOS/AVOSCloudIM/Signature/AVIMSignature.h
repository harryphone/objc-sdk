//
//  AVIMSignature.h
//  AVOSCloudIM
//
//  Created by Qihe Bian on 12/4/14.
//  Copyright (c) 2014 LeanCloud Inc. All rights reserved.
//

#import "LCIMCommon.h"

NS_ASSUME_NONNULL_BEGIN

@interface AVIMSignature : NSObject

/**
 *  Signture result signed by server master key.
 */
@property (nonatomic, copy, nullable) NSString *signature;

/**
 *  Timestamp used to construct signature.
 */
@property (nonatomic, assign) int64_t timestamp;

/**
 *  Nonce string used to construct signature
 */
@property (nonatomic, copy, nullable) NSString *nonce;

/**
 *  Error in the course of getting signature from server. Commonly network error. Please set it if any error when getting signature.
 */
@property (nonatomic, strong, nullable) NSError *error;

@end

@protocol AVIMSignatureDataSource <NSObject>
@optional

/*!
 对一个操作进行签名. 注意:本调用会在后台线程被执行
 @param clientId - 操作发起人的 id
 @param conversationId － 操作所属对话的 id
 @param action － @see LCIMSignatureAction
 @param clientIds － 操作目标的 id 列表
 @return 一个 AVIMSignature 签名对象.
 */
- (AVIMSignature *)signatureWithClientId:(NSString *)clientId
                          conversationId:(NSString * _Nullable)conversationId
                                  action:(LCIMSignatureAction)action
                       actionOnClientIds:(NSArray<NSString *> * _Nullable)clientIds;
@end

NS_ASSUME_NONNULL_END
