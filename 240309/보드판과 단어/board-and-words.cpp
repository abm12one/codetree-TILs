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
vector<vector<int>>visit;
vector<vector<int>>map;
int dy[8]={-1,-1,-1,0,0,1,1,1};
int dx[8]={-1,0,1,-1,1,-1,0,1};
class trienode{
    public:
        int isend;
        trienode *child[26];
        trienode(){
            isend=0;
            for(int i=0;i<26;i++){
                child[i]=nullptr;
            }
        }
};

trienode *root=new trienode();

void insert(string s){
    
    trienode *t=root;
    for(int i=0;i<s.size();i++){
        int next=s[i]-'a';
        if(t->child[next]==nullptr){
            t->child[next]=new trienode;
        }
        t=t->child[next];
    }
    t->isend=1;

}

int ans=0;

void search(int y ,int x, trienode *root,int num,string s){
    trienode*t=root;

    visit[y][x]=1;
    s+=map[y][x]+'a';

    int next=map[y][x];
    if(t->child[next]==nullptr){
        visit[y][x]=0;
        return;
    }
    
    if(t->child[next]->isend){
        ans=max(ans,num+1);
        //cout<<s<<'\n';
    }

    for(int i=0;i<8;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0||ny>=4||nx<0||nx>=4){
            continue;
        }
        if(visit[ny][nx]==1)continue;
        search(ny,nx,t->child[next],num+1,s);

    }
    visit[y][x]=0;
    return;


}




int main() {
    int n;
    cin>>n;
    visit=vector<vector<int>>(4,vector<int>(4,0));
    map=vector<vector<int>>(4,vector<int>(4,0));
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        insert(temp);

    }
    
    for(int i=0;i<4;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<4;j++){
            map[i][j]=temp[j]-'a';
        }
    }






    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            search(i,j,root,0,"");

        }
    }
    cout<<ans<<'\n';



	
}