### 3714.Longest-Balanced-Substring-II

因为此题限制了只有三种字符，所以可以暴力分解为三种情况：

只有一种字符的substring。那么整个substring都是符合条件的。

只有两种字符的substring。对于这部分substring，我们只需要对于前缀里两种字符的频次之差做Hash即可。在遍历该substring的过程中，如果发现当前的频次差曾经出现在了Hash中，那么意味着两个前缀所夹的子串就符合条件。

只有三种字符的substring，这其实就是针对整个原字符串。类似地，我们对前缀里三种字符的频次之差{a-c,b-c}做Hash即可。在遍历该substring的过程中，如果发现当前的频次差曾经出现在了Hash中，那么意味着两个前缀所夹的子串里a,b,c的频次是相同的。

