#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    //스택 선언
    stack<char> stk;
    
    for(int i=0;i<s.size();i++){
        //여는 괄호면 push
        if(s[i]=='('){
            stk.push(s[i]);
        }
        //닫는 괄호이면
        //스택이 비어있지 않고 top값이 여는 괄호면 pop
        //비어 있으면 닫는 괄호 push
        else{
            if(!stk.empty()&&stk.top()=='('){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
        
        //스택 비어있으면 올바른 괄호
        if(stk.empty()){
            answer=true;
        }
        else{
            answer=false;
        }
    }  
    return answer;
}
