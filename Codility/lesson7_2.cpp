#include <stack>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    stack<int> st; // direction is downstream
    int cnt = 0;   // the number of alive fish of which direction is upstream
    int n = A.size();
    
    for(int i = 0; i < n; i++){
        if(B[i] == 1) st.push(A[i]);
        else{
            if(st.empty()) cnt++; // no predator, just pass
            else{
                // upstream fish eat continuously until meet the predator
                for(; !st.empty() && st.top() < A[i]; st.pop());
                if(st.empty()) cnt++; // all prey has eaten, just pass
            }
        }
    }
    // the number of fish of which direction is upstream/downstream
    return cnt + st.size();
    
}
