## LeetCode 358. Rearrange String k Distance Apart 

解题思想：贪心法。

设计一个大顶堆的priority_queue{pair{int,char}}，乘装所有字符和对应的出现次数，这个队列能够保证自动按照出现次数多少从前往后排列（因为默认按照pair类型的第一个index排序）。

每个回合，从q里一次性取出k个不同字符，这些字符每个的次数减去1之后再次放回这个大顶堆。下一个回合，从q里再次取出k个不同字符。可以证明，按照这样的策略进行下去，不会出现任何重复的字符间距小于k的情况。所以相当于每个回合，我们都能确定最终解的k个字符。
```cpp
while (!q.empty())
{       
  count++;
  temp.push_back(q.top());
  result.push_back(q.top().second);
  temp.back().first--;
  
  if (count==k)
  {
     count = 0;
     将temp里的元素倒入q队列;
     temp.clear();
  }
}
```
结束的情况。考虑某个回合过程中，q拿着拿着已经空了，（此时还没有拿够k个字符，所以q无法补充），但如果最终解的字符数还不到s.size()，也就是说没有把所有字符都派完，这说明剩下的字符必定会造成间隔小于k。
```cpp
if (result.size()<s.size) return "";
```
