//
//  AVAnonymousUtils.h
//  LeanCloud
//
//  Created by Zhu Zeng on 6/20/13.
//  Copyright (c) 2013 AVOS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LCUser.h"
#import "LCConstants.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 Provides utility functions for working with Anonymously logged-in users.  Anonymous users have some unique characteristics:
 <ul>
   <li>Anonymous users don't need a user name or password.</li>
   <li>Once logged out, an anonymous user cannot be recovered.</li>
   <li>When the current user is anonymous, the following methods can be used to switch to a different user or convert the
     anonymous user into a regular one:
     <ul>
       <li>signUp converts an anonymous user to a standard user with the given username and password.
           Data associated with the anonymous user is retained.</li>
       <li>logIn switches users without converting the anonymous user.  Data associated with the anonymous user will be lost.</li>
       <li>Service logIn (e.g. Facebook, Twitter) will attempt to convert the anonymous user into a standard user by linking it to the service.
           If a user already exists that is linked to the service, it will instead switch to the existing user.</li>
       <li>Service linking (e.g. Facebook, Twitter) will convert the anonymous user into a standard user by linking it to the service.</li>
     </ul>
 </ul>
 */
__deprecated_msg("Deprecated. use LCUser instead.")
@interface AVAnonymousUtils : NSObject

/*! @name Creating an Anonymous User */

/*!
 Creates an anonymous user.
 @param block The block to execute when anonymous user creation is complete. The block should have the following argument signature:
 (LCUser *user, NSError *error)
 */
+ (void)logInWithBlock:(LCUserResultBlock)block __deprecated_msg("Deprecated. use +[LCUser loginAnonymouslyWithCallback:] instead.");

/*! @name Determining Whether a LCUser is Anonymous */

/*!
 Whether the user is logged in anonymously.
 @param user User to check for anonymity. The user must be logged in on this device.
 @return True if the user is anonymous.  False if the user is not the current user or is not anonymous.
 */
+ (BOOL)isLinkedWithUser:(LCUser *)user __deprecated_msg("Deprecated. use -[LCUser isAnonymous:] instead.");

@end

NS_ASSUME_NONNULL_END
