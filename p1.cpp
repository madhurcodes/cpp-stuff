#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main(){
    int test, i;
    cin >> test;
    for(i=0;i<test;i++){ // n m
        int n, m;
        cin >> n;
        cin >> m;
        string lin;
        vector<int> done;
        int temp;
        int k=0;
        for (k=0;k<m;k++){
            cin >> temp;
            done.push_back(temp);
        }
        sort(done.begin(),done.end());
        vector <int> outp;
        vector <int> ::iterator smallest = done.begin();
        for(k=1;k<=n;k++){
            if( (smallest == done.end()) || ( k < *smallest) ){
                outp.push_back(k);
            }
            else{
                smallest++;
            }
        }
        for(k=0;k<(outp.size()+1)/2 ; k++){
            cout  << outp[k*2] << " " ;
        }
        cout << endl;
        for(k=0;k < outp.size() / 2  ; k++){
            cout << outp[k*2 + 1] << " " ;
        }
        cout << endl;
    }
    return 0;

}