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

void addEdge(vector <vector <pair<int,int> > > &ad,vector<vector<int>> &edgeList, int s, int t,int weight){
    ad[s].push_back(make_pair(t,weight));
    ad[t].push_back(make_pair(s,weight));
    vector<int> n;
    n.push_back(weight);
    n.push_back(s);
    n.push_back(t);
    edgeList.push_back(n);
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
    cout << "path from 5 to 0 is ";
    printDijkstraPath(before,5,0);

        
}

struct union_find{
    struct union_find *par;
    int num;
    int rank;
};

struct union_find *uf_findset(struct union_find *a){
    struct union_find *b = a;
    int t = 0;
    while(a->par != NULL){
        a = a->par;
        t = 1;
    }
    if(t==1){
        b->par = a;
    }
    return a;
}
void uf_union(struct union_find *a, struct union_find *b){
    struct union_find *ap = uf_findset(a);
    struct union_find *bp = uf_findset(b); 
    if(ap->num==bp->num){
        return;
    }
    if (ap->rank > bp->rank){
        bp->par = ap;
    }
    else if (ap->rank < bp->rank){
        ap->par = bp;
    }
    else{
        ap->rank += 1;
        bp->par = ap;
    }
}


void kruskals(vector <vector <pair<int,int> > > &adj,vector<vector<int>> &edgeList, int s){
    vector <vector <pair<int,int> > > newg(adj.size());
    vector<vector<int>> newEdgeList;
    vector<struct union_find *> ulis;
    auto comp = [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
        };
    sort(edgeList.begin(),edgeList.end(),comp);
    int i,j;
    struct union_find *temp;
    for (i=0;i<adj.size();i++){
        temp = new union_find;
        *temp = {NULL,i,0};
        ulis.push_back(temp);
    }
    vector <int> temp_edge;
    for(i=0;i<edgeList.size();i++){
        temp_edge = edgeList[i];
        if(uf_findset(ulis[temp_edge[1]])->num !=  uf_findset(ulis[temp_edge[2]])->num){
            addEdge(newg,newEdgeList,temp_edge[1],temp_edge[2],temp_edge[0]);
            uf_union(ulis[temp_edge[1]],ulis[temp_edge[2]]);
        }
    }
    cout<<"Kruskal MST "<<endl;
    printAdjList(newg);
}

int main(){
    int n=6,x,i;// 0 to n-1 vertice numbers
    // vector<struct union_find *> ulis;
    // struct union_find* temp;
    // for (i=0;i<5;i++){
    //     temp = new union_find;
    //     *temp = {NULL,i,0};
    //     ulis.push_back(temp);
    // }
    // cout<<ulis[2]->num;
    // cout<<ulis[4]->num;
    
    // struct union_find a1 = {NULL,4,0};
    // struct union_find *fd1 = new struct union_find (NULL,4,0);
    // struct union_find a2 = {NULL,7,0};
    // struct union_find a3 = {NULL,88,0};
    // struct union_find a4 = {NULL,1,0};
    // struct union_find a5 = {NULL,9,0};
    // cout << "a3 - "<< uf_findset(&a3)->num << "a4 - "<< uf_findset(&a4)->num<<"a5 - "<<uf_findset(&a5)->num<<endl;
    // uf_union(&a3,&a4);
    // uf_union(&a3,&a5);
    // cout << "a3 - "<< uf_findset(&a3)->num << "a4 - "<< uf_findset(&a4)->num<<"a5 - "<<uf_findset(&a5)->num<<endl;
    
    // cout << a4.num<<endl;
    // cout << a4.num<<endl;
    // cout << a4.num<<endl;
    vector <vector <pair<int,int> > > adj(n);
    vector <vector<int>> edgeList;
    // // first el of pair is vertice next is weight
    addEdge(adj,edgeList,0,1,1);
    addEdge(adj,edgeList,1,2,6);
    addEdge(adj,edgeList,2,5,2);
    addEdge(adj,edgeList,4,5,4);
    addEdge(adj,edgeList,3,4,1);
    addEdge(adj,edgeList,0,3,3);
    addEdge(adj,edgeList,1,3,5);
    addEdge(adj,edgeList,2,4,5);
    addEdge(adj,edgeList,1,4,1);
    // addEdge(adj,edgeList,2,5,4);
    // addEdge(adj,edgeList,5,6,2);
    // addEdge(adj,edgeList,3,5,14);
    // addEdge(adj,edgeList,3,4,9);
    // addEdge(adj,edgeList,4,5,10);
    printAdjList(adj);
    cout<<"----------------"<<endl;
    // kruskals(adj,edgeList,1);
    // bfs_from_source(adj,2);
    // dfs(adj);
    // dijkstra_nlogn(adj,0);

    return 0;
}