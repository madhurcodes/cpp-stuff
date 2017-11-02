#include<iostream>
#include<vector>
#include <algorithm> 
#include <queue>

using namespace std;

void addEdge(vector <vector <int> > &ad, int s, int t){
    ad[s].push_back(t);
}

void bfs_from_source(vector <vector <int> > &adj, int s,int t){
    int i;
    queue <int> vertices;
    vertices.push(s); 
    vector <int> distance(adj.size(),numeric_limits<int>::max());
    int curr;
    // cout << "BFS from "<<s<<endl;
    distance[s] = 0;
    while(vertices.size()!=0){
        curr = vertices.front();
        vertices.pop();
        // cout<< curr << " ";
        for(i=0;i<adj[curr].size();i++){
            if(distance[adj[curr][i]]==numeric_limits<int>::max()){
                vertices.push(adj[curr][i]);
                distance[adj[curr][i]] = distance[curr] + 1;
                if(adj[curr][i]==t){
                    cout<<distance[adj[curr][i]];
                    return;
                }
            }
        }
    }
    // cout<<"Distances are - "<<endl;
    // for(i=0;i<adj.size();i++){
    //     cout<<i <<" - " <<distance[i]<<endl;
    // }
}
int main(){
    int n,i,j,k,m;
    vector <vector <int> > adj(20001);
    for(i=1;i<=10000;i++){
        addEdge(adj,i,i*2);
    }
    for(i=20000;i>=2;i--){
        addEdge(adj,i,i-1);
    }
    cin>>n>>m;
    bfs_from_source(adj,n,m);



    return 0;
} 