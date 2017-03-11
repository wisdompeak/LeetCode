###080.Remove-Duplicates-from-Sorted-Array-II
要实现in-place的功能，利用快慢指针。right指针判定合格的，就拷贝到left指针上去。

注意：初始值left=1，right=2。保证有不超过两个重复的判断条件是
```cpp
if (nums[right]==nums[left] && nums[right]==nums[left-1])
  right++;
else
{
  left++;
  nums[left]=nums[right];
  right++;
}
```
