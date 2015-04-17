//
//  HashTable.h
//  Assignment9
//
//  Created by Nolawee Mengist on 4/16/15.
//  Copyright (c) 2015 nope. All rights reserved.
//

#ifndef __Assignment9__HashTable__
#define __Assignment9__HashTable__

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;


struct Movie{
    std::string title;
    int year;
    Movie *next;
    
    
    Movie(){};
    
    Movie(std::string in_title, int in_year)
    {
        title = in_title;
        year = in_year;
    }
    
};

class HashTable
{
public:
    HashTable(int x);
    //~HashTable();
    void insertMovie(std::string in_title, int year);
    Movie* findMovie(std::string in_title, int *index);
    void deleteMovie(std::string in_title);
    void printInventory();
    int hashSum(std::string in_title, int s);
    //int hash(std::string) in_title);
protected:
private:
    Movie **hashTable;
    std::vector<Movie*> movieTable;
    const int tableSize = 10;
    
};

#endif /* defined(__Assignment9__HashTable__) */
