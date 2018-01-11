//
//  ALPSStoredContourPoint.h
//  RealmBug
//
//  Created by Nick Wilkerson on 12/10/17.
//  Copyright © 2017 nsnick. All rights reserved.
//

#import <Realm/Realm.h>

@interface ALPSStoredContourPoint : RLMObject

@property NSNumber<RLMDouble> *x;
@property NSNumber<RLMDouble> *y;

@end
