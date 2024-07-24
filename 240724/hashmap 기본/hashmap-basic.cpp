#ifndef _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 
#endif

#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<set>

#define CMD_MKDIR 1
#define CMD_RM 2
#define CMD_CP 3
#define CMD_MV 4
#define CMD_FIND 5

#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999
using namespace std;
vector<set<int>>tree;
vector<string>dirname;
queue<int>que;
vector<int>p;
vector<int>cnt;


void init(int n) {
    tree=vector<set<int>>(n+1);
    dirname=vector<string>(n+1);
    p=vector<int>(n+1,-1);
    cnt=vector<int>(n+1,0);
    for(int i=1;i<n+1;i++){
        que.push(i);
    }
    dirname[0]='/';
    cnt[0]=1;
    return;

}

int findid(string path){

    int now=1;
    string temp="";
    int ptr=0;
    while(now<path.size()){
        if(path[now]=='/'){
            for(auto it=tree[ptr].begin();it!=tree[ptr].end();it++){
                if(temp==dirname[*it]){
                    ptr=*it;
                    break;
                }
            }
            temp="";
            now++;
        }
        temp+=path[now];
        now++;
    }
    return ptr;

}

void renewcnt(int newnum,int v){
    int now=newnum;
    while(p[now]!=-1){
        cnt[p[now]]+=v;
        now=p[now];
    }
    return;
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
    //cout<<"#1"<<path<<" "<<name<<"\n";
    int id=findid(path);
    int newnum=que.front();
    que.pop();
    dirname[newnum]=name;
    tree[id].insert(newnum);
    cnt[newnum]=1;
    p[newnum]=id;
    renewcnt(newnum,1);
    //cout<<id<<" "<<newnum<<'\n';
    //cout<<p[id]<<" "<<p[newnum]<<'\n';
    //cout<<cnt[id]<<" "<<cnt[newnum]<<'\n';
    return;
}

void remove(int now){

    for(auto it=tree[now].begin();it!=tree[now].end();it++){
        remove(*it);
    }
    tree[now].clear();
    p[now]=-1;
    cnt[now]=0;
    que.push(now);
    return;

}

void cmd_rm(char path[PATH_MAXLEN + 1]) {
    cout<<"#2"<<"\n";
    int id=findid(path);
    cout<<id<<" "<<p[id]<<"\n";
    renewcnt(id,-cnt[id]);
    remove(id);
    cout<<id<<" "<<p[id]<<"\n";
    
    return;

}

int copy(int sid,int did){
    
    
    int newnum=que.front();
    que.pop();
    dirname[newnum]=dirname[sid];
    cnt[newnum]=cnt[sid];
    p[newnum]=did;
    tree[did].insert(newnum);

    for(auto it=tree[sid].begin();it!=tree[sid].end();it++){
        copy(*it,newnum);
    }
    return newnum;
}

void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
    cout<<"#3"<<"\n";
    int sid=findid(srcPath);
    int did=findid(dstPath);
    cout<<sid<<" "<<did<<'\n';
    int newnum=copy(sid,did);
    renewcnt(newnum,cnt[newnum]);
    
    return;


}

void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
    int sid=findid(srcPath);
    int did=findid(dstPath);
    renewcnt(sid,-cnt[sid]);
    int ps=p[sid];
    for(auto it=tree[ps].begin();it!=tree[ps].end();it++){
        if(*it==sid){
            tree[ps].erase(*it);
            break;
        }
    }
    p[sid]=did;
    renewcnt(sid,cnt[sid]);
    return;

}

int cmd_find(char path[PATH_MAXLEN + 1]) {
    int id=findid(path);
    return cnt[id]-1;
	
}

static bool run(int m) {

	bool isAccepted = true;
	int cmd;
	char name[NAME_MAXLEN + 1];
	char path1[PATH_MAXLEN + 1], path2[PATH_MAXLEN + 1];

	while (m--) {

		scanf("%d", &cmd);

		if (cmd == CMD_MKDIR) {
			scanf("%s%s", path1, name);
			cmd_mkdir(path1, name);
		}
		else if (cmd == CMD_RM) {
			scanf("%s", path1);
			cmd_rm(path1);
		}
		else if (cmd == CMD_CP) {
			scanf("%s%s", path1, path2);
			cmd_cp(path1, path2);
		}
		else if (cmd == CMD_MV) {
			scanf("%s%s", path1, path2);
			cmd_mv(path1, path2);
		}
		else {
			int ret;
			int answer;

			scanf("%s", path1);
			ret = cmd_find(path1);
			scanf("%d", &answer);

			isAccepted &= (ret == answer);
		}
	}

	return isAccepted;
}

int main(void) {

	int test, T;
	int n, m;

	// freopen("sample_input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (test = 1; test <= T; ++test) {

		scanf("%d%d", &n, &m);

		init(n);

		if (run(m)) {
			printf("#%d 100\n", test);
		}
		else {
			printf("#%d 0\n", test);
		}
	}

	return 0;
}