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
int arr[30001],freq[1000001],ans[200001];
int cnt=0;
int main(){
    memset(freq,0,sizeof(freq));
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>Q[i].l>>Q[i].r;
        Q[i].l--,Q[i].r--;
        Q[i].i=i;
    }
    sort(Q,Q+m,comp);
    int ml=0,mr=-1;
    for(int i=0;i<m;i++){
        int l=Q[i].l;
        int r=Q[i].r;
        // cout<<l<<" "<<r<<endl;
        while(ml>l){
            ml--;
            freq[arr[ml]]++;
            if(freq[arr[ml]]==1){
                cnt++;
            }
        }
        while(mr<r){
            mr++;
            freq[arr[mr]]++;
            if(freq[arr[mr]]==1){
                cnt++;
            }
        }
        while(ml<l){
            freq[arr[ml]]--;
            if(freq[arr[ml]]==0){
                cnt--;
            }
            ml++;
        }
        while(mr>r){
            freq[arr[mr]]--;
            if(freq[arr[mr]]==0){
                cnt--;
            }
            mr--;
        }
        // cout<<cnt<<endl;
        ans[Q[i].i]=cnt;
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<'\n';
    }
}