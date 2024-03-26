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

#define MAX_K 100

using namespace std;

vector<vector<int>>pg;
vector<vector<int>>dp;

int main() {
    int n;
    cin>>n;
    dp=vector<vector<int>>(MAX_K+1,vector<int>(1<<(n+1)));
    pg=vector<vector<int>>(MAX_K+1);

    for(int i=1;i<=n;i++){
        int m;
        cin>>m;
        while(m--){
            int temp;
            cin>>temp;
            pg[temp].push_back(i);
        }
    }

    dp[0][1]=1;

    for(int i=0;i<MAX_K;i++){
        for(int j=0;j<(1<<(n+1));j++){
            if(dp[i][j]==0)continue;

            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=10007;

            for(int id=0;id<pg[i+1].size();id++){
                int k=pg[i+1][id];
                if(j&(1<<k))continue;
                dp[i+1][j|(1<<k)]+=dp[i][j];
                dp[i+1][j|(1<<k)]%=10007;
                

            }


        }
    }
    cout<<dp[MAX_K][(1<<(n+1))-1];
   



    

 
}