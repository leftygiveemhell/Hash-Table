//
//  Slot.cpp
//  430_Assign1
//
//  Created by Jonathan Korn on 1/28/14.
//  Copyright (c) 2014 Jonathan Korn. All rights reserved.
//

#include "Slot.h"

Slot::Slot()
{
    key = STR10();
    data = STR20();
}
Slot::Slot(STR10 Newkey)
{
    key = Newkey;
    data[0] = '\0';
}
Slot::Slot(STR10 Newkey, STR20 Newdata)
{
    key = Newkey;
    data = Newdata;
}
Slot::Slot(Slot& anotherSlot)
{
    key = anotherSlot.key;
    data = anotherSlot.data;
}
void Slot::set(STR10 Newkey, STR20 Newdata)
{
    key = Newkey;
    data = Newdata;
}
void Slot::setKey(STR10 Newkey)
{
    key = Newkey;
}
void Slot::setData(STR20 Newdata)
{
    data = Newdata;
}
STR10 Slot::getKey()
{
    return key;
}
STR20 Slot::getData()
{
    return data;
}