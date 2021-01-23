### 287. Find the Duplicate Number

#### 解法1：二分法
此题的二分法思想非常巧妙，将所有元素和n/2进行比较，如果大于n/2的个数多于n/2个，说明重复的元素必定在n/2到n之间。以此类推，可以不断缩小折半考察范围。  

举个general的例子，如果考察范围是left\~right，则考察 mid = left+(right-left)/2。如果比mid大的元素个数，多于mid\~n之间的个数，则说明重复的元素在mid\~n之间。
```cpp
count = 大于mid的个数
if (count > n-mid) 
  left=mid+1;  //注意是n-mid 不是 right-mid
else 
  right=mid;
```  
直到left和right重合，即为所求的答案。

或者
```cpp
count = 小于等于mid的个数
if (count < mid) 
  right=mid;  //注意是n-mid 不是 right-mid
else 
  left=mid+1;
```  

#### 解法2：indexing sort
利用indexing sort的方法，我们尝试将n+1个数组元素尽可能地按照“index==value”的方法重新放置在1~n+1这些位置上。放置完之后，必然是有n个位置的index==val，而有一个index对应的nums[index]!=index，并且该位置的数值就是duplicated number。

[Leetcode Link](https://leetcode.com/problems/find-the-duplicate-number)
