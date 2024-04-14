#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<int>arr;
vector<int>arr2;
int cnt;
int n;
void sol(int a,int b){
    int num=b-a+1;
    cnt-=num;
    arr2=vector<int>(arr.size());
    for(int i=0;i<=a-1;i++){
        arr2[i]=arr[i];
    }
    int s=a;
    for(int i=b+1;i<arr.size();i++,s++){
        arr2[s]=arr[i];
    }

    for(int i=0;i<arr.size();i++){
        arr[i]=arr2[i];
    }


}

int main() {
    
    cin>>n;
    cnt=n;
    arr=vector<int>(n+1);
    
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<2;i++){
        int a,b;
        cin>>a>>b;
        sol(a,b);
    }
    cout<<cnt<<'\n';
    for(int i=1;i<=cnt;i++){
        cout<<arr[i]<<"\n";
    }



    
    
    
    

 


}