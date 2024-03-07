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

string text,pattern;
int m;

int main() {
	cin>>text>>pattern;

    m=pattern.size();
    
    pattern='#'+pattern;

    vector<int>f(m+1);

    f[0]=-1;
    for(int i=1;i<=m;i++){
        int j=f[i-1];
        while(j>=0&&pattern[i]!=pattern[j+1]){
            j=f[j];
        }
        f[i]=j+1;

    }
    int cnt=0;
    while(1){
        int flag=0;
        int n=text.size();
        text='#'+text;
        int j=0;
        for(int i=1;i<=n;i++){
            while(j>=0&&text[i]!=pattern[j+1]){
                j=f[j];
            }

            j++;
            
            if(j==m){
                flag=1;
                string a=text.substr(1,i-m);
                string b="";
                if(i==n){
                    b="";
                }
                else{
                    b=text.substr(i+1);
                }
                text="";
                text=a+b;
                j=f[j];
                cnt++;
                break;
            }

        }

        if(flag==0)break;

    }
    
    
    cout<<cnt;
  



    

	
}