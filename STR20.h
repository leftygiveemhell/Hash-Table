//
//  STR20.h
//  430_Assign1
//
//  Created by Jonathan Korn on 1/28/14.
//  Copyright (c) 2014 Jonathan Korn. All rights reserved.
//

#ifndef ___30_Assign1__STR20__
#define ___30_Assign1__STR20__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAXDATALEN 20

using namespace std;

class STR20
{
private:
    char data[MAXDATALEN+1];
public:
    STR20();
    STR20(char Newdata[]);
    STR20(STR20& anotherSTR20);
    void set(char Newdata[]);
    char &operator[](const int &);
    friend ostream &operator<<(ostream &, const STR20 &);
};
#endif /* defined(___30_Assign1__STR20__) */
