#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

unordered_map<int,int>m;
int n,k;
vector<int>bomb;
vector<int>arr;

int main() {
    
    cin>>n>>k;
    arr=vector<int>(n);
    bomb=vector<int>(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=n-1;i>=0;i--){
        int temp=arr[i];
        if(m.find(temp)==m.end()){
            bomb[i]=-1;
            m[temp]=i;
        }
        else{
            bomb[i]=m[temp];
            m[temp]=i;
        }
    }
    int ans=-1;
    /*
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<bomb[i]<<' ';
    }
    cout<<'\n';
    */
    for(int i=0;i<n;i++){
        if(bomb[i]==-1)continue;
        if(abs(i-bomb[i])<=k){
            ans=max(ans,arr[i]);
        }
    }
    cout<<ans;

}