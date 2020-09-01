#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    int idx=0;
    for(int i=0;i<completion.size();i++){
        if(participant[idx] == completion[idx]){
            idx++;
        }
    }
    return participant[idx];
}