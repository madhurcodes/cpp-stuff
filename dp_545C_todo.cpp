#include<iostream>
#include<vector>
#include <algorithm> 
#include<unordered_map>

using namespace std;


struct MyComparator
{
    const vector<int> & value_vector;

    MyComparator(const vector<int> & val_vec):
        value_vector(val_vec) {}

    bool operator()(int i1, int i2)
    {
        return value_vector[i1] < value_vector[i2];
    }
};


int main(){
    int n;
    cin >> n;
    vector <int> x;
    vector <int> h;    
    int t,i;
    for(i=0; i<n;i++){
        cin >> t;
        x.push_back(t);
        cin>> t;
        h.push_back(t);
    }
    // sort(x.begin(),x.end());
    // sort(h.begin(),h.end(),MyComparator(x));
    vector <int> befl;
    int ll;
    for(vector<int>::iterator num = x.begin();num!=x.end();num++){
        ll = lower_bound(x.begin(),num,(*num)-h[num-x.begin()]) - x.begin() - 1;
        befl.push_back(ll);
    }
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    int j,k;
    for(i=3;i<=n;i++){
            if(x[i-1]<=x[i-2]+h[i-2]){
                k = dp[i-2];
                for(j=i-3;j>=0;j--){
                    if(!(x[i-2]<=x[j]+h[j])){
                        k = dp[j+1];
                        break;
                    }
                }
                dp[i] = max(dp[befl[i-2]+1] + 2, k + 1);                 
                    // dp[i] = max(dp[befl[i-2]+1] + 2, dp[i-1]);  
            }
            else{
                dp[i] = dp[i-1] + 1;
            }
        
    }
    cout<<dp[n];
    return 0;
}