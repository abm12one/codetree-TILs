#include <iostream>
#include <vector>
using namespace std;
int n,k;

vector<int>frag;
vector<int>people;
int beg;
int endd;

void move(){
    
    if(people[endd]==1){
        people[endd]=0;
    }
    
    beg-=1;
    endd-=1;
    
    if(beg==0){
        beg=2*n;
    }
    if(endd==0){
        endd=2*n;
    }
    return;
}

void pr(){
    for(int i=1;i<=2*n;i++){
        cout<<frag[i]<<' ';
    }
    cout<<'\n';
}

void pr2(){
    for(int i=1;i<=2*n;i++){
        cout<<people[i]<<' ';
    }
    cout<<'\n';
}

void movepeople(){
    int now=endd;
    
    for(int i=1;i<=n;i++){
        //cout<<now<<"\n";
        
        if(people[now]==1){
            if(now==endd){
                people[now]=0;
            }
            else{
                int next=now+1;
                if(next==2*n+1){
                    next=1;
                }
                if(people[next]==0&&frag[next]!=0){
                    //cout<<now<<' '<<next<<'\n';
                    people[now]=0;
                    people[next]=1;
                    frag[next]--;;
                    
                }
                
            }
        }
        if(people[endd]==1){
            people[endd]=0;
        }
        //pr();
        //pr2();
        now--;
        if(now==0){
            now=2*n;
        }

    }
    //cout<<'\n';
    if(frag[beg]!=0&&people[beg]==0){
        people[beg]=1;
        frag[beg]--;
    }
    return;
}



int check(){
    int cnt=0;
    for(int i=1;i<=2*n;i++){
        if(frag[i]==0){
            cnt++;
        }
    }
    return cnt;
}

void sol(){
    move();
    movepeople();

}

int main() {
    
    cin>>n>>k;
    beg=1;
    endd=n;
    frag=vector<int>(2*n+1);
    people=vector<int>(2*n+1);
    for(int i=1;i<=2*n;i++){
        cin>>frag[i];
    }
    int rep=0;
    while(1){
        rep++;
        sol();
        //pr();
        //pr2();
        int ans=check();
        if(ans>=k)break;
    }
    cout<<rep;

}