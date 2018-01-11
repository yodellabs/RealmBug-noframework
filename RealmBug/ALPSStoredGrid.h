//
//  ALPSStoredGrid.h
//  RealmBug
//
//  Created by Nick Wilkerson on 12/10/17.
//  Copyright © 2017 nsnick. All rights reserved.
//

#import <Realm/Realm.h>
#import "ALPSStoredBeacon.h"
#import "ALPSStoredContour.h"
#import <UIKit/UIKit.h>

RLM_ARRAY_TYPE(ALPSStoredBeacon)
//RLM_ARRAY_TYPE(ALPSStoredZone)
RLM_ARRAY_TYPE(ALPSStoredContour)


@interface ALPSStoredGrid : RLMObject

@property NSString *_Nullable identifier;
@property NSNumber<RLMDouble> *_Nullable latitude;
@property NSNumber<RLMDouble> *_Nullable longitude;
@property NSNumber<RLMInt> *_Nullable floor;

@property NSNumber<RLMDouble> *_Nullable rotation;
@property NSNumber<RLMDouble> *_Nullable scale;

@property NSData *_Nullable gridData;
@property NSNumber<RLMDouble> *_Nullable gridWidth;

@property RLMArray<ALPSStoredContour*><ALPSStoredContour> *_Nullable contours;

@property NSData *_Nullable floorPlanImagePNGData;


//@property RLMArray<ALPSStoredZone*><ALPSStoredZone> *_Nonnull zones;
@property RLMArray<ALPSStoredBeacon*><ALPSStoredBeacon> *_Nonnull beacons;

/* calculated properties */
-(UIImage *_Nonnull)gridImage;
-(NSArray<NSArray<NSValue*>*>*_Nonnull)contourArrays;
-(UIImage *_Nonnull)floorPlanImage;
-(NSArray <ALPSStoredBeacon*>*_Nonnull)allBeacons;
//-(NSArray <ALPSStoredZone*>*_Nonnull)allZones;


@end
