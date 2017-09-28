#include<iostream>
#include<vector>
#include <algorithm> 
#include<unordered_map>

using namespace std;

int main(){
    int n,m;
    cin >> n;
    vector <int> b; 
    int t,i;
    for(i=0; i<n;i++){
        cin >> t;
        b.push_back(t);
    }
    cin >> m;
    vector <int> g; 
    for(i=0; i<m;i++){
        cin >> t;
        g.push_back(t);
    }
    //Try HashTable method
    unordered_map <int,int> freq;
    for(i=0;i<n;i++){
        freq[b[i]] = freq[b[i]] + 1; 
    }
    int mun = 0;
    for(i=0;i<n;i++){
        mun += freq[g[i]+1]+freq[g[i]]+freq[g[i]-1];
    }
    cout<<mun;
    return 0;
}
    