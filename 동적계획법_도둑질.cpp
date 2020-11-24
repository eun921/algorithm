#include <string>
#include <vector>
#define MAX 1000010
using namespace std;
 
int dp[MAX];
int dp2[MAX];
int max(int A, int B) 
{ 
    if (A > B) return A;
    return B; 
}
 
int solution(vector<int> money)
{
    int n = money.size() - 1;
    //첫번째 집을 터는 경우
    dp[0] = money[0];
    dp[1] = dp[0];
    //첫번째 집을 털지 않는 경우
    dp2[0] = 0;
    dp2[1] = money[1];
    
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
    }
    for (int i = 2; i <= n; i++)
    {
        dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);
    }
    
    return max(dp[n - 1], dp2[n]);
}