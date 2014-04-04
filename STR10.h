//
//  STR10.h
//  430_Assign1
//
//  Created by Jonathan Korn on 1/28/14.
//  Copyright (c) 2014 Jonathan Korn. All rights reserved.
//

#ifndef ___30_Assign1__STR10__
#define ___30_Assign1__STR10__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAXKEYLEN 10

using namespace std;

class STR10
{
private:
    char data[MAXKEYLEN+1];
public:
    STR10();
    STR10(char Newdata[]);
    STR10(STR10& anotherSTR10);
    void set(char key[]);
    char &operator[](const int &);
    bool operator==(const char[]);
    bool operator==(const STR10);
    friend ostream &operator<<(ostream &, const STR10 &);
};



#endif /* defined(___30_Assign1__STR10__) */
