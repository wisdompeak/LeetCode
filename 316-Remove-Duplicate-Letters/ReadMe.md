## 316. Remove Duplicate Letters  
解体思想：贪心法。尽量维持一个字典序递增的栈，遇到下一个不能维持栈递增的元素，则考虑退栈一些已有元素以继续维持递增序列。

如果下一个字符大于栈顶元素且未访问，则入栈，该字符标记为已访问。显然，到目前为止，都是最优解。
```cpp
if (Stack.empty() || Visited[s[i]]==0 && s[i]>=Stack.top())
  {
    Stack.push(s[i]);
    Map[s[i]]--;
    Visited[s[i]]=1;
  }
```
如果下一个字符小于栈顶元素且未访问，则考虑此刻栈顶元素是否在此后还会出现（这需要一个Map[char,int]来实时记录此时该字符的剩馀次数）。还会出现的话，说明这个较大字符可以扔到后面取处理，所以将其退栈并标记为未访问，循环考虑下一个栈顶元素；否则就停止退栈，老老实实加入下一个字符。
```cpp
if (Visited[s[i]]==0 && s[i]<Stack.top())
  {
      while (!Stack.empty() && Stack.top()>s[i] && Map[Stack.top()]>0)
      {
        Visited[Stack.top()]=0;
        Stack.pop();
      }
      Stack.push(s[i]);
      Map[s[i]]--;
      Visited[s[i]]=1;
  }
```
