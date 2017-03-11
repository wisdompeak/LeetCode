###159. Longest-Substring-with-At-Most-Two-Distinct Characters  
需要一个记录每种字符出现次数的映射，这里为了加快效率，我们不用Map，而是直接用一个数组 vector<int>Map(128,0)，用字符的ascii码作为index，注意需要开辟至少128个空间才能装下所有字母字符。  
另外还需要一个计数器count还记载目前指针范围内有几种字符。  

当右移right的时候：  
 a. 如果新字符已经出现过，只要Map[nums[right]]++即可，count不用改变。    
 b. 如果新字符未曾出现过，则Map[nums[right]]=1，自然count++。此时如果count>2的话，就需要left不断右移直到count==2，这个过程中每一步都要Map[nums[left]]--，如果发现Map[nums[left]]==0则可以将count--。
