#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
int k, m;
vector<vector<int>>map;
vector<vector<int>>visit;
vector<vector<int>>temp;
vector<int>patt;
queue<pair<int, int>>q;
vector<vector<int>>rotate(vector<vector<int>>&map,int y,int x) {
	temp = vector<vector<int>>(5, vector<int>(5, 0));
	temp = map;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp[y+j][x+2-i] = map[y+i][x+j];
		}
	}
	return temp;

}

void pmap() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	return;
}


int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int range(int y,int x) {
	if (y<0|| y>4)return 0;
	if (x<0|| x>4)return 0; 
	return 1;
}
vector<pair<int, int>>temparr;
int bfs(int y,int x) {
	temparr = vector<pair<int, int>>();
	int ret = 1;
	q=queue<pair<int, int>>();
	q.push(make_pair(y, x));
	temparr.push_back(make_pair(y, x));
	visit[y][x] = 1;
	while (!q.empty()) {
		int nowy, nowx;
		tie(nowy, nowx) = q.front();
		q.pop();
		for (int d = 0; d < 4; d++) {
			int ny = nowy+dy[d];
			int nx = nowx+dx[d];
			if (!range(ny, nx))continue;
			if (visit[ny][nx] == 1)continue;
			if(map[nowy][nowx]!=map[ny][nx])continue;
			q.push(make_pair(ny,nx));
			temparr.push_back(make_pair(ny, nx));
			visit[ny][nx] = 1;
			ret++;

		}
	}
	return ret;

}


int find() {
	int findcnt = 0;
	visit= vector<vector<int>>(5, vector<int>(5, 0));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (visit[i][j] == 0&&map[i][j]>0) {
				int nowcnt=bfs(i, j);
				if (nowcnt >= 3)findcnt += nowcnt;
			}
		}
	}
	return findcnt;

}
priority_queue<tuple<int, int, int, int>>pq;
void solve() {
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 4; k++) {
				
				map=rotate(map,i,j);
				
				
				if (k == 3)continue;
				int wid = find();
				if (wid == 0)continue;
				pq.push(make_tuple(wid,-k,-i,-j));
				
				
			}
		}
	}
	return;
}

void makemap(int d,int y,int x){
	for (int i = 0; i <= d; i++) {
		map = rotate(map, y, x);
	}
	return;
}

int makeblank() {
	int ret = 0;
	visit = vector<vector<int>>(5, vector<int>(5, 0));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (visit[i][j] == 0 && map[i][j] > 0) {
				int nowcnt = bfs(i, j);
				if (nowcnt >= 3) {
					ret += nowcnt;
					for (int k = 0; k < temparr.size(); k++) {
						int hy, hx;
						tie(hy, hx) = temparr[k];
						map[hy][hx]=0;
					}
				
				}
			}
		}
	}
	return ret;
}
int here=0;
void fill() {
	
	for (int j = 0; j < 5; j++) {
		for (int i = 4; i >= 0; i--) {
			if (map[i][j] == 0) {
				if (here >= m)return;
				map[i][j] = patt[here++];
			}
		}
	}
	return;



}


int main() {
	
	cin >> k >> m;
	map = vector<vector<int>>(5, vector<int>(5, 0));
	patt = vector<int>(m);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> patt[i];
	}
	
	
	
	for (int i = 0; i < k; i++) {
		int ans = 0;
		pq = priority_queue<tuple<int, int, int, int>>();
		solve();
		
		if (pq.empty())break;
		int a, d, y, x;
		tie(a, d, y, x) = pq.top();
	
		//cout << a << " " << -d << " " << -y << " " << -x << "\n";
		
		makemap(-d, -y, -x);
		//pmap();
		
		while (1) {
			
			int plus = makeblank();
			if (plus == 0)break;
			ans += plus;
			//cout << plus << '\n';
			//pmap();
			fill();
			//pmap();
		}
		cout << ans << ' ';

	
	}

	

	

}