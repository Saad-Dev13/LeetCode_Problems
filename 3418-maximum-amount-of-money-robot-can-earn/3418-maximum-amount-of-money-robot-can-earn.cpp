class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        const long long INF = 1e16;
        
        vector<vector<long long>> dp(n + 1, vector<long long>(3, -INF));

        for (int k = 0; k < 3; k++) {
            dp[1][k] = 0;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = coins[i][j];
                int col = j + 1;

                dp[col][2] = max({dp[col - 1][2] + x, dp[col][2] + x, dp[col - 1][1], dp[col][1]});

                dp[col][1] = max({dp[col - 1][1] + x, dp[col][1] + x, dp[col - 1][0], dp[col][0]});

                dp[col][0] = max(dp[col - 1][0], dp[col][0]) + x;
            }
        }

        return dp[n][2];
    }
};
#define MY_MAX(a, b) ((a) > (b) ? (a) : (b))

long long max4_val(long long a, long long b, long long c, long long d) {
    long long res = MY_MAX(a, b);
    res = MY_MAX(res, c);
    return MY_MAX(res, d);
}

long long maximumAmount(int** coins, int coinsSize, int* coinsColSize) {
    int m = coinsSize;
    int n = coinsColSize[0];
    
    const long long INF_VAL = 1e16;
    
    long long** dp = (long long**)malloc((n + 1) * sizeof(long long*));
    for (int j = 0; j <= n; j++) {
        dp[j] = (long long*)malloc(3 * sizeof(long long));
        for (int k = 0; k < 3; k++) {
            dp[j][k] = -INF_VAL;
        }
    }

    for (int k = 0; k < 3; k++) {
        dp[1][k] = 0;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x = coins[i][j];
            int col = j + 1;

            long long next2 = max4_val(dp[col - 1][2] + (long long)x, 
                                       dp[col][2] + (long long)x, 
                                       dp[col - 1][1], 
                                       dp[col][1]);

            long long next1 = max4_val(dp[col - 1][1] + (long long)x, 
                                       dp[col][1] + (long long)x, 
                                       dp[col - 1][0], 
                                       dp[col][0]);

            long long next0 = MY_MAX(dp[col - 1][0], dp[col][0]) + (long long)x;

            dp[col][2] = next2;
            dp[col][1] = next1;
            dp[col][0] = next0;
        }
    }

    long long result = dp[n][2];

    for (int j = 0; j <= n; j++) {
        free(dp[j]);
    }
    free(dp);

    return result;
}