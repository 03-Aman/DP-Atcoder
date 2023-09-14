#include <bits/stdc++.h>
using namespace std;

long long int solve( long long i, vector<long long> &stones, long long& k, vector<long long>& dp)
{
    if (i == stones.size() - 1)
        return 0;
    

    if(dp[i]!=-1)
        return dp[i];

    long long ans=1e9;

    for(int j=1;j<=k;j++){
        if(i+j<stones.size())
        ans=min(ans,abs(stones[i]-stones[i+j])+solve(i+j,stones,k,dp));
    }

    return dp[i]=ans;
    
}
int main()
{
    long long n,k;
    cin>>n>>k;
    vector<long long> h;
    long long ele;
    vector<long long> dp(n+1,-1);
    for(long long i=0;i<n;i++){
        cin>>ele;
        h.push_back(ele);
    }

    cout<<solve(0,h,k,dp);
    return 0;
}