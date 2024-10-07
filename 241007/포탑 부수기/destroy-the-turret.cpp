#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<unordered_set>
using namespace std;

pair<int, int> map[12][12]; //공격력, 가장 최근 공격
bool visited[12][12];
pair<int, int> before[12][12];
int n, m, k;
unordered_set<int> us; //간접피해 포탑 좌표 저장용
queue<pair<int, int> > q;

void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << map[i][j].first << " ";
		cout << "\n";
	}
	cout << endl;
}

int oob(int i, int j) {
	if (i < 0)	return 1;
	if (i >= n)	return 2;
	if (j < 0)	return 3;
	if (j >= m)	return 4;
	return 0;
}

pair<pair<int, int>, pair<int, int> > pick_attacker_and_target() { //공격자, 타겟 선정
	pair<pair<int, int>, pair<int, int> > attacker = { {-0x7fffffff,0}, {1, 1} }, target = { {0x7fffffff,0}, {0, 0} };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j].first == 0)
				continue;
			attacker = max(attacker, make_pair(make_pair(-map[i][j].first, map[i][j].second), make_pair(i + j, j)));
			target = min(target, make_pair(make_pair(-map[i][j].first, map[i][j].second), make_pair(i + j, j)));
		}
	return { {attacker.second.first - attacker.second.second, attacker.second.second}, {target.second.first - target.second.second, target.second.second} };
}

void attack(pair<int, int> attacker, pair<int, int> target) { //공격
	int dr[4] = { 0, 1, 0, -1 }, dc[4] = { 1, 0, -1, 0 };
	map[attacker.first][attacker.second].first += n + m;
	us.insert(attacker.first*100 + attacker.second);
	us.insert(target.first*100 + target.second);
	q = {};
	memset(visited, false, sizeof(visited));
	q.push(attacker);
	visited[attacker.first][attacker.second] = true;
	while (!q.empty()) {
		int cur_i = q.front().first, cur_j = q.front().second;
		q.pop();
		if (cur_i == target.first && cur_j == target.second) {
			map[cur_i][cur_j].first -= map[attacker.first][attacker.second].first;
			int stri = cur_i, strj = cur_j;
			cur_i = before[stri][strj].first, cur_j = before[stri][strj].second;
			while (cur_i != attacker.first || cur_j != attacker.second) {
				stri = cur_i, strj = cur_j;
				us.insert(cur_i * 100 + cur_j);
				map[cur_i][cur_j].first -= map[attacker.first][attacker.second].first / 2;
				cur_i = before[stri][strj].first, cur_j = before[stri][strj].second;
			}
			return;
		}
		for (int dir = 0; dir < 4; dir++) {
			int ii = cur_i + dr[dir], jj = cur_j + dc[dir];
			int ret = oob(ii, jj);
			if (ret == 1) ii = n - 1;
			else if (ret == 2) ii = 0;
			else if (ret == 3) jj = m - 1;
			else if (ret == 4) jj = 0;
			if (!visited[ii][jj] && map[ii][jj].first != 0) {
				q.push({ ii, jj });
				visited[ii][jj] = true;
				before[ii][jj] = { cur_i, cur_j };
			}
		}
	}
	int dr_sub[8] = { 0, 0, 1, 1, 1, -1, -1, -1 }, dc_sub[8] = { 1, -1, 0, 1, -1, 0, 1, -1 };
	map[target.first][target.second].first -= map[attacker.first][attacker.second].first;
	for (int dir = 0; dir < 8; dir++) {
		int ii = target.first + dr_sub[dir], jj = target.second + dc_sub[dir];
		int ret = oob(ii, jj);
		if (ret == 1) ii = n - 1;
		else if (ret == 2) ii = 0;
		else if (ret == 3) jj = m - 1;
		else if (ret == 4) jj = 0;
		if (map[ii][jj].first == 0 || ii == attacker.first && jj == attacker.second)
			continue;
		map[ii][jj].first -= map[attacker.first][attacker.second].first / 2;
		us.insert(ii * 100 + jj);
	}
}

bool crash_tower() { //살아남은 포탑이 1개면 false 반환
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j].first <= 0)
				map[i][j].first = 0;
			else
				cnt++;
		}
	if (cnt == 1)
		return false;
	return true;
}
	
void fix_tower() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (us.find(i * 100 + j) != us.end() || map[i][j].first == 0)
				continue;
			map[i][j].first++;
		}
	us.clear();
}

int solve() {
	for (int turn = 1; turn <= k; turn++) {
		pair<pair<int, int>, pair<int, int> > att_tar = pick_attacker_and_target();
		attack(att_tar.first, att_tar.second);
		map[att_tar.first.first][att_tar.first.second].second = turn;
		if (!crash_tower())
			break;
		fix_tower();
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ret = max(ret, map[i][j].first);
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j].first;
			map[i][j].second = 0;
		}
	cout << solve();
	return 0;
}