### 340.Longest-Substring-with-At-Most-K-Distinct-Characters.cpp

请多练，条件判断要考虑全面，做到bug free  

基本的模板是：
```
int i = 0;
for (int j=0; j<s.size(); j++)
{
  Map[s[j]]++;
  
  if (满足条件）
  {
    记录和更新答案；
  }
  else (不满足条件，需要移动左指针)
  {
    Map[s[i]]--;
    处理Map；
    i++;
  }  
}
```


[Leetcode Link](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters)