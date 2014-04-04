//
//  HashTable.h
//  430_Assign1
//
//  Created by Jonathan Korn on 1/28/14.
//  Copyright (c) 2014 Jonathan Korn. All rights reserved.
//

#ifndef ___30_Assign1__HashTable__
#define ___30_Assign1__HashTable__

#define MAXBUCKETS 30
#define MAXSEARCH 20

#include "Bucket.h"
#include <iostream>

using namespace std;

class HashTable
{
private:
    Bucket buckets[MAXBUCKETS];
    int nextFreeBucket;
    int hashFunction(STR10 k)
    {
        return (k[1]+k[3]+k[5])%20;
        //int hashValue = (k[2]+k[4]+k[6])%20;
        //return hashValue;
        //STR10 tempKey;
        //return hashValue;
    }
    int hashFunction(char k[])
    {
        int hashValue = (k[1]+k[3]+k[5])%20;
        return hashValue;
        STR10 tempKey;
        return hashValue;
    }
    int count;
    int index;
public:
    HashTable();
    HashTable(Bucket Newbucket);
    HashTable(HashTable& anotherHashTable);
    void Initialize();
    void InsertIntoHT(STR10 k, STR20 d, int hashIndex);
    void WriteHTtoDisk(ofstream *);
    void RestoreHTtoMem(ifstream *);
    void ReportHT(char reportFileName[], char title[]);
    void SearchReportHT (char searchFileName[]);
    void SearchNewWay(char key[],int hashIndex, ofstream*);
    int findBucket(char key[], int hashIndex);
    void GenerateStatReportExtnd(char reportFileName[]);
    int GenerateCollisionCount(int index);
    bool hasFreeSlot(short bucketIndex);
    bool hasOverflow(short bucketIndex);
    bool hasMatch(char key[], int location);
    int findSlot(char key[], int location);
    int  nextAvailBucket();
    void iterate_Start();
    bool iterate_HasNext();
    Bucket iterate_GetNext();
};

#endif /* defined(___30_Assign1__HashTable__) */
