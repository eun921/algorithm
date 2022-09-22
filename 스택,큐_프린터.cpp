#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int size=priorities.size();
    
    //우선순위 담긴 우선순위큐(자동으로 최대힙으로 구성됨)
    //인덱스와 우선순위 담긴 큐
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    
    //큐에 넣기
    for(int i=0;i<size;i++){
        pq.push(priorities[i]);
        q.push(make_pair(i,priorities[i]));
    }
    
    //큐가 비어있지 않으면 반복
    //우선순위 높은 순서대로 출력해야함
    while(!q.empty()){
        //대기목록 가장 앞에 있는 문서의 인덱스, 우선순위 저장하고 pop

        int id=q.front().first;
        int p=q.front().second;
        q.pop();
        
        //현재 문서의 우선순위와 우선순위큐의 top 우선순위가 같으면 우선순위 큐에서 pop
        if(p==pq.top()){
            pq.pop();
            answer++;
            //pop하는 문서가 요청한 문서면 break
            if(id==location){
                break;
            }
        }
        //현재 문서의 우선순위가 우선순위큐의 top 우선순위가 다르면
        //더 높은 우선순위를 가진 문서가 있다는 뜻이므로 
        //우선순위큐에서 pop하지 않고, 큐 가장 뒤에 다시 넣음
        else{
            q.push(make_pair(id,p));
            
        }
        
    }

    return answer;
}
