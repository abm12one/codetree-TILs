#include <iostream>
#include <vector>

using namespace std;
vector<int>arr;

int main() {
    
    int n,k;
    cin>>n>>k;

    arr=vector<int>(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int i=1;
    int j=1;
    int sum=arr[1];
    int ans=0;
    while(i<=j&&j<=n){
        if(sum==k){
            ans++;
            
            sum-=arr[i];
            i++;
        }
        else if(sum<k){
            j++;
            sum+=arr[j];
        }
        else if(sum>k){
            sum-=arr[i];
            i++;
        }


    }
    cout<<ans<<'\n';







}