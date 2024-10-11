#define _CRT_SECURE_WARNINGS
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
int l, n, q;

vector<vector<int>>map;
vector<vector<int>>kmap;
vector<pair<int,int>>kpos;
vector<pair<int,int>>kshield;
vector<int>kp;
vector<int>kblood;
vector<int>visit;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int range(int y,int x) {
	if (y<1 || y>l)return 0;
	if (x<1 || x>l)return 0;
	return 1;
}

void setkmap() {
	visit = vector<int>(n + 1,0);
	kmap = vector<vector<int>>(l + 1, vector<int>(l + 1,0));
	for (int i = 1; i <= n; i++) {
		if (kp[i] <= 0)continue;
		int y, x;
		tie(y, x) = kpos[i];
		int r, c;
		tie(r, c) = kshield[i];
		for (int rr = 0; rr < r; rr++) {
			for (int cc = 0; cc < c; cc++) {
				kmap[y+rr][x+cc] = i;
			}
		}

	}
	return;

}

int canmove(int id,int d) {
	int ret = 1;
	visit[id] = 1;
	int y, x;
	tie(y, x) = kpos[id];
	int r, c;
	tie(r, c) = kshield[id];
	for (int rr = 0; rr < r; rr++) {
		for (int cc = 0; cc < c; cc++) {
			int nowy = y + rr;
			int nowx = x + cc;
			int ny = nowy+dy[d];
			int nx = nowx + dx[d];
			if (!range(ny, nx)) return 0;
			if (map[ny][nx] == 2)return 0;
			if (kmap[ny][nx] == 0)continue;
			int nid = kmap[ny][nx];
			if (visit[nid] == 1)continue;
			ret = min(ret, canmove(nid, d));

		}
	}
	return ret;
}

void move(int id,int now, int d) {
	visit[now] = 1;
	int y, x;
	tie(y, x) = kpos[now];
	int r, c;
	tie(r, c) = kshield[now];
	for (int rr = 0; rr < r; rr++) {
		for (int cc = 0; cc < c; cc++) {
			int nowy = y + rr;
			int nowx = x + cc;
			int ny = nowy + dy[d];
			int nx = nowx + dx[d];
			if (!range(ny, nx)) continue;
			if (map[ny][nx] == 2)continue;
			if (kmap[ny][nx] == 0)continue;
			int nid = kmap[ny][nx];
			if (visit[nid] == 1)continue;
			move(id,nid, d);

		}
	}
	kpos[now] = make_pair(y+dy[d],x+dx[d]);
	if (id == now)return;
	int cnt = 0;
	for (int rr = 0; rr < r; rr++) {
		for (int cc = 0; cc < c; cc++) {
			int nowy = y +dy[d] + rr;
			int nowx = x +dx[d] + cc;
			if (map[nowy][nowx] == 1)cnt++;

		}
	}
	kp[now] -= cnt;
	return;


}

void pkmap() {
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= l; j++) {
			cout << kmap[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
	return;
}

int main() {
	cin >> l >> n >> q;
	kmap = vector<vector<int>>(l + 1, vector<int>(l + 1));
	map = vector<vector<int>>(l + 1, vector<int>(l + 1));
	kpos = vector<pair<int, int>>(n + 1);
	kshield = vector<pair<int, int>>(n+1);
	kp = vector<int>(n+1,0);
	kblood = vector<int>(n + 1, 0);
	visit = vector<int>(n + 1,0);

	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= l; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		int r, c, h, w, k;
		cin >> r >> c >> h >> w >> k;
		kpos[i] = make_pair(r,c);
		kshield[i] = make_pair(h,w);
		kp[i] = k;
		kblood[i] = k;
	}

	for (int i = 0; i < q; i++) {
		int id, d;
		cin >> id >> d;
		//cout << "# " << i<< '\n';
		setkmap();
		//pkmap();
		
		if (canmove(id, d) == 1) {
			//cout << "yes" << '\n';
			visit = vector<int>(n + 1, 0);
			move(id,id, d);
		}
		else {
			//cout << "no" << '\n';
		}
		//setkmap();
		//pkmap();
		
	}
	
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (kp[i] <= 0)continue;
		ans +=(kblood[i]-kp[i]);
	}
	cout << ans << '\n';
	
}