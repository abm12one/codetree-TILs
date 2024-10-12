#define _CRT_SECURE_WARNINGS
#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
using namespace std;
int n, m;
vector<vector<int>>basemap;
vector<vector<int>>map;
vector<vector<int>>visit;
vector<pair<int, int>>conv;
vector<pair<int, int>>player;
vector<int>pexit;
int t;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int pcnt;
int range(int y,int x) {
	if (y<1 || y>n)return 0;
	if (x<1 || x>n)return 0;
	return 1;
}

void find(int id) {
	int sy, sx;
	tie(sy, sx) = conv[id];
	visit = vector<vector<int>>(n + 1, vector<int>(n + 1));
	queue<tuple<int, int,int>>q;
	priority_queue<tuple<int,int, int>>pq;
	visit[sy][sx] = 1;
	q.push(make_tuple(sy,sx,0));

	while (!q.empty()) {
		int nowy, nowx,nowd;
		tie(nowy, nowx,nowd) = q.front();
		q.pop();
		for (int d = 0; d < 4; d++) { 
			int ny = nowy+dy[d];
			int nx = nowx+dx[d];
			if (!range(ny, nx))continue;
			if (visit[ny][nx] == 1)continue;
			if (map[ny][nx] == 1)continue;
			q.push(make_tuple(ny, nx,nowd+1));
			visit[ny][nx] = 1;
			if (basemap[ny][nx] == 1) {
				pq.push(make_tuple(-nowd - 1, -ny, -nx));
			}
		}

	}
	
	int l, r, c;
	tie(l, r, c) = pq.top();
	player[id] = make_pair(-r,-c);
	map[-r][-c] = 1;
	return;
}

int findlen(int sy,int sx,int id) {
	int cy, cx;
	tie(cy, cx) = conv[id];
	if (sy == cy && sx == cx)return 0;
	visit = vector<vector<int>>(n + 1, vector<int>(n + 1,0));
	queue<tuple<int, int, int>>q;
	visit[sy][sx] = 1;
	q.push(make_tuple(sy, sx, 0));

	while (!q.empty()) {
		int nowy, nowx, nowd;
		tie(nowy, nowx, nowd) = q.front();
		q.pop();
		for (int d = 0; d < 4; d++) {
			int ny = nowy + dy[d];
			int nx = nowx + dx[d];
			if (!range(ny, nx))continue;
			if (visit[ny][nx] == 1)continue;
			if (map[ny][nx] == 1)continue;
			q.push(make_tuple(ny, nx, nowd + 1));
			visit[ny][nx] = 1;
			if (ny==cy&&nx==cx) {
				return nowd + 1;
			}
		}
	}
	return 987654321;

}


void move(int id) {
	//cout << id << " move" << '\n';
	int y, x;
	tie(y, x) = player[id];
	int ry=-1;
	int rx = -1;
	int mlen = 987654321;
	for (int d = 0; d < 4; d++) {
		int ny =y+dy[d];
		int nx =x+dx[d];
		if (!range(ny, nx))continue;
		if (map[ny][nx] == 1)continue;
		int l=findlen(ny, nx, id);
		
		if (mlen > l) {
			mlen = l;
			ry=ny;
			rx=nx;
		}
	}
	player[id] = make_pair(ry,rx);
	//cout << id << " " << ry << " " << rx << '\n';
	return;
}


void posp() {
	for (int i = 1; i <= m; i++) {
		int y, x;
		tie(y, x) = player[i];
		cout << i << "사람 " << y << " " << x << '\n';
	}
	cout << '\n';
	return;
}

void pmap() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
	return;

}

int main() {
	
	cin >> n >> m;
	pcnt = 0;
	basemap = vector<vector<int>>(n + 1, vector<int>(n + 1));
	map = vector<vector<int>>(n + 1, vector<int>(n + 1));
	visit = vector<vector<int>>(n + 1, vector<int>(n + 1));
	conv = vector<pair<int, int>>(m + 1);
	pexit = vector<int>(m + 1,0);
	player = vector<pair<int, int>>(m + 1,make_pair(-1,-1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {		
			cin >> basemap[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		int y, x;
		cin >> y >> x;
		conv[i] = make_pair(y,x);
	}

	t= 0;
	while (1) {
		if (pcnt == m)break;
		//if (t == 10)break;
		t++;
		//cout << "# " << t << '\n';
		//움직여
		for (int i = 1; i <= m; i++) {
			if (pexit[i] == 1)continue;
			int y, x;
			tie(y, x) = player[i];
			if (y == -1 && x == -1)continue;
			move(i);
		}
		
		
		//도착처리
		for (int i = 1; i <= m; i++) {
			if (pexit[i] == 1)continue;
			int y, x;
			tie(y, x) = player[i];
			if (y == -1 && x == -1)continue;
			
			int cy, cx;
			tie(cy, cx) = conv[i];
			if (y == cy && x == cx) {
				map[cy][cx] = 1;
				pexit[i] = 1;
				pcnt++;
			}

		}
		
		

		if (t <= m) {
			find(t);
		}
		//posp();
		//pmap();
	}
	cout << t << '\n';


}