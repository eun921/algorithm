#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    //정렬
    sort(phone_book.begin(),phone_book.end()); 
    int len=phone_book.size();

    //반복문을 통해 접두어에 해당하는지 확인
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if(phone_book[i]==phone_book[j].substr(0,phone_book[i].size())){
                return false;
            }
        }
    }
    return true;
}