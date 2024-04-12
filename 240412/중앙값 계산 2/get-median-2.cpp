#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>arr;

int main() {
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        arr.push_back(t);
        if(i%2==1){
            sort(arr.begin(),arr.end());
            cout<<arr[(i+1)/2-1]<<' ';
        }
    }
   

    


    
}