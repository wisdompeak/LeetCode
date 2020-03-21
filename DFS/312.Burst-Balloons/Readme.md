### 312.Burst-Balloons

此题的关键是找出递推关系式.从上往下的比较容易理解.

令score[left,right]表示我们想消除[left,right]中所有元素能够得到的分数.消除所有元素的话,肯定有最后一枪:假设最后一枪是k,那么在打灭k之前,一定已经打灭了[left,k-1]和[k+1,right],这两部分的得分可以提前算出来,即score[left,k-1]和score[k+1,right].另外,最后打的K也会得分,分数是什么?注意,应该是nums[left-1]*nums[k]*nums[right+1],即涉及到[left,right]两端外的这两个元素.

所以总的递推关系:
```cpp
for (k=left, k<=right; k++)
  score(left,right) = max(score(left,k-1)+nums[left-1]*nums[k]*nums[right+1]+score(k+1,right));
```
这种关系可以由上往下通过递归实现,也可以由下而上写成动态规划的形式. 单纯递归的话可能会有重复的函数调用,采用记忆化存在dp数组的话就和动态规划完全一样了.


[Leetcode Link](https://leetcode.com/problems/burst-balloons)