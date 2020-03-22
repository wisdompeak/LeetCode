### 028.Implement-strStr

#### KMP算法

维护两个指针i和j。对于每一个i，可以找到一个j：使得haystack里以i结尾的一个长度为j的子串（长度可以是零），等于needle里的前j个字符组成的子串；并且这个j是尽可能的大。

假设现在已知了i和j，即对于needle我们已经匹配到了j这个位置。接下来考虑haystack[i+1]，就面临两种情况。第一种，就是haystack[i+1]==needle[j+1]，那么两个指针的更新就是i++，j++。第二种，就是haystack[i+1]!=needle[j+1]，那么我们就要减小j，找到在j之前的最大的j'，同样使得haystack里以i结尾的一个子串，等于needle里的0\~j'组成的子串；然后继续考察haystack[i+1]是否等于needle[j'+1]。如果还不行，则以j'为末尾，重复找下一个j''。以此类推直至找到合适的j，或者j变成了-1为止。

那么如何已知i，j的情况下，找到下一个j'呢？可以想象，j'应该满足在needle[0\~j]中，首端的0~j'子串能等于尾端的(j-j')~j子串。如果提前处理needle，得到一个prefix数组，其中prefix[j]表示的就是对于j而言那个最大的j'，则程序主体中可以通过不断地访问prefix直至找到适合i的那个j。
```cpp
int j=-1;
for (int i=0; i<haystack.size(); i++)
{
   while (j>=0 && needle[j+1]!=haystack[i])
      j=prefix[j];
   if (needle[j+1]==haystack[i])
      j++;
   if (j==m-1) return i-j;
}
return -1;
```
接下来思考如何构造prefix数组。假设已知两个指针i和j，表示needle[i]为末尾的一个最长的子串，能等于needle[0~j]。那么现在考虑i+1的话，就要考察needle[j+1]和needle[i+1]的关系。如果needle[j+1]==needle[i+1]，则说明prefix[i+1]=j+1。否则的话，则调用之前已经算出来的prefix[j]，将j的指针更新为j'，再考察needle[j'+1]和needle[i+1]的关系，依次重复直至找到合适的j赋给prefix[i+1]或者j==-1.
```cpp
vector<int>prefix(m,-1);
j=-1;
for (int i=1; i<m; i++)  // i从1开始，因为必须prefix[0]=-1
{
   while (j>=0 && needle[j+1]!=needle[i])
      j=prefix[j];
   if (needle[j+1]==needle[i])
      j++; 
   prefix[i]=j;
}
```

#### Sunday算法
预处理needle构造一个shift数组。该数组记录了needle里的字符最后一次出现的位置距离needle结尾的位移。

举个例子，最开始将haystack和needle左对齐，如果发现needle和haystack匹配不上，就考察haystack[n]的字符（即needle长度n之后的第一个字符）。

1. 如果这个字符在shift里有记录，那么将needle整体右移相应的位移，这样使得haystack[n]和needle里最后一次出现的字符（这两个字符相同）对齐，再从needle首字符开始逐一判断匹配。

2. 如果这个字符不存在needle里面，则shift里默认给n+1，即将整个needle右移至haystack[n]之后，再从needle首字符开始逐一判断匹配。


[Leetcode Link](https://leetcode.com/problems/implement-strstr)
