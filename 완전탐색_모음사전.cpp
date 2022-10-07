#include <string>
#include <vector>

using namespace std;

string words="AEIOU";
int answer=0, cnt=0;

void dfs(string tmp, string target){
    if(tmp==target) answer=cnt;
    if(tmp.length()>5) return;
    
    cnt++;
    for(int i=0;i<words.length();i++){
        dfs(tmp+words[i],target);
    }
    
}

int solution(string word) {
    dfs("",word);
    return answer;
}
