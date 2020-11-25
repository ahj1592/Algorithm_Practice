#include <algorithm>

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    int mul1 = A[n-1] * A[n-2] * A[n-3];
    int mul2 = A[n-1] * A[0] * A[1];

    if(mul1 >= mul2) return mul1;
    return mul2;
}
