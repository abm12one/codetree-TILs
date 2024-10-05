#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<tuple>
#include<cmath>
#include<queue>
using namespace std;
int n, m, p, c, d;
int ry, rx,rd;
vector<pair<int, int>>santa;
vector<vector<int>>map;
vector<int>sdie;
vector<int>sko;
vector<int>score;
priority_queue<tuple<int, int, int>>pq;
int dy[8] = {-1,0,1,0,-1,-1,1,1};
int dx[8] = {0,1,0,-1,-1,1,-1,1};
int turn;
void setmap(){
	pq=priority_queue<tuple<int, int, int>>();
	map = vector<vector<int>>(n + 1, vector<int>(n + 1,0));
	for(int i=1;i<=p;i++){
		if (sdie[i] == 1)continue;
		
		int sy, sx;
		tie(sy, sx) = santa[i];
		map[sy][sx] = i;
		int dis = pow(abs(ry - sy), 2) + pow(abs(rx - sx), 2);
		pq.push(make_tuple(-dis,sy,sx));
	}
	int a, desty, destx;
	tie(a, desty, destx) = pq.top();
	int mindist = 987654321;
	int rety, retx,retd;
	for (int i = 0; i < 8; i++) {
		int ny=ry+dy[i];
		int nx=rx+dx[i];
		int dis = pow(abs(desty - ny), 2) + pow(abs(destx - nx), 2);
		if (mindist > dis) {
			mindist = dis;
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


int range(int y,int x) {
	if (y<1 || y>n)return 0;
	if (x<1 || x>n)return 0;
	return 1;
}
void moverudol() {
	
	if (map[ry][rx] == 0) return;

	int s = map[ry][rx];
	score[s] += c;

	int nowy = ry;
	int nowx = rx;
	int nowd = rd;
	map[nowy][nowx] = 0;
	int ny = nowy + c*dy[nowd];
	int nx = nowx + c*dx[nowd];
	if (!range(ny, nx)) {
		sdie[s] = 1;
	}
	sko[s] = turn;
	if (map[ny][nx] == 0) {
		santa[s] = make_pair(ny,nx);
	}
	while (1) {
		if (!range(ny, nx)) break;

		if (map[ny][nx] != 0) {
			int heres = map[ny][nx];
			ny += dy[nowd];
			nx += dx[nowd];
			if (!range(ny, nx)) {
				sdie[heres] = 1;
				break;
			}
			santa[heres] = make_pair(ny,nx);

		
		}
		else {

			break;
		}


	}
	return;
	

}

void moves(int num) {
	int sy, sx;
	tie(sy,sx)= santa[num];
	pq = priority_queue<tuple<int, int, int>>();
	for (int i = 0; i < 4; i++) {
		int ny=sy+dy[i];
		int nx = sx + dx[i];
		if (!range(ny, nx))continue;
		if(map[ny][nx]!=0)
	}

}


void santamove() {
	map = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= p; i++) {
		if (sdie[i] == 1)continue;
		int sy, sx;
		tie(sy, sx) = santa[i];
		map[sy][sx] = i;
	}
	for (int i = 1; i <= p; i++) {
		if (sdie[i] == 1)continue;
		if (sko[i] != 0 && turn - sko[i] < 2) continue;
		moves(i);

	}

}


int main() {
	cin >> n >> m >> p >> c >> d;
	cin >> ry >> rx;
	santa = vector<pair<int, int>>(p + 1);
	sdie = vector<int>(p + 1);
	sko = vector<int>(p + 1);
	score = vector<int>(p + 1);
	for (int i = 0; i < p; i++) {
		int num, ty, tx;
		cin >> num >> ty >> tx;
		santa[num] = make_pair(ty,tx);
	}
	turn = 0;
	while (1) {
		turn++;

		moverudol();

	}


}