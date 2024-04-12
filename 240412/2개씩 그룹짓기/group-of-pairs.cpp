#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>arr;

int main() {

    int n;
    cin>>n;
    for(int i=0;i<2*n;i++){
        int t;
        cin>>t;

        arr.push_back(t);
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    for(int i=0;i<n;i++){
        int t=arr[i]+arr[2*n-1-i];
        ans=max(ans,t);
    }
    cout<<ans;
    
}