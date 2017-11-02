#include<iostream>

#include<vector>

using namespace std;
//bettwe also exists (we do qn exists q)
// taking hor and ver separately gives better
int main(){
    int i,j,n,m,k;
    cin>>n>>m;
    char ax;
    vector<vector<int> > mat(n, vector<int>(m,-1));    
    vector<vector<int> > dp(n, vector<int>(m,-1));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>ax;
            if(ax=='.'){
                mat[i][j] = 1;
            }
            else if(ax=='#'){
                mat[i][j] = 0;
            }
            else{
                cout<<"ARGHDC";
                return 0;
            }
        }
    }
    dp[0][0] = 0;
    for(j=1;j<m;j++){
        if((mat[0][j]==1) && (mat[0][j-1]==1)){
            dp[0][j] = dp[0][j-1] + 1; 
        }
        else{
            dp[0][j] = dp[0][j-1];
        }
    }
    for(j=1;j<n;j++){
        if((mat[j][0]==1) && (mat[j-1][0]==1)){
            dp[j][0] = dp[j-1][0] + 1; 
        }
        else{
            dp[j][0] = dp[j-1][0];
        }
    }
    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
            if((mat[i][j]==1)&&(mat[i-1][j]==1)){
                dp[i][j]  = dp[i][j]  + 1;
            }
            if((mat[i][j]==1)&&(mat[i][j-1]==1)){
                dp[i][j]  = dp[i][j]  + 1;
            }
        }
    }
    int q,a,b,c,d,ans;
    cin>>q;
    for(i=0;i<q;i++){
        cin>>a>>b>>c>>d;
        a = a-1;
        b = b-1;
        c = c-1;
        d= d-1;
        ans = dp[c][d];
        if((a==0)&&(b==0)){
        }
        else if((a==0)&&(b!=0)){
            ans -= dp[c][b-1];
        }
        else if((a!=0)&&(b==0)){
            ans -= dp[a-1][d];
        }
        else{
            ans -= dp[c][b-1];
            ans -= dp[a-1][d];
            ans += dp[a-1][b-1];
        }
        if(!(b==0)){
            for(j=a;j<=c;j++){
                if((mat[j][b]==1)&&(mat[j][b-1]==1)){
                    ans -=1;
                }
            }
        }
        if(!(a==0)){
        for(j=b;j<=d;j++){
            if((mat[a][j]==1)&&(mat[a-1][j]==1)){
                    ans -=1;
            }
        }
    }
        cout<<ans<<endl ;
    }
    return 0;
}