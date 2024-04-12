#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

class node{
    public:
        int id;
        int num;
        

        node(int a,int b){
            id=a;
            num=b;
            
        }

};

bool cmp(node a,node b){
    if(a.num==b.num){
        return a.id<b.id;
    }
    
    return a.num<b.num;
}

vector<node>arr;
vector<int>ans;

int main() {

    int n;
    cin>>n;
    ans=vector<int>(n+1);

    for(int i=0;i<n;i++){
        int t;
        cin>>t;

        
        arr.push_back(node(i+1,t));



    }
   
    sort(arr.begin(),arr.end(),cmp);

    for(int i=0;i<n;i++){
        int tid=arr[i].id;
        ans[tid]=i+1;

    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    
    


    
}