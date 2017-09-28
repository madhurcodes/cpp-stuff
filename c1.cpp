#include<iostream>
#include<vector>
#include <algorithm> 
#include<unordered_map>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> a; 
    int t,i;
    for(i=0; i<n;i++){
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    cout<<max(0,(a[n-1]-25));
    return 0;
}