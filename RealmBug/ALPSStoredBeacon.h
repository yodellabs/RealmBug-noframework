//
//  ALPSStoredBeacon.h
//  RealmBug
//
//  Created by Nick Wilkerson on 12/10/17.
//  Copyright © 2017 nsnick. All rights reserved.
//

#import <Realm/Realm.h>

@class ALPSStoredGrid;
//@class ALPSStoredZone;

@interface ALPSStoredBeacon : RLMObject

@property NSString *identifier;
@property NSNumber<RLMInt> *slotNumber;
@property NSNumber<RLMDouble> *x;
@property NSNumber<RLMDouble> *y;

@property ALPSStoredGrid *grid;
//@property ALPSStoredZone *zone;

@end
