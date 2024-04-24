#include <iostream>
#include <vector>
using namespace std;
int f=0;
int s=0;
int main() {
    string str;
    cin>>str;
    for(int i=0;i<str.size()-1;i++){
        if(str[i]=='('){
            if(str[i]==str[i+1]){
                f++;
            }
        }
        else if(str[i]==')'){
            if(str[i]==str[i+1]){
                s++;
            }
        }
    }
    cout<<s*f;
}