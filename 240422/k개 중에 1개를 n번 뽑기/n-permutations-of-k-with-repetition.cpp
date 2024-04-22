#include <iostream>
#include <vector>
using namespace std;
int n,k;
vector<int>arr;
void bt(int num){
    if(num==n){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<' ';
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=k;i++){
        arr.push_back(i);
        bt(num+1);
        arr.pop_back();
    }
    return;

}

int main() {
    
    cin>>k>>n;
    
    bt(0);
}