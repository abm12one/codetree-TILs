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
#include<unordered_map>
//#include< map>
#include<unordered_set>
#include<set>
#define MAX_M 100000

using namespace std;

string text;
int n,m;
int main() {
	cin>>text;
    int n=text.size();
    text='#'+text;

    cin>>m;
    vector<vector<int>>ispos(n+1,vector<int>(m+1,0));
    vector<int>psize(m+1);

    for(int id=1;id<=m;id++){
        string pattern;
        cin>>pattern;
        
        int pn=pattern.size();
        psize[id]=pn;

        pattern='#'+pattern;

        vector<int>f(pn+1);

        f[0]=-1;

        for(int i=1;i<=pn;i++){
            int j=f[i-1];
            while(j>=0&&pattern[i]!=pattern[j+1]){
                j=f[j];
            }
            f[i]=j+1;
        }
        int j=0;
        for(int i=1;i<=n;i++){
            while(j>=0&&text[i]!=pattern[j+1]){
                j=f[j];
            }
            j++;;

            if(j==pn){
                ispos[i][id]=1;
                j=f[j];

            }


        }

    }
    vector<int>dp(n+1,0);

    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        for(int id=1;id<=m;id++){
            int pn=psize[id];
            if(ispos[i][id]==1){
                dp[i]=max(dp[i],dp[i-pn]+pn);
            }
            
        }
    }
    cout<<dp[n]<<'\n';

    

	
}