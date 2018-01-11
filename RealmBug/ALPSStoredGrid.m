//
//  ALPSStoredGrid.m
//  RealmBug
//
//  Created by Nick Wilkerson on 12/10/17.
//  Copyright © 2017 nsnick. All rights reserved.
//

#import "ALPSStoredGrid.h"

@implementation ALPSStoredGrid

+ (NSString *)primaryKey {
    return @"identifier";
}

-(UIImage *)floorPlanImage {
    return [UIImage imageWithData:self.floorPlanImagePNGData];
}

-(NSArray<NSArray<NSValue*>*>*)contourArrays {
    NSMutableArray *contourArrays = [[NSMutableArray alloc] init];
    for (ALPSStoredContour *contour in self.contours) {
        NSMutableArray *contourArray = [[NSMutableArray alloc] init];
        for (ALPSStoredContourPoint *contourPoint in contour.points) {
            [contourArray addObject:[NSValue valueWithCGPoint:CGPointMake(contourPoint.x.doubleValue, contourPoint.y.doubleValue)]];
        }
        [contourArrays addObject:contourArray];
    }
    return contourArrays;
}

-(NSArray *)allBeacons {
    NSMutableArray *beaconsArray = [[NSMutableArray alloc] init];
    for (ALPSStoredBeacon *beacon in self.beacons) {
        [beaconsArray addObject:beacon];
    }
    return beaconsArray;
}
/*
 -(NSArray <ALPSStoredZone*>*_Nonnull)allZones {
 NSMutableArray *zonesArray = [[NSMutableArray alloc] init];
 for (ALPSStoredZone *zone in self.zones) {
 [zonesArray addObject:zone];
 }
 return zonesArray;
 }
 */

-(UIImage *)gridImage {
    NSLog(@"gridImage");
    
    NSData *gridData = [self gridData];
    long gridWidth = self.gridWidth.doubleValue;
    long gridHeight = gridData.length / self.gridWidth.longValue;
    
    uint8_t *bytes = (uint8_t *)gridData.bytes;
    
    //  let sampleImage = UIImage()
    CGRect imageRect = CGRectMake(0,  0, gridWidth, gridHeight);
    
    UIGraphicsBeginImageContext(imageRect.size);
    CGContextRef context  = UIGraphicsGetCurrentContext();
    
    long occupiedPixelCount = 0;
    for (long row=0; row< gridHeight; row++) {
        for (long column=0; column<gridWidth; column++){
            if (*(bytes + (long)(row * gridWidth + column)) != 0) {
                occupiedPixelCount += 1;
                CGContextSetFillColorWithColor(context, [UIColor blueColor].CGColor);
            } else {
                CGContextSetFillColorWithColor(context, [UIColor clearColor].CGColor);
            }
            CGContextFillRect(context, CGRectMake(column, row, 1, 1));
        }
    }
    
    UIImage *img = UIGraphicsGetImageFromCurrentImageContext();
    return img;
}



@end
