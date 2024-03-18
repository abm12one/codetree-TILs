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
#define MAX_M 100000

using namespace std;

vector<int>arr;
int isok(int a,int b){
    if((a|b)==(a+b)){
        
        return 1;
    }
    
    return 0;
}

int main() {
    
    int n;
    cin>>n;
    
    arr=vector<int>(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    int ans=0;
    int flag=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                
                if(!isok(arr[i],arr[j]))continue;
                if(!isok(arr[i]+arr[j],arr[k]))continue;
                
                ans=max(ans,arr[i]+arr[j]+arr[k]);
                break;
            }
        }
    }
    cout<<ans<<'\n';

	
}