### 003.Longest Substring Without Repeating Characters

#### 解法1：
双指针的基础题。用```vector<int>Map(256,0)```来模拟字符的Hash表。

如果Map[s[j]]==0，移动右指针将Map[s[j]]=1； 否则移动左指针，将Map[s[i]]=0。

#### 解法2：
对于上述的方法，左指针的前移其实可以跳跃，以加快效率。

对于Map[s[j]]已经有记录的情况，此时左指针可以调到Map[s[j]]+1的地方。但是注意，这个地方可能还不及i本身，所以最终左指针的跳跃应该是```max(i,Map[s[j]]+1)```


[Leetcode Link](https://leetcode.com/problems/longest-substring-without-repeating-characters)