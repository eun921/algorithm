#include <string>
#include <vector>
#define max_int 501

using namespace std;

int answer, height, d[max_int][max_int];

int max(int a, int b){
    return a > b ? a : b;
}

int solution(vector<vector<int>> triangle) {
    //초기값 설정
    answer = d[0][0] = triangle[0][0];
    //높이 계산
    height = (int)triangle.size();
    
    for(int i=1; i<height; i++){
        for(int j=0; j<=i; j++){
            //삼각형 제일 왼쪽 끝인 경우
            if(j == 0){
                d[i][j] = d[i-1][j] + triangle[i][j];
            //삼각형 제일 오른쪽 끝인 경우
            }else if(j == i){
                d[i][j] = d[i-1][j-1] + triangle[i][j];
            }
            //내부인 경우
            else{
                d[i][j] = max(d[i-1][j-1], d[i-1][j]) + triangle[i][j];
            }
            // 최대값 갱신
            answer = max(answer, d[i][j]);
        }
    }
        
    return answer;
}