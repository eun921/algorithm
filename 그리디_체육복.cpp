#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //가진 체육복 수를 담을 vector 전부 1로 설정
    vector<int> student(n,1);
    //lost,reserve 배열 반영
    for(int i=0;i<lost.size();i++){
        student[lost[i]-1]--;
    }
    for(int i=0;i<reserve.size();i++){
        student[reserve[i]-1]++;
    }
    //체육복이 없는 경우 앞,뒷번호 확인해 갱신
    for(int i=0;i<n;i++){
        if(student[i]==0){
            if(i!=0&&student[i-1]==2){
                student[i-1]--;
                student[i]++;
            }
            if(i!=n-1&&student[i+1]==2){
                student[i+1]--;
                student[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(student[i]>=1){
            answer++;
        }
    }
    return answer;
}