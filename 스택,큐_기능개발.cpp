#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    while(progresses.size()){
        int count=0;
        //작업 진행 계산
        for(int j=0;j<progresses.size();j++){
            progresses[j]+=speeds[j];
        }
        //진도 100넘으면 삭제하고 count계산
        while(progresses.size()>0&&progresses[0]>=100){
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            count++;
        }
        if(count>0){
            answer.push_back(count);
        }
    }
    return answer;
}