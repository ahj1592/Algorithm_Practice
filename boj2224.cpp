#include <iostream>
using namespace std;

int map[58][58] = { 0, };

bool possible(int i, int j, int k) {
	if (map[i][k] > 0 && map[k][j] > 0) return true;
	else return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	getchar();
	char src, dest;
	int ans = 0;

	for (int i = 0; i < TC; i++) {
		scanf("%c => %c", &src, &dest);
		getchar();
		//cout << src << dest << endl;
		map[src - 'A'][dest - 'A'] = 1;
	}

	for (int k = 0; k < 58; k++) {
		for (int i = 0; i < 58; i++) {
			for (int j = 0; j < 58; j++) {
				map[i][j] = map[i][j] | (map[i][k] & map[k][j]);
			}
		}
	}

	for (int i = 0; i < 58; i++) {
		for (int j = 0; j < 58; j++) {
			if (map[i][j] && i != j) {
				ans++;
			}
		}
	}
	cout << ans << endl;

	for (int i = 0; i < 58; i++) {
		for (int j = 0; j < 58; j++) {
			if (map[i][j] && i!=j) {
				printf("%c => %c\n", i + 'A', j + 'A');
			}
		}
	}

	return 0;
}
