#include<iostream>
#include<vector>
#include <algorithm> 
#include<unordered_map>
#include <set>
using namespace std;

void printDijkstraPath(vector<int> &par,int dest, int s){
    if(par[dest]==-1){
        cout<<-1;
        return;
    }
    int i;
    vector<int> temp;
    while(dest!=s){
        temp.push_back(dest+1);
        // cout<<dest+1<<" ";
        dest = par[dest];
    }
    temp.push_back(s+1);
    for(i=temp.size()-1;i>=0;i--){
        cout<<temp[i];
        if(i!=0){
            cout<<" ";
        }
    }
    // cout << s+1<<endl;
}

void addEdge(vector <vector <pair<int,int> > > &ad, int s, int t,int weight){
    // int i,exists=0,less = 0,w;
    // for(i=0;i<ad[s].size();i++){
    //     if(ad[s][i].first==t){
    //         exists=1;
    //         if(ad[s][i].second>weight){
    //             less = 1;
    //             w = ad[s][i].second;
    //         }
    //         break;
    //     }
    // }
    // if(exists==0){
        // cout<<"-----------";
        ad[s].push_back(make_pair(t,weight));
        ad[t].push_back(make_pair(s,weight));
    // }
    // else if (less==1){
    //     ad[s].erase(remove(ad[s].begin(),ad[s].end(),make_pair(t,w)), ad[s].end());        
    //     ad[t].erase(remove(ad[t].begin(),ad[t].end(),make_pair(s,w)), ad[t].end());        
    //     ad[s].push_back(make_pair(t,weight));
    //     ad[t].push_back(make_pair(s,weight));        
    // }
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
    // cout << "Dijkstra from "<<s<<endl;
    while(vertices.size()!=0){
        curr = *vertices.begin();
        vertices.erase(curr);

        // cout<< curr.second << " ";
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
    // cout<<"Distances are - "<<endl;
    // for(i=0;i<adj.size();i++){
    //     cout<<i <<" - " <<distance[i]<<endl;
    // }
    // cout<<"Parents are - "<<endl;
    // for(i=0;i<adj.size();i++){
    //     cout<<i <<" - " <<before[i]<<endl;
    // }
    // cout << "path from n-1 to 0 is ";
    printDijkstraPath(before,adj.size()-1,0);
}

int main(){
    int n,m;
    cin >> n>>m;
    int t,i,a,b,c;
    vector <vector <pair<int,int> > > adj(n);
    for(i=0; i<m;i++){        
        cin>>a>>b>>c;
        addEdge(adj,a-1,b-1,c);
    }
    dijkstra_nlogn(adj,0);
    return 0;
}