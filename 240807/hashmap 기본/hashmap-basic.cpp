#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N, int K);
extern void registerUser(int mTime, int mUID, int mNum, int mGroupIDs[]);
extern int offerNews(int mTime, int mNewsID, int mDelay, int mGroupID);
extern void cancelNews(int mTime, int mNewsID);
extern int checkUser(int mTime, int mUID, int mRetIDs[]);

/////////////////////////////////////////////////////////////////////////

#define INIT	0
#define REGI	1
#define OFFER	2
#define CANCEL	3
#define CHECK	4

static int gids[30];
static int ansids[3];
static int retids[3];
static bool run()
{
	int N, K;
	int cmd, ans, ret;	
	int time, num, uid, gid, nid, delay;

	int Q = 0;
	bool okay = false;

	scanf("%d", &Q);
	for (int q = 0; q < Q; ++q)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case INIT:
			scanf("%d %d", &N, &K);
			init(N, K);
			okay = true;
			break;

		case REGI:
			scanf("%d %d %d", &time, &uid, &num);
			for (int m = 0; m < num; m++) {
				scanf("%d", &gids[m]);
			}
			registerUser(time, uid, num, gids);
			break;

		case OFFER:
			scanf("%d %d %d %d %d", &time, &nid, &delay, &gid, &ans);
			ret = offerNews(time, nid, delay, gid);
			if (ans != ret) {
				okay = false;
			}
			break;

		case CANCEL:
			scanf("%d %d", &time, &nid);
			cancelNews(time, nid);
			break;

		case CHECK:
			scanf("%d %d %d", &time, &uid, &ans);
			ret = checkUser(time, uid, retids);

			num = ans;
			if (num > 3) num = 3;
			for (int m = 0; m < num; m++) {
				scanf("%d", &ansids[m]);
			}
			if (ans != ret)	{
				okay = false;
			}
			else {
				for (int m = 0; m < num; m++) {
					if (ansids[m] != retids[m]) {
						okay = false;
					}
				}
			}
			break;

		default:
			okay = false;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<tuple>
using namespace std;

vector<vector<int>>chan2user;
vector<vector<int>>user2newsid;
vector<bool>isdelete;
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
unordered_map<int,int>cmap;
unordered_map<int,int>umap;
unordered_map<int,int>nmap;
unordered_map<int,int>omap;
int n,k;
int userid=0;
int channelid=0;
int newsid=0;
void init(int N, int K)
{
	n=N;
	k=K;
	umap.clear();
	cmap.clear();
	nmap.clear();
	omap.clear();
	userid=1;
   	channelid=1;
  	newsid=1;
	chan2user=vector<vector<int>>(501);
	user2newsid=vector<vector<int>>(501);
	isdelete=vector<bool>(501,false);
	return;

}

void sendnews(int time){

	while(!pq.empty()){
		int mtime;
		int nid;
		int cid;
		tie(mtime,nid,cid)=pq.top();
		if(mtime>time)return;
		pq.pop();

		for(int i=0;i<chan2user[cid].size();i++){
			int nextuid=chan2user[cid][i];
			user2newsid[nextuid].push_back(nid);
		}

	}

	return;

}


void registerUser(int mTime, int mUID, int mNum, int mChannelIDs[])
{
	sendnews(mTime);
	if(umap[mUID]==0){
		umap[mUID]=userid++;
	}
	int uid=umap[mUID];
	for(int i=0;i<mNum;i++){
		int nextchan=mChannelIDs[i];
		if(cmap[nextchan]==0){
			cmap[nextchan]=channelid++;
		}
		int ncid=cmap[nextchan];
		chan2user[ncid].push_back(uid);
	}
	return;

	

}

int offerNews(int mTime, int mNewsID, int mDelay, int mChannelID)
{
	//sendnews(mTime);
	if(nmap[mNewsID]==0){
		nmap[mNewsID]=newsid++;
	}
	int nid=nmap[mNewsID];
	omap[nid]=mNewsID;

	if(cmap[mChannelID]==0){
		cmap[mChannelID]=channelid++;
	}
	int cid=cmap[mChannelID];
	//cout<<nid<<" "<<cid<<'\n';
	pq.push(make_tuple(mTime+mDelay,nid,cid));
	cout<<chan2user[cid].size()<<"\n";
	return chan2user[cid].size();
}

void cancelNews(int mTime, int mNewsID)
{
	sendnews(mTime);
	if(nmap[mNewsID]==0){
		nmap[mNewsID]=newsid++;
	}
	int nid=nmap[mNewsID];
	isdelete[nid]=true;
	return;

}

void pr(){
	for(int i=0;i<user2newsid[1].size();i++){
		cout<<user2newsid[1][i]<<" ";
	}
	cout<<"\n";
	return;
}

int checkUser(int mTime, int mUID, int mRetIDs[])
{
	sendnews(mTime);
	pr();
	cout<<"check"<<' ';                                                                          
	if(umap[mUID]==0){
		umap[mUID]=userid++;
	}
	int uid=umap[mUID];
	cout<<uid<<" ";
	cout<<user2newsid[uid].size()<<"\n";
	queue<int>q;
	for(int i=0;i<user2newsid[uid].size();i++){
		int nextnewsid=user2newsid[uid][i];
		if(isdelete[nextnewsid]==true)continue;
		q.push(nextnewsid);
		if(q.size()>3){
			q.pop();
		}

	}
	user2newsid[uid].clear();
	int now=0;
	while(!q.empty()){
		int qf=q.front();

		mRetIDs[now++]=omap[qf];
		cout<<omap[qf]<<" ";
		q.pop();
	}
	cout<<'\n';
	return now;


}