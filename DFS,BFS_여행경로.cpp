#include <string>
#include <vector>
#include <iostream>

using namespace std;

int visited[10000];
int ticketNum;
string tmp;

void dfs(int depth, int index, string sum, vector<vector<string>> &tickets){
    //모든 항공권 사용 완료 후
    //알파벳 순 정렬
    if(depth==ticketNum){
        sum+=tickets[index][1];
        if(tmp.compare("")==0||tmp.compare(sum)>0){
            tmp=sum;
        }
        return;
    }
    //아직 사용하지 않았고, 현재 항공권의 도착지와 다음 항공권의 출발지가 같으면
    //재귀 호출
    visited[index]=1; //항공권 사용 처리
    for(int i=0;i<ticketNum;i++){
        if(visited[i]==0&&tickets[index][1]==tickets[i][0]){
            dfs(depth+1,i,sum+tickets[i][0],tickets);
        }
    }
    visited[index]=0;
    return;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    //출발지가 ICN인 것을 찾아서 DFS
    ticketNum=tickets.size();
    for(int i=0;i<ticketNum;i++){
        if(tickets[i][0].compare("ICN")==0){
            dfs(1,i,"ICN",tickets);
        }
    }
    //여행 경로를 answer에 넣어줌
    //3글자씩 끊음
    for(int i=0,len=tmp.length();i<len;i+=3){
        string stmp="";
        stmp+=tmp[i];
        stmp+=tmp[i+1];
        stmp+=tmp[i+2];
        answer.push_back(stmp);
    }
    return answer;
}