//
//  BreathalyzerAppDelegate.h
//  Breathalyzer
//
//  Created by Nathan Collingridge on 3/8/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HiJackMgr.h"

@class GlucometerViewController;
@class GlucoViewController;

typedef enum
{
    INIT,    //initial state
    ONLINE,  //hijack is connected (online)
    TEST,    //user is performing a test
    COMPLETE //test is finished, final value is received.
} State;

@interface GlucometerAppDelegate : NSObject <UIApplicationDelegate> {
      HiJackMgr* hiJackMgr;
      UIWindow *window;
      GlucometerViewController *viewController;
      GlucoViewController *glucoViewController;
      UInt8 value;
      UInt8 result;
      State state;
      BOOL showAlert;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet GlucometerViewController *viewController;
@property (nonatomic, retain) IBOutlet GlucoViewController *glucoViewController;

-(int)receive:(UInt8)data;
-(int)sendByte:(UInt8)message;
-(void)update;
-(BOOL)isOnline;
-(void)resetState;

@end
