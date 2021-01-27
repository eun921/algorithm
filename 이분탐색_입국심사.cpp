#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    int size=times.size();
    sort(times.begin(),times.end());
    long long min=1;
    long long max=(long long)(times[size-1])*n;
    long long answer=max;
    
    //이진 탐색
    while(min<=max){
        long long mid=(min+max)/2;
        long long sum=0;
        //시간을 기준으로, 그 시간에 해결 가능한지 검사
        //전체 걸리는 추정 시간 값을 각 심사관별 심사 시간으로 나누면
        //한 심사관이 맡은 입국자 수가 나오게 됨
        //이를 모두 더해서 주어진 입국자 수를 감당 가능한지 계산
        for(int i=0;i<size;i++){
            sum+=mid/times[i];//한 심사관 당 담당 인원 수
        }
        if(n>sum)
            min=mid+1;
        else{
            if(mid<=answer)
                answer=mid;
            max=mid-1;
        }
    }
    return answer;
}