#include<iostream>
#include<vector>
#include <algorithm> 

using namespace std;

int main(){
    int m;
    cin >> m;
    vector <int> f;
    int i;
    int t;
    for( i=0; i<m;i++){
        cin >> t;
        f.push_back(t);
    }
    int val = 1;
    int max = 1;
    for(i=1;i<m;i++){
        if(f[i]>=f[i-1]){
            val++ ;
        }
        else{
            val = 1;
        }
        if(val>max){
            max = val;
        }
    }
    cout << max;



}