#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string m;
    getline(cin, m);
    int i;
    int k = m.size();
    vector<int> trans(k);
    vector<int> sums(k);
    sums[0] = 0;
    for(i=1;i<k;i++){
        if(m[i-1]==m[i]){
            sums[i] = sums[i-1]+1;
        }
        else{
            sums[i] = sums[i-1];
        }
    }
    int n;
    cin >> n;
    int a,b;
    for(i=0;i<n;i++){
        cin >> a >> b;
        cout<<(sums[b-1]-sums[a-1])<<endl;
    }
    return 0;
}