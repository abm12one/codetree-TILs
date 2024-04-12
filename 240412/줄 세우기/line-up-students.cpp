#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

class node{
    public:
        int height;
        int weight;
        int id;

        node(int a,int b,int c){
            height=a;
            weight=b;
            id=c;
        }

};

bool cmp(node a,node b){
    if(a.height==b.height){
        if(a.weight==b.weight){
            return a.id<b.id;
        }
        return a.weight>b.weight;
    }
    return a.height>b.height;
}

vector<node>arr;

int main() {

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        
        int a,b;
        cin>>a>>b;
        arr.push_back(node(a,b,i+1));



    }
    sort(arr.begin(),arr.end(),cmp);

    for(int i=0;i<n;i++){
        
        cout<<arr[i].height<<' '<<arr[i].weight<<' '<<arr[i].id<<'\n';


    }

    


    
}