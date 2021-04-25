//
//  AVIMCommandFormatter.m
//  AVOSCloudIM
//
//  Created by CHEN YI LONG on 15/11/17.
//  Copyright (c) 2015 LeanCloud Inc. All rights reserved.
//

#import <AVOSCloud/AVOSCloud.h>

#import "AVIMCommandFormatter.h"
#import "AVIMErrorUtil.h"

const NSInteger LCIMErrorCodeSessionTokenExpired = 4112;

@implementation AVIMCommandFormatter

+ (NSString *)commandType:(AVIMCommandType)commandType {
    NSString *commandTypeString = nil;
    switch (commandType) {
        case AVIMCommandType_Session:
            commandTypeString = @"Session";
            break;
            
        case AVIMCommandType_Conv:
            commandTypeString = @"Conv";
            break;
            
        case AVIMCommandType_Direct:
            commandTypeString = @"Direc";
            break;
            
        case AVIMCommandType_Ack:
            commandTypeString = @"Ack";
            break;
            
        case AVIMCommandType_Rcp:
            commandTypeString = @"Rcp";
            break;
            
        case AVIMCommandType_Unread:
            commandTypeString = @"Unread";
            break;
            
        case AVIMCommandType_Logs:
            commandTypeString = @"Logs";
            break;
            
        case AVIMCommandType_Error:
            commandTypeString = @"Error";
            break;
            
        case AVIMCommandType_Login:
            commandTypeString = @"Login";
            break;
            
        case AVIMCommandType_Data:
            commandTypeString = @"Data";
            break;
            
        case AVIMCommandType_Room:
            commandTypeString = @"Room";
            break;
            
        case AVIMCommandType_Read:
            commandTypeString = @"Read";
            break;
            
        case AVIMCommandType_Presence:
            commandTypeString = @"Presence";
            break;
            
        case AVIMCommandType_Report:
            commandTypeString = @"Report";
            break;
            
        default:
            break;
    }
    return commandTypeString;
}

+ (AVIMJsonObjectMessage *)JSONObjectWithDictionary:(NSDictionary *)dictionary {
    AVIMJsonObjectMessage *jsonObjectMesssage = nil;

    if (dictionary && [NSJSONSerialization isValidJSONObject:dictionary]) {
        NSError *error = nil;
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dictionary options:0 error:&error];

        if ([jsonData length]) {
            NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
            jsonObjectMesssage = [[AVIMJsonObjectMessage alloc] init];
            jsonObjectMesssage.data_p = jsonString;
        } else if (error) {
//            LCLoggerError(LCLoggerDomainIM, @"Can not stringify dictionary: %@.", error.localizedDescription);
        } else {
//            LCLoggerError(LCLoggerDomainIM, @"Empty data for dictionary.");
        }
    }

    return jsonObjectMesssage;
}

+ (NSData *)dataWithJSONObject:(AVIMJsonObjectMessage *)JSONObject {
    NSData *data = [JSONObject.data_p dataUsingEncoding:NSUTF8StringEncoding];
    return data;
}

@end
