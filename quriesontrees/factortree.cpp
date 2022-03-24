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
const int blk=600;
struct queries{
    int a,b,i,parent;
};
int timer=0;
vector<int> flatten,st,en,depth;
bool comp(queries& ab,queries &bc){
    if(ab.a/blk!=bc.a/blk){
        return ab.a<bc.a;
    }
    return ab.b<bc.b;
}

void dfs(int node,int parent,vector<vector<int> >&arr){
    st[node]=timer;
    flatten[timer]=node;
    timer++;
    for(int a:arr[node]){
        if(a!=parent){
            dfs(a,node,arr);
        }
    }
    en[node]=timer;
    flatten[timer++]=node;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int> > arr(n+1);
        vector<int> weight(n+1);
        flatten.resize(2*n+1);
        depth.resize(n+1);
        st.resize(n+1);
        en.resize(n+1);
        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            cin>>weight[i];
        }
        int q;
        cin>>q;
        vector<queries> qu(q);
        dfs(1,-1,arr);
        for(int i=0;i<q;i++){
            int a,b;cin>>a>>b;
            if(st[a]<st[b]&&en[a]>en[b]){
                qu[i].parent=-1;
            }else if(st[a]>st[b]&&en[a]<en[b]){
                qu[i].parent=-1;
            }
            int s=st[a],s1=st[b];
            if(s>s1)swap(s,s1);
            
            qu[i].a=s,qu[i].b=s1,qu[i].i=i;
        }
        sort(qu.begin(),qu.end());
        for(int i=0;i<q;i++){
            int l=qu[i].a,r=qu[i].b;
            
        }
    }
}