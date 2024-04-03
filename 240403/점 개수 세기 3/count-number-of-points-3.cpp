#include<iostream>
#include<map>
#include<set>

using namespace std;

map<int,int>m;
set<int>s;

int main() {
    int n,q;
    cin>>n>>q;

    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        s.insert(t);
    }

    int num=0;
    for(auto it=s.begin();it!=s.end();it++){
        m[*it]=num++;
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<m[b]-m[a]+1<<'\n';
    }
    

    
    
}