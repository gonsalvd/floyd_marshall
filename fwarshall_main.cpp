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

int counter = 0;
int num_edges;
int num_queries;
FWar *Graph;

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
    Graph = new FWar(num_nodes, num_edges);

    while (getline(cin, input))
    {
        stringstream ss(input);

        if (ableToEnterEdges())
        {
            ss>>from_node;
            ss>>to_node;
            ss>>cost;
            Graph->addEdgeCost(from_node, to_node, cost);
            cout<<from_node<<to_node<<cost<<endl;
            
        }
        if (ableToQuery())
        {
            ss>>from_node;
            ss>>to_node;
            cout<<from_node<<to_node<<endl;
            
            if (Graph->isPath(from_node, to_node))
            {
                Graph->printCost(from_node, to_node);
                Graph->printShortestPath(from_node, to_node);
            }
            else cout<<"NO PATH"<<endl;
        }
        
        ++counter;
        
    }
    return 0;
    
}

bool ableToEnterEdges()
{
    if (counter < num_edges)
    {
        return true;
    }
//    else if (counter == num_edges - 1)
//    {
//        cout<<"here"<<endl;
//        Graph ->updateShortestPaths();
//    }
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




