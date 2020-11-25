#include <stack>

int solution(string &S) {
    stack<char> st;
    for(int i = 0; i < S.length(); i++){
        char c = S.at(i);
        if(c == '(' || c == '[' || c == '{'){
            st.push(c);
        }
        else if(c == ')'){
            if(st.empty() || st.top() != '(') return 0;
            else st.pop();
        }
        else if(c == ']'){
            if(st.empty() || st.top() != '[') return 0;
            else st.pop();
        }
        else{
            if(st.empty() || st.top() != '{') return 0;
            else st.pop();
        }
    }
    if(!st.empty()) return 0;
    return 1;
}
