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


void HashTable::deleteMovie(string in_title)
{
    int index = hashSum(in_title, tableSize);
    Movie *start = movieTable[index];  //hash numbers
    Movie *previous = NULL;

    if(start == NULL)
    {
        cout << "not found" << endl;
    }
    else
    {
        while(start != NULL)
        {
            if(start -> title == in_title)
            {
                if(previous == NULL)
                {
                    movieTable[index] = start -> next;
                    delete start;
                    return;
                }
                else
                {
                    previous -> next = start->next;
                    delete start;
                    return;
                }
            }

            previous = start;
            start = start -> next;
        }
        cout << "not found" << endl;
    }
 }

void HashTable::printInventory()
{
    Movie* temp;
    for(int i = 0; i< tableSize; i++)
    {
        if (movieTable[i] != NULL && movieTable[i]->next != NULL) {
            temp = movieTable[i];
            while (temp != NULL) {
                cout<<temp->title<<":"<<temp->year<<endl;
                temp = temp->next;
            }
        }
        else if(movieTable[i] != NULL && movieTable[i]->next == NULL)
        {
            cout<<movieTable[i]->title<<":"<<movieTable[i]->year<<endl;
        }
        
        if (movieTable[i] == NULL)
        {
            cout<<"empty"<<endl;
            break;
        }
         
    }
}

Movie* HashTable::findMovie(string in_title){
    Movie *movieTitle = NULL;
    bool flag = false;
    int index = HashTable::hashSum(in_title, tableSize);
    Movie * entry = movieTable[index];
    while(entry != NULL){
        if(entry->title == in_title){
            std::cout<<entry->title<<":"<<entry->year<<std::endl;
            return entry;
        }
        entry = entry->next;
    }
    if(!flag){
        printf("Not Found\n");
    }
    return movieTitle;
}
