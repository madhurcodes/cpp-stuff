#include<iostream>
#include<vector>
#include <algorithm> 
#include<unordered_map>

using namespace std;

int main(){
    int n,k;
    cin >> n>>k;
    vector <int> a; 
    int t,i;
    for(i=0; i<n;i++){
        cin >> t;
        a.push_back(t);
    }
    vector <int> b(n);
    for(i=1;i<n;i++){
        b[i] = max(0,k-b[i-1]-a[i-1]-a[i]);
    }
    int s =0;
    for(i=0;i<n;i++){
        s += b[i];
    }
    cout<<s<<endl;
    for(i=0;i<n;i++){
        cout<< a[i] + b[i]<<" ";
    }
    return 0;
}