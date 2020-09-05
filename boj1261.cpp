/* 
   Dijkstra Algorithm in 2D graph
*/
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

#define INF (1<<31-1)/2

using namespace std;

typedef pair<int, pair<int, int>> P;
int N, M;
char map[101][101];
int dist[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int isHere(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}

int main() {
	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &M, &N);
	getchar(); // erase '\n'

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &map[i][j]);
			dist[i][j] = INF;
		}
		getchar(); // erase '\n'
	}
	dist[0][0] = 0; // start point is (0, 0)

	// P = {cost, x, y}
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({ 0, {0, 0} });
	while (!pq.empty()) {
		P tmp = pq.top();
		int cost = tmp.first;
		int x = tmp.second.first;
		int y = tmp.second.second;
		pq.pop();

		// visit 4 direction
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!isHere(nx, ny)) continue;
			
			if (dist[nx][ny] > cost + map[nx][ny] - '0') {
				dist[nx][ny] = cost + map[nx][ny] - '0';
				pq.push({ dist[nx][ny], {nx, ny} });
			}
		}
	}

	printf("%d", dist[N - 1][M - 1]);

	return 0;
}
