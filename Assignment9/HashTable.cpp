#include "HashTable.h"
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <stdio.h>
using namespace std;

HashTable::HashTable(int x)
{
    for(int i = 0;i< x; i++){
        movieTable.push_back(NULL);
    }
}

void HashTable::insertMovie(string in_title, int year)
{
    int position = hashSum(in_title, tableSize);
     if (movieTable[position] == NULL) {
         Movie* moviePosition=new Movie(in_title, year);
         movieTable[position] = moviePosition;
    }else{
        Movie* temp3;
        Movie* temp = movieTable[position];
        Movie* temp2 = new Movie(in_title, year);
        while (temp->next != NULL){
            temp3 = temp;
            temp = temp->next;
            if((temp->title).compare(temp2->title) < 0)
               {
                   temp->next = temp2;
                   temp3->next = temp;
                   
               }else{
                temp2->next = temp;
                temp3->next = temp2;
               }
        }
    }

}

int HashTable::hashSum(string in_title, int s)
{
    int sum = 0;
    for(int i=1; i < in_title.length(); i++)
    {
        sum = sum + in_title[i];
    }
    sum = sum % s;
    return sum;
}
/*
int HashTable::hash(string in_title);
{
    int hashValue = 0;
    for(int i = 0; i<in_title.length(); i++)
    {
        hashValue = hashValue + int(in_title([i]));
    }
}
*/
void HashTable::deleteMovie(string in_title)
{
    //int index = HashTable(in_title);
}