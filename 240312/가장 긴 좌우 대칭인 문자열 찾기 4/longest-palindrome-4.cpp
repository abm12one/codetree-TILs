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
vector<vector<int>>dp;
int ans;
int n;
int main() {

    string str;
    cin>>str;
    n=str.size();
    ans=1;
    dp=vector<vector<int>>(n+1,vector<int>(n+1,0));

    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }

    for(int i=0;i<n-1;i++){
        if(str[i]==str[i+1]){
            dp[i][i+1]=1;
            ans=2;
        }
    }

    for(int gap=3;gap<=n;gap++){
        for(int i=0;i<=n-gap;i++){
            int j=i+gap-1;
            if(dp[i+1][j-1]&&str[i]==str[j]){
                dp[i][j]=1;
                ans=gap;
            }

        }
    }

    cout<<ans<<'\n';





	
}