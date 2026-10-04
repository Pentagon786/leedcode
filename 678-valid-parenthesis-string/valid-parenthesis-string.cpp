class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Length = 1
        for (int i = 0; i < n; i++) {
            if (s[i] == '*')
                dp[i][i] = true;
        }

        // Length >= 2
        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                // '*' as empty
                if (s[i] == '*' && dp[i + 1][j])
                    dp[i][j] = true;

                if (dp[i][j]) continue;

                // Try matching first char with some k
                for (int k = i + 1; k <= j; k++) {

                    bool leftMatch =
                        (s[i] == '(' || s[i] == '*') &&
                        (s[k] == ')' || s[k] == '*');

                    if (!leftMatch)
                        continue;

                    bool inside =
                        (k == i + 1) ? true : dp[i + 1][k - 1];

                    bool remaining =
                        (k == j) ? true : dp[k + 1][j];

                    if (inside && remaining) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};