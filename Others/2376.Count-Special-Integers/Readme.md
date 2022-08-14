### 2376.Count-Special-Integers

本题本质和`1012.Numbers-With-Repeated-Digits`，完全一致。如果本题的答案是`X`，那么`N-X`就是1012的答案。

基本思路就是递归和数学方法相结合。我们从高到低穷举每一位的digit的可能。如果当前构造的高位数字已经注定比N小，那么剩下的排列方法就是一个组合数计算。如果当前构造的高位数字和N是一样的，那么就递归处理下一位。

大致的思路是：
```cpp
void dfs(string s, int i)  // 处理s的第i位
{  
  for (int d = 0; d <= 9; d++) {
    if (visited[d]) continue;
    if (d < s[i]) 
        ret += Permuation(未使用的数字个数，未填充的位数)；  
    else if (d == s[i])
    {
        visited[d] = 1;
        dfs(s, i);
    }
  }
}  
```
