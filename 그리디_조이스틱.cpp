#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    //A로 채워진 string과 비교
    string s="";
    for(int i=0;i<name.size();i++){
        s+="A";
    }
    //name과 s 같지 않으면 계속 반복
    int tmp=0;
    while(name!=s){
        answer+=min(name[tmp]-'A','Z'+1-name[tmp]);
        s[tmp]=name[tmp];
        if(name==s){
            return answer;
        }
        
        //왼쪽 이동 횟수 구하기
        int left=tmp;
        int leftcnt=0;
        while(s[left]==name[left]){
            left--;
            leftcnt++;
            //왼쪽 범위 벗어나는 경우
            if(left==-1){
                left=name.size()-1;
            }
        }
        //오른쪽 이동 횟수 구하기
        int right=tmp;
        int rightcnt=0;
        while(s[right]==name[right]){
            right++;
            rightcnt++;
            //오른쪽 범위 벗어나는 경우
            if(right==name.size()){
                right=0;
            }
        }
        //둘 중 횟수 최소인 것 선택
        if(leftcnt<rightcnt){
            answer+=leftcnt;
            tmp=left;
        }
        else{
            answer+=rightcnt;
            tmp=right;
        }
    }
    return answer;
}