#include <iostream>
#include <vector>

using namespace std;

vector<int>arr;
vector<int>aarr;
vector<int>barr;
vector<int>carr;
vector<int>pa;
vector<int>pb;
vector<int>pc;


int main() {
    
    int n,q;
    cin>>n>>q;

    arr=vector<int>(n+1);
    aarr=vector<int>(n+1);
    barr=vector<int>(n+1);
    carr=vector<int>(n+1);
    pa=vector<int>(n+1);
    pb=vector<int>(n+1);
    pc=vector<int>(n+1);
    
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]==1){
            aarr[i]=1;
        }
        else if(arr[i]==2){
            barr[i]=1;
        }
        else if(arr[i]==3){
            carr[i]=1;
        }

        pa[i]=pa[i-1]+aarr[i];
        pb[i]=pb[i-1]+barr[i];
        pc[i]=pc[i-1]+carr[i];
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;

        cout<<pa[b]-pa[a-1]<<' ';
        cout<<pb[b]-pb[a-1]<<' ';
        cout<<pc[b]-pc[a-1]<<'\n';
    }
    

}