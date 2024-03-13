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
string str;
vector<vector<int>>dp;

int getsum(int i,int k){
    if(str[i]=='('){
        if(str[k]==')'||str[k]=='?')return 1;
        else return 0;
    }
    else if(str[i]=='{'){
        if(str[k]=='}'||str[k]=='?')return 1;
        else return 0;
    }
    else if(str[i]=='['){
        if(str[k]==']'||str[k]=='?')return 1;
        else return 0;
    }
    else if(str[i]=='?'){
        if(str[k]=='?')return 3;
        else if(str[k]==')'||str[k]=='}'||str[k]==']'){
            return 1;
        }
        return 0;
    }
    
    return 0;
    

}

int main() {
    
    cin>>str;
    int n=str.size();

    dp=vector<vector<int>>(n+1,vector<int>(n+1,0));
    
    for(int i=0;i<n;i++){
        dp[i][i]=0;
        dp[i+1][i]=1;
    }    

    for(int gap=2;gap<=n;gap++){

        for(int i=0;i<=n-gap;i++){

            int j=i+gap-1;

            for(int k=i+1;k<=j;k++){
                dp[i][j]+=getsum(i,k)*dp[i+1][k-1]*dp[k+1][j];
                dp[i][j] %= 10007;
            }

        }
    }
    cout<<dp[0][n-1];


}