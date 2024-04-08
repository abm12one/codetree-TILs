#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>arr;

int main() {
    int n,k;
    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }

    sort(arr.begin(),arr.end());
    cout<<arr[k-1];

}