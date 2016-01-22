/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <FBSimulatorControl/FBSimulator.h>
#import <FBSimulatorControl/FBSimulatorEventSink.h>

@class FBMutableSimulatorEventSink;
@class FBProcessQuery;
@class FBSimulatorEventRelay;
@class FBSimulatorHistoryGenerator;
@protocol FBSimulatorLogger;

@interface FBSimulator ()

@property (nonatomic, strong, readonly) FBSimulatorEventRelay *eventRelay;
@property (nonatomic, strong, readonly) FBSimulatorHistoryGenerator *historyGenerator;
@property (nonatomic, strong, readonly) FBMutableSimulatorEventSink *mutableSink;
@property (nonatomic, strong, readonly) FBProcessQuery *processQuery;

@property (nonatomic, copy, readwrite) FBSimulatorConfiguration *configuration;

+ (instancetype)fromSimDevice:(SimDevice *)device configuration:(FBSimulatorConfiguration *)configuration pool:(FBSimulatorPool *)pool query:(FBProcessQuery *)query logger:(id<FBSimulatorLogger>)logger;
- (instancetype)initWithDevice:(SimDevice *)device configuration:(FBSimulatorConfiguration *)configuration pool:(FBSimulatorPool *)pool query:(FBProcessQuery *)query logger:(id<FBSimulatorLogger>)logger;

@end
