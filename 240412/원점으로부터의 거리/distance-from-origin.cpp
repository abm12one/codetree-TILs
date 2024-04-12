#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;

class node{
    public:
        int id;
        int dist;
        

        node(int a,int b){
            
            id=a;
            dist=b;
            
        }

};

bool cmp(node a,node b){
    if(a.dist==b.dist){
        return a.id<b.id;
    }
    return a.dist<b.dist;
}

vector<node>arr;

int main() {

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int y1,x1;
        cin>>y1>>x1;
        

        int d=abs(y1)+abs(x1);
        arr.push_back(node(i+1,d)) ;



    }

    sort(arr.begin(),arr.end(),cmp);

    for(int i=0;i<n;i++){
        
        cout<<arr[i].id<<'\n';
    }
    cout<<'\n';
    
    


    
}