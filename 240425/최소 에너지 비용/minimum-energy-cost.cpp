#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
vector<int>dist;
vector<int>charge;
vector<pair<int,int>>arr;
vector<int>p;

int main() {
    
    cin>>n;
    dist=vector<int>(n);
    charge=vector<int>(n+1);
    p=vector<int>(n+1);
    for(int i=1;i<n;i++){
        cin>>dist[i];
        p[i]=p[i-1]+dist[i];
    }
    for(int i=1;i<=n;i++){
        cin>>charge[i];
    }
    for(int i=1;i<=n;i++){
        arr.push_back(make_pair(charge[i],i));
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        int id,ch;
        tie(ch,id)=arr[i];
        //cout<<ch<<" "<<id<<'\n';
    }
    //cout<<'\n';
    
   

    int e=n;
    long ans=0;
    for(int i=0;i<arr.size();i++){
        int id,ch;
        tie(ch,id)=arr[i];
        if(id<e){
            ans+=(long)ch*(p[e-1]-p[id-1]);
            //cout<<e<<" "<<id<<'\n';
            //cout<<ans<<'\n';
            e=id;
        }

    }
    cout<<ans;

}