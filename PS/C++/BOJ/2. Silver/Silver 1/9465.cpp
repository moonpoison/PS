#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n=0;
        cin>>n;
        vector<vector<int>> arr(2, vector<int>(100000));
        vector<vector<int>> dp(2, vector<int>(100000));
        for(int i=0;i<2;++i)
            for(int j=0;j<n;++j)
                cin>>arr[i][j];
        dp[0][0]=arr[0][0]; dp[1][0]=arr[1][0]; dp[0][1]=arr[0][1]+dp[1][0]; dp[1][1]=arr[1][1]+dp[0][0];
        for(int i=2;i<n;++i)
        {
            dp[0][i]=arr[0][i]+max(dp[1][i-1], dp[1][i-2]);
            dp[1][i]=arr[1][i]+max(dp[0][i-1], dp[0][i-2]);
        }
        cout<<max(dp[0][n-1], dp[1][n-1])<<endl;
    }
}