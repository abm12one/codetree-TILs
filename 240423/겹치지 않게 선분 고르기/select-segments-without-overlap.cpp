#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<pair<int,int>>arr;
int n;
int s=0;
int e=0;
void sol(){
    int cnt=0;
    for(int i=0;i<n;i++){
        int nowe,nows;
        tie(nowe,nows)=arr[i];

        if(nows>e){
            cnt++;
            e=nowe;

        }
    }
    cout<<cnt;
    return ;

}


int main(){

    cin>>n;
    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        arr.push_back(make_pair(e,s));
    }
    sort(arr.begin(),arr.end());
    sol();

}