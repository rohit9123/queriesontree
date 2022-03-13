//first it will give a array of n size
//and divide the array in sqrtn
//12 -> 3 ->[0,2],[3,5],[6,8][9,11]
//first calculate the block size floor(sqrt(N))

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
#define INT_MAX 2147483647
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    const int len=(int)sqrt(n+.0)+1;
    vector<int> sqrtarr(len,INT_MAX);
    for(int i=0;i<n;i++){
        sqrtarr[i/len]=min(sqrtarr[i/len],arr[i]);
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        int lb=l/len,rb=r/len;
        int ans=INT_MAX;
        if(lb==rb){
            for(int i=l;i<=r;i++){
                ans=min(ans,arr[i]);
            }
        }else{
            int nb=(lb+1)*len;
            for(int i=l;i<nb;i++){
                ans=min(ans,arr[i]);
            }
            for(int i=lb+1;i<rb;i++){
                ans=min(ans,sqrtarr[i]);
            }
            for(int i=rb*len;i<=r;i++){
                ans=min(ans,arr[i]);
            }
        }
        cout<<ans<<endl;
    }
}