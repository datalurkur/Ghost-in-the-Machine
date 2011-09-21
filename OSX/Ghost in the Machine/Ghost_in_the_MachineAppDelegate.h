//
//  Ghost_in_the_MachineAppDelegate.h
//  Ghost in the Machine
//
//  Created by Andrew Jean on 9/21/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface Ghost_in_the_MachineAppDelegate : NSObject <NSApplicationDelegate> {
@private
    NSWindow *window;
}

@property (assign) IBOutlet NSWindow *window;

@end
