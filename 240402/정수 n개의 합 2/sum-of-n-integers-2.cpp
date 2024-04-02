#include <iostream>
#include <vector>

using namespace std;

vector<int>arr;
vector<int>psum;

int main() {
    int n,k;
    cin>>n>>k;
    arr=vector<int>(n+1);
    psum=vector<int>(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        psum[i]=psum[i-1]+arr[i];
    }
    int ans=0;
    for(int s=n;s-k>=0;s--){
        ans=max(ans,psum[s]-psum[s-k]);
    }
    cout<<ans<<'\n';





}