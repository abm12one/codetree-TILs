#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
using namespace std;
extern void init(int N, int K, int mNodeA[], int mNodeB[], int mTime[]);
extern void addLine(int mNodeA, int mNodeB, int mTime);
extern void removeLine(int mNodeA, int mNodeB);
extern int checkTime(int mNodeA, int mNodeB);

#define CMD_INIT   0
#define CMD_ADD    1
#define CMD_REMOVE 2
#define CMD_CHECK  3

#define MAX_LINE 30000

static int nodeA[MAX_LINE];
static int nodeB[MAX_LINE];
static int Time[MAX_LINE];

static bool run()
{
	int Q, N, K, ans;
	scanf("%d", &Q);

	bool ok = false;

	for (int q = 0; q < Q; q++)
	{
		int cmd;
		scanf("%d", &cmd);
		if (cmd == CMD_INIT)
		{
			scanf("%d %d", &N, &K);
			for (int i = 0; i < K; i++) {
				scanf("%d %d %d", &nodeA[i], &nodeB[i], &Time[i]);
			}
			init(N, K, nodeA, nodeB, Time);
			ok = true;
		}
		else if (cmd == CMD_ADD)
		{
			scanf("%d %d %d", &nodeA[0], &nodeB[0], &Time[0]);
			addLine(nodeA[0], nodeB[0], Time[0]);
		}
		else if (cmd == CMD_REMOVE)
		{
			scanf("%d %d", &nodeA[0], &nodeB[0]);
			removeLine(nodeA[0], nodeB[0]);
		}
		else if (cmd == CMD_CHECK)
		{
			scanf("%d %d", &nodeA[0], &nodeB[0]);
			int ret = checkTime(nodeA[0], nodeB[0]);
			scanf("%d", &ans);
			cout<<ret<<" "<<ans<<'\n';
			if (ans != ret) {
				ok = false;
			}
		}
		else ok = false;
	}
	return ok;
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
#include<queue>
#include<vector>
#include<tuple>
#include<unordered_map>
using namespace std;
vector<vector<vector<int>>>dist(31,vector<vector<int>>(31,vector<int>(31,987654321)));
vector<vector<vector<int>>>mindist(31,vector<vector<int>>(31,vector<int>(31,987654321)));
vector<vector<tuple<int,int,int>>>road(34,vector<tuple<int,int,int>>(34,make_tuple(-1,0,0)));
int sn;

void sett(int n){
	vector<vector<int>>temp(31,vector<int>(31));
	for(int i=1;i<31;i++){
		for(int j=1;j<31;j++){
			if(i==j){
				dist[n][i][j]=0;
			}
			temp[i][j]=dist[n][i][j];
		}
	}
	for(int j=1;j<31;j++){
		for(int i=1;i<31;i++){
			for(int k=1;k<31;k++){
				temp[i][k]=min(temp[i][k],temp[i][j]+temp[j][k]);
			}
		}
	}
	for(int i=1;i<31;i++){
		for(int j=1;j<31;j++){
			mindist[n][i][j]=temp[i][j];
		}
	}

	return;


}

void pr(){
	for(int i=1;i<4;i++){
		for(int j=1;j<31;j++){
			for(int k=1;k<31;k++){
				if(mindist[i][j][k]==987654321){
					cout<<-1<<" ";
				}
				else{
					cout<<mindist[i][j][k]<<' ';
				}
				
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
	cout<<"\n";

}

void init(int N, int K, int mNodeA[], int mNodeB[], int mTime[])
{
	sn=N;
	for(int i=0;i<K;i++){
		int na=mNodeA[i]/100;
		int ac=mNodeA[i]%100;
		int nb=mNodeB[i]/100;
		int bc=mNodeB[i]%100;
		if(na==0){
			na=30+ac;
		}
		if(nb==0){
			nb=30+bc;
		}
		
		if(na==nb){
			
			dist[na][ac][bc]=mTime[i];
			dist[na][bc][ac]=mTime[i];
		}
		else{
			
			road[na][nb]=make_tuple(mTime[i],mNodeA[i],mNodeB[i]);
			road[nb][na]=make_tuple(mTime[i],mNodeB[i],mNodeA[i]);
		}
	}	
	for(int i=1;i<31;i++){
		sett(i);
	}

	//pr();
	return;
	

}

void addLine(int mNodeA, int mNodeB, int mTime)
{
	int na=mNodeA/100;
	int ac=mNodeA%100;
	int nb=mNodeB/100;
	int bc=mNodeB%100;
	if(na==0){
		na=30+ac;
	}
	if(nb==0){
		nb=30+bc;
	}
	
	if(na!=nb){
		road[na][nb]=make_tuple(mTime,mNodeA,mNodeB);
		road[nb][na]=make_tuple(mTime,mNodeB,mNodeA);
		return;
	}
	else{
		dist[na][ac][bc]=mTime;
		dist[na][bc][ac]=mTime;
		sett(na);
	}
	return;

}

void removeLine(int mNodeA, int mNodeB)
{
	int na=mNodeA/100;
	int ac=mNodeA%100;
	int nb=mNodeB/100;
	int bc=mNodeB%100;
	if(na==0){
		na=30+ac;
	}
	if(nb==0){
		nb=30+bc;
	}
	if(na!=nb){
		road[na][nb]=make_tuple(-1,0,0);
		road[nb][na]=make_tuple(-1,0,0);
		return;
	}
	else{
		dist[na][ac][bc]=987654321;
		dist[na][bc][ac]=987654321;
		sett(na);
	}
	return;
}

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<int>mind;

void pr2(){
	
	
	
	for(int i=1;i<34;i++){
		for(int j=1;j<34;j++){
			int d,s,e;
			tie(d,s,e)=road[i][j];
			if(d==-1)continue;
			cout<<d<<" "<<s<<" "<<e<<'\n';
		}
		
	}
	
	
	return;
}

int checkTime(int mNodeA, int mNodeB)
{	
	//pr2();
	pq=priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>();
	mind=vector<int>(40000,987654321);
	//cout<<mind.size()<<"\n";
	mind[mNodeA]=0;
	pq.push(make_pair(0,mNodeA));
	//cout<<mind[mNodeB]<<'\n';
	while(!pq.empty()){
		int nowd,now;
		tie(nowd,now)=pq.top();
		//cout<<nowd<<" "<<now<<'\n';
		pq.pop();
		//cout<<mind[now]<<" "<<nowd<<"\n";
		if(mind[now]<nowd)continue;
		
		//cout<<"wow"<<"\n";
		int nowcity=0;
		if(now==1||now==2||now==3){
			nowcity=now+30;
		}
		else{
			nowcity=now/100;
		}
		//cout<<nowcity<<"\n";
		
		for(int nextcity=1;nextcity<=33;nextcity++){
			int d,s,e;
			tie(d,s,e)=road[nowcity][nextcity];
			if(d==-1)continue;
			if(s!=now)continue;
			//cout<<"temp"<<nowd+d<<" "<<e<<'\n';
			if(nowd+d<mind[e]){
				mind[e]=nowd+d;
				pq.push(make_pair(nowd+d,e));
				if(e==mNodeB){
					return mind[mNodeB];
				}
			}
			
		}

		if(nowcity!=31&&nowcity!=32&&nowcity!=33){
			int na=nowcity;
			int ac=now%100;
			for(int i=1;i<=3;i++){
				
				if(ac==i)continue;
				pq.push(make_pair(nowd+mindist[na][ac][i],na*100+i));
				mind[na*100+i]=nowd+mindist[na][ac][i];
			}
		}

	}
	
	
}