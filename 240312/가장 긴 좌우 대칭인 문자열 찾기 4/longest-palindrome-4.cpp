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
bool dp[MAX_N][MAX_N];
string str;
int ans;
int n;
int main() {

    
    cin>>str;
    n=str.size();
    ans=1;
    

    for(int i=0;i<n;i++){
        dp[i][i] = true;
    }

    for(int i=0;i<n-1;i++){
        if(str[i]==str[i+1]){
            dp[i][i+1]=true;
            ans=2;
        }
    }

    for(int gap=3;gap<=n;gap++){

        for(int i=0;i<=n-gap;i++){

            int j=i+gap-1;

            if(dp[i+1][j-1]&&str[i]==str[j]){
                dp[i][j]=true;
                ans=gap;
            }

        }
    }

    cout<<ans<<'\n';
    return 0;





	
}