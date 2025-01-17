#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define MAX_N 1000
#define MAX_M 20

struct Result {
	int y, x;
};

extern void init(int N, int M, int Map[MAX_N][MAX_N]);
extern Result findTreasureChest(int Pieces[MAX_M][MAX_M]);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static int mSeed;
static int pseudo_rand(void)
{
	mSeed = mSeed * 431345 + 2531999;
	return mSeed & 0x7FFFFFFF;
}

#include<iostream>
#include<vector>
#include<string>
#include<tuple>
#include<set>
#include<algorithm>
#include <bitset>
using namespace std;

static int Map[MAX_N][MAX_N];
static int Pieces[MAX_M][MAX_M];

vector<vector<int>>map;
vector<vector<int>>cmap;
vector<vector<int>>pmap;
vector<bitset<400>>puzzle;
//bitset<400> puzzle[4];
bitset<400> oripart;
int n, m;


int findsum(int y, int x) {
	return cmap[y+m][x+m] - cmap[y][x+m] - cmap[y+m][x] + cmap[y][x];
	
}
void init(int N, int M, int Map[MAX_N][MAX_N]){

	n = N;
	m = M;
	map = vector<vector<int>>(n, vector<int>(n, 0));
	cmap = vector<vector<int>>(n+1, vector<int>(n+1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { 
			map[i][j] = Map[i][j];
			cmap[i+1][j+1] = cmap[i][j+1] + cmap[i+1][j] - cmap[i][j] + Map[i][j];
		}
	}
	return;
}
void resetcmap() {
	cmap = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cmap[i + 1][j + 1] = cmap[i][j + 1] + cmap[i + 1][j] - cmap[i][j] + map[i][j];
		}
	}
	return;
}
vector<vector<int>>rotateright(vector<vector<int>>puzz) {
	vector<vector<int>>temp= vector<vector<int>>(m, vector<int>(m, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			temp[j][m - 1 - i] = puzz[i][j];
		}
	}
	return temp;
}
pair<int, int>rr(int y,int x) {
	return make_pair(x,m-1-y);
}
void sett(vector<vector<int>>pmap,int k) {
	puzzle[k].reset(); // 초기화
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if (pmap[i][j] == 1) {
				puzzle[k].set(i * m + j); // 비트를 설정
			}
		}
	}
	return;
	
}

void settmap(int y,int x) {
	oripart.reset(); // 초기화
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[y + i][x + j] == 1) {
				oripart.set(i * m + j); // 비트를 설정
			}
		}
	}
	return;

}

tuple<int, int, int>findstpoint(int pcnt) {
	int sty = -1;
	int stx = -1;
	int rrcnt = -1;
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			if (findsum(i, j) < pcnt)continue;
			
			settmap(i, j);

			for (int k = 0; k < 4; k++) {
				
				if ((oripart&puzzle[k])== puzzle[k]){
					sty = i;
					stx = j;
					rrcnt = k;
					return make_tuple(sty,stx,rrcnt);
				}
			}
			
		}
	}
	return make_tuple(sty, stx, rrcnt);
}

Result findTreasureChest(int Pieces[MAX_M][MAX_M]){
	pmap = vector<vector<int>>(m, vector<int>(m, 0));
	puzzle=vector<bitset<400>>(4);
	int py = -1;
	int px = -1;
	int pcnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (Pieces[i][j] == 1) {
				pmap[i][j] = 1;
				pcnt++;
			}
			else if (Pieces[i][j] == 9) {
				pmap[i][j] = 1;
				py = i;
				px = j;
				pcnt++;
			}
		}
	}

	for (int k = 0; k < 4; k++) {
		sett(pmap,k);
		pmap = rotateright(pmap);
	}
	
	int sty, stx, rrcnt;
	tie(sty,stx,rrcnt)=findstpoint(pcnt);
	//cout << sty << " " << stx << " " << rrcnt << '\n';
	for (int i = 0; i < rrcnt; i++) {
		tie(py, px) = rr(py, px);
	}
	//cout << py << " " << px << '\n';
	int ry=sty+py;
	int rx=stx+px;

	for (int k = 0; k < rrcnt; k++) {
		pmap = rotateright(pmap);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (pmap[i][j] == 1) {
				map[sty+i][stx+j] -= 1;
			}
		}
	}
	resetcmap();
	//cout << ry << " " << rx << '\n';
	//cout << '\n';
	return Result({ ry,rx });


}



static int run(int Ans)
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; ++i) {
		int num;
		int cnt = N / 30;
		int idx = 0;
		for (int k = 0; k < cnt; ++k) {
			scanf("%d", &num);
			for (int m = 0; m < 30; ++m) {
				Map[i][idx++] = num & 0x01;
				num = num >> 1;
			}
		}

		if (N % 30) {
			scanf("%d", &num);
			for (int m = 0; m < (N % 30); ++m) {
				Map[i][idx++] = num & 0x01;
				num = num >> 1;
			}
		}
	}

	init(N, M, Map);
	

	for (int t = 0; t < K; ++t) {
		int num, sy, sx;
		scanf("%d %d %d %d", &mSeed, &num, &sy, &sx);

		for (int i = 0; i < M; ++i)
			for (int k = 0; k < M; ++k)
				Pieces[i][k] = 0;

		int y = pseudo_rand() % M;
		int x = pseudo_rand() % M;
		Pieces[y][x] = 9;
		for (int i = 1; i < num; ++i) {
			y = pseudo_rand() % M;
			x = pseudo_rand() % M;
			Pieces[y][x] = 1;
		}

		Result answer = findTreasureChest(Pieces);
		if ((answer.y != sy) || (answer.x != sx))
			Ans = 0;
	}

	return Ans;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, Ans;
	scanf("%d %d", &T, &Ans);

	for (int tc = 1; tc <= T; tc++) {
		printf("#%d %d\n", tc, run(Ans));
	}

	return 0;
}