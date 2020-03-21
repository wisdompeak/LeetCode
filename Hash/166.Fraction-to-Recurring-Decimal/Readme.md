### 166.Fraction-to-Recurring-Decimal

注意的几个细节：
1. 被除数为0；
2. 被除数或除数为负数；
3. 遇到INT_MIN时的溢出;
4. 整除的情况。


需要一个set记录每次的余数t。如果某次的余数已经在集合中，则说明有循环。

同时需要一个Map来记录每次的余数与对应的小数位置，当发现循环的起始位置时，便于插入‘(’。

```cpp
        while (t!=0 && Set.find(t)==Set.end())
        {
            Set.insert(t);
            Map[t]=result.size();            
            result.push_back((t*10/B)+'0');
            t=t*10%B;
        }
        
        if (t==0) return result; //整除：就直接输出
        
        int pos=Map[t]; // 非整除：找到循环体开始的位置
        result.insert(result.begin()+pos,'(');
        result.push_back(')');        
```


[Leetcode Link](https://leetcode.com/problems/fraction-to-recurring-decimal)