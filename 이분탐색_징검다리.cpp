#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int len=rocks.size();
    if(len==n)
        return distance;
    
    sort(rocks.begin(),rocks.end());//정렬
    
    //바위들 사이 간격 저장
    vector<int> gap; 
    int start = 0; 
    for(int i = 0; i < rocks.size(); i++){
        gap.push_back(rocks[i] - start);
        start = rocks[i]; 
    } 
    gap.push_back(distance - start);

    int left=1;
    int right=distance;
    //이진탐색
    while(left<right){
        //mid를 바위 사이 최소 간격으로 설정
        //간격이 가능한지 판단
        int mid=(left+right+1)/2;
        int idx=0;
        int count=0;
        for(int i=0;i<=len;i++){
            if(mid<=gap[i]+idx){
                idx=0;
            }
            else{
                count++;
                idx+=gap[i];
            }
        }
        //불가능한 경우
        if(count>n){
            right=mid-1;
        }
        //가능한 경우
        else{
            left=mid;
        }
    }
    return left;
}