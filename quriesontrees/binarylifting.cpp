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
using namespace std;
int depth[100001];
void dfs(int node,int dep,int parent,vector<vector<int> >& tree){
    depth[node]=dep;
    for(int a:tree[node]){
        if(a!=parent){
            dfs(a,dep+1,parent,tree);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > tree(n);
    vector<vector<int> > parent(n,vector<int>(21,-1));
    
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        parent[b][0]=a;

    }
    //calculate depth
    dfs(0,0,-1,tree);
    for(int i=1;i<21;i++){
        for(int j=0;j<n;j++){
            if(parent[parent[i][j-1]][j-1]!=-1)
            parent[j][i]=parent[parent[i][j-1]][j-1];
        }
    }
    //kth node
    int k,node;cin>>k>>node;
    for(int j=0;j<21;j++){
        if(k&(1<<j)){
            if(parent[parent[i][j-1]][j-1]!=-1)
            node=parent[node][j];
        }
    }
    //lca of 2 node
        int a,b;
        cin>>a>>b;
        if(depth[a]<depth[b]){
            swap(a,b);
        }
        int k=depth[a]-depth[b];
        for(int i=0;i<21;i++){
            if(k&(1<<i)){
                a=parent[a][i];
            }
        }
        if(a==b)
        cout<<a<<endl;
        else{
        for(int j=20;j>=0;j--){
            if(parent[a][j]!=parent[b][j]){
                a=parent[a][j];
                b=parent[b][j];
            }
        }
            cout<<parent[a][0]<<endl;
        }
        //distance between 2 nodes
        depth[a]+depth[b]-2*depth[parent[a][0]];
        
}