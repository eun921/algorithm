#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    //선택할 폰켓몬 수
    int n=nums.size()/2;
    
    //셋에 넣기(중복제거)
    set<int> mon;
    for(int i=0;i<nums.size();i++){
        mon.insert(nums[i]);
    }
    
    //폰켓몬 종류가 선택 가능 수보다 작으면 answer=폰켓몬 종류
    if(mon.size()<=n){
        answer=mon.size();
    }
    //폰켓몬 종류가 선택 가능 수보다 많으면 answer=전체 폰켓몬 수/2
    else{
        answer=n;
    }
    
    
    return answer;
}
