#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main(){
    int test;
    int i;
    cin >> test;
    for(i=0;i<test;i++){ // n m
        int p , q;
        cin >> p;
        cin >> q;
        vector<int> remainders;
        while ( (p / q) == 0 && (! p==0) ){
            p = p * 10;
        }
        bool fou  = false;
        int rem = -1, quo;
        while(find(remainders.begin(),remainders.end(),rem) == remainders.end()){
            if(rem!=-1){
                remainders.push_back(rem);
            }
            rem = p % q;
            p = rem;
            while(p/q == 0 && (! p==0) ){
                p = p * 10;
                fou = true;
                // cout <<"--" ;
            }
        }
        if(fou){
        cout << remainders.size();
        }
        else {
            cout << -1;
        }
    }
    return 0;
}