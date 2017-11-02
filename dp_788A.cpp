#include<iostream>
#include<vector>
#include <algorithm> 
#include<cmath>

using namespace std;
long long int sub_max(vector<long long int> &in){
    long long int i,max_so_far=0,max_end_here=0,siz=in.size();
    for(i=0;i<siz;i++){
        max_end_here = max_end_here + in[i];
        if(max_end_here<0){
            max_end_here = 0;
        }
        if(max_so_far<max_end_here){
            max_so_far = max_end_here;
        }
    }
    return max_so_far;
}
int main(){
    long long int n;
    cin >> n;
    vector <long long int> f;
    long long int t;
    for(long long int i=0; i<n;i++){
        cin >> t;
        f.push_back(t);
    }
    vector <long long int> new1(n-1);
    vector <long long int> new2(n-1);
    long long int s = 1;
    for(t=0;t<n-1;t++){
        new1[t] = s*abs(f[t] - f[t+1]);
        new2[t] = -s*abs(f[t] - f[t+1]);
        s = -1*s;
    }
    cout<<max(sub_max(new1),sub_max(new2));
    return 0;
}