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
vector<int>dif;
int main() {
    
    int n;
    cin>>n;
    arr=vector<int>(n);
    
    
    for(int i=0;i<n;i++){
        
        
        cin>>arr[i];
        
    }

    int ans=1;
    int cnt=0;
    if(arr[0]>arr[n-1]){
        cout<<0<<'\n';
    }
   
    else{
        for(int i=1;i<n-1;i++){
            if(arr[0]<arr[i]&&arr[i]<arr[n-1]){
                cnt++;
                //cout<<cnt<<' '<<arr[i]<<'\n';
                ans*=3;
                ans%=10007;
            }
            

        }
        cout<<ans<<'\n';
    }
    
	
}