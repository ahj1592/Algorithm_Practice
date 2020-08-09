#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int LCS[1010][1010];

int main() {
	//freopen("input.txt", "r", stdin);
	// input two strings
  string str1, str2;
	cin >> str1 >> str2;

  // init LCS[][]
	for (int i = 0; i <= str2.length(); i++)
		LCS[i][0] = 0;
	for (int j = 0; j <= str1.length(); j++)
		LCS[0][j] = 0;

	for (int i = 0; i <= str2.length(); i++) {
		for (int j = 0; j <= str1.length(); j++) {
			if (str2[i] == str1[j]) LCS[i + 1][j + 1] = LCS[i][j] + 1;
			else LCS[i + 1][j + 1] = max(LCS[i + 1][j], LCS[i][j + 1]);
		}
	}



	cout << LCS[str2.length()][str1.length()] << endl;

	return 0;
}
