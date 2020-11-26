#include <stack>
using namespace std;
int solution(string &S) {
    stack<char> st;
    int n = S.length();
    for(int i = 0; i < n; i++){
        char c = S.at(i);
        if(c == '(') st.push(c);
        else{
            if(!st.empty() && st.top() == '(') st.pop();
            else st.push(c);
        }
    }

    if(st.empty()) return 1;
    return 0;
}
