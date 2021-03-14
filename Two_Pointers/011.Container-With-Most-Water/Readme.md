### 11. Container With Most Water 
#### 算法：双指针。  
让左指针指向0，右指针指向height.size()-1。每次考虑如果减少横向距离1，判断应该选择移左指针还是右指针，还是考察both？  

事实上，只需要移动height[left]和height[right]中较矮的一个板子即可，这样才有使总面积增大的可能。否则移动较高的板子，不会使结果变得更好，因为面积受限于较矮的那块板子。
```cpp
if (height[left]>=height[right])
   right--;
else
   left++;
```


[Leetcode Link](https://leetcode.com/problems/container-with-most-water)
