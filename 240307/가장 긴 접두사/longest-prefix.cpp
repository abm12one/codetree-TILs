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
 
int lo,hi;
int ans=-1;
int main() {
	
	cin>>text;
    
    int n=text.size();
    text='#'+text;
    lo=1;
    hi=n;
    vector<int>f(MAX_M+1);

    while(lo<=hi){
        string pattern="";
        int mid=(lo+hi)/2;
        for(int i=mid;i>=1;i--){
            pattern+=text[i];
        }
        
        int pn=pattern.size();
        pattern='#'+pattern;

        
        f[0]=-1;

        for(int i=1;i<pn;i++){
            int j=f[i-1];
            while(j>=0&&pattern[i]!=pattern[j+1]){
                j=f[j];
            }
            

            f[i]=j+1;


        }
        int flag=0;
        int j=0;

        for(int i=1;i<=n;i++){

            while(j>=0&&text[i]!=pattern[j+1]){
                j=f[j];
            }
            j++;

            if(j==pn){
                flag=1;
                break;

            }


        }
        if(flag==1){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;

        }

    }
	
	cout<<ans<<'\n';
	
}