#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    //map으로 선택지를 개수 계산
    //key는 의상 이름, value는 count값
    map<string,int> m;
    for(int i=0;i<clothes.size();i++){
        m[clothes[i][1]]++;
    }
    //iterator를 통해 map 조회
    //선택하지 않는 경우(+1)를 포함해서 계산
    map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        answer*=it->second+1;
    }
    //모두 선택하지 않는 경우를 빼서 리턴
    return answer-1;
}