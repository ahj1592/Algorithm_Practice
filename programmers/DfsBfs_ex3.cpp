#include <string>
#include <vector>
#include <queue>

using namespace std;

bool cmp_words(string s1, string s2){
    int cnt = 0;
    bool ret = true;
    for(int i = 0; i < s1.length(); i++){
        if(s1.at(i) != s2.at(i)) cnt++;
        if(cnt >= 2) {
            ret = false;
            break;
        }
    }
    return ret;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool isfind = false;
    int n = words.size();
    vector<int> visit(n, 0);
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    while(!q.empty()){
        string cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(cur == target) {
            answer = dist;
            isfind = true;
            break;
        }
        
        for(int i = 0; i < n; i++){
            if(!visit[i] && cmp_words(cur, words[i])){
                q.push({words[i], dist + 1});
                visit[i] = true;
            }
        }
    }
    
    return answer;
}
