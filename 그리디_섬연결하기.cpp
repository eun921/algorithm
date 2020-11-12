#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;

//한 정점에서 모든 정점을 지나는 최소 경로를 구하는 문제
//MST알고리즘 (Kruskal) 사용

//가중치에 따른 오름차순 정렬 위한 비교
bool cmp(vector<int> a, vector<int> b){
    return a[2]<b[2];
}
//부모노드 찾기
int getParent(int x){
    //부모노드가 자신이라면 자신을 리턴
    if(parent[x]==x) return x;
    //아니라면 최상위 부모노드 찾기
    return parent[x]=getParent(parent[x]);
}
//부모노드 병합
void unionParent(int a, int b){
    a=getParent(a);
    b=getParent(b);
    //작은쪽으로 병합
    if(a<b)
        parent[b]=a;
    else
        parent[a]=b;
}
//부모노드가 같은지 비교
int find(int a, int b){
    a=getParent(a);
    b=getParent(b);
    if(a==b) return 1;
    else return 0;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    //가중치 기준으로 오름차순 정렬
    sort(costs.begin(),costs.end(),cmp);
    
    for(int i=0;i<n;i++){
        parent.push_back(i);
    }
    for(int i=0;i<costs.size();i++){
        //두 개의 부모노드가 같지 않다면
        //결과에 가중치 추가하고 부모노드 병합
        if(!find(costs[i][0],costs[i][1])){
            answer+=costs[i][2];
            unionParent(costs[i][0],costs[i][1]);
        }
    }
    return answer;
}