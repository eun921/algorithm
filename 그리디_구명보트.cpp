#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int left=0, right=people.size()-1;
    //오름차순 정렬
    sort(people.begin(),people.end());
    
    while(left<=right){
        //가장 적은 무게의 사람과 가장 많은 무게의 사람이 같이 탈 수 있는지 확인
        //limit을 넘으면 가장 많이 나가는 사람이 혼자 타야함
        if(people[left]+people[right]<=limit){
            right--;
            left++;
        }
        else{
            right--;
        }
        answer++;
    }
    return answer;
}