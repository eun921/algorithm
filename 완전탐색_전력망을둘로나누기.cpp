#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int graph[101][101]={0}; //간선 배열
vector<bool> visited; //방문 확인 배열

int dfs(int cur, int n){
    if(visited[cur]) return 0;
    int ret=1;
    visited[cur]=true;
    for(int i=1;i<=n;i++){
        if(graph[cur][i]){ //연결되어 있으며, 방문하지 않은 곳인 경우
            ret+=dfs(i,n);//몇 개의 정점으로 구성되어 있는지 파악
        }
    }
    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    //간선 표현
    for(int i=0;i<wires.size();i++){
        int x=wires[i][0];
        int y=wires[i][1];
        graph[x][y]=1;
        graph[y][x]=1;
    }
    
    //각 간선에 대해 두 연결망이 몇 개의 정점으로 이루어져 있는지 계산
    for(int i=0;i<wires.size();i++){
        int x=wires[i][0];
        int y=wires[i][1];
        graph[x][y]=graph[y][x]=0;
        
        visited=vector<bool>(n+1,false);
        vector<int> diff;
        
        for(int j=1;j<=n;j++){
            int tmp=dfs(j,n);
            if(tmp==0) continue;
            diff.push_back(tmp);
        }
        
        answer=min(answer,abs(diff[0]-diff[1]));
        if(answer==0) break; //두 연결망 개수가 같으면 최소이므로 종료
        graph[x][y]=graph[y][x]=1;
    }
    return answer;
}
