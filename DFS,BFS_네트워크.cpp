#include <string>
#include <vector>
#define MAX 200

using namespace std;

bool visited[MAX];
int DFS(vector<vector<int>> computers, vector<int> numbers, int n){
    visited[n]=true;//방문 표시
    for(int i=0;i<numbers.size();i++){
        if(!visited[i]&&numbers[i]==1)//미방문노드이고 연결된 노드이면 DFS호출
            DFS(computers,computers[i],i);
    }
    return 0;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){//방문하지 않은 노드면
            DFS(computers,computers[i],i);//DFS탐색
            answer++;
        }
    }
    return answer;
}