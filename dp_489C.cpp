#include<iostream>
#include<vector>
#include <algorithm> 

using namespace std;

int main(){
    int l, s;
    cin >> l >> s;
    vector<vector<int> > dp(s+1,vector<int>(l));
    int i,j,k,flag;
    if(l==1){
        if(s>=0&&s<=9){
            cout<<s<<" "<<s;
            return 0;
        }
    }
    for(i=0;i<s+1;i++){
        if(i<=9){
            dp[i][0] = 1;
        }
        else{
            dp[i][0] = 0;
        }
    }
    for(j=1;j<l-1;j++){
        for(i=0;i<s+1;i++){
            flag=0;
            for(k=0;(k<=9) && ((i-k)>=0) ;k++){
                if(dp[i-k][j-1] == 1){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
   
    for(i=0;i<s+1;i++){
        flag=0;
        for(k=1;(k<=9) && ((i-k)>=0) ;k++){
            if(dp[i-k][l-2] == 1){
                flag=1;
                break;
            }
        }
        if(flag==1){
            dp[i][l-1] = 1;
        }
        else{
            dp[i][l-1] = 0;
        }
    }    
    int lar=-1, smal=-1;
    int lsum,ssum;

    for(k=1;k<=9;k++){
        if(((s-k)>=0)&& dp[s-k][l-2]==1){
            smal = k;
            cout<<k;
            ssum=s-k;
            break;
        }
    }
    if(smal==-1){
        cout << -1<<" " << -1;
        return 0;
    }
    for(j=l-2;j>=1;j--){
        for(k=0;k<=9;k++){
            if((ssum-k>=0) && dp[ssum-k][j-1]==1){
                cout<<k;
                //smal = smal*10+k;
                ssum = ssum-k;
                break;
            }
        }
    }
    if((ssum>9) || (ssum <0)){
        cout << "Weird err";
    }
    else {
        cout<<ssum;
    }
    cout<<" ";
    for(k=9;k>=1;k--){
        if(((s-k)>=0)&& (dp[s-k][l-2]==1)){
            lar = k;
            cout <<k;
            lsum = s-k;
            break;
        }
    }
   

    for(j=l-2;j>=1;j--){
        for(k=9;k>=0;k--){
            if((lsum-k>=0) && (dp[lsum-k][j-1]==1)){
                cout<<k;
                //lar = lar*10+k;
                lsum = lsum-k;
                break;
            }
        }
    }
    if((lsum>9) || (lsum <0)){
        cout << "Weird err";
    }
    else {
        cout<<lsum;
      //  lar = lar*10 +lsum;
    }
    return 0;
}