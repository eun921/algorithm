using namespace std;

//최대공약수 구하는 함수
int gcd(int w, int h){
    int tmp;
    while(h!=0){
        tmp=w%h;
        w=h;
        h=tmp;
    }
    return w;
    
}

//잘려진 사각형 개수=(W+H-최대공약수)
long long solution(int w,int h) {
    long long answer = 1;
    long long sum=(long long)w*h;
    answer=sum-(w+h)+gcd(w,h);
    return answer;
}