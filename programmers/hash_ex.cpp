#include <string>
#include <vector>
#include <unordered_map> // using hash, O(1) for search
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m; // <name, count>
    int N = participant.size();
    for(int i = 0; i < N; i++){
        m[participant[i]] += 1; // increase count for same name
    }
    
    for(int i = 0; i < N-1; i++){
        m[completion[i]] -= 1;
    }
    
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second != 0) return it->first;
    }

}
