#include <string>
#include <vector>
using namespace std;

int answer{100};

void dfs(string begin, string target, vector<string> words, vector<bool>& check, int cnt=0){
    //단어의 개수만큼 반복
    for(int i=0;i<words.size();i++){
        //알파벳 일치여부 초기화
        int count{0};
        //한글자씩 반복하면서 글자가 다를 경우 count 증가
        for(int j=0;j<words[i].length();j++){
            if(!check[i]&&begin[j]!=words[i][j])
                count++;
        }
        //한 글자만 다른 경우
        if(count==1){
            //한 글자만 다른 단어가 target이고 
            //answer가 지금까지 들어온 깊이+1보다 큰 경우 answer 반환
            if(target==words[i]&&answer>cnt+1){
                answer=cnt+1;
                return;
            }
            //단어 사용 체크하고 재귀적 호출
            check[i]=true;
            dfs(words[i],target,words,check,cnt+1);
            //단어 사용 해제
            check[i]=false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    //사용한 단어 체크용 변수 선언
    vector<bool> check(words.size(),false);
    dfs(begin,target,words,check);
    //answer가 100이면 target까지 갈 수 없으므로 0리턴
    if(answer==100) return 0;
    return answer;
}