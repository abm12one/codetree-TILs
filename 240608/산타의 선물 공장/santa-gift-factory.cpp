#include <iostream>
#include <vector>
#include <tuple>
#include <map>
using namespace std;
int q;
int n,m;
vector<vector<pair<int,int>>>belt;
vector<int>id;
vector<int>weight;
vector<int>tail;
vector<pair<int,int>>temp;
vector<int>malfun;
map<int,int>smap;

void sett(int n,int m){
    
    belt=vector<vector<pair<int,int>>>(m+1,vector<pair<int,int>>());
    id=vector<int>(n+1);
    weight=vector<int>(n+1);
    
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

    tail=vector<int>(m+1,n/m-1);

    return;

}

void hacha(int wmax){
    int ret=0;
    for(int i=1;i<=m;i++){
        if(malfun[i]==1)continue;
        int fid;
        int fw;
        tie(fid,fw)=belt[i][0];
        
        ret+=fw;
        if(fw>wmax){
            belt[i].push_back(make_pair(fid,fw));
            ret-=fw;
        }
        else{
            smap.erase(fid);
        }
        
        temp=vector<pair<int,int>>();
        
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
        int nid,nw;
        tie(nid,nw)=belt[b][i];
        belt[b][i-1]=make_pair(nid,nw);
    }

    belt[b].pop_back();
    return;

}

void erase(int rid){
    
    if(smap.find(rid)==smap.end()){
        cout<<-1<<'\n';
        return ;
    }
    int b=smap[rid];

    for(int i=0;i<belt[b].size();i++){
        int id,w;
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
    
    temp=vector<pair<int,int>>();
    
    for(int i=0;i<=now;i++){
        int id,w;
        tie(id,w)=belt[b][i];
        smap.erase(id);
    }

    for(int i=now+1;i<belt[b].size();i++){
        temp.push_back(belt[b][i]);
    }

    belt[b]=temp;
    return;


}

void check(int fid){
    
    
    if(smap.find(fid)==smap.end()){
        cout<<-1<<'\n';
        return ;
    }
    int b=smap[fid];
    cout<<b<<"\n";

    for(int i=0;i<belt[b].size();i++){
        int id,w;
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
    }
    return;
}

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
        

    }
    return 0;

}