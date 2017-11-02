#include<iostream>
#include<vector>
#include <algorithm> 
#include <stack>

using namespace std;


int main(){
    long long int i,n,t,k,m,a,b,c;
    cin>>n>>m>>k;
    vector<bool> is_f(n+1,false);
    vector<vector<pair<long long int,long long int> > > myg(n+1);    
    for(i=0;i<m;i++){
        cin>>a>>b>>c;
        myg[a].push_back(make_pair(b,c));
        myg[b].push_back(make_pair(a,c));
    }
    for(i=0;i<k;i++){
        cin>>a;
        is_f[a] = true;
    }
    long long int min = 10000000000000000;
    for(i=0;i<n+1;i++){
        if(is_f[i]){
            for(t=0;t<myg[i].size();t++){
                if((!is_f[myg[i][t].first])&&(myg[i][t].second<min)){
                    min = myg[i][t].second;
                }
            }
        }
    }
    if(min == 10000000000000000){
        cout<<-1;
    }
    else{
        cout<<min;
    }
    return 0;
}