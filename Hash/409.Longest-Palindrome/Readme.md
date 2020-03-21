### 409.Longest-Palindrome

注意，出现了奇数次的字符也可以参与构建回文串：其中一个可以全部采用；剩余的只需要取用其偶数次。

所以，判定方法是：
```cpp
        int sum=0;
        int flag=0;
        for (auto a:Map)
        {
            if ((a % 2) ==1)
            {
                sum+=a-1;
                flag=1;
            }
            else
                sum+=a;
        }        
        return sum+flag;
```        


[Leetcode Link](https://leetcode.com/problems/longest-palindrome)