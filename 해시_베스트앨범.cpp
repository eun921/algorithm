//실패코드
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//비교함수 정의
bool cmp(pair<int,int> v1, pair<int,int> v2){
    if(v1.first>v2.first) return true;
    else if(v1.first==v2.first) return v1.second<v2.second;
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> music;
    vector<string> list;
    
    //재생횟수 합 계산
    //장르를 따로 list에 저장
    for(int i=0;i<genres.size();i++){
        if(music[genres[i]]==0){
            music[genres[i]]+=plays[i];
            list.push_back(genres[i]);
        }
        else{
            music[genres[i]]+=plays[i];
        }
    }
    //가장 많이 들은 장르, 두번째로 많이 들은 장르 탐색
    int first=0,second=0;
    string first_name, second_name;
    for(int i=0;i<list.size();i++){
        if(music[list[i]]>first){
            first=music[list[i]];
            first_name=list[i];
        }
    }
    music[first_name]=0;//가장 많이 들은 장르는 빼줌
    for(int i=0;i<list.size();i++){
        if(music[list[i]]>second){
            second=music[list[i]];
            second_name=list[i];
        }
    }
    
    //가장 많이, 두번째로 많이 들은 장르의 인덱스별 들은 횟수를 저장함
    vector<pair<int,int>> first_genre;
    vector<pair<int,int>> second_genre;
    int first_c=0, second_c=0;
    for(int i=0;i<genres.size();i++){
        if(genres[i]==first_name){
            first_genre.push_back(make_pair(plays[i],i));
            first_c++;
        }
        if(genres[i]==second_name){
            second_genre.push_back(make_pair(plays[i],i));
            second_c++;
        }
    }
    
    //정렬
    sort(first_genre.begin(),first_genre.end(),cmp);
    sort(second_genre.begin(),second_genre.end(),cmp);
    
    //answer에 추가
    for(int i=0;i<first_genre.size();i++){
        if(i==2) break;
        answer.push_back(first_genre[i].second);
    }
    for(int i=0;i<second_genre.size();i++){
        if(i==2) break;
        answer.push_back(second_genre[i].second);
    }
    return answer;
}

//성공코드
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//비교함수 정의
bool cmp(pair<string,int> v1, pair<string,int> v2){
    return v1.second>v2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> music;
    vector<pair<string, int>> list;
    
    //장르 별 재생횟수 합 계산
   for(int i=0;i<genres.size();i++){
       music[genres[i]]+=plays[i];
   }
    //value를 기준으로 정렬하기 위해 map을 vector에 저장
    map<string,int>::iterator iter;
    for(iter=music.begin();iter!=music.end();++iter){
        list.push_back(make_pair(iter->first,iter->second));
    }
    //재생 횟수를 기준으로 정렬
    sort(list.begin(),list.end(),cmp);
    
    //장르 별로 많이 재생된 두 곡 찾음
    for(int i=0;i<list.size();i++){
        int first=0, second=0;
        int first_n=0, second_n=0;
        for(int j=0;j<genres.size();j++){
            if(genres[j]==list[i].first){
                if(plays[j]>first){
                    second=first;
                    second_n=first_n;
                    first=plays[j];
                    first_n=j;
                }
                else if(plays[j]>second){
                    second=plays[j];
                    second_n=j;
                }
            }
        }
        answer.push_back(first_n);
        if(second>0){
            answer.push_back(second_n);
        }
    }
    return answer;
}