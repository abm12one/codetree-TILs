#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cmath>
#include<limits.h>
#include<cassert>
//#include<unordered_map>
//#include<map>
#include<unordered_set>
#include<set>
#define MAX_M 100000

using namespace std;
vector<int>arr;
vector<int>sum;
vector<vector<int>>cache;

int getsum(int i,int j){
    return sum[j]-sum[i-1];
}

int dp(int a,int b){
    
    int &ret=cache[a][b];
    if(ret!=-1){
        return ret;
    }
    if(a==b){
        return ret=0;
    }
    int ans=(int)1e9;
    for(int i=a;i<b;i++){
        ans=min(ans,dp(a,i)+dp(i+1,b)+getsum(a,b));
    }
    return ret=ans;

}

int main() {
    int n;
    cin>>n;
    
    arr=vector<int>(n+1);
    sum=vector<int>(n+1);
    cache=vector<vector<int>>(n+1,vector<int>(n+1,-1));
    for(int i=1;i<n+1;i++){
        cin>>arr[i];
    }

    for(int i=1;i<n+1;i++){
        sum[i]=sum[i-1]+arr[i];
    }
    cout<<dp(1,n);

	
}