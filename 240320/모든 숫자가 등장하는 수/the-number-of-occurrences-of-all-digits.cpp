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

vector<vector<vector<int>>>dp;

int main() {
    
    int n;
    cin>>n;

    dp=vector<vector<vector<int>>>(n,vector<vector<int>>((1<<10),vector<int>(10,0)));
    
    
    for(int i=1;i<10;i++){
        dp[0][(1<<i)][i]=1;
    }
    
    for(int i=0;i<(1<<10);i++){

        for(int s=0;s<n-1;s++){
            
            for(int j=0;j<10;j++){
                if(dp[s][i][j] == 0)continue;

                if(i&(1<<j)){
                    
                    if(j<9){
                        int st=(i&~(1<<(j+1)))+(1<<(j+1));
                        dp[s+1][st][j+1]+=dp[s][i][j];
                        dp[s+1][st][j+1]%=10007;                        
                    }
                    if(j>0){
                        int st=(i&~(1<<(j-1)))+(1<<(j-1));
                        dp[s+1][st][j-1]+=dp[s][i][j];
                        dp[s+1][st][j-1]%=10007;  
                        
                    }

                }
            }


        }


    }
    int ans=0;
    for(int i=0;i<10;i++){
        ans+=dp[n-1][(1<<10)-1][i];
        ans%=10007;
    }
    cout<<ans;



    
    
    

 
}