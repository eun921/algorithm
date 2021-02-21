#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    //선수의 수, 경기 결과를 2차원 배열
    vector<vector<bool>> graph(n+1,vector<bool>(n+1,false));
    //승리한 경우에 추가
    for(auto r:results){
        int winner=r[0];
        int loser=r[1];
        graph[winner][loser]=true;
    }
    //플로이드 와샬 알고리즘
    for(int b=1;b<=n;b++){
        for(int a=1;a<=n;a++){
            for(int c=1;c<=n;c++){
                if(graph[a][b]&&graph[b][c])
                    graph[a][c]=true;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int count=0;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            //a가 b를 이겼거나 b가 a를 이긴 경우
            if(graph[i][j]||graph[j][i])
                count++;
        }
        //둘중에 승패가 확실한 경우
        if(count==n-1)
            answer++;
    }   
    return answer;
}