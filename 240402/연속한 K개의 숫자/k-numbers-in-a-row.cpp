#include <iostream>
#include <vector>

using namespace std;

vector<int>arr;
vector<int>psum;

int main() {
    
    int n,k,b;
    cin>>n>>k>>b;

    arr=vector<int>(n+1);
    psum=vector<int>(n+1);

    for(int i=0;i<b;i++){
        int t;
        cin>>t;
        arr[t]=1;
        
    }
    for(int i=1;i<=n;i++){
        psum[i]=psum[i-1]+arr[i];
    }
    int ans=1e9;
    for(int i=1;i+k-1<n+1;i++){
        ans=min(psum[i+k-1]-psum[i],ans);
    }
    cout<<ans<<'\n';








}