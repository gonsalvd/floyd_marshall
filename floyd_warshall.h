//
//  floyd_warshall.h
//  Exercise4
//
//  Created by Gonsalves on 4/18/15.
//
//

#ifndef __Exercise4__floyd_warshall__
#define __Exercise4__floyd_warshall__

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class FWar
{
    
public:
    
    FWar(int num_nodes, int num_edges);
    
    //-----EDGE--------
    //Adds the edge costs for input file
    void addEdgeCost(int from_node, int to_node, int cost);
    
    //-----QUERY-------
    //Checks if there is a path first for a query
    bool isPath(int from_node, int to_node);
    
    //Prints the shortest path if isPath() is true for a query
    void printShortestPath(int from_node, int to_node);
    
    //Prints the cost in a query if isPath() is true
    void printCost(int from_node, int to_node);
    
    
    
private:
    
    int _NUM_NODES;
    int _NUM_EDGES;
    //Matrix holding shortest distance costs betwen nodes i,j
    int **adj_matrix;
    //Matrix holding the previous node value in path
    int **path_matrix;
    //Vector holding the actual path values to be used for printing to cout
    vector<int> print_matrix;
    
    //-----EDGE--------
    //Floyd-Warshall algorithm with path reconstruction
    void updateShortestPaths();
    
    //Finds the cost from one node to the other node. Added together in public.
    int Cost(int from_node, int to_node);
    
    //-----QUERY-------
    //Finds the shortest path between two nodes and stores data into vector to be printed
    void findShortestPath(int from_node, int to_node);
    
    //Used to print the shortest path elements to cout
    void pathR(int from_node, int to_node);
    
    //-----HELPER--------
    //HELPER FUNCTION TO VISUALIZE MATRIX OF DISTANCES
    void printAdjList();
    
    //HELPER FUNCTION TO VISUALIZE MATRIX OF LAST NODES ON PATH FOR PATH RECONSUTRUCTION
    void printPathList();
    
};

#endif /* defined(__Exercise4__floyd_warshall__) */
