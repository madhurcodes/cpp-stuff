#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define MAX 1000000

int numberVertex, numberEdges;
int particion[MAX], visited[MAX];
vector< int > adjacencyMatrix[MAX];

bool bfs(int begin)
{
    int i, origin, destination;
    queue< int > queueVertex;
    queueVertex.push(begin);
    particion[begin] = 1; // 1 left,
    visited[begin] = 1; // set adjacencyMatrixray

    while(!queueVertex.empty())
    {
        origin = queueVertex.front(); queueVertex.pop();
        for(i=0; i < adjacencyMatrix[origin].size(); i++)
        {
            destination = adjacencyMatrix[origin][i];
            if(particion[origin] == particion[destination])
            {
                return false;
            }
            if(visited[destination] == 0)
            {
                visited[destination] = 1;
                particion[destination] = 3 - particion[origin]; // alter 1 and 2 subsets
                queueVertex.push(destination);
            }
        }
    }
    return true;
}

bool is_bipartite()
{
    for(int i=1; i< numberVertex+1; i++)
    {
       if (visited[i] == 0 && !bfs(i)) {
           return false;
       }
    } 
    return true;
}

int main()
{
    int n;
    cin >> n;

    //freopen("tarea2.in", "r", stdin);
    int i,j, nodeOrigin, nodeDestination;
    numberVertex = n;
    for(i=0; i<n-1; i++)
    {
        cin >> nodeOrigin >> nodeDestination;
        adjacencyMatrix[nodeOrigin].push_back(nodeDestination);
        adjacencyMatrix[nodeDestination].push_back(nodeOrigin);
    }
    int k =0;
    if(is_bipartite()) {

        // printf("Is bipartite\n");
          for (j=1; j<numberVertex+1; j++){
              if(particion[j]==1){
                  k++;
              }
            //   k+=particion[j];
              
            //    cout<<j<<" "<<particion[j]<<endl;
        }

    }
    long long int r = k;
    r = (r*(n-r)-(n-1));
        cout << r;

    return 0;
}



// // A simple representation of graph using STL,
// // for the purpose of competitive programming
// #include<bits/stdc++.h>
// using namespace std;
 
// // A utility function to add an edge in an
// // undirected graph.
// void addEdge(vector<int> adj[], int u, int v)
// {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }
 
// // A utility function to do DFS of graph
// // recursively from a given vertex u.
// void DFSUtil(int u, vector<int> adj[],
//                     vector<bool> &visited,int *kk,int camefrom)
// {
//     visited[u] = true;
//     int c = camefrom == 0? 1:0;
//     if(c==0){
//         *kk=*kk+1;
//     }
//     //cout << u << " ";
//     for (int i=0; i<adj[u].size(); i++)
//         if (visited[adj[u][i]] == false)
//             DFSUtil(adj[u][i], adj, visited,kk,c);
// }
 
// // This function does DFSUtil() for all 
// // unvisited vertices.
// int DFS(vector<int> adj[], int V)
// {
//     vector<bool> visited(V, false);
//     vector<int> comp(V, 0);

//     int kk = 0;
//     int *nn = &kk;
//     for (int u=1; u<V; u++)
//         if (visited[u] == false)
//             DFSUtil(u, adj, visited,nn,0);
//     return kk;
// }
 
// // Driver code
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> adj[n+1];
//     int i,a,b;
//     for(i=0;i<n-1;i++){
//         cin >> a >> b;
//         addEdge(adj, a, b);    
//     }
//     int r = DFS(adj, n+1);
//     cout << (r*(n-r)-(n-1));

//     return 0;
// }