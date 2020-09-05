#include <stdio.h>
#include <vector>
#include <queue>

#define MAX 100000
#define INF 987654321
using namespace std;

typedef pair<int, int> P; // pair<int, int> = {cost, destination}
int dist[MAX + 1];

int main() {
	//freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);

	// dijkstra
	// cost(time) for walk = 1, cost(time) for teleport = 0
	for (int i = 0; i <= MAX; i++) {
		dist[i] = INF;
	}
	dist[N] = 0;

	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({ 0, N });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		// arrive to the target
		if (x == M) {
			printf("%d", cost);
			break;
		}

		// no more search
		if (dist[x] < cost) continue;
		
		
		if (2*x <= MAX && dist[2 * x] > cost) {
			dist[2 * x] = cost;
			pq.push({ dist[2 * x], 2 * x });
		}

		if (x + 1 <= MAX && dist[x + 1] > cost + 1) {
			dist[x + 1] = cost + 1;
			pq.push({ dist[x + 1], x + 1 });
		}

		if (x - 1 >= 0 && dist[x - 1] > cost + 1) {
			dist[x - 1] = cost + 1;
			pq.push({ dist[x - 1], x - 1 });
		}
	}

	return 0;
}
