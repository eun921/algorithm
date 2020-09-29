#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//string 비교 함수
//두 string을 더했을 때 큰 값을 가지는 것이 우위를 가짐
bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
	vector<string> tmp;
    //numbers의 수를 string 벡터에 넣기
	for (int i = 0; i < numbers.size(); i++) {
		tmp.push_back(to_string(numbers[i]));
	}
    //정렬
	sort(tmp.begin(),tmp.end(),cmp);
    //tmp의 숫자를 다 이어붙여서 answer 계산
	for(int i=0;i<tmp.size();i++){
        answer+=tmp[i];
    }
    //answer의 첫번째 숫자가 0이면 가장 큰 값이 0이라는 뜻이므로 0 리턴
	if (answer[0] == '0')
		return "0";
	return answer;
}