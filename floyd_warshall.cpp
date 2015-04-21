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
    _NUM_NODES = num_nodes;
    _NUM_EDGES = num_edges;
    //The +1 is because we label our nodes from 1 to ... versus 0 to .... We could also just make a matrix of say a very large size like 50 x 50. 
    int width = _NUM_NODES + 1;
    int height = _NUM_NODES + 1;
    
    /*http://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
     Create 2D matrices*/
    adj_matrix = new int*[width];
    for (int a = 0; a < width; a++)
    {
        adj_matrix[a] = new int[height];
    }
    path_matrix = new int*[width];
    for (int a = 0; a < width; a++)
    {
        path_matrix[a] = new int[height];
    }
}

void FWar::addEdgeCost(int from_node, int to_node, int cost)
{
    adj_matrix[from_node][to_node] = cost;
    //Updates original last node in path value in original addition of edge to graph
    path_matrix[from_node][to_node] = from_node;
}

void FWar::updateShortestPaths()
{
    //Search through each of our nodes. Each of these nodes will be interposed between any other two nodes
    for (int k = 1; k <= _NUM_NODES; k++)
    {
        //Search through all of our nodes to set i
        for (int i = 1; i <= _NUM_NODES; i++)
        {
            //Search through all our nodes to set j
            for (int j = 1; j <= _NUM_NODES; j++)
            {
                //CHECK: make sure there IS a path between k, i and j
                if ( (adj_matrix[i][k] * adj_matrix[k][j] != 0) )
                {
                    //This is checking to see to if we interpose k in between i and j, do we get a shortest path
                    //Eg, if i to j is 20, but i to k is 5 and k to j is 10, then 10+5<20, so that is our new shortest path
                    //Also saying that if the original shortest path from i to j was 0 then we can 'create' a path by updating that value. Eg, say we werent originally given a length from a to c, but we know a to b and b to c (and all is conntected) we can update this distance.
                    if ( (adj_matrix[i][k] + adj_matrix[k][j]) < adj_matrix[i][j] || (adj_matrix[i][j] == 0))
                    {
                        //Update our new shortest path distance
                        adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];
                        //Update our last node on path
                        path_matrix[i][j] = path_matrix[k][j];
                    }
                }
            }
        }
    }
}

bool FWar::isPath(int from_node, int to_node)
{
    //Make sure we have the shortest paths updated
    updateShortestPaths();
    //Make sure there is a distance value or that the from and to nodes are the same (self loops)
    int length_of_zero = 0;
    if (adj_matrix[from_node][to_node] != length_of_zero || (from_node == to_node))
    {
        return true;
    }
    return false;
}

void FWar::findShortestPath(int from_node, int to_node)
{
    if (isPath(from_node, to_node))
    {
        //If there is a path, then call call recursive function that builds up vector containing path we want to print
        pathR(from_node, to_node);
        //Pushing in order from start node to end node of path
        print_matrix.push_back(to_node);
    }
    //This is for the case of self-loops, eg, if from and to_nodes both equal 1, we should have a path 1-1. We already pushed it on once to our vector
    if (from_node == to_node)
    {
        print_matrix.push_back(to_node);
    }
}

void FWar::pathR(int from_node, int to_node)
{
    //Stop case meaning we we have gotten to our start node
    if (from_node == to_node)
    {
        return;
    }
    else
    {
        /*Order matters in next two lines, pathR and print_matrix*/
        //pathR calls on the last node element on the path
        pathR(from_node, path_matrix[from_node][to_node]);
        print_matrix.push_back(path_matrix[from_node][to_node]);
    }
}

void FWar::printShortestPath(int from_node, int to_node)
{
    findShortestPath(from_node, to_node);
    //PRINTING
    for (int a = 0; a < print_matrix.size(); a++)
    {
        cout<<print_matrix.at(a);
        //Used for formatting the "-" symbols properly
        if( a < print_matrix.size() - 1 )
        {
            cout<<"-";
        }
    }
    cout<<endl;
    //Clear the path list from the vector so we can just use push_back and at() easily
    print_matrix.clear();
}

int FWar::Cost(int from_node, int to_node)
{
    return adj_matrix[from_node][to_node];
}

void FWar::printCost(int from_node, int to_node)
{
    //Make sure everything updated
    updateShortestPaths();
    cout<<"cost="<<Cost(from_node, to_node)<<endl;
}

void FWar::printAdjList()
{
    cout<<"--------AdjListBeg----------"<<endl;
    for (int i = 0; i <= _NUM_NODES; i++)
    {
        //Search through all of our nodes to set i
        for (int j = 0; j <= _NUM_NODES; j++)
        {
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"--------AdjListEnd----------"<<endl;
}

void FWar::printPathList()
{
    cout<<"--------PathListBeg----------"<<endl;
    for (int i = 0; i <= _NUM_NODES; i++)
    {
        //Search through all of our nodes to set i
        for (int j = 0; j <= _NUM_NODES; j++)
        {
            cout<<path_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"--------PathListEnd----------"<<endl;
}
