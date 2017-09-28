#include<iostream>
#include<vector>
#include <algorithm> 

using namespace std;

int main(){
    int n, a,b,c;
    cin >> n >>a>> b>>c;
    vector<int> dp(n+1);
    int x,y,z,t;
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        x = (i-a)>=0 ? dp[i-a] : -1;
        y = (i-b)>=0 ? dp[i-b] : -1;
        z = (i-c)>=0 ? dp[i-c] : -1;
        t = max({x,y,z});
        if(t>=0){
            dp[i] = 1 + t;
        }
        else{
            dp[i] = -1;
        }
    }
    cout<<dp[n];
    return 0;
}