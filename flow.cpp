// Write Edmond's Karp for Max Flow / Min Cut
#include <iostream>
#include <limits>
#include <string>
#include <queue>

using namespace std;

// s to t edge
void addEdge(vector <vector <pair<int,int> > > &ad, int s, int t,int weight){
    ad[s].push_back(make_pair(t,weight));
}


void printAdjList(vector <vector <pair<int,int> > > &ad){
    int ii,b,c=0;
    for(ii=0;ii<ad.size();ii++){
        c=0;
        for(b=0;b<ad[ii].size();b++){
            if(c==0){
                cout<<ii<<" - ";
            }
            c=1;
            cout<< ad[ii][b].first<< "(" <<ad[ii][b].second<<") ";
        }
        if(c==1){
            cout<<endl;
        } 
    }
}

vector<int> bfs_from_s_to_t(vector <vector <pair<int,int> > > &adj, int s){
    int i;
    queue <int> vertices;
    vertices.push(s); 
    vector <int> distance(adj.size(),numeric_limits<int>::max());
    int curr;
    // cout << "BFS from "<<s<<endl;
    distance[s] = 0;
    vector <int> parent (adj.size(),-1);
    parent[s] = s;
    while(vertices.size()!=0){
        curr = vertices.front();
        vertices.pop();
        // cout<< curr << " ";
        for(i=0;i<adj[curr].size();i++){
            if( distance[curr] + 1 < distance[adj[curr][i].first]){
                vertices.push(adj[curr][i].first);
                parent[adj[curr][i].first] = curr;
                distance[adj[curr][i].first] = distance[curr] + 1;
            }
        }
    }
    return parent;
}

int fordFulkerson(vector <vector <pair<int,int> > > &adj, int s, int t)
{
	int u, v, k;
    // Edmond's Karp Polynomial Time Algo
    vector<vector<pair<int,int> > > res_graph = adj;
	int max_flow = 0; // There is no flow initially
    vector<int> par;
    int path_flow = numeric_limits<int>::max();
    int flag = 0;    
	while (true)
	{
        par = bfs_from_s_to_t(res_graph,s);
        if(par[t]==-1){
            break;
        }
        
		path_flow = numeric_limits<int>::max();
		for (v=t; v!=s; v=par[v])
		{
            u = par[v];
            for(k=0;k<res_graph[u].size();k++){
                if(res_graph[u][k].first == v){
                    break;
                }
            }
			path_flow = min(path_flow,res_graph[u][k].second );
		}

		// update residual capacities of the edges and reverse edges
		// along the path
		for (v=t; v != s; v=par[v])
		{
            u = par[v];
            for(k=0;k<res_graph[u].size();k++){
                if(res_graph[u][k].first == v){
                    if(res_graph[u][k].second == path_flow){
                        res_graph[u].erase(res_graph[u].begin()+k);
                    }
                    else{
                        res_graph[u][k].second -= path_flow;
                    }
                }
            }
            flag = 0;
            for(k=0;k<res_graph[v].size();k++){
                if(res_graph[v][k].first == u){
                    flag = 1;
                    res_graph[v][k].second += path_flow;
                }
            }
            if(flag==0){
                addEdge(res_graph,v,u,path_flow);
            }
		}

		// Add path flow to overall flow
		max_flow += path_flow;
    }
    cout << "Part of Min cut with S is ";
    for (u=0;u<par.size();u++){
        if(par[u]!=-1){
            cout<<u<<" ";
        }
    }
    cout<<endl;
	// Return the overall flow
	return max_flow;
}

// Driver program to test above functions
int main()
{
    int n=6,i,x;
    vector <vector <pair<int,int> > > adj(n);
    addEdge(adj,0,1,33);
    addEdge(adj,0,2,12);
    addEdge(adj,2,1,1);
    addEdge(adj,1,3,12);
    addEdge(adj,2,4,11);
    addEdge(adj,4,3,7);    
    addEdge(adj,3,5,19);
    addEdge(adj,4,5,4);
    printAdjList(adj);
    cout<< "-------------------"<<endl;
    int s=0,t=5;
    int fl  = fordFulkerson(adj, s, t);
	cout << "The maximum possible flow from "<<s<<" to "<<t<< " is " << fl<<endl;

	return 0;
}
