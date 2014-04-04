//
//  HashTable.cpp
//  430_Assign1
//
//  Created by Jonathan Korn on 1/28/14.
//  Copyright (c) 2014 Jonathan Korn. All rights reserved.
//

#include "HashTable.h"
#define DATAIN "/users/jonathankorn/desktop/datain.txt"


HashTable::HashTable()
{
    STR10 emptyKey;
    STR20 emptyData;
    for (int i=0; i<MAXBUCKETS; i++)
    {
        for(int j=0; j<MAXSLOTS; j++)
        {
            buckets[i].set(emptyKey, emptyData, j);
        }
    }
    nextFreeBucket = 20;
    count = 0;
    index = 0;
}
HashTable::HashTable(Bucket Newbucket)
{
    STR10 tempKey;
    STR20 tempData;
    for(int i=0; i<3; i++)
    {
        tempKey = Newbucket.getKey(i);
        tempData = Newbucket.getData(i);
        buckets[0].set(tempKey, tempData, i);
    }
    STR10 emptyKey;
    STR20 emptyData;
    for (int i=1; i<MAXBUCKETS; i++)
    {
        for(int j=0; j<MAXSLOTS; j++)
        {
            buckets[i].set(emptyKey, emptyData, j);
        }
    }
    nextFreeBucket = 20;
    count = 1;
}
HashTable::HashTable(HashTable& anotherHashTable)
{
    for (int i=0; i<MAXBUCKETS; i++)
    {
            buckets[i] = anotherHashTable.buckets[i];
    }
    nextFreeBucket = anotherHashTable.nextFreeBucket;
    count = anotherHashTable.count;
}
void HashTable::Initialize()
{
    FILE * inputFile;
	char keyTemp[10+1];
	char dataTemp[20+1];
    STR10 key4hash;
    STR20 data4hash;
    int hashTemp;
	inputFile = fopen(DATAIN,"rt");
	if (!inputFile)
	{
		printf(" Input file access error ....\n");
		fflush(stdin);
		getchar();
		exit(-100); // input file read error ....
	}
	while (!(feof(inputFile)))
	{
		fscanf(inputFile,"%10c%20c\n",keyTemp,dataTemp);
		keyTemp[10]=dataTemp[20]=0; // add the string termination byte
        
        key4hash = keyTemp;
        data4hash = dataTemp;
        hashTemp = hashFunction(key4hash);
        
        InsertIntoHT(key4hash, data4hash, hashTemp);
    }
	fclose(inputFile);
	fflush(stdin);
}
void HashTable::InsertIntoHT(STR10 k, STR20 d, int hashIndex)
{
    if(buckets[hashIndex].hasFreeSlot())
    {
        short slotIndex = buckets[hashIndex].getCount();
        buckets[hashIndex].set(k, d, slotIndex);
        buckets[hashIndex].incrementCount();
    }
    else if(buckets[hashIndex].hasOverflow())
    {
        hashIndex = buckets[hashIndex].getOverflow();
        InsertIntoHT(k, d, hashIndex);
    }
    else
    {
        int Over = nextAvailBucket();
        buckets[hashIndex].setOverflow(Over);
        InsertIntoHT(k, d, buckets[hashIndex].getOverflow());
    }
}
void HashTable::WriteHTtoDisk(ofstream *out)
{
    out->write((char *) this, sizeof(HashTable));
    if (out->fail())
        cout << "write failed" << endl;
}
void HashTable::RestoreHTtoMem(ifstream *in)
{
    in->read((char *) this, sizeof(HashTable));
    if (in->fail())
        cout << "read failed" << endl;
}

void HashTable::ReportHT(char reportFileName[], char title[])
{
    Bucket bucketprint;
    ofstream printfile (reportFileName);
    STR20 dataTemp;
    int i=1;
    int j=1;
    
    if (printfile.is_open())
    {
        printfile << setw(38) << "Hash Table" << endl;
        printfile << setw(42) << "Verification Report" << endl;
        printfile << setw(30) << title << " Restoration" << endl <<endl;
        
        iterate_Start();
        while(iterate_HasNext())
        {
            bucketprint = iterate_GetNext();
            if(buckets[i-1].getCount()>0)
            {
                printfile << endl << "Bucket " << i << endl;
                printfile << setw(12) << "Slot " << j << ": ";
                printfile << buckets[i-1].getKey(j-1) << "      ";
                dataTemp = buckets[i-1].getData(j-1);
                for (int k=0; k<20; k++)
                {
                    printfile << dataTemp[k];
                }
                printfile << endl;
                
                if(buckets[i-1].getCount()>1)
                {
                    j++;
                    printfile << setw(12) << "Slot " << j << ": ";

                    printfile << buckets[i-1].getKey(j-1) << "      ";
                    dataTemp = buckets[i-1].getData(j-1);
                    for (int k=0; k<20; k++)
                    {
                        printfile << dataTemp[k];
                    }
                    printfile << endl;
                }
                if(buckets[i-1].getCount()>2)
                {
                    j++;
                    printfile << setw(12) << "Slot " << j << ": ";
                    printfile << buckets[i-1].getKey(j-1) << "      ";
                    dataTemp = buckets[i-1].getData(j-1);
                    for (int k=0; k<20; k++)
                    {
                        printfile << dataTemp[k];
                    }
                    
                    printfile << endl;
                }
                if(buckets[i-1].hasOverflow())
                    printfile << setw(24) << "OverflowPointer: " << buckets[i-1].getOverflow() << endl;

            }
            i++;
            j=1;
        }
    }

}
void HashTable::SearchReportHT(char searchFileName[])
{
    char keyTemp[10+1];
    int hashIndex;
    
    FILE * searchFile = fopen(searchFileName, "rt");
    ofstream searchprint ("/users/jonathankorn/desktop/searchreport.txt");
    
    if (searchprint.is_open())
    {
        searchprint << setw(38) << "Search and Retrieval" << endl;
        searchprint << setw(34) << "Transactions" << endl << endl;
        
        searchprint << "SearchKey         " << "Bucket/Slot              " << "Record";
        searchprint << endl << endl;
    }
    
    if(!searchFile)
    {
        printf(" Input file access error ....\n");
		fflush(stdin);
		getchar();
		exit(-100); // input file read error ....
    }
    while (!(feof(searchFile)))
    {
        fscanf(searchFile,"%10c\n", keyTemp);
        keyTemp[10]=0;
        hashIndex = hashFunction(keyTemp);
        
        if (searchprint.is_open())
        {
            SearchNewWay(keyTemp,hashIndex,&searchprint);
        }

    }
    
    searchprint.close();

}

void HashTable::SearchNewWay(char searchKey[],int hashIndex, ofstream *searchreport)
{
    int matchBucket;
    int matchSlot;
    STR10 keyTemp;
    
    if (hasMatch(searchKey,hashIndex))
    {
        matchBucket = hashIndex;
        matchSlot = findSlot(searchKey, matchBucket);
        *searchreport << buckets[hashIndex].getKey(matchSlot-1) << "            ";
        *searchreport << (matchBucket+1) << "/" << matchSlot << "            ";
        *searchreport << buckets[hashIndex].getData(matchSlot-1) << endl;
    }
    else if (buckets[hashIndex].hasOverflow())
    {
        hashIndex = buckets[hashIndex].getOverflow();
        SearchNewWay(searchKey, hashIndex, searchreport);
    }
    else
    {
        keyTemp = searchKey;
        *searchreport << keyTemp << "                             ";
        *searchreport << "Record Not Found" << endl;
    }
}
void HashTable::GenerateStatReportExtnd(char reportFileName[])
{
    ofstream printfile (reportFileName);
    int total=0;
    int bwithc=0;
    int CollisionCount;
    
    if (printfile.is_open())
    {
        printfile << setw(38) << "Hash Table" << endl;
        printfile << setw(42) << "Statistics Report" << endl << endl;

        for (int i=0; i<(MAXBUCKETS-10); i++)
        {
            printfile << endl << "Bucket " << (i+1) << ": ";
            if (buckets[i].getCount()>1)
            {
                CollisionCount = GenerateCollisionCount(i)-1;
                if (CollisionCount>0) {
                    bwithc++;
                    total += CollisionCount;
                }
                printfile << CollisionCount << " collisions" << endl;
            }
            else
                printfile << "0 collisions" << endl;
        }
        
        printfile << "      Total: " << total << " collisions" << endl;
        printfile << "    Average: " << ((float)total/((float)bwithc));
        printfile << " collisions" << endl;
        
    }

}
int HashTable::GenerateCollisionCount(int index)
{
    if (buckets[index].hasOverflow())
    {
        return buckets[index].getCount() + GenerateCollisionCount(buckets[index].getOverflow());
    }
    else
        return buckets[index].getCount();
}

bool HashTable::hasFreeSlot(short bucketIndex)
{
    if (buckets[bucketIndex].getCount() > 2)
        return false;
    else
        return true;
}
bool HashTable::hasOverflow(short bucketIndex)
{
    if (buckets[bucketIndex].getOverflow() > 0)
        return true;
    else
        return false;
}
bool HashTable::hasMatch(char key[], int location)
{
    if (buckets[location].getCount() > 0)
    {
        if (buckets[location].getKey(0)==key)
            return true;
        else if(buckets[location].getKey(1)==key)
            return true;
        else if (buckets[location].getKey(2)==key)
            return true;
        else return false;
    }
    else
        return false;
}
int HashTable::findSlot(char key[], int location)
{
    if (buckets[location].getCount() > 0)
    {
        if (buckets[location].getKey(0)==key)
            return 1;
        else if(buckets[location].getKey(1)==key)
            return 2;
        else if (buckets[location].getKey(2)==key)
            return 3;
        else return -1;
    }
    else return -1;
}
int HashTable::nextAvailBucket()
{
    return nextFreeBucket++;
}
void HashTable::iterate_Start()
{
    index = 0;
}
bool HashTable::iterate_HasNext()
{
    return (index<MAXBUCKETS);
}
Bucket HashTable::iterate_GetNext()
{
    return buckets[index++];
}