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

int main() {
    
    int n;
    cin>>n;

    arr=vector<int>(n);

    for(int i=0;i<n;i++){
        
        int r;
        cin>>r;
        
        for(int j=0;j<r;j++){
            int temp;
            cin>>temp;
            arr[i]|=(1<<temp);
        }

    }

    int ans=0;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(!(arr[i]&arr[j])){
                ans++;
            }
        }
    }
   
    cout<<ans<<'\n';
	
}