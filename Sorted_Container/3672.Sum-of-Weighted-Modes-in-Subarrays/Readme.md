### 3672.Sum-of-Weighted-Modes-in-Subarrays

比较容易想到设计两个容器：
```cpp
map<int,set<int>>freq2val;
unordered_map<int,int>val2freq;
```
freq2val[f]里面放所有频率为f的元素（按照从小到大排序）。这样每个sliding window，我们就可以用`*(freq2val.rbegin()->second.begin())`找到其中的众数。val2[freq]顾名思义就是每种元素的频次。

每次我们加入一个新元素x，可以查到它的f。于是小心地更新这两个容器即可
```cpp
// 先删除{x,f}
freq2val[f].erase(x);
if (freq2val[f].empty())
    freq2val.erase(f);
// 再加入{x,f+1}
val2freq[x]=f+1;
freq2val[f+1].insert(x);
```
同理，每次我们删除一个旧元素x，可以查到它的f。也是小心地更新这两个容器即可
```cpp
// 先删除{x,f}
freq2val[f].erase(x);
if (freq2val[f].empty())
    freq2val.erase(f);
// 再加入{x,f+1}
val2freq[x] = f-1;
if (f!=1)
    freq2val[f-1].insert(x);
```
关键就是及时清理freq2val里没有值的key（即空频次），保证freq2val的结尾元素是有意义的。
