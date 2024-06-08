#include <iostream>
#include <vector>
#include <tuple>
#include <map>
using namespace std;
int q;
int n,m;
vector<vector<pair<long,long>>>belt;
vector<long>id;
vector<long>weight;

vector<pair<long,long>>temp;
vector<int>malfun;
map<long,int>smap;

void sett(int n,int m){
    
    belt=vector<vector<pair<long,long>>>(m+1,vector<pair<long,long>>());
    id=vector<long>(n+1);
    weight=vector<long>(n+1);
    
    for(int i=1;i<=n;i++){
        cin>>id[i];
    }

    for(int i=1;i<=n;i++){
        cin>>weight[i];
    }

    int s=1;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n/m;j++){
            smap[id[s]]=i;
            belt[i].push_back(make_pair(id[s],weight[s]));
            s++;
        }
    }

    

    return;

}
//2
void hacha(int wmax){
    long ret=0;
    for(int i=1;i<=m;i++){
        if(malfun[i]==1)continue;
        if(belt[i].size()==0)continue;
        long fid;
        long fw;
        tie(fid,fw)=belt[i][0];
        
        ret+=fw;
        if(fw>wmax){
            belt[i].push_back(make_pair(fid,fw));
            ret-=fw;
        }
        else{
            smap.erase(fid);
        }
        
        temp=vector<pair<long,long>>();
        
        for(int j=1;j<belt[i].size();j++){
            temp.push_back(belt[i][j]);
        }

        belt[i]=temp;

    }
    cout<<ret<<'\n';
    return;
}

void boxerase(int b,int now){

    for(int i=now+1;i<belt[b].size();i++){
        long nid,nw;
        tie(nid,nw)=belt[b][i];
        belt[b][i-1]=make_pair(nid,nw);
    }

    belt[b].pop_back();
    return;

}
//3
void erase(long rid){
    
    if(smap.find(rid)==smap.end()){
        cout<<-1<<'\n';
        return ;
    }
    long b=smap[rid];

    for(int i=0;i<belt[b].size();i++){
        long id,w;
        tie(id,w)=belt[b][i];
        if(id==rid){
            
            boxerase(b,i);
            smap.erase(rid);
            cout<<rid<<'\n';
            return ;
        }
    }
    

    return;
}

void move(int b,int now){
    
    temp=vector<pair<long,long>>();
    for(int i=now;i<belt[b].size();i++){
        temp.push_back(belt[b][i]);
    }


    for(int i=0;i<now;i++){
        temp.push_back(belt[b][i]);
    }

    

    belt[b]=temp;
    return;


}
//4
void check(long fid){
    
    
    if(smap.find(fid)==smap.end()){
        cout<<-1<<'\n';
        return ;
    }
    long b=smap[fid];
    cout<<b<<"\n";

    for(int i=0;i<belt[b].size();i++){
        long id,w;
        tie(id,w)=belt[b][i];
        if(id==fid){
            
            move(b,i);
            
            return;
                
        }
       
    }

    return;

}

void change(int next,int now){

    for(int i=0;i<belt[now].size();i++){
        belt[next].push_back(belt[now][i]);
        long id,w;
        tie(id,w)=belt[now][i];
        smap[id]=next;
    }
    return;
}
//5
void as(int bnum){
    if(malfun[bnum]==1){
        cout<<-1<<'\n';
        return;
    }
    malfun[bnum]=1;
    for(int i=bnum+1;i<=m;i++){
        if(malfun[i]==0){
            change(i,bnum);
            cout<<bnum<<"\n";
            return;
        }
        
    }

    for(int i=1;i<=bnum;i++){
        if(malfun[i]==0){
            change(i,bnum);
            cout<<bnum<<"\n";
            return;
        }
        
    }

    cout<<-1<<'\n';
    return; 



}

void pr(){
    for(int i=1;i<=m;i++){
        for(int j=0;j<belt[i].size();j++){
            long id,w;
            tie(id,w)=belt[i][j];
            cout<<id<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
    cout<<'\n';
    return;
    
}

int main() {
    
    cin>>q;
    malfun=vector<int>(m+1,0);
    for(int i=0;i<q;i++){
        int com;
        cin>>com;
        if(com==100){
            
            cin>>n>>m;
            sett(n,m);
        }
        
        else if(com==200){
            long wmax;
            cin>>wmax;
            hacha(wmax);
        }
        
        else if(com==300){
            long rid;
            cin>>rid;
            erase(rid);
        }

        else if(com==400){
            long fid;
            cin>>fid;
            check(fid);
        }
        
        else if(com==500){
            int bnum;
            cin>>bnum;
            as(bnum);
        }
        //pr();

    }
    return 0;

}