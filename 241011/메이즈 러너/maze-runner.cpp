#define _CRT_SECURE_WARNINGS
#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
using namespace std;
int n, m, k;
int ey, ex;

vector<vector<int>>map;
vector<pair<int, int>>player;
vector<int>pexit;
vector<int>pdis;
int ecnt;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
int range(int y,int x) {
	if (y<1 || y>n)return 0;
	if (x<1 || x>n)return 0;
	return 1;
}
void pmove() {

	for (int i = 1; i <= m; i++) {
		
		if (pexit[i] == 1)continue;
		//cout << i << "사람" << '\n';
		int py, px;
		tie(py, px) = player[i];
		int dis = abs(py-ey) + abs(px-ex);
		for (int d = 0; d < 4; d++) {
			int ny = py+dy[d];
			int nx = px +dx[d];
			if (!range(ny, nx))continue;
			if (map[ny][nx] > 0)continue;
			int ndis = abs(ey - ny) + abs(ex - nx);
			//cout <<ny<<" "<<nx<<" "<< ndis << " " << dis << '\n';
			if (ndis >= dis) continue;
			player[i] = make_pair(ny,nx);
			pdis[i]++;
			if (ny == ey && nx == ex) {
				pexit[i] = 1;
				ecnt++;
			}
			break;
			
		}

	}
	return;
}


tuple<int,int,int> findrc() {
	priority_queue<tuple<int, int, int>>pq;
	for (int i = 1; i <= m; i++) {
		if (pexit[i] == 1)continue;
		int py, px;
		tie(py, px) = player[i];
		int d = max(abs(py-ey), abs(px-ex));
		int ny, nx;
		if (py <= ey && px <= ex) {
			ny = max(1,ey - d);
			nx = max(1,ex - d);
		}
		else if (py <= ey && px > ex) {
			ny = max(1, ey - d);
			nx = max(1, px - d);
		}
		else if (py > ey && px <= ex) {
			ny = max(1, py - d);
			nx = max(1, ex - d);
		}
		else if (py > ey && px > ex) {
			ny = max(1, py - d);
			nx = max(1, px - d);
		}
		int nd= max(max(abs(ny - py), abs(nx - px)),max(abs(ny - ey), abs(nx - ex)))+1;
		//cout << "push " << " " << ny << " " << nx <<" "<<nd<< '\n';
		pq.push(make_tuple(-nd, -ny, -nx));
	
	}
	int d, r, c;
	tie(d, r, c) = pq.top();
	return make_tuple(-d, -r, -c);

}

void rotate(int d,int r,int c) {

	vector<vector<int>>temp(d,vector<int>(d));
	for (int i = 1; i <= m; i++) {
		if (pexit[i] == 1)continue;
		int py, px;
		tie(py, px) = player[i];
		if (py >= r&& py <r+d && px>=c && px<c+d) {
			player[i] = make_pair(px-c+r, d - 1 - py+r+c);
		}
	}

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			if (map[r+i][c+j] > 0)map[r+i][c+j]--;
			temp[i][j] = map[r + i][c + j];

		}
	}
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			map[r+j][c+d-1-i] = temp[i][j];
			
		}
	}

	int ney=ex - c + r;
	int nex = d - 1 - ey + r + c;
	ey = ney;
	ex = nex;
	return;

}

void pmap() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <=n; j++) {
			cout << map[i][j]<<' ';
		}
		cout << '\n';
	}
	cout << "\n";
	return;
}

void pwhere() {
	for (int i = 1; i <= m; i++) {
		int y, x;
		tie(y, x) = player[i];
		cout << i << "번 " << y << " " << x << '\n';
	}
	return;
}

void pd() {
	for (int i = 1; i <= m; i++) {
		cout <<i<<" "<< pdis[i] << " ";
	}
	cout << '\n';
	return;
}

int main() {
	cin >> n >> m >> k;
	ecnt = 0;
	map = vector<vector<int>>(n + 1, vector<int>(n + 1));
	player = vector<pair<int, int>>(m + 1);
	pexit = vector<int>(m + 1,0);
	pdis = vector<int>(m + 1,0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	
	for (int i = 1; i <= m; i++) {
		int y, x;
		cin >> y >> x;
		player[i] = make_pair(y,x);
	}
	cin >> ey >> ex;
	
	
	for (int i = 1; i <= k; i++) {
		
		//cout << "#" << i <<" "<<ecnt<< '\n';
		pmove();
		//pmap();
		//pwhere();	
		if (ecnt == m)break;
		int d, r, c;
		tie(d, r, c)=findrc();
		//cout << d << "    " << r << "    " << c << '\n';
		rotate(d, r, c);
		//pmap();
		//pwhere();
		
	}
	
	int ret = 0;
	for (int i = 1; i <= m; i++) {
		ret += pdis[i];
	}
	cout <<ret << '\n';
	
	cout <<ey<<" "<<ex<< '\n';
	
}