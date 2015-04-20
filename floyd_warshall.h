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

class FWar
{
    
public:
    FWar(int num_nodes, int num_edges);
    bool isPath(int from_node, int to_node);
    void printShortestPath(int from_node, int to_node);
    void addEdgeCost(int from_node, int to_node, int cost);
    void printCost(int from_node, int to_node);
    void updateShortestPaths();


    
private:
    
    int _NUM_NODES;
    int _NUM_EDGES;
    int **adj_matrix;
    int **path_matrix;
    
    void findShortestPath(int from_node, int to_node);
    int Cost(int from_node, int to_node);
    void printAdjList();
    void printPathList();
    
    
};

#endif /* defined(__Exercise4__floyd_warshall__) */
