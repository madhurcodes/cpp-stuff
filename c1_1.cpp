#include<iostream>
#include<vector>
#include <algorithm> 
#include<unordered_map>

using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector <int> a; 
    int t,i;
    for(i=0; i<n;i++){
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    int k=0,exists=0;
    for(i=0;i<a.size();i++){
        if(a[i]<x){
            k++;
        }
        else if(a[i]==x){
            exists = 1;
        }
        else{
            break;
        }
    }
    if(exists==1){
        cout<<x-k+1;
    }
    else{
        cout<<x-k; 
    }


    return 0;
}