#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;

int ns;
int fr[1010][1010];
int t2pid[100010];
int t2uid[100010];
int p2like[100010];
priority_queue<tuple<int,int,int>>pq;
vector<deque<int>>posts;
void init(int N){
    ns=N;
    posts=vector<deque<int>>(ns+1);
    memset(fr,0,sizeof(fr));
    memset(t2pid,0,sizeof(t2pid));
    memset(t2uid,0,sizeof(t2uid));
    memset(p2like,0,sizeof(p2like));
    for(int i=1;i<=ns;i++){
        fr[i][i]=1;
    }
    return;

}
void follow(int uId1, int uId2, int timestamp){
    fr[uId1][uId2]=1;
    
    return;
}

void makePost(int uId, int pId, int timestamp){

    
    t2uid[timestamp]=uId;
    t2pid[timestamp]=pId;

    if(posts[uId].size()==10){
        posts[uId].pop_front();
    }
    posts[uId].push_back(timestamp);
    return;


}

void like(int pId, int timestamp){
    p2like[pId]++;
}
void getFeed(int uId, int timestamp, int pIdList[]){

    pq=priority_queue<tuple<int,int,int>>();
    int st=max(1,timestamp-1000);
    for(int t=st;t<=timestamp;t++){
        
        int u=t2uid[t];
        int p=t2pid[t];
        int l=p2like[p];
        if(p<=0)continue;
        if(fr[uId][u]==0)continue;
        if(pq.size()==10){
            pq.pop();
        }
        pq.push(make_tuple(0,-l,-t));

    }

    for(int f=1;f<=ns;f++){
        if(fr[uId][f]==0)continue;
        for(int i=0;i<posts[f].size();i++){
            if(posts[f][i]>=timestamp-1000)continue;
            if(pq.size()==10){
                pq.pop();
            }
            pq.push(make_tuple(1,0,-posts[f][i]));
        }
    }
    //cout<<"pq"<<"\n";
    for(int i=pq.size()-1;i>=0;i--){
        int a,b,c;
        tie(a,b,c)=pq.top();
        pq.pop();
        //cout<<a<<" "<<b<<" "<<t2pid[-c]<<"\n";
        pIdList[i]=t2pid[-c];
    }
    cout<<'\n';
    return;




}













































static int mSeed;
static int pseudo_rand(void)
{
	mSeed = mSeed * 431345 + 2531999;
	return mSeed & 0x7FFFFFFF;
}

static int follow_status[1005][1005];
static int answer_score;
static int n; // n >= 2 && n <= 1000
static int end_timestamp;
static int follow_ratio; // follow_ratio >= 1 && follow_ratio <= 10000
static int make_ratio; // make_ratio >= 1 && make_ratio <= 10000
static int like_ratio; // like_ratio >= 1 && like_ratio <= 10000
static int get_feed_ratio; // get_feed_ratio >= 1 && get_feed_ratio <= 10000
static int post_arr[200000];
static int total_post_cnt;
static int min_post_cnt;

static bool run()
{
	int uId1, uId2, pId, pIdList[10], ans_pIdList[10], rand_val;
	bool ret = true;

	scanf("%d%d%d%d%d%d%d", &mSeed, &n, &end_timestamp, &follow_ratio, &make_ratio, &like_ratio, &get_feed_ratio);
	init(n);

	for (int uId1 = 1; uId1 <= n; uId1++)
	{
		follow_status[uId1][uId1] = 1;
		int m = n / 10 + 1;
		if (m > 10)
			m = 10;
		for (int i = 0; i < m; i++)
		{
			uId2 = uId1;
			while (follow_status[uId1][uId2] == 1)
			{
				uId2 = pseudo_rand() % n + 1;
			}
			follow(uId1, uId2, 1);
			follow_status[uId1][uId2] = 1;
		}
	}
	min_post_cnt = total_post_cnt = 1;

	for (int timestamp = 1; timestamp <= end_timestamp; timestamp++)
	{
		rand_val = pseudo_rand() % 10000;
		if (rand_val < follow_ratio)
		{
			uId1 = pseudo_rand() % n + 1;
			uId2 = pseudo_rand() % n + 1;
			int lim = 0;
			while (follow_status[uId1][uId2] == 1 || uId1 == uId2)
			{
				uId2 = pseudo_rand() % n + 1;
				lim++;
				if (lim >= 5)
					break;
			}
			if (follow_status[uId1][uId2] == 0)
			{
				follow(uId1, uId2, timestamp);
				follow_status[uId1][uId2] = 1;
			}
		}
		rand_val = pseudo_rand() % 10000;

		if (rand_val < make_ratio)
		{
			uId1 = pseudo_rand() % n + 1;
			post_arr[total_post_cnt] = timestamp;

			makePost(uId1, total_post_cnt, timestamp);
			total_post_cnt += 1;
		}

		rand_val = pseudo_rand() % 10000;

		if (rand_val < like_ratio && total_post_cnt - min_post_cnt > 0)
		{
			while (post_arr[min_post_cnt] < timestamp - 1000 && min_post_cnt < total_post_cnt)
				min_post_cnt++;

			if (total_post_cnt != min_post_cnt)
			{
				pId = pseudo_rand() % (total_post_cnt - min_post_cnt) + min_post_cnt;
				like(pId, timestamp);
			}
		}

		rand_val = pseudo_rand() % 10000;
		if (rand_val < get_feed_ratio && total_post_cnt > 0)
		{
			uId1 = pseudo_rand() % n + 1;
			getFeed(uId1, timestamp, pIdList);

			for (int i = 0; i < 10; i++)
			{
				scanf("%d", ans_pIdList + i);
			}

			for (int i = 0; i < 10; i++)
			{
				if (ans_pIdList[i] == 0)
					break;

				if (ans_pIdList[i] != pIdList[i])
				{
					ret = false;
				}
			}
		}
	}

	return ret;
}

int main()
{
//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int tc;
	scanf("%d%d", &tc, &answer_score);

	for (int t = 1; t <= tc; t++)
	{
		int score;
		for (int i = 0; i < 1005; i++)
			for (int j = 0; j < 1005; j++)
				follow_status[i][j] = 0;

		if (run())
			score = answer_score;
		else
			score = 0;

		printf("#%d %d\n", t, score);
	}
	return 0;
}