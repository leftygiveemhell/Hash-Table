//
//  Bucket.cpp
//  430_Assign1
//
//  Created by Jonathan Korn on 1/28/14.
//  Copyright (c) 2014 Jonathan Korn. All rights reserved.
//

#include "Bucket.h"

Bucket::Bucket()
{
   STR10 emptyKey;
    STR20 emptyData;
    slots[0].set(emptyKey, emptyData);
    slots[1].set(emptyKey, emptyData);
    slots[2].set(emptyKey, emptyData);
    count = 0;
    overflow = -1;
}
Bucket::Bucket(Slot slotA)
{
    STR10 tempKey;
    tempKey= slotA.getKey();
    STR20 tempData;
    tempData = slotA.getData();
    slots[0].set(tempKey, tempData);
    STR10 emptyKey;
    STR20 emptyData;
    slots[1].set(emptyKey, emptyData);
    slots[2].set(emptyKey, emptyData);
    count = 1;
    overflow = -1;
}

Bucket::Bucket(Bucket& anotherBucket)
{
    slots[0] = anotherBucket.slots[0];
    slots[1] = anotherBucket.slots[1];
    slots[2] = anotherBucket.slots[2];
    count = anotherBucket.count;
    count = anotherBucket.overflow;
}
void Bucket::set(STR10 Newkey, STR20 Newdata, short slotIndex)
{
    slots[slotIndex].set(Newkey, Newdata);
}
void Bucket::setKey(STR10 Newkey, short slotIndex)
{
    slots[slotIndex].setKey(Newkey);
}
void Bucket::setData(STR20 data, short slotIndex)
{
    slots[slotIndex].setData(data);
}
void Bucket::setOverflow(int O)
{
    overflow = O;
}
void Bucket::incrementCount()
{
    count++;
}
STR10 Bucket::getKey(short slotIndex)
{
    STR10 tempKey;
    tempKey = slots[slotIndex].getKey();
    return tempKey;
}
STR20 Bucket::getData(short slotIndex)
{
    STR20 tempData;
    tempData = slots[slotIndex].getData();
    return tempData;
}
int Bucket::getCount()
{
    return count;
}
int Bucket::getOverflow()
{
    return overflow;
}
bool Bucket::hasFreeSlot()
{
    if (count > 2)
        return false;
    else
        return true;
}
bool Bucket::hasOverflow()
{
    if (overflow < 0)
        return false;
    else
        return true;
}


