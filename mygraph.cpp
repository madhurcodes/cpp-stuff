#include<iostream>
#include<vector>
#include <algorithm> 
#include<unordered_map>
#include <string>
#include <stack>
#include <queue>
#include <limits>



using namespace std;

void dfs_rec(vector <vector <int> > &ad , vector<int> &visited, int s, string prefix,
                      vector<int> &start_time,vector<int> &end_time,int* time){
    int i;
    visited[s] = -1; // -1 means I'm in the process of visiting it's children.
    string dash = "--";
    start_time[s] = *time;
    // cout<<endl<<dash<<"--debug"<<endl;
    cout<<prefix<<s<< " "<<endl;
    (*time)++;
    for(i=0;i<ad[s].size();i++){
        if(visited[ad[s][i]]==0){
            dfs_rec(ad,visited,ad[s][i],prefix+dash,start_time,end_time,time);
        }
    }
    end_time[s] = *time;
    visited[s] = 1;
}
void dfs(vector <vector <int> > &ad){
    vector<int> start_time(ad.size()), end_time(ad.size());
    int time = 0;
    int i,n = ad.size();
    cout << "DFS  "<<endl;
    vector<int> visited(n,0);
    // This is dfs from all vertices separately so every vertice
    // guaranteed to be visited.
    for(i=0;i<ad.size();i++){
        if(visited[i]==0){
            dfs_rec(ad,visited,i,"",start_time,end_time,&time);
        }
    }

} 
void dfs_from_source(vector <vector <int> > &ad, int s){
    vector<int> start_time(ad.size()), end_time(ad.size());
    int time = 0;
    int i,n = ad.size();
    cout << "DFS  from "s<<endl;
    vector<int> visited(n,0);
    dfs_rec(ad,visited,s,"",start_time,end_time,&time); 
    // The above line can do dfs from only one node
    // so if another unconnected component is there it won't visit it.

    // cout<<"------------"<<endl;    
    // for(i=0;i<ad.size();i++){
    //     cout<< i<<" " << start_time[i]<<" to "<<end_time[i]<< endl;
    // }
}

void bfs_from_source(vector <vector <int> > &adj, int s){
    int i;
    queue <int> vertices;
    vertices.push(s); 
    vector <int> distance(adj.size(),numeric_limits<int>::max());
    int curr;
    cout << "BFS from "<<s<<endl;
    distance[s] = 0;
    while(vertices.size()!=0){
        curr = vertices.front();
        vertices.pop();
        cout<< curr << " ";
        for(i=0;i<adj[curr].size();i++){
            if(distance[adj[curr][i]]==numeric_limits<int>::max()){
                vertices.push(adj[curr][i]);
                distance[adj[curr][i]] = distance[curr] + 1;
            }
        }
    }
    cout<<"Distances are - "<<endl;
    for(i=0;i<adj.size();i++){
        cout<<i <<" - " <<distance[i]<<endl;
    }
}

void addEdge(vector <vector <int> > &ad, int s, int t){
    ad[s].push_back(t);
    ad[t].push_back(s);
}


void printAdjList(vector <vector <int> > &ad){
    int ii,b,c=0;
    for(ii=0;ii<ad.size();ii++){
        c=0;
        for(b=0;b<ad[ii].size();b++){
            if(c==0){
                cout<<ii<<" - ";
            }
            c=1;
            cout<< ad[ii][b]<<" ";
        }
        if(c==1){
            cout<<endl;
        } 
    }
}



int main(){
    int n=7,x,i;// 0 to n-1 vertice numbers
    vector <vector <int> > adj(n);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,3);
    addEdge(adj,4,3);
    addEdge(adj,0,1);
    addEdge(adj,6,5);
    addEdge(adj,4,5);
    printAdjList(adj);
    cout<<"----------------"<<endl;
    bfs_from_source(adj,2);
    dfs(adj)
    return 0;
}