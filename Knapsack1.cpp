#include <bits/stdc++.h>
using namespace std;
int n;
int w;
vector<vector<int>> arr;
vector<vector<long long>>dp;
long long solve(int i, vector<vector<int>>& arr, int w, vector<vector<long long>>& dp){
    if(i==0){
        if(arr[0][0]<=w)
        return arr[0][1];

        return 0;
    }
    
    if(dp[i][w]!=-1)
    return dp[i][w];

    long long take=0;
    if(arr[i][0]<=w)
    take=arr[i][1]+solve(i-1,arr,w-arr[i][0],dp);

    long long notTake=solve(i-1,arr,w,dp);

    return dp[i][w]=max(take,notTake);
}
int main()
{   cin>>n>>w;
    arr.resize(n,vector<int>(2));
    dp.resize(n,vector<long long>(w+1,-1));
    for(int i=0;i<n;i++)
    cin>>arr[i][0]>>arr[i][1];

    cout<<solve(n-1,arr,w,dp);
    return 0;
}