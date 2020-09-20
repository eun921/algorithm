#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int t1,t2;
    //우선순위 큐 사용(오름차순)
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    //음식 섞기
    while(pq.top()<K&&pq.size()>1){
        answer++;
        t1=pq.top();
        pq.pop();
        t2=pq.top();
        pq.pop();
        pq.push(t1+2*t2);
    }
    if(pq.top()<K){
        return -1;
    }
    else return answer;
}