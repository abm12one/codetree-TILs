#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<tuple>
#include<cmath>
#include<queue>
using namespace std;
int n, m, p, c, d;
int ry, rx,rd;
vector<vector<int>>map;
vector<pair<int,int>>santa;
vector<int>sdie;
vector<int>sstun;
vector<int>score;
int turn;
priority_queue<tuple<int, int, int>>pq;
int cnt;
int dy[8] = {-1,0,1,0,1,1,-1,-1};
int dx[8] = {0,1,0,-1,1,-1,1,-1};
int range(int y, int x) {
	if (y<1 || y>n)return 0;
	if (x<1 || x>n)return 0;
	return 1;
}

void rudolmove() {
	pq = priority_queue<tuple<int, int, int>>();
	for (int i = 1; i <= p; i++) {
		if (sdie[i] == 1)continue;
		int sy, sx;
		tie(sy, sx) = santa[i];
		int dis = pow(abs(ry-sy), 2) + pow(abs(rx-sx), 2);
		pq.push(make_tuple(-dis, sy, sx));
	}
	int d, y, x;
	tie(d, y, x) = pq.top();
	int maxd = 987654321;
	int rety, retx,retd;
	for (int i = 0; i < 8; i++) {
		int ny=ry+dy[i];
		int nx=rx+dx[i];
		if (!range(ny, nx))continue;
		int dis = pow(abs(y - ny), 2) + pow(abs(x - nx), 2);
		if (maxd > dis) {
			maxd = dis;
			rety = ny;
			retx = nx;
			retd = i;
		}
	}
	ry = rety;
	rx = retx;
	rd = retd;
	return;

}

void setmap() {
	map= vector<vector<int>>(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= p; i++) {
		if (sdie[i] == 1)continue;
		int sy, sx;
		tie(sy, sx) = santa[i];
		map[sy][sx] = i;
		
	}
	return;

}

void pmap() {
	map = vector<vector<int>>(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= p; i++) {
		if (sdie[i] == 1)continue;
		int sy, sx;
		tie(sy, sx) = santa[i];
		map[sy][sx] = i;

	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}
	cout << ry << " " << rx << "\n";
	cout << '\n';
	return;

}



void chkrcoll() {
	setmap();
	if (map[ry][rx] == 0)return;
	int nows = map[ry][rx];
	sstun[nows] = turn;
	int nowy, nowx;
	nowy = ry + c * dy[rd];
	nowx = rx + c * dx[rd];
	score[nows] += c;
	if (!range(nowy, nowx)) {
		sdie[nows] = 1;
		cnt++;
		return;
	}
	santa[nows] = make_pair(nowy, nowx);
	if (map[nowy][nowx] == 0)return;
	
	while (1) {
		
		
		nows = map[nowy][nowx];
		int newy = nowy + dy[rd];
		int newx = nowx + dx[rd];
		if (!range(newy, newx)) {
			sdie[nows] = 1;
			cnt++;
			return;
		}
		santa[nows] = make_pair(newy, newx);
		if (map[newy][newx] == 0)return;
		nowy=newy; 
		nowx = newx;

	}

	return;

}


void chkscoll(int num) {
	
	sstun[num] = turn;
	int nows;
	int nowy, nowx;
	nowy = ry + d * dy[rd];
	nowx = rx + d * dx[rd];
	score[num] += d;
	if (!range(nowy, nowx)) {
		cnt++;
		sdie[num] = 1;
		return;
	}
	santa[num] = make_pair(nowy, nowx);
	if (map[nowy][nowx] == 0)return;

	while (1) {


		nows = map[nowy][nowx];
		int newy = nowy + dy[rd];
		int newx = nowx + dx[rd];
		if (!range(newy, newx)) {
			cnt++;
			sdie[nows] = 1;
			return;
		}
		santa[nows] = make_pair(newy, newx);
		if (map[newy][newx] == 0)return;
		nowy = newy;
		nowx = newx;

	}
	setmap();
	return;

}

void santamove() {
	setmap();
	for (int i = 1; i <= p; i++) {
		if (sdie[i] == 1)continue;
		if (sstun[i]!=0&&turn-sstun[i]<2)continue;
		int maxd = 987654321;
		int sy, sx;
		tie(sy, sx) = santa[i];
		int kijun = pow(abs(ry - sy), 2) + pow(abs(rx - sx), 2);
		int nexty = sy;
		int nextx = sx; 
		int nextd=0;
		for (int j = 0; j < 4; j++) {
			int ny = sy + dy[j];
			int nx = sx + dx[j];
			if (!range(ny, nx))continue;
			if (map[ny][nx]!=0)continue;
			int dis = pow(abs(ry - ny), 2) + pow(abs(rx - nx), 2);
			if (dis > kijun)continue;
			if (maxd > dis) {
				maxd = dis;
				nexty = ny;
				nextx = nx;
				nextd = j;
			}
		}
		santa[i] = make_pair(nexty,nextx);
		//cout << i << " " << nexty << " " << nextx << '\n';
		rd = (nextd + 2) % 4;
		if (nexty ==ry && nextx==rx) {
			chkscoll(i);
		}
		else{
			map[sy][sx]=0;
			map[nexty][nextx]=i;
		}
	}

}

void heal() {

	for (int i = 1; i <= p; i++) {
		if (sdie[i] == 1)continue;
		score[i]++;
	}
	return;
}

int main() {
    cnt = 0;
	cin >> n >> m >> p >> c >> d;
	cin >> ry >> rx;
	sdie = vector<int>(p + 1);
	sstun = vector<int>(p + 1);
	score = vector<int>(p + 1,0);
	map = vector<vector<int>>(n + 1, vector<int>(n + 1));
	santa = vector<pair<int,int>>(p + 1);
	for (int i = 1; i <=p; i++) {
		int num, y, x;
		cin >> num >> y >> x;
		santa[num] = make_pair(y, x);
	}
	turn = 0;
	for (int i = 0; i < m; i++) {
		//cout << "# " << i + 1 << '\n';
		if (cnt == p)break;
		turn++;
		rudolmove();
		//pmap();
		chkrcoll();
		//pmap();
		santamove();
		//pmap();
		heal();
	}
	for (int i = 1; i <= p; i++) {
		cout << score[i] << " ";
	}
	cout << '\n';
}