#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    //물 웅덩이 위치 확인하기 위한 배열
    int check[101][101] = {0, };
    //목표지점까지 경로의 수 저장하기 위한 배열
    int visited[101][101] = {0, };
    
    //물 웅덩이 위치 저장
    for(int i = 0; i < puddles.size(); i++)
        check[puddles[i][1]][puddles[i][0]] = -1;
    //시작 위치
    visited[1][0] = 1;
    //물웅덩이 있으면 0으로
    //없으면 visited[i - 1][j] + visited[i][j - 1]을 해주고 바로 1000000007로 나누어줌
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(check[i][j] == -1)
                visited[i][j] = 0;
            else
                visited[i][j] = (visited[i - 1][j] + visited[i][j - 1]) % 1000000007;
        }
    }
    return visited[n][m];
}