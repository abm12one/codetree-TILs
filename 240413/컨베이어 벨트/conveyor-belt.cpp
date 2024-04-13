#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<int>arr;

int main() {

    int n,t;
    cin>>n>>t;

    arr=vector<int>(2*n);

    for(int i=0;i<2*n;i++){
        cin>>arr[i];
    }
    

    while(t--){
        int temp=arr[2*n-1];

        for(int i=2*n-2;i>=0;i--){
            arr[i+1]=arr[i];
        }

        arr[0]=temp;

        
    }

    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    for(int i=n;i<2*n;i++){
        cout<<arr[i]<<' ';
    }



    
    

 


}