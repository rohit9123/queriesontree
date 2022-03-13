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
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int blk=745;
struct query{
    int l,r,i;
};
bool static comp(query& a,query& b){
    if(a.l/blk!=b.l/blk){
        return a.l/blk<b.l/blk;
    }
    else
    return a.r<b.r;
}
query Q[200001];
long long ar[200001],ans[200001],freq[1000001];
long long cnt=0;

void add(int& pos){
    cnt-=freq[ar[pos]]*freq[ar[pos]]*ar[pos];
    freq[ar[pos]]++;
    cnt+=freq[ar[pos]]*freq[ar[pos]]*ar[pos];
}
void remove(int& pos){
    cnt-=freq[ar[pos]]*freq[ar[pos]]*ar[pos];
    freq[ar[pos]]--;
    cnt+=freq[ar[pos]]*freq[ar[pos]]*ar[pos];
}

int main(){
    fast;
    memset(freq,0,sizeof(freq));
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
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
