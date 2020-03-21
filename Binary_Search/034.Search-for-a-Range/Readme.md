### 034.Search-for-a-Range

#### 寻找下界函数lower_bound()	
```cpp
auto pos=lower_bound(MyVector.begin(), MyVector.end(), val) ;	
```
函数lower_bound()在first和last中的前闭后开区间进行二分查找，返回大于或等于val的第一个元素位置。如果所有元素都小于val，则返回last的位置. 
自定义比较函数：
```cpp
static bool cmp(long long a, long long b)  
{         
  return (a<=b);         
}    
pos=lower_bound(q.begin(),q.end(),val,cmp);
```
分析：将val看做自定义比较函数中的b，满足条件的a都会摆在b的前面，然后返回值就是b的位置。  
例如：如果a<=b，则所有小于等于val的数都会放在插入位置之前，即插入的位置是第一个大于val的地方；  
同理，如果a<b，则所有小于val的数都会放在插入位置之前，即插入的位置是第一个大于等于val的地方。

#### 寻找上界函数upper_bound()	
```cpp
auto pos=upper_bound(MyVector.begin(), MyVector.end(), val) ;	
```
函数upper_bound()在first和last中的前闭后开区间进行二分查找，返回指向第一个比参数大的元素，故有可能是MyVector.end()。
自定义比较函数：
```cpp
static bool cmp(long long a, long long b)  
{         
  return (a<=b);
}    
pos=lower_bound(q.begin(),q.end(),val,cmp);
```
分析：将val看做自定义比较函数中的a，满足条件的b都会摆在a的前面，然后返回值依然是b的位置。  
例如：如果a<b，则插入的位置必定大于val（即第一个大于val的元素地址）；  
同理，如果a<=b，则插入的位置必定大于等于val（即第一个大于等于val的元素地址）  

#### 二分搜索法    
常规的二分搜索，但是要注意选择好合适的框架。如果等号的情况不容易判断，那就从大于或小于的情况下手。

对于下确界，可以分析出应该这么判断： 
```cpp
if (nums[mid]<target)
  left = mid+1; // 不等于target的mid元素都可以排除
else
  right = mid;
```
于是，对于这种框架，显然二分方法用 mid = left+(right-left)/2;

同理：对于上确界    
```cpp
mid = left + (right-left)/2 +1;
if (nums[mid]>target)
  right = mid-1; // 不等于target的mid元素都可以排除
else
  left = mid;
```




[Leetcode Link](https://leetcode.com/problems/search-for-a-range)