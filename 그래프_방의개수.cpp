#include <string>
#include <vector>
#include <map>

using namespace std;

int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};

//방이 생성되는 경우는 방문했던 정점을 재방문하는 경우
//현재 만들어지는 간선이 기존에 만들어진 적 없으면서, 하나의 정점을 재방문하는 경우

int solution(vector<int> arrows) {
    map<pair<int,int>,bool> node_visit;
    map<pair<pair<int,int>, pair<int,int>>, bool> edge_visit;
    
    int answer = 0;
    int x=0;
    int y=0;
    node_visit[{x,y}]=true;
    for(int i=0;i<arrows.size();i++){
        int dir=arrows[i];
        for(int j=0;j<2;j++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            
            if(node_visit[{nx,ny}]==true){
                if(edge_visit[{{x,y},{nx,ny}}]==false||edge_visit[{{x,y},{nx,ny}}]==0){
                    answer++;
                }
            }
            //정점 체크
            node_visit[{nx,ny}]=true;
            //엣지 체크
            edge_visit[{{x,y},{nx,ny}}]=true;
            edge_visit[{{nx,ny},{x,y}}]=true;
            x=nx;
            y=ny;
        }
    }
    return answer;
}