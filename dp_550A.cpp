#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string m;
    getline(cin, m);
    int i,j;
    int k = m.size();
    string at=m,bt=m;
    int aba=0,ab=0,ba=0;
    for(i=0;i<k-1;i++){
        if((at[i]=='A')&&(at[i+1]=='B')){
            at[i] = 'X';
            at[i+1] = 'X';
            for(j=0;j<k-1;j++){
                if((at[j]=='B')&&(at[j+1]=='A')){
                    ab = 1;
                }
            }
            break;
        }
    }
    for(i=0;i<k-1;i++){
        if((bt[i]=='B')&&(bt[i+1]=='A')){
            bt[i] = 'X';
            bt[i+1] = 'X';
            for(j=0;j<k-1;j++){
                if((bt[j]=='A')&&(bt[j+1]=='B')){
                    ba = 1;
                }
            }
            break;
        }
    }
    if(ab||ba){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;

}