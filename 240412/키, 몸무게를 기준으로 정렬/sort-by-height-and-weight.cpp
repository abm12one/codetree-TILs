#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

class node{
    public:
        string name;
        int height;
        int weight;
        

        node(string a,int b,int c){
            name=a;
            height=b;
            weight=c;
            
        }

};

bool cmp(node a,node b){
    if(a.height==b.height){
        return a.weight>b.weight;
    }
    return a.height<b.height;
}



vector<node>arr;

int main() {

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        string a;
        int b;
        int c;

        cin>>a>>b>>c;
        arr.push_back(node(a,b,c));



    }
    
    sort(arr.begin(),arr.end(),cmp);

    for(int i=0;i<n;i++){

        cout<<arr[i].name<<' '<<arr[i].height<<' '<<arr[i].weight<<'\n';
    }
    
    


    
}