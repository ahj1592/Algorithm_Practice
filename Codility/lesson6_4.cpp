#include <algorithm>

int solution(vector<int> &A) {
    int n = A.size();
    if(n < 3) return 0;
    
    sort(A.begin(), A.end());
    int ret = 0;
    for(int i = 0; i < n - 2; i ++){
        // Do not assing long long a = A[i] + A[i + 1]
        // long <- int(already overflowed)
        long long a = A[i];
        long long b = A[i + 1];
        long long c = A[i + 2];
        if(a + b > c){
            ret = 1;
            break;
        }
    }

    return ret;
}
