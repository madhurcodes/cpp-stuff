#include<iostream>
#include<vector>
#include <algorithm> 
#include <stack>

using namespace std;


int main(){
    int i,n,t,k;
    cin>>n>>t;
    vector<vector<int> > myg(n);
    for(i=0;i<n-1;i++){
        cin>>k;
        myg[i].push_back(i+k);
    }
    // 0 to t-1
    stack <int> dd;
    dd.push(0);
    vector<int> visited(n,-1);
    visited[0] = 1;
    while(!dd.empty()){
        k = dd.top();
        dd.pop();
        for(i=0;i<myg[k].size();i++){
            if(visited[myg[k][i]]==-1){
                if(myg[k][i]==t-1){
                    cout<<"YES";
                    return 0;
                }
                visited[myg[k][i]] = 1;
                dd.push(myg[k][i]);
            }
        }
    }
    cout<<"NO";

    return 0;
}