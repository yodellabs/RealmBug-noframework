//
//  ALPSStoredContour.h
//  RealmBug
//
//  Created by Nick Wilkerson on 12/10/17.
//  Copyright © 2017 nsnick. All rights reserved.
//

#import <Realm/Realm.h>
#import "ALPSStoredContourPoint.h"

RLM_ARRAY_TYPE(ALPSStoredContourPoint)

@interface ALPSStoredContour : RLMObject

@property RLMArray<ALPSStoredContourPoint*><ALPSStoredContourPoint> *points;

@end
