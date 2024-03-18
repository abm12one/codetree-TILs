#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cmath>
#include<limits.h>
#include<cassert>
//#include<unordered_map>
//#include<map>
#include<unordered_set>
#include<set>
#define MAX_M 100000

using namespace std;

int main() {
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        int t;
        
        if(temp=="add"){
            cin>>t;
            ans&=~(1<<t);
            ans|=(1<<t);
        }
        else if(temp=="delete"){
            cin>>t;
            ans&=~(1<<t);
           
        }
        else if(temp=="print"){
            cin>>t;
            if(ans&(1<<t)){
                cout<<1<<"\n";
            }
            else{
                cout<<0<<"\n";
            }
        }
        else if(temp=="toggle"){
            cin>>t;
            if(ans&(1<<t)){
                ans&=~(1<<t);
            }
            else{
                ans|=(1<<t);
            }

        }
        else if(temp=="clear"){
            ans=0;
        }


    }
	
}