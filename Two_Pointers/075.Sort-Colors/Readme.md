### 075.Sort-Colors
难点在于如何in-palce实现。基本思想是设置三个指针：
```cpp
int left=0;
int mid=0;
int right=nums.size()-1;
```  
遍历mid指针，当遇到2号球时，便和right指针进行交换；遇到1号球时，继续前进；与到0号球时，便和left指针进行交换。
理解的难点在于：
```cpp
if (nums[mid]==0)
{
  swap(nums[left],nums[mid]);
  left++;
  mid++;
}
```
因为left和mid初始位置相同，他们之间出现异步只是因为1号球的出现。所以这两个指针之间间隔的永远只会是1号球，所以当left和mid交换时，left指针传给mid的一定会是1号球而不是0号球。


[Leetcode Link](https://leetcode.com/problems/sort-colors)