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

using namespace std;
int n;
vector<vector<int>>map;
vector<vector<int>>dp;

int cnt(int num){
    int ret=0;
    for(int i=0;i<n;i++){
        if(num&(1<<i))ret++;
    }
    return ret;
}

int main() {
    

    cin>>n;
    map=vector<vector<int>>(16,vector<int>(16));
    dp=vector<vector<int>>(1<<16,vector<int>(16+1,-987654321));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }

    dp[0][0]=0;
    
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){

            if(dp[i][j]==-987654321)continue;;
            

            for(int k=0;k<n;k++){
                if(i&(1<<k))continue;
                dp[i+(1<<k)][j+1]=max(dp[i+(1<<k)][j+1],dp[i][j]+map[j][k]);
            }
        }
                
        

    }
    
    int ans=0;
    cout<<dp[(1<<n)-1][n];
    
    


 
}