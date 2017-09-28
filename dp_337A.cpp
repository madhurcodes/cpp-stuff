#include<iostream>
#include<vector>
#include <algorithm> 

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> f;
    //int i;
    int t;
    for(int i=0; i<m;i++){
        cin >> t;
        f.push_back(t);
    }
    sort(f.begin(),f.end());
    int t_max = -1,t_min = 10000000, lv, val;
    int min_diff = 10000000;
    for(int i=0;i<=m-n;i++){
        min_diff = min(min_diff, f[i+n-1] - f[i]);
        // int t_max = -1,t_min = 10000000, lv, val;
        // for(lv=i;lv<i+n;lv++){
        //     val = f[lv];
        //     if(t_max<val){
        //         t_max =val;
        //     }
        //     if(t_min>val){
        //         t_min =val;
        //     }
        // }
        // if(min>t_max-t_min){
        //     min  = t_max-t_min;
        // }
    }
    cout << min_diff;
    return 0;
}