### 287. Find the Duplicate Number

#### 算法：二分法
此题的二分法思想非常巧妙，将所有元素和n/2进行比较，如果大于n/2的个数多于n/2个，说明重复的元素必定在n/2到n之间。以此类推，可以不断缩小折半考察范围。  

举个general的例子，如果考察范围是left~right，则考察 mid = left+(right-left)/2。如果比mid大的元素个数，多余mid~n之间的个数，则说明重复的元素在mid~n之间。
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
