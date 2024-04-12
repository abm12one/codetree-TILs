#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string>arr;

int main() {
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    int sn=str.size();
    
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;

        if(temp.substr(0,sn)==str){
            arr.push_back(temp);
        }

    }
    sort(arr.begin(),arr.end());
    cout<<arr[k-1];
   

    


    
}