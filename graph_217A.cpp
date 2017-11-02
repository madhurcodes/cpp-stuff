#include<iostream>
#include<vector>
#include<set>

using namespace std;


struct union_find{
    struct union_find *par;
    int num;
    int rank;
};

struct union_find *uf_findset(struct union_find *a){
    struct union_find *b = a;
    int t = 0;
    while(a->par != NULL){
        a = a->par;
        t = 1;
    }
    if(t==1){
        b->par = a;
    }
    return a;
}
void uf_union(struct union_find *a, struct union_find *b){
    struct union_find *ap = uf_findset(a);
    struct union_find *bp = uf_findset(b); 
    if (ap->rank > bp->rank){
        bp->par = ap;
    }
    else if (ap->rank < bp->rank){
        ap->par = bp;
    }
    else{
        ap->rank += 1;
        bp->par = ap;
    }
}


int main(){
    // map<pair<int,int>,int> m;
    int i,j,k,m,n;
    cin>>n;
    vector<struct union_find *> ulis(2001,NULL);
    struct union_find *temp;
    // for (i=0;i<n;i++){
    //     temp = new union_find;
    //     *temp = {NULL,i,0};
    //     ulis.push_back(temp);
    // }
    vector<bool> is_x(1001,false);
    vector<bool> is_y(1001,false);
    for(i=0;i<n;i++){
        cin>>j>>k;
        if(!is_x[j]){
            is_x[j] = true;
            temp = new union_find;
            *temp = {NULL,j,0};
            ulis[j] = temp;    
        }
        if(!is_y[k]){
            is_y[k] = true;
            temp = new union_find;
            *temp = {NULL,1000+k,0};
            ulis[1000+k] = temp;    
        }
        if(uf_findset(ulis[j]) != uf_findset(ulis[1000+k]) ){
            uf_union(ulis[j],ulis[1000+k]);
        }
    }
    int c;
    set<int> meme;
    for(i=1;i<=2000;i++){
        if(ulis[i]!=NULL){
            meme.insert(uf_findset(ulis[i])->num);  
        }
    }
    c = meme.size();
    cout<<c-1;
    return 0;
}