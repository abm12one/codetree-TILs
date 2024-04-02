#include <iostream>
#include <vector>

using namespace std;

vector<int>arr;
vector<int>psum;

int main() {
    
    int n,q;
    cin>>n>>q;

    arr=vector<int>(100001);
    psum=vector<int>(100001);

    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        arr[t]=1;
        
    }
    for(int i=1;i<=100000;i++){
        psum[i]=psum[i-1]+arr[i];
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<psum[b]-psum[a-1]<<'\n';
    }
    








}