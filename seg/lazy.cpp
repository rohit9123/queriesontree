
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
const int maxn=100001;
int arr[maxn];
int st[4*maxn],lazy[4*maxn];

void build(int si,int ss,int se){
    if(ss==se){
        st[si]=arr[ss];
        return;
    }
    int mid=(ss+se)/2;
    build(2*si,ss,mid);
    build(2*si+1,mid+1,se);
    st[si]=st[2*si]+st[2*si+1];
}

int query(int si,int ss,int se,int qs,int qe){
    if(lazy[si]!=0){
        int dx=lazy[si];
        lazy[si]=0;
        st[si]+=dx*(se-ss+1);
        if(ss!=se){
            lazy[2*si]+=dx,lazy[2*si+1]+=dx;
        }
    }
    if(ss>qe||se<qs)return 0;
    if(ss>=qs&&se<=qe)return st[si];
    int mid=(ss+se)/2;
    return query(2*si,ss,mid,qs,qe)+query(2*si+1,mid+1,se,qs,qe);
}
void update(int si,int ss,int se,int qs,int qe,int val){
    if(lazy[si]!=0){
        int dx=lazy[si];
        lazy[si]=0;
        st[si]+=dx*(se-ss+1);
        if(ss!=se){
            lazy[2*si]+=dx,lazy[2*si+1]+=dx;
        }
    }
    if(ss>qe||se<qs)return;
    if(ss>=qs&&se<=qe){
        int dx=(se-ss+1)*val;
        st[si]+=dx;
        if(ss!=se){
            lazy[2*si]+=dx,lazy[2*si+1]+=dx;
        }
        return;
    }
    int mid=(ss+se)/2;
    update(2*si,ss,mid,qs,qe,val);
    update(2*si+1,mid+1,se,qs,qe,val);
    st[si]=st[2*si]+st[2*si+1];
}
int main(){
    int n,q;
    cin>>n>>q;
    build(1,1,n);
    while(q--){
        int t,a,b;
        cin>>t>>a>>b;
        if(t==1){
            cout<<query(1,1,n,a,b)<<endl;
        }else{
            int val;
            cin>>val;
            update(1,1,n,a,b,val);
        }
    }
    return 0;
}