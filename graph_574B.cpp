#include<iostream>
#include<vector>
#include <algorithm> 
#include<unordered_map>
#include <string>
#include <stack>
#include <queue>
#include <limits>



using namespace std;

void addEdge(vector <vector <int> > &ad, int s, int t){
    ad[s].push_back(t);
    ad[t].push_back(s);
}
int main(){
    int n,m,j,x,i;// 0 to n-1 vertice numbers
    cin>>n>>m;
    vector <vector <int> > adj(n+1);
    vector<pair<int,int> > edg;
    vector <vector <int> > mat(n+1,vector<int>(n+1,0));
    for(x=0;x<m;x++){
        cin>>i>>j;
        mat[i][j] = 1;
        mat[j][i] = 1;
        edg.push_back(make_pair(i,j));
        addEdge(adj,i,j);
    }
    pair<int,int> t;
    int min = 20000;
    int s,d,f;
    for(i=0;i<m;i++){
        t = edg[i];
        s = t.first;
        d = t.second;
        for(j=1;j<=n;j++){
            if((mat[s][j]==1) && (mat[d][j]==1)){
                f = adj[s].size()+adj[d].size()+adj[j].size();
                if(f<min){
                    min = f;
                }
            }
        }
    }
    if(min==20000){
        cout<<-1;
    }
    else{
        cout<<min-6;
    }
    // cout<<"----------------"<<endl;
    return 0;
}