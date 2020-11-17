#include <string>
#include <vector>

using namespace std;

int answer=9;

void cal(int n, int goal, int cnt, int sum){
    //8보다 크면 리턴
    if(cnt>8) return;
    //목표값과 같아지는 경우
    //최소횟수 갱신
    if(sum==goal){
        if(answer>cnt) answer=cnt;
    }
    int tmp=0;
    for(int i=1;i<=8;i++){
        //n 추가
        tmp=(tmp*10)+n;
        //사칙연산
        cal(n,goal,cnt+i,sum+tmp);
        cal(n,goal,cnt+i,sum-tmp);
        cal(n,goal,cnt+i,sum*tmp);
        cal(n,goal,cnt+i,sum/tmp);
    }
}
int solution(int N, int number) {
    cal(N,number,0,0);
    if(answer>8) answer=-1;
    return answer;
}