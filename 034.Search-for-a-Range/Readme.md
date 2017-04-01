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
