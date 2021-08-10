### 158.Read-N-Characters-Given-Read4-II-Call-multiple-times

此题对于系统设计的考察非常巧妙．

首先要理清题意．题目所要求设计的```int read(char *buf, int n)```，是说期望你从某个地方（你不用关心）读进n个字符，写进题目所指定的buf。这只是一个形式上的任务，但是真正实现读的工作函数是题目所给的API read4，它一次读取最多4个放在缓存里（ReadBuf），但是也可能一次读取的个数少于4（比如说已经读到底了），这可以从它的返回值来判断。

本题的核心思想是，用指针j来控制我们要读取、写出n次字符。每次需要读取一个字符时，都试图从缓存ReadBuf里拿。如果ReadBuf里为空，就调用一次read4来填充ReadBuf，多数情况下一次能填充4个字符。如果ReadBuf不为空，那么我们就从ReadBuf里拿出下一个字符即可，直至ReadBuf里都取完。

所以我们需要一个指针i来指向ReadBuf里待读的字符，同时用count来标记ReadBuf里还有多少未读。每次从缓存里成功读取一个，那么就i++且count--。当遇到count==0时，就需要调用read4()，将i重置为0，并且count重置为实际获取的字符个数（通常为4，但也可能更少）。

```cpp
int j;
for (j=0; j<n; j++)
{
    if (count==0)
    {
         count = read4(ReadBuf);
         i = 0;
         if (count==0) break;
    }
    buf[j] = ReadBuf[i];
    i++;
    count--;
}

return j;   
```

[Leetcode Link](https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times)
