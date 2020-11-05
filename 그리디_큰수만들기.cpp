#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int start=0, size=number.size()-k;
    //정답 문자열의 i번째 수를 구함
    //i번째 숫자부터 size-i번째 사이를 탐색하면서
    //범위 내 가장 큰 숫자가 i번째 숫자가 됨
    for(int i=0;i<size;i++){
        char maxnum=number[start];
        int maxidx=start;
        for(int j=start;j<=i+k;j++){
            if(maxnum<number[j]){
                maxnum=number[j];
                maxidx=j;
            }
        }
        //다음 탐색은 정답 숫자의 다음 인덱스부터
        start=maxidx+1;
        answer+=maxnum;
    }
    return answer;
}