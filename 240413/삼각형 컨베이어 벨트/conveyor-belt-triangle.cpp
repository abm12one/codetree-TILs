#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<int>arr;

int main() {

    int n,t;
    cin>>n>>t;
    arr=vector<int>(n*3);
    for(int i=0;i<3*n;i++){
        cin>>arr[i];
    }
    while(t--){
        int temp=arr[3*n-1];
        for(int i=3*n-2;i>=0;i--){
            arr[i+1]=arr[i];
        }
        arr[0]=temp;
    }
    for(int i=0;i<3*n;i++){
        
        cout<<arr[i]<<' ';
        if((i+1)%n==0)cout<<'\n';
    }


    
    

 


}