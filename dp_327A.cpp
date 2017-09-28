#include<iostream>
#include<vector>
#include <algorithm> 

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> f; 
    int t;
    for(int i=0; i<n;i++){
        cin >> t;
        f.push_back(t);
    }
    vector <int> dp(n);
    int i;
    dp[0] = f[0]==0? 1 : -1;
    int max_1= dp[0];
    int max_i=0;
    int max_L = 1;
    int l=1;
    for(i=1;i<n;i++){
        t = f[i]==0?1:-1;
        if(t>=t+dp[i-1]){
            dp[i] = t;
            l=1;
         }
         else{
             dp[i] = t+dp[i-1];
             l++;
         }
        if(dp[i]>max_1){
            max_1=dp[i];
            max_i = i;
            max_L = l;
        }
    }
    int res = 0;
    // if(max_1<1){
    //     for(i=0;i<=n;i++){
    //         res = f[i]==1?res+1:res; 
    //     }
    //     cout<<res;
    //     return 0;
    // }
    for(i=0;i<=max_i-max_L;i++){
        res = f[i]==1?res+1:res; 
    }
    res += (max_1+max_L )/ 2;
    for(i=max_i+1;i<n;i++){
        res = f[i]==1?res+1:res; 
    }

    cout<<res;
    return 0;
}