#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
using namespace std;
int q;
int n,m;
vector<int>id;
vector<int>w;
vector<int>head;
vector<int>tail;
unordered_map<int,int>boxw;
unordered_map<int,int>pre,nxt;
unordered_map<int,int>belt;
vector<int>malf;
void sett(int n,int m){
    id=vector<int>(n+1);
    w=vector<int>(n+1);
    malf=vector<int>(m+1);
    head=vector<int>(m+1);
    tail=vector<int>(m+1);
    for(int i=1;i<=n;i++){
        cin>>id[i];
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        boxw[id[i]]=w[i];
    }
    int s=1;

    for(int i=1;i<=m;i++){
        head[i]=id[s];
        belt[id[s]]=i;
        
        s++;
        for(int j=2;j<=n/m;j++){
            int now=s;
            belt[id[s]]=i;
            
            nxt[id[s-1]]=id[s];
            pre[id[s]]=id[s-1];
            s++;
        }
        tail[i]=id[s-1];

        
        
    }

    return;


}

void hacha(int wmax){
    
    //cout<<wmax<<'\n';
    
    int ret=0;
    for(int i=1;i<=m;i++){
        if(malf[i]==1)continue;
        int nowid=head[i];
        int noww=boxw[nowid];
        
        if(noww>wmax){
            int prehead=head[i];
            head[i]=nxt[prehead];
            nxt.erase(prehead);
            pre.erase(head[i]);

            int pretail=tail[i];
            nxt[pretail]=prehead;
            pre[prehead]=pretail;
            tail[i]=prehead;

        }
        else{
            ret+=noww;
            belt.erase(head[i]);

            int prehead=head[i];
            head[i]=nxt[head[i]];
            nxt.erase(prehead);
            pre.erase(head[i]);
        }

    }
    cout<<ret<<'\n';
    
    return;

}

void erase(int rid){
    if(belt.find(rid)==belt.end()){
        cout<<-1<<'\n';
        return;
    }
    cout<<rid<<'\n';
    int prev=pre[rid];
    int next=nxt[rid];
    pre[next]=prev;
    nxt[prev]=next;
    nxt.erase(rid);
    pre.erase(rid);
    belt.erase(rid);
    return;
}

void check(int fid){
    if(belt.find(fid)==belt.end()){
        cout<<-1<<'\n';
        return;
    }

    int now=belt[fid];
    cout<<now<<'\n';

    int pretail=tail[now];
    int prehead=head[now];

    nxt[pretail]=prehead;
    pre[prehead]=pretail;

    int newtail=pre[fid];
    int newhead=fid;

    nxt.erase(newtail);
    pre.erase(newhead);
    head[now]=newhead;
    tail[now]=newtail;

    return;


}

void move(int now,int next){
    int here=head[now];

    while(1){
        
        if(nxt.find(here)==nxt.end()){
            break;
        }
        belt[here]=next;
        here=nxt[here];
    }

    int nowhead=head[now];
    int nexttail=tail[next];
    nxt[nexttail]=nowhead;
    pre[nowhead]=nexttail;
    tail[next]=tail[now];
    return;

}

void as(int bnum){
    
    if(malf[bnum]==1){
        cout<<-1<<"\n";
        return;
    }
    malf[bnum]=1;
    
    cout<<bnum<<'\n';
    
    for(int i=bnum+1;i<=m;i++){
        if(malf[i]==0){
            move(bnum,i);
            return;
        }
    }

    for(int i=1;i<bnum;i++){
        if(malf[i]==0){
            move(bnum,i);
            return;
        }
    }
    
    return;
   
}

void pri(int now){
    int here=head[now];
    //cout<<head[now]<<"  "<<tail[now]<<"\n";
    while(1){
        
        cout<<here<<' ';
        if(nxt.find(here)==nxt.end()){
            break;
        }
        here=nxt[here];
    }

    cout<<'\n';
    return;
}

void pr(){
    for(int i=1;i<=m;i++){
        if(malf[i]==1)continue;
        pri(i);
    }
}

int main(){
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int com;
        cin>>com;
        
       
        if(com==100){
            
            cin>>n>>m;
            sett(n,m);
        }
        
        else if(com==200){
            int wmax;
            cin>>wmax;
            hacha(wmax);
        }
        
       
        else if(com==300){
            int rid;
            cin>>rid;
            erase(rid);
        }
        
        else if(com==400){
            int fid;
            cin>>fid;
            check(fid);
        }
        
        else if(com==500){
            int bnum;
            cin>>bnum;
            as(bnum);
        }
        //pr();
        //cout<<'\n';
        
    }
    return 0;

}