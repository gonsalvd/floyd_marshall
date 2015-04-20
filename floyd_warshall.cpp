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
    //http://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
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
    path_matrix[from_node][to_node] = from_node;
    cout<<"Added Edge from: "<<from_node<<" to: "<<to_node<<" with cost: "<<cost<<endl;
    printAdjList();
    printPathList();
    //cout<<"added cost:"<<adj_matrix[from_node][to_node]<<endl;

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

void FWar::updateShortestPaths()
{
    cout<<"---Called UpdateShortestPaths---"<<endl;
    printAdjList();
    printPathList();
    //Search through each of our nodes. Each of these nodes will be interposed between any other two nodes
    for (int k = 1; k <= _NUM_NODES; k++)
    {
        //Search through all of our nodes to set i
        for (int i = 1; i <= _NUM_NODES; i++)
        {
            //Search through all our nodes to set j
            for (int j = 1; j <= _NUM_NODES; j++)
            {
                //TWO CHECKS: first, make sure there IS a path between k, i and j, then check to make sure i and j are diff nodes due to the inaccuracy of our loops above in catching this
                //cout<<"here1"<<endl;

                if ( (adj_matrix[i][k] * adj_matrix[k][j] != 0) )
                {
                    //This is checking to see to if we interpose k in between i and j, do we get a shortest path
                    //Eg, if i to j is 20, but i to k is 5 and k to j is 10, then 10+5<20, so that is our new shortest path
                    //Also saying that if the original shortest path from i to j was 0 then we can 'create' a path by updating that value. Eg, say we werent originally given a length from a to c, but we know a to b and b to c (and all is conntected) we can update this distance. This is for undirected graphs: if ( ((adj_matrix[i][k] + adj_matrix[k][j]) < adj_matrix[i][j]) || (adj_matrix[i][j] == 0))
                    
                    if ( (adj_matrix[i][k] + adj_matrix[k][j]) < adj_matrix[i][j] || (adj_matrix[i][j] == 0))
                    {
                        //Update our new shortest path distance
                        //cout<<"here2"<<endl;
                        adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];
                        path_matrix[i][j] = k;
                        //cout<<"updated value for i: "<<i<<" j: "<<j<<" k: "<<k<<" is: "<<adj_matrix[i][j]<<endl;
                    }
                }
            }
        }
    }
}

bool FWar::isPath(int from_node, int to_node)
{
    updateShortestPaths();
    int length_of_zero = 0;
    //cout<<"adj value:"<<adj_matrix[from_node][to_node]<<endl;
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
        
    }
}

void FWar::printShortestPath(int from_node, int to_node)
{
    
}

int FWar::Cost(int from_node, int to_node)
{
    return adj_matrix[from_node][to_node];
}

void FWar::printCost(int from_node, int to_node)
{
    updateShortestPaths();
    int cost = Cost(from_node, to_node);
    cout<<"cost = "<<cost<<endl;
}







//void findShort
