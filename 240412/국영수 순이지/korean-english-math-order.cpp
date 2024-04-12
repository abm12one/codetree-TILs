#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

class node{
    public:
        string name;
        int kor;
        int eng;
        int math;

        node(string a,int b,int c,int d){
            name=a;
            kor=b;
            eng=c;
            math=d;
        }

};

bool cmp(node a,node b){
    if(a.kor==b.kor){
        if(a.eng==b.eng){
            return a.math>b.math;
        }
        return a.eng>b.eng;
    }
    return a.kor>b.kor;
}

vector<node>arr;

int main() {

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        string str;
        int a,b,c;
        cin>>str>>a>>b>>c;
        arr.push_back(node(str,a,b,c));



    }
    sort(arr.begin(),arr.end(),cmp);

    for(int i=0;i<n;i++){
        
        cout<<arr[i].name<<' '<<arr[i].kor<<' '<<arr[i].eng<<' '<<arr[i].math<<'\n';


    }

    


    
}