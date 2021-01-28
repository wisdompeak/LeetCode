### 1416.Restore-The-Array

令dp[i]表示以第i个数字结尾的array有多少种。我们考察最后一个number是什么？显然只需要遍历最后一个number的范围s[j:i]（最多不超过10个digit）。只要s[j:i]符合题目的要求（没有leading zero、在[1,k]之间），那么就可以更新```dp[i]+=dp[j-1]```.
