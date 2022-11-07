### 2461.Maximum-Sum-of-Distinct-Subarrays-With-Length-K

非常普通的固定长度的滑窗。

用一个HashMap来记录每个number出现的次数。用count来表示滑窗内的distinct number的数量。count的变动依据如下：
1. 当新加入一个数字时
```cpp
Map[num]++;
if (Map[num]==1) 
  count++;
```
2. 当移出一个数字时
```cpp
Map[num]--;
if (Map[num]==0) 
  count--;
```
