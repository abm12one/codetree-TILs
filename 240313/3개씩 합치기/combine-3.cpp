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
#define MAX_N 5000

using namespace std;

vector<vector<int>>cache;
vector<int>arr;
int getsum(int i,int s,int j){
    int ans=1;
    ans*=arr[i];
    ans*=arr[s];
    ans*=arr[j];
    return ans;
}

int dp(int i,int j){
    int &ret=cache[i][j];
    if(ret!=-1){
        return ret;
    }
    if(j-i+1<3){
        return ret=0;
    }

    if(j-i+1==3){
        return ret=getsum(i,i+1,i+2);
    }

    int ans=(int)2e9;
    
    for(int s=i+1;s<=j-1;s++){
        ans=min(ans,dp(i,s)+dp(s,j)+getsum(i,s,j));
    }
    return ret=ans;

}

int main() {
    
    int n;
    cin>>n;
    cache=vector<vector<int>>(n,vector<int>(n,-1));
    arr=vector<int>(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<dp(0,n-1);
    


	
}