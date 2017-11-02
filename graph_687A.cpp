#include<iostream>
#include<vector>
#include <algorithm> 
#include <stack>

using namespace std;


void addEdge(vector <vector <int> > &ad, int s, int t){
    ad[s].push_back(t);
    ad[t].push_back(s);
}

int main(){
    int i,j,n,k,m;
    cin>>n>>m;
    vector<vector<int> > myg(n);
    for(i=0;i<m;i++){
        cin>>j>>k;
        j = j-1;
        k = k-1;
        addEdge(myg,j,k);
    }
    stack<int> dd;
    vector<int> color(n,0);
    for(i=0;i<n;i++){
        if(myg[i].size()==0){
            continue;
        }
        if((color[i]==0)){
            dd = stack<int>();
            dd.push(i);
            color[i] = 1;
            while(!dd.empty()){
                k = dd.top();
                dd.pop();
                for(j=0;j<myg[k].size();j++){
                    if(color[myg[k][j]]==0){
                        color[myg[k][j]] = color[k] == 1 ? 2: 1; 
                        dd.push(myg[k][j]);
                    }
                    else if (color[myg[k][j]]==color[k]){
                        cout<<-1;
                        return 0;
                    }
                }
            }
        }
    }
    int c1=0,c2=0;
    for(i=0;i<n;i++){
        if(color[i]==1){
            c1+=1;
        }
        else if(color[i]==2){
            c2+=1;
        }
    }

    cout<<c1<<endl;
    for(i=0;i<n;i++){
        if(color[i]==1){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
    cout<<c2<<endl;
    for(i=0;i<n;i++){
        if(color[i]==2){
            cout<<i+1<<" ";
        }
    }


    return 0;
}