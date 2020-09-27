#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(int a=0;a<commands.size();a++){
        int i=commands[a][0];
        int j=commands[a][1];
        int k=commands[a][2];
        vector<int> tmp;
        for(int b=i-1;b<j;b++){
            tmp.push_back(array[b]);
        }
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[k-1]);
    }
    
    return answer;
}