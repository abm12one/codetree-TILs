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

vector<vector<int>>map;
vector<vector<int>>dp;

int n,m;

int cnt(int lo,int num){
    int ret=0;
    
    return ret;
}

int main() {

    cin>>n>>m;

    map=vector<vector<int>>(n,vector<int>(m+1));
    dp=vector<vector<int>>(m+1,vector<int>(1<<n,-1));

    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];

        }
    }

    dp[0][0]=0;
    
    for(int i=0;i<m;i++){

        for(int j=0;j<(1<<n);j++){
            
            if(dp[i][j]==-1)continue;

            for(int k=0;k<(1<<n);k++){
                
                if(j&k)continue;

                int flag=0;
                for(int l=0;l<n-1;l++){
                    if((k&(1<<l))&&(k&(1<<(l+1)))){
                        flag=1;
                        break;
                    }
                }
                if(flag==1){
                   continue;
                }

                int f=0;
                for(int l=0;l<n;l++){
                    if((k&(1<<l))&&map[l][i+1]==1){
                        f=1;
                        break;
                    }
                }
                if(f==1){
                    continue;
                }
                int num=0;
                for(int l=0;l<n;l++){
                    if(k&(1<<l)){
                        num+=map[l][i+1];
                    }
                }


                dp[i+1][k]=max(dp[i+1][k],dp[i][j]+num);

            }

        }

    }
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        ans=max(ans,dp[m][i]);
    }
    cout<<ans<<'\n';

}