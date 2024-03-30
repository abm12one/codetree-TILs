#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int>l;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        int num;
        cin>>str;
        if(str=="push_back"){
            cin>>num;
            l.push_back(num);
        }
        else if(str=="push_front"){
            cin>>num;
            l.push_front(num);
        }
        else if(str=="pop_front"){
            cout<<l.front()<<'\n';
            l.pop_front();
        }
        else if(str=="pop_back"){
            cout<<l.back()<<'\n';
            l.pop_back();
        }
        else if(str=="front"){
            cout<<l.front()<<'\n';;
        }
        else if(str=="back"){
            cout<<l.back()<<'\n';;
        }
        else if(str=="size"){
            cout<<l.size()<<'\n';;
        }
        else if(str=="empty"){
            cout<<l.empty()<<'\n';;
        }






        
    }



}