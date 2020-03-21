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

#### 解法2：快慢指针
此题还有一个非常绝妙的算法。将1~N个数放在N+1个位置上，那么val->index将会出现一个一对多的映射，反之，index->val将会有一个多对一的映射。而其余的则是一一映射。于是这些index和val势必会有一部分构成一个环。

举个例子：2,4,1,3,1 从index到val的映射关系是：1->2, 2->4, {3,5}->1, 4->3，其中1->2->4->3->1就构成了一个环。可见，这个环的入口就是重复的数字。

于是此题可以联想到 142. Linked List Cycle II，用快慢指针来确定一个linked list中环的入口。算法是，先用快慢指针做追及（快指针的速度比慢指针快一倍），直到他们相遇的位置；再用一个慢指针从起点开始，和在追及位置的慢指针共同前进。他们再次相遇的地方就是环的入口。


[Leetcode Link](https://leetcode.com/problems/find-the-duplicate-number)