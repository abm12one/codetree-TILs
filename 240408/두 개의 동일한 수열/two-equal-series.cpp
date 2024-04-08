#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>arr;
vector<int>arr2;
int main() {
    int n;
    cin>>n;
    arr=vector<int>(n);
    arr2=vector<int>(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }

    sort(arr.begin(),arr.end());
    sort(arr2.begin(),arr2.end());
    int f=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=arr2[i]){
            f=1;
            break;
        }
    }
    if(f==0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

}