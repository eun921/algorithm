#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> one={1,2,3,4,5};
vector<int> two={2,1,2,3,2,4,2,5};
vector<int> three={3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> result(3);
    int size=answers.size();
    for(int i=0;i<size;i++){
        if(answers[i]==one[i%one.size()])
            result[0]++;
        if(answers[i]==two[i%two.size()])
            result[1]++;
        if(answers[i]==three[i%three.size()])
            result[2]++;
    }
    int max = -1;
    for(int i=0;i<3;i++){
        if(max<=result[i])
            max=result[i];
    }
    for(int i=0;i<3;i++){
        if(result[i]==max){
            answer.push_back(i+1);
        }
    }
    return answer;
}