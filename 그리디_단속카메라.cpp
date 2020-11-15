#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    //진입지점을 기준으로 정렬
    sort(routes.begin(),routes.end());
    //가장 먼저 진입한 차의 진출 시점으로 tmp 설정
    int tmp=routes[0][1];
    //차량의 진출 시점이 tmp 이전에 있을 경우 tmp를 진출 시점으로 갱신
    //카메라를 만나지 않을 경우 카메라 새로 설치하고 tmp값 갱신
    for(int i=1;i<routes.size();i++){
        if(routes[i][1]<tmp){
            tmp=routes[i][1];
        }
        if(routes[i][0]>tmp){
            answer++;
            tmp=routes[i][1];
        }
    }
    return answer;
}