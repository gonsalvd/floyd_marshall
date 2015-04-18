//
//  floyd_warshall.cpp
//  Exercise4
//
//  Created by Gonsalves on 4/18/15.
//
//

#include "floyd_warshall.h"
using namespace std;

FWar::FWar(int num_nodes, int num_edges)
{
    int width = num_nodes;
    int height = num_nodes;
    //http://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
    adj_matrix = new int*[width];
    for (int a = 0; a < width; a++)
    {
        adj_matrix[a] = new int[height];
    }
}

bool FWar::isPath(int from_node, int to_node)
{
    return false;
}

void FWar::printShortestPath()
{
    
}
void FWar::printActualPath()
{
    
}