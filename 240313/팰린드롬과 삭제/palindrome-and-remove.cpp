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

vector<vector<int>>dp;

int main() {
    
    string str;
    cin>>str;

    int n=str.size();
    dp=vector<vector<int>>(n,vector<int>(n,(int)1e9));
    
    for(int i=0;i<n;i++){
        dp[i][i]=0;
    }

    for(int i=0;i<n-1;i++){
        if(str[i]==str[i+1]){
            dp[i][i+1]=0;
        }
        else{
            dp[i][i+1]=1;
        }
    }

    for(int gap=3;gap<=n;gap++){

        for(int i=0;i<=n-gap;i++){

            int j=i+gap-1;

            dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            dp[i][j]=min(dp[i][j],dp[i+1][j]+1);

            if(str[i]==str[j]){
                dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
            }
        }


    }
    cout<<dp[0][n-1];


	
}