
/*
note 
only applicable to tree

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
#define REP(i,n) for (int i = 1; i <= n; i++)
using namespace std;
set<int> ar[100001];
int par[100001];
int sub[100001];

int dfs1(int node,int p){
    sub[node]=1;
    for(int adj:ar[node]){
        if(adj!=p){
            sub[node]+=dfs1(node,p);
        }
    }
    return sub[node];
}

int dfs(int node,int p,int n){

    for(int adj:ar[node]){
        if(adj!=p&&sub[adj]>n/2)return dfs(adj,node,n);
    
    }
    return node;
}
void decompose(int node , int p){
 
	int subTreeSize = dfs1(node , -1);
 
	int centroid = dfs(node , p , subTreeSize);
 
	cout<<"tree rooted at "<<node<<" with size "<<subTreeSize<<" has centroid "<<centroid<<endl;
 
	par[centroid] = p;
 
	for(int adj : ar[centroid])
		ar[adj].erase(centroid) , decompose(adj , centroid);
}

void update(int node){
	int curr=node;
	while(curr!=-1){
		res[curr]=min(res[curr],dist(curr,node));
		curr=par[curr]
	}
}
int query(int node){
	int curr=node;
	int ans=1e9;
	while(curr!=-1){
		ans=min(ans,res[curr]+dist(node,curr));
		curr=par[curr];
	}
	return ans;
}

 
//---------- decompose ends here -----------//
 
int main()
{
 
	int n ,x , y;
	cin>>n;
 
	REP(i , n-1)	cin>>x>>y , ar[x].insert(y) , ar[y].insert(x);
 
	decompose(1 , -1);
 
	cout<<"Parent array is as follows\n";
	REP(i , n)
	cout<<"\tPar["<<i<<"] = "<<par[i]<<endl;
}