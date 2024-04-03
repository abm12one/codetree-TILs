#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

set<int>s;
unordered_map<int,int>m;
vector<pair<int,int>>arr;
vector<vector<int>>psum;

int n,q;

int low(int x){
    auto it=s.lower_bound(x);
    if(it==s.end()){
        return s.size()+1;
    }
    return m[*it];
}

int upp(int x){
    auto it=s.upper_bound(x);
    if(it==s.begin()){
        return 0;
    }
    it--;
    return m[*it];
}

int sol(int y1,int x1,int y2,int x2){
    int ly=low(y1);
    int lx=low(x1);
    int uy=upp(y2);
    int ux=upp(x2);

    return psum[uy][ux]-psum[uy][lx-1]-psum[ly-1][ux]+psum[ly-1][lx-1];


}

int main() {
    
    cin>>n>>q;
    
    
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr.push_back(make_pair(a,b));

        s.insert(a);
        s.insert(b);
    }
    
    int num=1;
    for(auto it=s.begin();it!=s.end();it++){
        m[*it]=num++;
    }
    
    psum=vector<vector<int>>(num+1,vector<int>(num+1));
    for(int i=0;i<n;i++){
        int a,b;
        tie(a,b)=arr[i];
        int y=m[a];
        int x=m[b];
        psum[y][x]++;
    }

   
    
    for(int i=1;i<=num;i++){
        for(int j=1;j<=num;j++){
            psum[i][j]+=psum[i][j-1]+psum[i-1][j]-psum[i-1][j-1];
        }
    }
    

    for(int i=0;i<q;i++){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        cout<<sol(y1,x1,y2,x2)<<'\n';

    }






}