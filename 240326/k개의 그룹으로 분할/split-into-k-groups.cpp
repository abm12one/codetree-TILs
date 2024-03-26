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

vector<int>a;
vector<int>dp;
int main() {
    int n,k;
    cin>>n>>k;
    
    int s=0;
    a=vector<int>(n);
    dp=vector<int>(1<<n,-1);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }

    if(s%k){
        cout<<"No";
        return 0;
    }

    dp[0]=0;
    
    int part=s/k;

    for(int i=0;i<(1<<n);i++){

        if(dp[i]==-1)continue;
        
        for(int j=0;j<n;j++){
            if(i&(1<<j))continue;

            int mod=dp[i]%part;
            if(mod+a[j]>part)continue;
            dp[i|(1<<j)]=dp[i]+a[j];

        }

    }
    if(dp[(1<<n)-1]==s){
        cout<<"Yes";
    }
    else {
        cout<<"No";
    }




    

 
}