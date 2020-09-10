#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size=prices.size();
    vector<int> answer(size);
    
    //뒤에서부터 비교
    for(int i=size-1;i>=0;i--){
        //일단 최대 시간으로 설정
        answer[i]=size-1-i;
        //현재 가격보다 이후 가격이 더 작으면 answer 갱신
        for(int j=i+1;j<size;j++){
            if(prices[i]>prices[j]){
                answer[i]=j-i;
                break;
            }
        }
    }
    return answer;
}