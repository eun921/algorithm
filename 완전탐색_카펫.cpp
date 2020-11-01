#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    //전체 격자 수 구하기
    int sum=brown+yellow;
    //높이는 3부터 반복
    for(int height=3;;height++){
        //나누어 떨어지는 것이 가로 길이가 됨
        if(!(sum%height)){
            //가로 길이 구하기
            int weight=sum/height;
            //노란 격자의 수와 일치하면 answer에 삽입
            if((height-2)*(weight-2)==yellow){
                answer.push_back(weight);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}