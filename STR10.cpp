//
//  STR10.cpp
//  430_Assign1
//
//  Created by Jonathan Korn on 1/28/14.
//  Copyright (c) 2014 Jonathan Korn. All rights reserved.
//

#include "STR10.h"

STR10::STR10()
{
    data[0] = 0;
}
STR10::STR10(char NewData[])
{
    for (int i=0;i<10;i++)
        data[i]=NewData[i];
    data[10]=0;
}
STR10::STR10(STR10& anotherSTR10)
{
    for (int i=0;i<11;i++)
        data[i]=anotherSTR10.data[i];
}
void STR10::set(char key[])
{
    for (int i=0;i<10;i++)
        data[i]=key[i];
    data[10]=0;
}
char &STR10::operator[](const int &sub)
{
    //if (sub < 0 || sub >= 11)
    //    subscriptError();
    return data[sub];
}
bool STR10::operator==(const char right[])
{
    bool status;
    
    if (strcmp(data,right)==0)
        status = true;
    else
        status = false;
    return status;
}
bool STR10::operator==(const STR10 right)
{
    bool status;
    if (strcmp(data,right.data)==0)
        status = true;
    else status = false;
    return false;
}
ostream &operator<<(ostream &output, const STR10 &right)
{
    output << right.data;
    return output;
}