#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char>arr;

int main() {
    string str;
    cin>>str;
    
    for(int i=0;i<str.size();i++){
        char c=str[i];
        arr.push_back(c);


    }
    sort(arr.begin(),arr.end());

    for(int i=0;i<str.size();i++){
        cout<<arr[i];


    }

}