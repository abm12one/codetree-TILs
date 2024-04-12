#include <iostream>
#include <vector>
#include <algorithm>
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
    return a.height<b.height;
}

vector<node>arr;

int main() {

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        string str;
        int a,b;
        cin>>str>>a>>b;
        arr.push_back(node(str,a,b));



    }
    sort(arr.begin(),arr.end(),cmp);

    for(int i=0;i<n;i++){
        cout<<arr[i].name<<" "<<arr[i].height<<' '<<arr[i].weight<<'\n';
    }

    


    
}