#include<iostream>
#include<vector>
#include <algorithm> 

using namespace std;

int main(){
    long long int n, k;
    cin >> n >> k;
    long long int i=1,lim = 100001;     
    vector <long long int> dp(lim,0);
    long long int mmm = 1000000007;    
    for(i=1;i<lim;i++){
        if(i<k){
            dp[i] = 1;
        }
        else if(i==k){
            dp[i] = 2;
        }
        else{
            dp[i] = (dp[i-1] + dp[i-k])% mmm;
        }

    }
    // for(i=1;i<21;i++){
    //     cout<<"dp of "<<i<<" is r-"<<dp[i]<<endl;
    // }
    vector <long long int> partial(lim,0);
    long long int a,b,v,s=0;
    for(i=1;i<lim;i++){
        partial[i] = (partial[i-1] + dp[i]) ; 
    }
    for(i=0;i<n;i++){
        s = 0;
        cin>>a>>b;
        cout<<(partial[b]-partial[a-1])%mmm<<endl;
    }
    return 0;
}