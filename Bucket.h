//
//  Bucket.h
//  430_Assign1
//
//  Created by Jonathan Korn on 1/28/14.
//  Copyright (c) 2014 Jonathan Korn. All rights reserved.
//

#ifndef ___30_Assign1__Bucket__
#define ___30_Assign1__Bucket__

#define MAXSLOTS 3

#include "Slot.h"
#include <iostream>

using namespace std;

class Bucket
{
private:
    Slot slots[3];
    int overflow;
    int count;
public:
    Bucket();
    Bucket(Slot slot1);
    Bucket(Bucket& anotherBucket);
    void set(STR10 key, STR20 data, short slotIndex);
    void setKey(STR10 key, short slotIndex);
    void setData(STR20 data, short slotIndex);
    void setOverflow(int O);
    void incrementCount();
    STR10 getKey(short slotIndex);
    STR20 getData(short slotIndex);
    int getCount();
    int getOverflow();
    bool hasFreeSlot();
    bool hasOverflow();
};

#endif /* defined(___30_Assign1__Bucket__) */
