// -*- Mode: objc; Coding: utf-8; indent-tabs-mode: nil; -*-
#import <Cocoa/Cocoa.h>

@interface WorkSpaceData : NSObject

+ (NSString*) getActiveApplicationName;
+ (unsigned int) getApplicationType:(NSString*)name;

@end


@interface WorkSpaceData (InputSource)
+ (void) refreshEnabledInputSources;

+ (NSString*) getTISPropertyInputSourceID;
+ (NSString*) getTISPropertyInputModeID:(NSString*)inputSourceID;
+ (void) getInputMode:(NSString*)name output_inputmode:(unsigned int*)output_inputmode output_inputmodedetail:(unsigned int*)output_inputmodedetail;
+ (void) selectInputSource:(unsigned int)vk_keycode;
@end
