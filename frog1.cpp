#include <bits/stdc++.h>
using namespace std;
long long int solve( long long i, vector<long long> &stones, vector<long long>& dp)
{
    if (i == stones.size() - 1)
        return 0;
    if (i > stones.size())
        return 1e9;

        if(dp[i]!=-1)
        return dp[i];

    long long int oneJump = abs(stones[i] - stones[i + 1]) + solve(i + 1, stones,dp);

    long long int twoJump = abs(stones[i] - stones[i + 2]) + solve(i + 2, stones,dp);

    return dp[i]=min(oneJump, twoJump);
}
int main()
{
    long long n;
    cin >> n;
    vector<long long> stones;
    vector<long long> dp(n+1,-1);
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        stones.push_back(ele);
    }

    cout<<solve(0,stones,dp);

    return 0;
}