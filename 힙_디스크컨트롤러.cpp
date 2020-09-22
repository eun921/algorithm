#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a.at(1)>b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int i=0,time=0;
    //도착시간에 따른 오름차순으로 정렬
    sort(jobs.begin(),jobs.end());
    //최소 힙 선언
    priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
    //대기 작업이 없고 우선순위 큐가 빌 때까지 반복
    while(i<jobs.size()||!pq.empty()){
        //대기 작업이 존재하고 
        //그 작업이 들어오는 시간이 현재 시간보다 작다면
        //우선순위 큐에 추가
        if(i<jobs.size()&&time>=jobs[i][0]){
            pq.push(jobs[i++]);
            continue;
        }
        //큐가 비어있지 않다면
        //작업 수행시간 계산
        //대기시간 계산
        if(!pq.empty()){
            time+=pq.top()[1];
            answer+=time-pq.top()[0];
            pq.pop();
        }
        //큐가 비어 있다면
        //다음 작업 시간으로 넘김
        else{
            time=jobs[i][0];
        }
    }
    //평균 계산
    return answer/jobs.size();
}