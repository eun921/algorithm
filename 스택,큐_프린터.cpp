#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int size=priorities.size();
    while(size!=0){
        //첫번째 원소보다 더 큰 수가 존재하는지 확인
        int check=0;
        int first=priorities[0];
        for(int i=1;i<priorities.size();i++){
            if(first<priorities[i]){
                check=1;
                break;
            }
        }
        //존재한다면 첫번째 원소 지우고 마지막에 넣기
        //location 갱신
        if(check==1){
            priorities.erase(priorities.begin());
            priorities.push_back(first);
            if(location==0){
                location=priorities.size()-1;
            }
            else{
                location--;
            }
        }
        //존재하지 않는다면 첫번째 원소 삭제
        //location 갱신
        else{
            priorities.erase(priorities.begin());
            answer++;
            if(location==0){
                break;
            }
            else{
                location--;
            }
        }
        size=priorities.size();
    }
    return answer;
}