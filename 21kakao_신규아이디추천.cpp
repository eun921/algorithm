#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    //1단계 - 대문자를 소문자로 치환
    for(int i=0;i<new_id.length();i++){
        if(new_id[i]>='A'&&new_id[i]<='Z'){
            new_id[i]=tolower(new_id[i]);
        }
    }
    
    //2단계 - 알파벳, 소문자, 숫자, 빼기, 밑줄, 마침표를 제외한 모든 문자 제거
    for(int i=0;i<new_id.length();){
        if((new_id[i]>='a'&&new_id[i]<='z')||(new_id[i]>='0'&&new_id[i]<='9')||(new_id[i]=='-')||(new_id[i]=='_')||(new_id[i]=='.')){
            i++;
            continue;
        }
        new_id.erase(new_id.begin()+i);
    }
    
    //3단계 - 마침표가 2번 이상 연속된 부분을 하나로 치환
    for(int i=1;i<new_id.length();){
        if(new_id[i]=='.'&&new_id[i-1]=='.'){
            new_id.erase(new_id.begin()+i);
            continue;
        }
        else{
            i++;
        }
    }
    
    //4단계 - 마침표가 처음이나 끝에 위치한다면 제거
    if(new_id.front()=='.'){
        new_id.erase(new_id.begin());
    }
    if(new_id.back()=='.'){
        new_id.erase(new_id.end()-1);
    }
    
    //5단계 - 빈 문자열이라면 a대입
    if(new_id.length()==0){
        new_id="a";
    }
    
    //6단계 - 길이가 16자 이상이면 첫 15개 제외하고 나머지 제거
    //제거후 마침표가 끝에 있다면 마침표 제거
    if(new_id.length()>=16){
        while(new_id.length()!=15){
            new_id.erase(new_id.begin()+15);
        }
    }
    if(new_id.back()=='.'){
        new_id.erase(new_id.end()-1);
    }
    
    //7단계 - 길이가 2자 이하라면 마지막 문자를 길이가 3이 될 때까지 추가
    if(new_id.length()<=2){
        while(new_id.length()!=3){
            new_id+=new_id.back();
        }
    }
    answer=new_id;
    return answer;
}
