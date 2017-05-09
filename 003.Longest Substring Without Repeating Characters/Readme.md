### 003.Longest Substring Without Repeating Characters

双指针的基础题。用vector<int>Map(256,0)来模拟字符的Hash表。

如果Map[s[j]]==0，移动右指针将Map[s[j]]=1； 否则移动左指针，将Map[s[i]]=0。
