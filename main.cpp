//  JONATHAN KORN
//  CISP 430, SPRING 2014
//  ASSIGNMENT 1
//
//  main.cpp
//  430_Assign1
//
//  Created by Jonathan Korn on 1/28/14.
//  Copyright (c) 2014 Jonathan Korn. All rights reserved.
//

/*
 
 CLASS MODEL
 
 STR10
  (-) data
  (+) STR10()
  (+) STR10(Newdata)
  (+) STR10(STR10 anotherSTR10)
  (+) void set(Newkey)
  (+) datatype &operator[](char[])
  (+) boolean operator==(char[])
  (+) boolean operator==(STR10)
  (+) friend ostream &operator<<(ostream &, const STR10 &);
 
 STR20
  (-) data
  (+) STR20()
  (+) STR20(Newdata)
  (+) STR20(STR20 anotherSTR20)
  (+) void set(Newkey)
  (+) datatype &operator[](char[])
  (+) friend ostream &operator<<(ostream &, const STR20 &);
 
 Slot
  (-) STR10 key
  (-) STR20 data
  (+) Slot()
  (+) Slot(STR10 Newkey)
  (+) Slot(STR10 Newkey, STR20 Newdata)
  (+) Slot(Slot& anotherSlot)
  (+) void set(STR10 Newkey, STR20 Newdata)
  (+) void setKey(STR10 Newkey)
  (+) void setData(STR20 Newdata)
  (+) STR10 getKey()
  (+) STR20 getData()
 
 Bucket
  (-) Slot slots[3]
  (-) overflow
  (-) count
  (+) Bucket()
  (+) Bucket(Slot slot1)
  (+) Bucket(Bucket& anotherBucket)
  (+) void set(STR10 key, STR20 data, short slotIndex)
  (+) void setKey(STR10 key, short slotIndex)
  (+) void setData(STR20 data, short slotIndex)
  (+) void setOverflow(int O)
  (+) void incrementCount()
  (+) STR10 getKey(short slotIndex)
  (+) STR20 getData(short slotIndex)
  (+) datatype getCount()
  (+) datatype getOverflow()
  (+) boolean hasFreeSlot()
  (+) boolean hasOverflow()

 HashTable
  (-) Bucket buckets[MAXBUCKETS]
  (-) nextFreeBucket
  (-) count
  (-) index
  (-) hashFunction(STR10 k)
  (-) hashFunction(char k[])
  (+) HashTable()
  (+) HashTable(Bucket Newbucket)
  (+) HashTable(HashTable& anotherHashTable)
  (+) void Initialize()
  (+) void InsertIntoHT(STR10 k, STR20 d, int hashIndex)
  (+) void WriteHTtoDisk(ofstream *)
  (+) void RestoreHTtoMem(ifstream *)
  (+) void ReportHT(char reportFileName[], char title[])
  (+) void SearchReportHT (char searchFileName[])
  (+) void SearchNewWay(char key[],int hashIndex, ofstream*)
  (+) datatype findBucket(char key[], int hashIndex)
  (+) void GenerateStatReportExtnd(char reportFileName[])
  (+) void GenerateCollisionCount(int index)
  (+) boolean hasFreeSlot(short bucketIndex)
  (+) boolean hasOverflow(short bucketIndex)
  (+) boolean hasMatch(char key[], int location)
  (+) datatype findSlot(char key[], int location)
  (+) datatype nextAvailBucket()
  (+) void iterate_Start()
  (+) boolean iterate_HasNext()
  (+) Bucket iterate_GetNext()
 
 CLASS ASSOCIATIONS
 
 HashTable  --- 1 : m(contains)     --- Bucket
 Bucket     --- 1 : 3(includes)     --- Slots
 Slot       --- 1 : 1(includes)     --- STR10
 Slot       --- 1 : 1(includes)     --- STR20
 
 */

#include <iostream>
#include "HashTable.h"
#define SEARCH "/users/jonathankorn/desktop/search.txt"


int main(void)
{
    HashTable ht;
    
    ht.Initialize();
    
    ht.ReportHT("/users/jonathankorn/desktop/reportHT.txt", "Before");
   
    ofstream out("/users/jonathankorn/desktop/htout");
    ht.WriteHTtoDisk(&out);
    out.close();
    
    ifstream in("/users/jonathankorn/desktop/htout");
    
    ht.RestoreHTtoMem(&in);
    
    ht.ReportHT("/users/jonathankorn/desktop/reportHT2.txt", "After");
    
    ht.SearchReportHT("/users/jonathankorn/desktop/search.txt");

    ht.GenerateStatReportExtnd("/users/jonathankorn/desktop/stats.txt");

    return 0;
}

