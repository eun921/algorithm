#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int next=0;//대기중인 트럭 중 맨 처음 트럭
    int totalweight=0;//다리 위에 있는 트럭 무게의 합
    queue<int> on_bridge;//다리 위에 있는 트럭 큐
    
    //처음에는 다리에 아무 트럭도 없으므로 길이만큼 0(무게)을 push
    for(int i=0;i<bridge_length;i++){
        on_bridge.push(0);
    }
    
    while(!on_bridge.empty()){
        //시간 지나면 트럭이 다리 빠져나가므로
        //다리 위 트럭 무게 재계산
        answer++;
        totalweight-=on_bridge.front();
        on_bridge.pop();
        
        //대기중인 트럭이 있는 경우
        if(next<truck_weights.size()){
            //다리 위에 트럭이 올라갈 수 있으면 큐에 트럭 무게 삽입
            if(totalweight+truck_weights[next]<=weight){
                totalweight+=truck_weights[next];
                on_bridge.push(truck_weights[next]);
                next++;
            }
            //올라갈 수 없으면 큐에 0 삽입
            else{
                on_bridge.push(0);
            }
        }
    }
    return answer;
}