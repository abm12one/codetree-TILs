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

int arr[200];
int dp[200][200][11];
bool pos[200][200][11];


int main() {

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        pos[i][i][arr[i]]=true;
        
        if(i+1!=n){
            dp[i][i+1][abs(arr[i]-arr[i+1])]=arr[i]+arr[i+1];
            pos[i][i+1][abs(arr[i]-arr[i+1])]=true;
        }
    }
    
    for(int gap=3;gap<=n;gap++){
        for(int i=0;i<=n-gap;i++){
            int j=i+gap-1;

            for(int k=i;k<j;k++){

                for(int x=0;x<=10;x++){

                    if(!pos[i][k][x])continue;

                    for(int y=0;y<=10;y++){

                        if(!pos[k+1][j][y])continue;

                        pos[i][j][abs(x-y)]=true;
                        dp[i][j][abs(x-y)]=max(dp[i][j][abs(x-y)],dp[i][k][x]+dp[k+1][j][y]+x+y);
                    }
                }
            }

        }
    }
    int ans=0;
    for(int i=0;i<=10;i++){
        ans=max(ans,dp[0][n-1][i]);
    }
    cout<<ans<<'\n';

}