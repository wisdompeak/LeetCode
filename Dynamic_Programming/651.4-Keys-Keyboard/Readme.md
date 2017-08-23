### 651.4-Keys-Keyboard

对于dp[i]，考察j=3~i-1，每个dp[j]通过ctrl-A,ctrl-C之后可以通过若干个ctrl-V做到倍增.
```cpp
  dp[i]=max(dp[i],dp[j]+i-j);
  if (j>2) dp[i]=max(dp[i],dp[j]*(i-2-j+1));
```

