#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
//소수 확인하는 함수
bool check(int n){
    int end=sqrt(n);
    for(int i=2;i<=end;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> num;
    vector<int> result;
    //numbers 숫자로 분리해서 num에 넣고 정렬
    for(int i=0;i<numbers.size();i++){
        num.push_back(numbers[i]-'0');
    }
    sort(num.begin(),num.end());
    
    //숫자 조합하고 정렬한 후 중복 삭제
    do{
        for(int i=0;i<=num.size();i++){
            int tmp=0;
            for(int j=0;j<i;j++){
                tmp=(tmp*10)+num[j];
                result.push_back(tmp);
            }
        }
    }while(next_permutation(num.begin(),num.end()));
    sort(result.begin(),result.end());
    result.erase(unique(result.begin(),result.end()),result.end());
    
    //소수 검사
    for(int i=0;i<result.size();i++){
        if(result[i]<2) continue;
        if(check(result[i])) answer++;
    }
    return answer;
}