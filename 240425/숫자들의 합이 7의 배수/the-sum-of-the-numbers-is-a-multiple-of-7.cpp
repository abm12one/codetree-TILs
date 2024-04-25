#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int>arr;
vector<int>p;
vector<int>last;
vector<int>pre;
int main() {
    
    cin>>n;
    arr=vector<int>(n+1);
    p=vector<int>(n+1);
    last=vector<int>(7,-1);
    pre=vector<int>(7,-1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        p[i]=p[i-1]+arr[i];
        p[i]%=7;
    }

    for(int i=1;i<n;i++){
        int temp=p[i];
        last[temp]=i;
    }
    for(int i=n;i>=1;i--){
        int temp=p[i];
        pre[temp]=i;
    }
    int ans=0;
    for(int i=0;i<7;i++){
        //cout<<i<<" "<<pre[i]<<' '<<last[i]<<'\n';
        if(pre[i]==-1)continue;
        ans=max(ans,last[i]-pre[i]);
    }
    cout<<ans;



}