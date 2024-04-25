#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int>dist;
vector<int>charge;
vector<pair<int,int>>arr;
vector<int>minch;
int n;
int main() {
    
    cin>>n;
    dist=vector<int>(n);
    charge=vector<int>(n+1);
    minch=vector<int>(n+1);
    for(int i=1;i<n;i++){
        cin>>dist[i];
    }
    for(int i=1;i<n+1;i++){
        cin>>charge[i];
    }
    minch[1]=charge[1];
    for(int i=2;i<=n;i++){
        minch[i]=min(minch[i-1],charge[i]);
    }
    long ans=0;
    for(int i=1;i<n;i++){
        ans+=(long)minch[i]*dist[i];
    }
    cout<<ans;

}