#include <iostream>
#include <vector>
using namespace std;
int n;
int ans=0;
void bt(int num){
    if(num<0){
        return;
    }
    if(num==0){
        ans++;
        return;
    }
    for(int i=1;i<=4;i++){
        bt(num-i);
    }
    return;

}
int main() {
    
    cin>>n;
    bt(n);
    cout<<ans;

}