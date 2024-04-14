#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
vector<int>arr;
int sn;

void sol(int a,int b){
    //cout<<a<<' '<<b<<"\n";
    for(int i=a;i<=b;i++){
        arr[i]=0;
    }

    for(int i=b+1;i<=sn;i++){
        arr[i+a-b-1]=arr[i];
    }
    sn-=(b-a+1);
    //cout<<sn<<'\n';

}

int main() {
    int n,m;
    cin>>n>>m;

    if(m==1){
        cout<<0;
        return 0;
    }

    arr=vector<int>(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sn=n;

    while(1){
        int s=-1;
        int e=-1;
        int temp=arr[1];
        s=1;
        int f=0;
        int a=0;
        int b=0;

        int cnt=1;
        for(int i=2;i<=sn;i++){
            if(arr[i]!=temp){
                if(cnt>=m){
                    e=i-1;
                    a=s;
                    b=e;
                }
                e=i-1;
                s=i;
                cnt=1;
                temp=arr[i];
                
            }
            else if(arr[i]==temp){
                if(a!=0||b!=0){
                    f=1;
                    break;
                }
                cnt++;
            }
            
        }

        if(f==0&&cnt>=m){
            a=s;
            b=sn;
        }

        if(a==0&&b==0){
            break;
        }
        sol(a,b);

        

    }

    
    cout<<sn<<'\n';
    
    
    for(int i=1;i<=sn;i++){
        cout<<arr[i]<<'\n';
    }
    


    
    

}