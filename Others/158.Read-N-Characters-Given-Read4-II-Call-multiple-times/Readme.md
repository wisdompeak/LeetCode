### 158.Read-N-Characters-Given-Read4-II-Call-multiple-times

此题对于系统设计的考察非常巧妙．

首先要理清题意．题目给的API```int read4(char *buf)```，是说从某个地方（你不用关心）可以一次性读进４个（或者更少）字符存入你指定的buf，至于到底是否是读进了４个还是更少，可以从它的返回值来考察．

题目所要求设计的```int read(char *buf, int n)```，是说期望你从某个地方（你不用关心）读进n个字符，存进题目所指定的buf．因为实际读取的可能少于n个（比如说文本的字数原本就少于n个），所以你要返回实际成功读取的字符个数．

此题的考点是，题目会多次调用read(n)，而且每次读取的字符数目可能多可能少，但要求是在文本中连续的．然而，你用read4得到的文本是无法回退的．举个例子，题目read(2),你调用了read4，得到了4个字符但只能返回２个．下一个回合，题目read(3)，你必须先考虑之前读取还存留的两个，然后继续read4，再返回一个．所以第二回合你会剩３个．

显然，我们应该开辟一个缓存ReadBuf，存放４个字符就足够了．每次题目要求读取，我们优先处理这个缓存的内容．所以我们要开辟一个缓存```char ReadBuf[4]```,一个记录缓存里面字符数的count，以及待读的指针i．主程序中，我们总是从缓存里给destination放东西,缓存空了的话就调用API充满缓存．
```cpp
            if (count!=0)
            {
                buf[j]=ReadBuf[i];
                i++;
                count--;
                j++;
            }
            else
            {
                int count = read4(ReadBuf);
                i = 0;
            }
```


[Leetcode Link](https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times)