#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<tuple>
#include<cmath>
#include<queue>
using namespace std;
vector<vector<int>>map;
vector<vector<int>>dmap;
vector<vector<int>>lastatt;
vector<vector<int>>visit;
int n, m, k;
vector<vector<int>>attacked;
priority_queue<tuple<int, int, int, int>>pq;
pair<int,int> findatt() {
	pq = priority_queue<tuple<int, int, int, int>>();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] <= 0) continue;
			pq.push(make_tuple(-map[i][j],lastatt[i][j],i+j,j));
		}
	}
	int p, l, h, x;
	tie(p, l, h, x) = pq.top();
	int rety = h - x;
	int retx=x;
	
	return make_pair(rety, retx);

}

pair<int, int> finddest() {
	pq = priority_queue<tuple<int, int, int, int>>();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] <= 0) continue;
			pq.push(make_tuple(map[i][j],-lastatt[i][j], -i - j, -j));
		}
	}
	int p, l, h, x;
	tie(p, l, h, x) = pq.top();
	int rety = -h + x;
	int retx = -x;

	return make_pair(rety, retx);

}

int dy[8] = { 0,1,0,-1,-1,-1,1,1 };
int dx[8] = { 1,0,-1,0,-1,1,-1,1};

int findpath(int sy, int sx, int ey, int ex) {
	visit = vector<vector<int>>(n, vector<int>(m,0));
	dmap = vector<vector<int>>(n, vector<int>(m, -1));
	queue<pair<int, int>>q;
	q.push(make_pair(sy, sx));
	visit[sy][sx] = 1;
	int flag = 0;
	while (!q.empty()) {
		int nowy, nowx;
		tie(nowy, nowx) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = (nowy + dy[i]+n)%n;
			int nx = (nowx + dx[i]+m)%m;
			if (map[ny][nx] <= 0)continue;
			if (visit[ny][nx] != 0)continue;
			visit[ny][nx] = 1;
			dmap[ny][nx] = (i + 2) % 4;
			q.push(make_pair(ny, nx));
			if (ny == ey && nx == ex) {
				flag = 1;
				break;
			}
		}
		
	}

	if (flag == 0) return 0;
	int att = map[sy][sx] / 2;
	int nowy = ey;
	int nowx = ex;

	while (1) {
		int d = dmap[nowy][nowx];
		int ny = (nowy+dy[d]+n)%n;
		int nx = (nowx + dx[d] + m) % m;
		if (dmap[ny][nx] == -1)break;
		attacked[ny][nx] = 1;
		map[ny][nx] -= att;
		nowy = ny;
		nowx = nx;

	}
	map[ey][ex] -= map[sy][sx];
	attacked[ey][ex] = 1;
	return 1;


}

void potress(int sy, int sx, int ey, int ex) {
	int att = map[sy][sx] / 2;
	for (int i = 0; i < 8; i++) {
		int ny=(ey+dy[i]+n)%n;
		int nx= (ex + dx[i] + m) % m;
		if (sy == ny&& sx ==nx )continue;
		if (map[ny][nx] <= 0)continue;
		attacked[ny][nx] = 1;
		map[ny][nx] -= att;
	}
	map[ey][ex]-= map[sy][sx];
	attacked[ey][ex] = 1;
	
	return;
}

void heal(int sy,int sx) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			if (i == sy && j == sx)continue;
			if (map[i][j] <= 0)continue;
			if (attacked[i][j] == 1)continue;
			map[i][j]++;
		}
	}
	return;
}


void pmap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j]<<" ";
		}
		cout << '\n';
	}
	cout << '\n';
	return;
}

int main() {

	
	cin >> n >> m >> k;
	attacked = vector<vector<int>>(n, vector<int>(m, 0));
	map = vector<vector<int>>(n, vector<int>(m, 0));
	lastatt = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int turn = 1; turn <= k; turn++) {
		//cout << "# " << turn << '\n';
		attacked = vector<vector<int>>(n, vector<int>(m, 0));
		int sy, sx;
		tie(sy,sx)=findatt();
		lastatt[sy][sx] = turn;
		int ey, ex;
		tie(ey, ex) = finddest();
		map[sy][sx] += (n + m);
		//pmap();
		if (findpath(sy, sx, ey, ex) == 0) {
			potress(sy, sx, ey, ex);
		}
		//pmap();
		heal(sy,sx);
		//pmap();
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] <= 0)continue;
			ans = max(ans, map[i][j]);
		}
	}
	cout << ans << "\n";


}