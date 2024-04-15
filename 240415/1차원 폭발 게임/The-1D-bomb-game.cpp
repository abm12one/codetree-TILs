#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n,m;
int sn;
vector<int>arr;

void erase(int a,int b){
    //cout<<"erase "<<a<<' '<<b<<'\n';
    for(int i=a;i<=b;i++){
        arr[i]=0;
    }
    sn-=(b-a+1);
    return ;
}

void recycle(){
    vector<int>arr2(n);
    for(int i=0;i<n;i++){
        arr2[i]=arr[i];
    }
    int s=0;
    for(int i=0;i<n;i++){
        if(arr2[i]==0)continue;
        arr[s]=arr2[i];
        s++;
    }
    /*
    for(int i=0;i<sn;i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n'*/
    
    return ;

}

int main() {
    
    cin>>n>>m;

    if(m==1){
        cout<<0;
        return 0;
    }
    sn=n;
    arr=vector<int>(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    while(1){
        int f=0;
        int s=0;
        int cnt=1;
        int len=sn;
        for(int i=1;i<len;i++){
            if(arr[i]==arr[s]){
                cnt++;
            }
            else if(arr[i]!=arr[s]){
                if(cnt>=m){
                    f=1;
                    
                    erase(s,i-1);
                }
                cnt=1;
                s=i;
            }
        }
        //cout<<s<<" "<<len-1<<' '<<m<<'\n';
        if(cnt>=m){
            erase(s,len-1);
            f=1;
        }
        if(f==0)break;
        recycle();

    }
    cout<<sn<<'\n';
    for(int i=0;i<sn;i++){
        cout<<arr[i]<<'\n';
    }
    
    


    
    

}