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

/*INPUT FILE EXAMPLE
 NOTE-node 0 does not exist in this setup, n=5 is from 1..5 not 0..4
 5 7 3 - num nodes, num edges, num queries
 1 2 5 - node 1 to 2 has cost of 5
 1 3 2
 2 3 -2
 3 4 7
 2 4 3
 5 2 9
 4 5 10
 1 5 - what is cost from 1 to 5? what is the entire path prinout, eg 1-2-4-5
 5 1
 1 1*/

int counter = 0;
int num_edges;
int num_queries;

bool ableToEnterEdges();
bool ableToQuery();

int main(int argc, char **argv)
{
    string input;
    int num_nodes;
    int from_node;
    int to_node;
    int cost;

    //Read in first line as N, E, Q (N-number of nodes, E-number of edges, Q-number of queries)
    getline(cin,input);
    stringstream ss(input);
    ss>>num_nodes;
    ss>>num_edges;
    ss>>num_queries;
    //Create Floyd-Warshall graph to store distance information between nodes
    FWar *Graph = new FWar(num_nodes, num_edges);
    
    //Keep reading in from cin and inputting into Graph
    while (getline(cin, input))
    {
        //Create a stringstream that can be outputted directly to ints
        stringstream ss(input);

        //Based on file input convention set forth by TA. Entering edge weights here
        if (ableToEnterEdges())
        {
            ss>>from_node;
            ss>>to_node;
            ss>>cost;
            Graph->addEdgeCost(from_node, to_node, cost);
            
        }
        //Based on file input conventions set forth by TA, Querying to see if this path is in the graph, its cost, and printout.
        if (ableToQuery())
        {
            ss>>from_node;
            ss>>to_node;
            
            //Check to see if there is a path between nodes
            if (Graph->isPath(from_node, to_node))
            {
                Graph->printCost(from_node, to_node);
                Graph->printShortestPath(from_node, to_node);
            }
            else cout<<"NO PATH"<<endl;
        }
        
        //Counter is used to check if we are entering edges or querying
        ++counter;
        
    }
    return 0;
    
}

bool ableToEnterEdges()
{
    //This is based on file input convertion set forth by TA
    if (counter < num_edges)
    {
        return true;
    }
    return false;
}

bool ableToQuery()
{
    if (counter >= num_edges)
    {
        return true;
    }
    return false;
}




