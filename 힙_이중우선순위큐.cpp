#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    //앞뒤로 접근 가능한 dequeue 사용
    deque<int> dq;
    
    //연산 처리
    for(int i=0;i<operations.size();i++){
        string opr=operations.at(i);
        int num=stoi(opr.substr(2));
        //insert 처리
        if(opr[0]=='I'){
            dq.push_back(num);
            sort(dq.begin(),dq.end());
        }
        //delete 처리
        else {
            if(dq.empty()){
                continue;
            }
            if(num==1){
                dq.pop_back();
            }
            else{
                dq.pop_front();
            }
        }
    }
    if (dq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    return answer;
}