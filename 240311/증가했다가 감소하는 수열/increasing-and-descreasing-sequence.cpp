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
    dif=vector<int>(n);
    
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        
        arr[i]=temp;
        dif[i]=temp;
    }
    sort(dif.begin(),dif.end());
    int flag=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=dif[i]){
            flag=1;
        }
    }
    int ans=1;
    if(flag==1){
        cout<<0<<'\n';
    }
   
    else{
        for(int i=0;i<n-2;i++){
            ans*=3;
            ans%=10007;

        }
        cout<<ans<<'\n';
    }
    
	
}