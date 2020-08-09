#include <stdio.h>

#define INF 987654321
#define mINF -987654321

typedef struct {
	int src, dest, cost;
}Edge;

Edge edge[6001];
int V, E; // 1 <= V <= 500, 1 <= 6000 <= E
long long dist[501];

void BellmanFord(int start) {
    // init dist[]
	for (int i = 1; i <= V; i++)
		dist[i] = INF;
	dist[start] = 0;

    // Using Bellman-Ford Algorithm
	for (int v = 0; v < V - 1; v++) {
		for (int e = 0; e < E; e++) {
			if (dist[edge[e].src] < INF && dist[edge[e].src] + edge[e].cost < dist[edge[e].dest])
				dist[edge[e].dest] = dist[edge[e].src] + edge[e].cost;
		}
	}

    // Use Algorithm again
    // if dist[] has changed, it means that there is a negative cycle
    // negative cycle -> dist[x] = mINF
	for (int v = 0; v < V - 1; v++) {
		for (int e = 0; e < E; e++) {
			if (dist[edge[e].src] < INF && dist[edge[e].src] + edge[e].cost < dist[edge[e].dest])
				dist[edge[e].dest] = mINF;
		}
	}

}

int isFail() {
	for (int i = 2; i <= V; i++)
		if (dist[i] == mINF) return 1;

	return 0;
}

int main() {
	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++)
		scanf("%d %d %d", &edge[i].src, &edge[i].dest, &edge[i].cost);



	BellmanFord(1);

	if (isFail()) {
		printf("-1\n");
	}
	else {
		for (int i = 2; i <= V; i++) {
			if (dist[i] == INF) printf("-1\n");
			else printf("%d\n", dist[i]);
		}

	}

	return 0;
}
