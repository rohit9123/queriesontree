
//path queries

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

#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;

 
using namespace std;
const int maxN = 100001;
const int BLK = 700;



struct query{
    int n1,n2,col,index,lca;
};

struct comp(query a,query b){
    int x=a.l/BLK,y=b.l/BLK;
    if(x!=y){
        return x<y;
    }else{
        return a.r<b.r;
    }
}
vector<int>arr[100001];
int nodeF[maxN],eleF[2*maxN],level[maxN],LCA[100001][21];
int val[maxN],res[maxN],s[maxN],t[maxN],ft[maxN];
query Q1[maxN];

int get_lca(int a,int b){


    int diff=level[b]-level[a];
    for(int i=20;i>=0;i--){
        if(diff&(1<<i)){
            b=LCA[b][i];
        }
    }
    if(a==b){
        return a;
    }
    for(int i=20;i>=0;i--){
        if(up[a][i]!=up[b][i]){
            a=up[a][i],b=up[b][i];
        }
    }
    return up[a][0];
}

int main(){
    int n,q,a,b,c;
    int t=0;
    while(cin>>n){
        if(t>0)cout<<endl;
        t++;
        cin>>q;
        for(int i=0;i<=n;i++){
            arr[i].clear(),eleF[i]=0,nodeF[i]=0;
        }
        for(int i=0;i<=q;i++){
            res[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>val[i];
        }
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        for(int i=0;i<q;i++){
            cin>>a>>b>>c;
        }
    }
}