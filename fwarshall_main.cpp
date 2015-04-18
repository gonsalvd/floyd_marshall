//
//  fwarshall_main.cpp
//  Exercise3
//
//  Created by Gonsalves on 4/18/15.
//
//


#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>

#include "floyd_warshall.h"
using namespace std;

int main(int argc, char **argv)
{
    string input;
    int number;
    string name;
    
    //Read in first line as the size of table
    std::getline(std::cin,input);
    int table_size = atoi(input.c_str());
     manager = Hash(table_size);
    
    
    while (getline(cin, input))
    {
        stringstream ss(input);
        ss>>number;
        if (number == 0)
        {
            break;
        }
        //This commands inserting
        else if (number == 1)
        {
            ss>>name;
            manager.insert(name);
        }
        //This commands search
        else if (number == 2)
        {
            ss>>name;
            cout<<manager.search(name)<<endl;
        }
        //This is for taking in the intial size of the array
        else if (number > 2)
        {
            table_size = number;
        }
        
    }
    return 0;
    
}




