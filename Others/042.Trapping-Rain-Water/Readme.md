### 42. Trapping Rain Water 
此题最巧妙的解法是找到解析表达式：
```cpp
area[i]=min(LeftMost[i]+RightMost[i])-height[i];
area[i]=area[i]<0?0:area[i];
```
LeftMost[i]是指i左边的最大高度。RightMost[i]的定义同理。
```cpp
LeftMost[i]=max(LeftMost[i-1],height[i-1]);
```
