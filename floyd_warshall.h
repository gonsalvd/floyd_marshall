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

class FWar
{
public:
    FWar(int num_nodes, int num_edges);
    bool isPath(int from_node, int to_node);
    void printShortestPath();
    void printActualPath();
private:
    
    int num_nodes;
    int num_edges;
    
    
};

#endif /* defined(__Exercise4__floyd_warshall__) */
