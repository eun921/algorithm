#include <string>
#include <vector>
using namespace std;

int answer = 0;

//dfs 재귀 호출
void dfs(vector<int>&num,int sum,int depth,int target){
    if(num.size()<=depth){
        if(sum==target){
            answer++;
        }
        return;
    }
    dfs(num,sum+num[depth],depth+1,target);
    dfs(num,sum+num[depth]*(-1),depth+1,target);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers,numbers[0],1,target);
    dfs(numbers,numbers[0]*(-1),1,target);
    return answer;
}