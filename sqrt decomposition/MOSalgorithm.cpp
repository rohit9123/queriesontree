/*Mo's algorithm is actually square root decomposition on queries
//it works with offline queries
//queries like finding number of unique integer in a given range can be amswered in O(sqrt(N)) time

sorting in Mo's Algorithm
Each query is sorted in ascending order of block number
of L,and ties are order by ascending order of r

10^6 -> Block size 1000
10^5 -> Block size 700

*/ 


#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<string.h>
#include<math.h>
#include<unordered_map>
#include<iomanip>
#include<unordered_set>
#include <string>

using namespace std;
// #define INT_MAX 2147483647

int blk=555;
struct query{
    int l,r,i;
};
bool static comp(query a,query b){
    if(a.l/blk!=b.l/blk){
        return a.l/blk<b.l/blk;
    }
    else
    return a.r<b.r;
}
query Q[200001];
int ar[30001],ans[200001],freq[1000001];
int cnt=0;

void add(int pos){
    freq[ar[pos]]++;
    if(freq[ar[pos]]==1){
        cnt++;
    }
}
void remove(int pos){
    freq[ar[pos]]--;
    if(freq[ar[pos]]==1)
    cnt--;
}

int main(){
    memset(freq,0,sizeof(freq));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>Q[i].l>>Q[i].r;
        Q[i].l--,Q[i].r--;
        Q[i].i=i;
    }
    sort(Q,Q+q,comp);
    int ml=0,mr=-1;
    for(int i=0;i<q;i++){
        int l=Q[i].l,r=Q[i].r;
        while(ml>l)ml--,add(ml);
        while(mr<r)mr++,add(mr);
        while(ml<l)remove(ml),ml++;
        while(mr>r)remove(mr),mr--;
        ans[Q[i].i]=cnt;
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<"\n";
    }
}


/*
Basic template of Mo's Algorithm
for(int i=0;i<q;i++){
    int L=Q[i].i;
    int R=Q[i].r,idx=Q[i].i;
    

    //extending range
    while(MR<R)MR++,add(MR);
    while(ML>L)ML--,add(ML)'

    //reducing range
    while(MR>R)remove(MR),MR--;
    while(ML<L)remove(ML),ML++;

    ans[ix]=cnt

}
*/