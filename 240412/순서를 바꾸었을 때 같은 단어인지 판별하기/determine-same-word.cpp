#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char>arr;
vector<char>arr2;
int main() {

    string str;
    string str2;

    cin>>str>>str2;
    for(int i=0;i<str.size();i++){
        arr.push_back(str[i]);
    }
    for(int i=0;i<str2.size();i++){
        arr2.push_back(str2[i]);
    }

    sort(arr.begin(),arr.end());
    sort(arr2.begin(),arr2.end());

    if(arr.size()!=arr2.size()){
        cout<<"No";
        return 0;
    }
    int f=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=arr2[i]){
            f=1;
            break;
        }

    }
    if(f==0){
        cout<<"Yes";
    }
    else {
        cout<<"No";

    }
    return 0;


    


    
}