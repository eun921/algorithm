#include<vector>
#include <queue>
#include <iostream>

using namespace std;

int m,n;
bool check[101][101]={0}; //방문 확인
int bfsMap[101][101]={0}; //거리 확인

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1}; //아래, 우, 위, 왼

queue<pair<int,int>> q;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    m=maps.size(); //행(x)
    n=maps[0].size();//열(y)
    
    //시작점 대입
    q.push(make_pair(0,0));
    check[0][0]=true;
    bfsMap[0][0]=1;
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx<0||nx>=m||ny<0||ny>=n) continue;
            if(check[nx][ny]) continue;
            if(maps[nx][ny]==0) continue;
            
            check[nx][ny]=true;
            q.push(make_pair(nx,ny));
            bfsMap[nx][ny]=bfsMap[x][y]+1;
        }
    }
    
    if(!bfsMap[m-1][n-1]) answer=-1;
    else answer=bfsMap[m-1][n-1];
    
    return answer;
}
