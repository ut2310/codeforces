#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int longestCommonSubsequence(const string& text1, const string& text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    if (text1[0] == text2[0]) {
        dp[0][0] = 0;
    } else {
        dp[0][0] = 1;
    }

    bool flag = true;
    if (text1[0] == text2[0]) {
        flag = false;
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + 1;
        if (flag && text1[i] == text2[0]) {
            flag = false;
            dp[i][0] = dp[i - 1][0];
        }
    }

    flag = true;
    if (text1[0] == text2[0]) {
        flag = false;
    }

    for (int i = 1; i < m; i++) {
        dp[0][i] = dp[0][i - 1] + 1;
        if (flag && text1[0] == text2[i]) {
            dp[0][i] = dp[0][i - 1];
            flag = false;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            if (text1[i] == text2[j]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            } else {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}
