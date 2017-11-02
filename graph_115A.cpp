#include<iostream>
#include<vector>
#include <algorithm> 
#include <stack>

using namespace std;
int dfs(vector<vector<int>  > &myg,vector<int> &distances, int st){
    stack<int> dd;
    int i,k;
    dd.push(st);
    while(!dd.empty()){
        k = dd.top();
        dd.pop();
        for(i=0;i<myg[k].size();i++){
            if(distances[myg[k][i]]==-1){
                dd.push(myg[k][i]);
                distances[myg[k][i]] = distances[k] + 1;
            }
        }
    }
}

int main(){
    int i,n,b,c;
    cin>>n;
    vector<vector<int>  > myg(n);    
    vector<bool> is_s(n,false);
    for(i=0;i<n;i++){
        cin>>b;
        if(b==-1){
            is_s[i] = true;
            continue;
        }
        b = b-1;
        myg[b].push_back(i); 
    }
    vector<int> dist(n,-1);
    for(i=0;i<n;i++){
        if(is_s[i]){
            dist[i] = 0;
            dfs(myg,dist,i);
        }
    }
    int maxy  = -9;
    for(i=0;i<n;i++){
        if(dist[i]>maxy){
            maxy= dist[i];
        }
    }
    cout<<maxy+1;

    return 0;
}