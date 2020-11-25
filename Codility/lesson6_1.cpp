#include <algorithm>
int solution(vector<int> &A) {
    /* Fucking Exception !!!! */
    if(A.size() == 0) return 0;
    
    sort(A.begin(), A.end());
    int ans = 1;
    for(int i = 1; i < A.size(); i++){
        if(A[i] != A[i-1]) ans++;
    }
    return ans;
}
