#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include "HashTable.h"

using namespace std;


void displayMenu();
int main(int argc, const char *argv[])
{
    HashTable* mTable= new HashTable(10);
    
    string command;
    displayMenu();
    getline(cin, command);
    while (command != "5") {
        if (command == "1") {
            string title;
            string yearString;
            cout<< "Enter title:"<<endl;
            getline(cin, title);
            cout<< "Enter year:"<<endl;
            getline(cin, yearString);
            int year = stoi(yearString);
            mTable->insertMovie(title, year);
        }
        else if (command == "2")
        {
            string title;
            cout<<"Enter title:"<<endl;
            getline(cin,title);
            
        }
        else if (command == "3")
        {
            string title;
            cout<<"Enter title:"<<endl;
            getline(cin, title);
        }
        else if (command == "4")
        {
            cout<<"Print table contents"<<endl;
        }
        else
            cout<<"not found"<<endl;
        displayMenu();
        getline(cin, command);
    }
    cout<<"Goodbye!"<<endl;
    return 0;
}


void displayMenu()
{
    cout << "======Main Menu=====" << endl;
    cout << "1. Insert movie" << endl;
    cout << "2. Delete movie" << endl;
    cout << "3. Find movie" << endl;
    cout << "4. Print table contents" << endl;
    cout << "5. Quit" << endl;
    return;
}
