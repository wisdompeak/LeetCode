### 76. Minimum-Window-Substring  

典型的双指针题型。

对于每个新加入的元素，统计s中字符出现次数的数组showTimes[s[i]]++。过程中，如果showTims[s[i]]等于需要出现的次数Map[s[i]]，则计数器count++，说明这个字符的出现次数已经达标.

当count等于所有待满足条件的字符总数TotalNums时，说明任务已经实现。此时，让left指针不断右移，相应的showTimes就要自减，一旦showTimes[s[left]] < Map[s[left]]，则count需要自减1从而不再满足TotalNums；在这个过程中如果满足条件count==TotalNum，都需要不断更新和记录结果。
