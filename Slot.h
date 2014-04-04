//
//  Slot.h
//  430_Assign1
//
//  Created by Jonathan Korn on 1/28/14.
//  Copyright (c) 2014 Jonathan Korn. All rights reserved.
//

#ifndef ___30_Assign1__Slot__
#define ___30_Assign1__Slot__

#include "STR10.h"
#include "STR20.h"

#include <cstring>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>

using namespace std;

class Slot
{
private:
    STR10 key;
    STR20 data;
public:
    Slot();
    Slot(STR10 Newkey);
    Slot(STR10 Newkey, STR20 Newdata);
    Slot(Slot& anotherSlot);
    void set(STR10 Newkey, STR20 Newdata);
    void setKey(STR10 Newkey);
    void setData(STR20 Newdata);
    STR10 getKey();
    STR20 getData();
    
};
#endif /* defined(___30_Assign1__Slot__) */
