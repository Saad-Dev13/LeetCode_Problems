class Solution {
public:
    int dp[201][201][201];

    vector<int> v;
    int n;
    const int mod = 1e9+7;
    int solve(int i,int gcd1,int gcd2){
        if(i==n){
            if(gcd1>0 and gcd2>0 and gcd1==gcd2) return 1;
            else return 0;
        }
        if(dp[i][gcd1][gcd2]!=-1) return dp[i][gcd1][gcd2];
        int ans=0;
        //3 choices

        //skip i
        ans=solve(i+1,gcd1,gcd2);
        //take gcd of v[i] and gcd1
        ans = (ans + solve(i+1,gcd(gcd1,v[i]),gcd2))%mod;
        //take gcd of v[i] and gcd2
        ans = (ans + solve(i+1,gcd1,gcd(gcd2,v[i])))%mod;

        return dp[i][gcd1][gcd2]=ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        v=nums;
        n=nums.size();
        return solve(0,0,0);
    }
};