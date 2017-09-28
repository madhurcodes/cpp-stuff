#include<iostream>
#include<vector>
#include <algorithm> 
#include<unordered_map>

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
    int rest=0,gym=0,con=0,t_rest,t_gym,t_con;
    for(i=0;i<n;i++){
        if(a[i]==3){
            t_gym = gym;
            t_rest = rest;
            t_con = con;
            rest = 1 + min({t_rest,t_gym,t_con});
            gym = min({t_rest,t_con});
            con = min({t_rest,t_gym});
        }
        else if(a[i]==2){
            t_gym = gym;
            t_rest = rest;
            t_con = con;
            rest = 1 + min({t_rest,t_gym,t_con});
            gym = min({t_rest,t_con});
            con = 1000000;

            
        }
        else if(a[i]==1){
            t_gym = gym;
            t_rest = rest;
            t_con = con;
            rest = 1 + min({t_rest,t_gym,t_con});
            gym = 1000000;
            con = min({t_rest,t_gym});
        }
        else{
            t_gym = gym;
            t_rest = rest;
            t_con = con;
            rest = 1 + min({t_rest,t_gym,t_con});
            gym = 100000;
            con = 10000;
        
        }
    }
    cout<<min({rest,gym,con});
    return 0;
}