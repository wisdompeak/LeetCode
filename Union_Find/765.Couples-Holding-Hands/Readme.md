### 765.Couples-Holding-Hands

#### 解法1：此题可以人工找到最优的策略,所以属于贪心法.

考虑这么一个字串```03....61....42....```.我们试图想把前两个数字变为```01```使得配成一对,那么最高效的方法就只有把3和1进行交换.于是得到```01....63....42....```接下来,为了充分利用刚才的这次交换,我们可以假定3已经处于了最终位置,那么我们需要把6换掉变成2,使得```23```配成一对.于是得到```01....23....46....```接下来,同理,为了充分利用刚才的这次交换,我们固定4的位置,需要把6换走,换来5,...以此类推,直到某次交换结束后恰好配成了一对不需要再做这样的换走/换来的swap.这其实说明这M次swap形成了一个闭环,共配成了M+1对,是最高效的方法.

接下来,我们可以继续在这个数列里寻找下一个没配对的位置,重复上述的过程,在一个闭环中完成若干次匹配.这种算法可以成为```cyclic swapping```

以上述例子的第二次swap为例,核心的代码如下:
```cpp
while (flag==0)
{
  // 此时序列是```03....61....42....```,partner是1,curPos是1
  
  swap(row[curPos],row[Pos[partner]]);  // 交换3和1,得到```01....63....42....```
  
  holder = row[Pos[partner]]; // holder是在当前配对中已经固定好的那个数,即3
  int holder_pos = Pos[partner];  // holder所在的idx,即此时3的那个位置
  
  partner = coupleID[holder]*2==holder? holder+1:holder-1;  //根据holder,确定它的partner,即2
  curPos = (holder_pos%2==0) ? holder_pos+1:holder_pos-1;   //根据holder_pos,确定下次需要交换的两个数的其中一个位置,即此时3前面的那个位置
  
  flag = row[curPos]==partner; //判断此时holder和partner是否已经配对,否则需要继续循环
}
```

#### 解法2：Union Find

我们根据如下的规则将所有的人分组：1.同属于一对couple的聚为一组；2.被安排在相邻位置的聚为一组（指的是01，23，45这样的位置）。

这样我们就得到了若干个union。这些union有如下性质：1.每个union之间是没有关系的，即没有任何couple被拆在不同的union里。2.在每个union内部，都可以通过若干次的swap使得内部的couple得到配对。3.每个union不可能再拆分为若干个更小的union。

因为每个union是这样一个“最小”的社区单位，所以他们其实形成了一个闭环。如果一个union内部有k对couple，则最多只需要k-1次swap就可以让所有couple配对。（这是因为每次swap至少能保证一对couple配对，而使得k-1对couple配对后，最后一对couple自然也就配对了。）那么有没有可能用更少次数的swap使其配对呢？其实不可能。

给一个比较粗糙的类比。Union A有k个couple，Union B有m个couple，Union C有n个couple，且k=m+n。要是的B和C理顺关系，只需要m-1+n-1=m+n-2=k-2次swap。如果理顺A也只需要k-2此的话，其意味着A可能分为B+C？但事实上A不可再分，其拓扑结构必然复杂于B+C，所以不可能也用k-2次swap就实现目标，只能用k-1次。


[Leetcode Link](https://leetcode.com/problems/couples-holding-hands)