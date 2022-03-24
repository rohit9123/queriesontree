//flat tree


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
int tim[201],timer=0,enter[100],exi[100];
void dfs(int node,int parent,vector<vector<int> >&arr){
    enter[node]=timer;
    tim[timer]=node;
    timer++;
    for(int a:arr[node]){
        if(a!=parent){
            dfs(a,node,arr);
        }
    }
    exi[node]=timer;
    tim[timer]=node;
    timer++;
}


int main(){
    int n;
    cin>>n;
    vector<vector<int> > arr(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1,-1,arr);
    for(int i=0;i<2*n;i++){
        cout<<tim[i]<<" ";
    }
}
