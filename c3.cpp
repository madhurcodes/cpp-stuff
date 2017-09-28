#include<iostream>
#include<vector>
#include <algorithm> 

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
    vector<vector<int> > dp(2,vector<int> (n)) ;
    vector<int>  choice(n);
    dp[0][n-1] = a[n-1];
    choice[n-1] = 1;
    choice[n-2] = (a[n-2] > a[n-1] )? 1 : 0;
    dp[1][n-1] = a[n-1];
    dp[0][n-2] = max(a[n-2],a[n-1]);
    dp[1][n-2] = max(a[n-2],a[n-1]);
    int mii=111111111,maa=-1;
    int j;
    int curr;
    int msofar = 11111111;
    vector <int> sums(n);
    sums[n-1] = a[n-1];
    for(i=n-2;i>=0;i--){
        sums[i] = a[i]+sums[i+1];
    } 
    for(i=n-3;i>=0;i--){
        dp[1][i] = max(a[i]+sums[i+1]-dp[0][i+1],dp[0][i+1]);
        dp[0][i] = max(a[i]+sums[i+1]-dp[1][i+1],dp[1][i+1]);
        // curr =0;
        // msofar = 11111111;
        // for(j=i+1;j<n;j++){
        //     curr = curr + a[j];           
        //     if(curr+dp[0][]
        // }
        
        if((a[i]+sums[i+1]-dp[0][i+1])>=(dp[0][i+1])){
            choice[i] = 1;
        }
    }
    int bob,alice;
    for(i=0;i<n;i++){
        if(choice[i]==1){
            bob = dp[0][i];
            break;
        }
    }
    alice = sums[0] - bob;
    cout<<alice<<" "<<bob;
    return 0;
}