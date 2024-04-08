#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string>arr;

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        cout<<arr[i]<<'\n';
    }

}