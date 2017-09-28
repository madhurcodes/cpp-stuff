#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

template <typename sup , typename iter > int find ( iter mm, iter mme, sup tar){
    iter i = mm;
    for(;i!= mme; i++){
        if(*i==tar){
            cout << "Found at " << *i;
            return 1;
        }
    }
    cout << "Not Found";
    return 0;
}

vector<int> sub_vec(const vector<int> &vec, int val)
{
    vector<int> local_vec(vec);
    sort(local_vec.begin(), local_vec.end());
    vector<int>::iterator iter = find_if(local_vec.begin(), local_vec.end(), bind2nd(greater<int>() , val));
    local_vec.erase(iter, local_vec.end());
    return local_vec;
}

int main(){
    map<string,int> nf;
    nf["mad"] = 3;
    cout << nf["madd"] ;

    // vector<int>  ars(5);
    // ars[0] = 33;
    // ars[1] = 4;
    // ars[2] = 23;
    // ars[3] = 13;
    // ars[4] = 3;
    // vector<int>::iterator beg = ars.begin();
    // vector<int>::iterator en = ars.end();
    // cout << ars.size()<< endl;
    // ars = sub_vec(ars , 16);
    // int i;
    // for(i=0; i<ars.size(); ++i){
    //     cout << ars[i] << ' ';  
    // }
    // cout << endl << ars.size();
    // return find(beg,en, 4);
}

