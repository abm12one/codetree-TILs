#include <iostream>
#include <vector>

using namespace std;
vector<int>buho;
vector<int>num;
int arr[6]={0,0,0,0,0,0};

int c2buho(char c){
    if(c=='+')return 0;
    else if(c=='-')return 1;
    else if(c=='*')return 2;

}
int c2num(char c){
    if(c=='a')return 0;
    else if(c=='b')return 1;
    else if(c=='c')return 2;
    else if(c=='d')return 3;
    else if(c=='e')return 4;
    else if(c=='f')return 5;
}
int ans=-987654321;
void sol(){

    int sum=arr[num[0]];
    for(int i=0;i<buho.size();i++){
        int tnum=arr[num[i+1]];
        int b=buho[i];
        if(b==0){
            sum+=tnum;
        }
        if(b==1){
            sum-=tnum;
        }
        if(b==2){
            sum*=tnum;
        }
    }
    //cout<<sum;
    ans=max(ans,sum);
    return;



}

void pr(){
    for(int i=0;i<6;i++){
        cout<<arr[i]<<' ';
    }
    cout<<"\n";
    return;
}
void prnum(){
    for(int i=0;i<num.size();i++){
        cout<<num[i]<<' ';
    }
    cout<<"\n";
    return;
}

void prbuho(){
    for(int i=0;i<buho.size();i++){
        cout<<buho[i]<<' ';
    }
    cout<<"\n";
    return;
}

void bt(int now){

    if(now==5){
        sol();
        //pr();
        return ;
    }

    for(int i=1;i<=4;i++){
        arr[now+1]=i;
        bt(now+1);
        arr[now+1]=0;
    }
    return ;

}

int main() {
    string str;
    cin>>str;
    
    for(int i=0;i<str.size();i++){
        if(i%2==0){
            
            num.push_back(c2num(str[i]));
            
        }
        else{
            
            buho.push_back(c2buho(str[i]));
            
        }
    }
    //prnum();
    //prbuho();
    //pr();

    bt(-1);
    cout<<ans;
    


}