### 535.Encode-and-Decode-TinyURL

利用62位的dict随机生成一个6位的字符串来作为短链接
```cpp
dict=""abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"";
for (int i=0; i<6; i++) 
  shortUrl+=dict[rand()%62];
```
将longUrl和shortUrl的配对放入两个哈希表中，用于查验短链接的生成是否重复、以及解码。


[Leetcode Link](https://leetcode.com/problems/encode-and-decode-tinyurl)