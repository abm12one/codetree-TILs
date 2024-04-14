#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

string str;
int sn;
vector<char>arr;
int ans;

int findlen(int cnt){
    if(cnt>=10){
        return 2;
    }
    else if(cnt==0){
        return 0;
    }
    return 1;

}

int sol(){
    int sum=0;
    int cnt=1;
    char temp=arr[0];
    for(int i=1;i<sn;i++){
        if(arr[i]!=temp){
            
            sum+=findlen(cnt);
            //cout<<temp<<' '<<cnt<<' '<<findlen(cnt)<<"\n";
            sum++;
            cnt=1;
            temp=arr[i];
            
        }
        else{
            cnt++;
        }

    }
    sum++;
    sum+=findlen(cnt);
    //cout<<temp<<' '<<cnt<<' '<<findlen(cnt)<<"\n";
    return sum;

}

void shift(){

    char temp=arr[sn-1];

    for(int i=sn-2;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=temp;
    /*
    for(int i=0;i<sn;i++){
        cout<<arr[i];
    }
    cout<<'\n';
    */


    

}


int main() {

    cin>>str;
    sn=str.size();
    arr=vector<char>(sn);
    ans=987654321;

    for(int i=0;i<sn;i++){
        arr[i]=str[i];
    }
   

    for(int i=0;i<sn;i++){
        shift();
        ans=min(ans,sol());
    }
    cout<<ans<<'\n';
    
    
    
    

 


}