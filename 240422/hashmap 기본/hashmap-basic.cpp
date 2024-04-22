#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int,int>map;
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        if(str=="add"){
            int k,v;
            cin>>k>>v;
            map[k]=v;
            
        }
        if(str=="find"){
            int k;
            cin>>k;
            if(map.find(k)!=map.end()){
                cout<<map[k]<<'\n';
            }   
            else{
                cout<<"None"<<'\n';
            }
        }
        if(str=="remove"){
            int k;
            cin>>k;
            map.erase(k);
        }

    }
}