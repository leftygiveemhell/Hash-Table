//
//  STR20.cpp
//  430_Assign1
//
//  Created by Jonathan Korn on 1/28/14.
//  Copyright (c) 2014 Jonathan Korn. All rights reserved.
//

#include "STR20.h"

STR20::STR20()
{
    data[0] = '\0';
}
STR20::STR20(char NewData[])
{
    for (int i=0;i<20;i++)
        data[i]=NewData[i];
}
STR20::STR20(STR20& anotherSTR20)
{
    for (int i=0;i<20;i++)
        data[i]=anotherSTR20.data[i];
}
void STR20::set(char NewData[])
{
    for (int i=0;i<20;i++)
        data[i]=NewData[i];
}
char &STR20::operator[](const int &sub)
{
    return data[sub];
}
ostream &operator<<(ostream &output, const STR20 &right)
{
    output << right.data;
    return output;
}