### 76. Minimum-Window-Substring  

典型的双指针题型。

对于每个新加入的元素s[j]，首先更新该字符出现次数的Map[s[i]]++。如果更新后，Map[s[i]]等于需要出现的次数Table[s[i]]，则计数器count++，说明有一个字符满足了出现次数的要求．

当count等于t中的字符类型数COUNT时，说明任务已经实现。此时，让左指针不断右移，相应的Map[s[i]]就要自减，一旦`Map[s[i]] < Table[s[i]]`，则count需要自减1从而不再满足COUNT，说明需要继续加入新元素才能满足任务. 从而j才可以右移继续遍历。

在这个过程中如果满足条件count==COUNT，都需要不断更新和记录结果。


[Leetcode Link](https://leetcode.com/problems/minimum-window-substring)
