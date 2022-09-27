#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(vector<int> a,vector<int> b)//작업 소요시간 기준
    {
        return a[1]>b[1];
    }
};


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int i=0,time=0;
    //도착시간에 따른 오름차순으로 정렬
    sort(jobs.begin(),jobs.end());
    //최소 힙 선언
    priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
    
    //작업이 있거나 우선순위 큐가 비지 않으면 반복
    while(i<jobs.size()||!pq.empty()){
        
        //작업이 있고, 작업이 들어온 시간이 현재 시간보다 작거나 같으면
        //우선순위 큐에 넣기
        if(i<jobs.size()&&jobs[i][0]<=time){
            pq.push(jobs[i++]);
            continue;
        }
        
        //우선순위 큐가 비지 않았으면(대기 작업 존재)
        //최상위 값(작업시간 가장 작은 것)으로
        //대기 시간 갱신하고(현재 시간-들어온 시간), 현재 시간도 갱신함(현재 시간+소요시간)
        if(!pq.empty()){
            time+=pq.top()[1];
            answer+=time-pq.top()[0];
            pq.pop();
        }
        //우선순위 큐가 비었으면
        //대기 작업이 없으므로 다음 작업이 들어오는 시간으로 이동함
        else{
            time=jobs[i][0];
        }
    }
    //평균 계산
    
    answer/=jobs.size();
    return answer;
}
