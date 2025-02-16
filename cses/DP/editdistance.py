s1 = input()
s2 = input()
def longestCommonSubsequence(text1, text2):
    dp = [[0 for i in range(len(text2))] for j in range(len(text1))]
    
    if text1[0] == text2[0]:
        dp[0][0] = 0
    if text1[0] != text2[0]:
        dp[0][0] = 1
    
    flag = True
    if text1[0] == text2[0]:
        flag = False
    for i in range(1, len(text1)):
        dp[i][0] = dp[i - 1][0] + 1
        if flag and text1[i] == text2[0]:
            flag = False
            dp[i][0] = dp[i - 1][0]
    flag = True
    if text1[0] == text2[0]:
        flag = False
    for i in range(1, len(text2)):
        dp[0][i] = dp[0][i - 1] + 1
        if flag and text1[0] == text2[i]:
            dp[0][i] = dp[0][i - 1]
            flag = False
    for i in range(1, len(text1)):
        for j in range(1, len(text2)):
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1)
            if text1[i] == text2[j]:
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1])
            else:
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1)
    return dp[len(text1) - 1][len(text2) - 1]
    
print(longestCommonSubsequence(s1, s2))