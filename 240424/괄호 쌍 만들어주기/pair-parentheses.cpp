#include <iostream>
#include <vector>
using namespace std;
vector<int>f;
vector<int>s;
int ans=0;
void sol(){
    
    for(int i=0;i<f.size();i++){
        for(int j=0;j<s.size();j++){
            if(f[i]<s[j]){
                ans+=s.size()-j;
                break;
            }
            
        }
    }
    return;
}


int main() {
    string str;
    cin>>str;
    for(int i=0;i<str.size()-1;i++){
        if(str[i]=='('){
            if(str[i]==str[i+1]){
                f.push_back(i);
            }
        }
        else if(str[i]==')'){
            if(str[i]==str[i+1]){
                s.push_back(i);
            }
        }
    }
    sol();
    cout<<ans;
}