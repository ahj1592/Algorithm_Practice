#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 987654321

int dist[501][501];

void init() {
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		init(); // init dist[][]

		int N, M, W;
		scanf("%d %d %d", &N, &M, &W);

		// input edges
		int src, dest, cost;
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &src, &dest, &cost);
           
            // store minimum cost
			if (dist[src][dest] > cost)
				dist[src][dest] = cost;

			if (dist[dest][src] > cost)
				dist[dest][src] = cost;
		}

		// input wormhole
		for (int i = 0; i < W; i++) {
			scanf("%d %d %d", &src, &dest, &cost);
			dist[src][dest] = -cost;
		}

		// Floyd Algorithm
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int isNegCycle = 0;

        // if(dist[x][x] < 0), there is a negative cycle
        
        // detecting negative cycle
		for (int i = 1; i <= N; i++) {
			if (dist[i][i] < 0) {
				isNegCycle = 1;
				break;
			}
		}

		if (isNegCycle) printf("YES\n");
		else printf("NO\n");
        
	} // while(TC)

	return 0;
}
