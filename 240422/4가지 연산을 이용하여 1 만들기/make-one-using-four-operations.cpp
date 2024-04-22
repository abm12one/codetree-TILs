#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int>arr;
void sol(){

    for(int i=2;i<=n+1;i++){
        arr[i]=arr[i-1]+1;
        if(i%2==0){
            arr[i]=min(arr[i],arr[i/2]+1);
        }
        if(i%3==0){
            arr[i]=min(arr[i],arr[i/3]+1);
        }
    }

    for(int i=n;i>=1;i--){
        arr[i]=min(arr[i],arr[i+1]+1);
    }
    return;

}

int main() {
    
    cin>>n;
    arr=vector<int>(n+2);
    arr[1]=0;

    sol();
    cout<<arr[n]<<'\n';
}