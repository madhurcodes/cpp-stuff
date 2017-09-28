#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main(){
    int test, i;
    cin >> test;
    for(i=0;i<test;i++){ // n m
        int n;
        cin >> n;
        vector<int> skill;
        int temp;
        int k=0;
        for (k=0;k<n;k++){
            cin >> temp;
            skill.push_back(temp);
        }
        // vector< vector<int> > big (n, vectot<int> (n, 1000000005));
        int  i = 0,j =0;
        int min = 1000000005;        
        int tem;
        sort(skill.begin(),skill.end());
        for(i=0;i<n-1;i++){
            tem = skill[i+1] - skill[i];
            if(tem<min){
                min = tem;
            }
        }
        // for(i=0;i<n;i++){
        //     for(j=0;j<i;j++){
        //         tem = skill[i] - skill[j];
        //         tem = ((tem  >=  0) ? tem : (-tem)) ;
        //         cout <<endl << "--" << tem<<endl;
        //         if ( tem < min ) {
        //             min  = tem;
        //         }
        //         // big[i][j] = skill[i] - skill[j];
        //         // big[i][j] = ((big[i][j] >=  0) ? big[i][j] : (-big[i][j]) );
        //     }
        // }
        cout << min << endl;



    }
    return 0;

}