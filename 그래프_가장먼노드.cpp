#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    // 그래프(dist), 방문여부(visit), 누적(dist) 초기화 
    int **graph = new int*[n+1]; 
    int *dist = new int[n+1]; 
    bool *visit = new bool[n+1]; 
    memset(dist, 0, sizeof(int)*(n+1)); 
    memset(visit, false, sizeof(bool)*(n+1));

    for(int i = 1; i < n+1; i++) { 
        graph[i] = new int[n+1]; 
        memset(graph[i], 0, sizeof(int)*(n+1)); 
    }
    for(int i=0; i<edge.size(); i++){
        graph[edge[i][0]][edge[i][1]] = 1;
        graph[edge[i][1]][edge[i][0]] = 1; 
    }
    
    int start_node=1; //1번 정점부터 시작
    int max_distance=0;//최대 거리 저장
    queue<int> q;
    q.push(start_node);//큐에 1번 노드를 넣고
    visit[start_node]=true;//1번 노드 방문 표시
    
    while(!q.empty()){
        start_node=q.front();//큐에서 가장 최근에 방문한 노드를 꺼내고
        q.pop();//큐에서 제거
        
        //1~n번 정점 순회
        for(int target_node=1;target_node<=n;target_node++){
            //간선이 연결되어 있고 방문하지 않았다면
            if(graph[start_node][target_node]==1&&visit[target_node]==false){
                //가중치에 1을 더해 누적해 나가면서
                dist[target_node]=dist[start_node]+1;
                //가장 먼 노드의 거리를 저장
                if(dist[target_node]>max_distance){
                    max_distance=dist[target_node];
                }
                //큐에 방문한 노드를 넣고
                q.push(target_node);
                //방문표시
                visit[target_node]=true;
            }
        }
    }
    //최대 거리를 가지는 노드들의 개수를 구함
    for(int i=0;i<=n;i++){
        if(dist[i]==max_distance){
            answer++;
        }
    }
    return answer;
}