#include<iostream>
#include<vector>
#include <algorithm> 
#include<unordered_map>
#include<math.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    double sq = n;
    double root = sqrt(sq);
    int s = (int) (0.99+root);
    int i;
    cout<<(s*4-2*((s*s-n)/s));
    return 0;
}