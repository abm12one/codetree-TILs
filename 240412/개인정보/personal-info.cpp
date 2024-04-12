#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

class node{
    public:
        string name;
        int height;
        double weight;
        

        node(string a,int b,double c){
            name=a;
            height=b;
            weight=c;
            
        }

};

bool cmp(node a,node b){
    return a.name<b.name;
}

bool cmp2(node a,node b){
    return a.height>b.height;
}

vector<node>arr;

int main() {

    int n=5;

    for(int i=0;i<n;i++){
        string a;
        int b;
        double c;

        cin>>a>>b>>c;
        arr.push_back(node(a,b,c));



    }
    cout<<"name"<<'\n';
    sort(arr.begin(),arr.end(),cmp);

    for(int i=0;i<n;i++){
        cout<<fixed;
        cout.precision(1);
        cout<<arr[i].name<<' '<<arr[i].height<<' '<<arr[i].weight<<'\n';
    }
    cout<<'\n';
    cout<<"height"<<'\n';

    sort(arr.begin(),arr.end(),cmp2);

    for(int i=0;i<n;i++){
        cout<<fixed;
        cout.precision(1);
        cout<<arr[i].name<<' '<<arr[i].height<<' '<<arr[i].weight<<'\n';
    }

    


    
}