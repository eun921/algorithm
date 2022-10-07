#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> number, int sum, int depth, int target){
    //탈출조건
    //정수를 다 더하거나 뺀 후에
    //타겟 넘버와 sum이 같으면 answer++
    if(depth==number.size()){
        if(sum==target){
            answer++;
        }
        return;
    }
    dfs(number,sum+number[depth],depth+1,target); //더하는 경우
    dfs(number,sum-number[depth],depth+1,target); //빼는 경우
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers,numbers[0],1,target);
    dfs(numbers,numbers[0]*(-1),1,target);
    
    return answer;
}
