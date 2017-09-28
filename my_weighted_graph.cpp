#include<iostream>
#include<vector>
#include <algorithm> 
#include <unordered_map>
#include <string>
#include <stack>
#include <queue>
#include <limits>
#include <set>



using namespace std;

void dfs_rec(vector <vector <pair<int,int> > > &ad , vector<int> &visited, int s, string prefix,
                      vector<int> &start_time,vector<int> &end_time,int* time){
    int i;
    visited[s] = -1; // -1 means I'm in the process of visiting it's children.
    string dash = "--";
    start_time[s] = *time;
    // cout<<endl<<dash<<"--debug"<<endl;
    cout<<prefix<<s<< " "<<endl;
    (*time)++;
    for(i=0;i<ad[s].size();i++){
        if(visited[ad[s][i].first]==0){
            dfs_rec(ad,visited,ad[s][i].first,prefix+dash,start_time,end_time,time);
        }
    }
    end_time[s] = *time;
    visited[s] = 1;
}
void dfs(vector <vector <pair<int,int> > > &ad){
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
void dfs_from_source(vector <vector <pair<int,int> > > &ad, int s){
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

void bfs_from_source(vector <vector <pair<int,int> > > &adj, int s){
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
            if(distance[adj[curr][i].first]==numeric_limits<int>::max()){
                vertices.push(adj[curr][i].first);
                distance[adj[curr][i].first] = distance[curr] + 1;
            }
        }
    }
    cout<<"Distances are - "<<endl;
    for(i=0;i<adj.size();i++){
        cout<<i <<" - " <<distance[i]<<endl;
    }
}

void addEdge(vector <vector <pair<int,int> > > &ad, int s, int t,int weight){
    ad[s].push_back(make_pair(t,weight));
    ad[t].push_back(make_pair(s,weight));
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
void printDijkstraPath(vector<int> &par,int dest, int s){
    while(dest!=s){
        cout<<dest<<" ";
        dest = par[dest];
    }
    cout << s<<endl;
}
void dijkstra_n2(vector <vector <pair<int,int> > > &adj,int s){
    vector <int> mark (adj.size(), 0);
    vector <int> distance(adj.size(),numeric_limits<int>::max());
    distance[s] = 0;    
    vector <int> before(adj.size(), -1);
    before[s] = s;
    cout<<"Dijkstra (Set version) "<<endl;
    int i,j,minv,min;
    while(1){
        min = numeric_limits<int>::max();
        minv = -1;
        for(i=0;i<adj.size();i++){
            if( (mark[i]==0) && (distance[i] < min) ){
                min = distance[i];
                minv = i;
            }
        }
        if(minv==-1){break;}
        mark[minv] = 1;
        for(i=0;i<adj[minv].size();i++){
            if ((distance[minv] + adj[minv][i].second)<distance[adj[minv][i].first]){
                distance[adj[minv][i].first] =  distance[minv] + adj[minv][i].second;
                before[adj[minv][i].first]  = minv;
            }
        }
    }
    cout<<"Distances are - "<<endl;
    for(i=0;i<adj.size();i++){
        cout<<i <<" - " <<distance[i]<<endl;
    }
    cout<<"Parents are - "<<endl;
    for(i=0;i<adj.size();i++){
        cout<<i <<" - " <<before[i]<<endl;
    }
    cout << "path from 8 to 0 is ";
    printDijkstraPath(before,8,0);
}

void dijkstra_nlogn(vector <vector <pair<int,int> > > &adj,int s){
    int i;
    set <pair<int,int> > vertices;
    vertices.insert(make_pair(0,s)); 
    vector <int> distance(adj.size(),numeric_limits<int>::max());
    vector <int> before(adj.size(), -1);
    before[s] = s;
    distance[s] = 0;
    pair<int,int> curr;
    cout << "Dijkstra from "<<s<<endl;
    while(vertices.size()!=0){
        curr = *vertices.begin();
        vertices.erase(curr);

        cout<< curr.second << " ";
        int c1,c2;
        for(i=0;i<adj[curr.second].size();i++){
            c1 =  distance[curr.second] + adj[curr.second][i].second;
            c2 = distance[adj[curr.second][i].first];
            if( c1 < c2){
                vertices.erase(make_pair(c2,adj[curr.second][i].first));
                vertices.insert(make_pair(c1,adj[curr.second][i].first));
                distance[adj[curr.second][i].first] = c1;
                before[adj[curr.second][i].first] = curr.second;
            }
        }
    }
    cout<<"Distances are - "<<endl;
    for(i=0;i<adj.size();i++){
        cout<<i <<" - " <<distance[i]<<endl;
    }
    cout<<"Parents are - "<<endl;
    for(i=0;i<adj.size();i++){
        cout<<i <<" - " <<before[i]<<endl;
    }
    cout << "path from 8 to 0 is ";
    printDijkstraPath(before,8,0);

        
}

int main(){
    int n=9,x,i;// 0 to n-1 vertice numbers
    vector <vector <pair<int,int> > > adj(n);
    // first el of pair is vertice next is weight
    // addEdge(adj,1,2,2);
    // addEdge(adj,1,3,3);
    // addEdge(adj,1,4,23);
    // addEdge(adj,2,3,6);
    // addEdge(adj,4,3,4);
    // addEdge(adj,0,1,2);
    // addEdge(adj,6,5,9);
    // addEdge(adj,4,5,8);
    //------------
    addEdge(adj,0,1,4);
    addEdge(adj,0,7,8);
    addEdge(adj,1,7,11);
    addEdge(adj,1,2,8);
    addEdge(adj,8,7,7);
    addEdge(adj,6,7,1);
    addEdge(adj,2,8,2);
    addEdge(adj,8,6,6);
    addEdge(adj,2,3,7);
    addEdge(adj,2,5,4);
    addEdge(adj,5,6,2);
    addEdge(adj,3,5,14);
    addEdge(adj,3,4,9);
    addEdge(adj,4,5,10);
    
    printAdjList(adj);
    cout<<"----------------"<<endl;
    // bfs_from_source(adj,2);
    // dfs(adj);
    dijkstra_nlogn(adj,0);

    return 0;
}