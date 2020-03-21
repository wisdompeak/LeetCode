### 535.Encode-and-Decode-TinyURL

利用62位的dict随机生成一个6位的字符串来作为短链接
```cpp
dict=""abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"";
for (int i=0; i<6; i++) 
   shortUrl+=dict[rand()%62];"
```
构建short2long和long2short两个Map来存储长短链接之间的互换.   

编码：
```cpp
        if (long2short.find(longUrl)!=long2short.end())
            return "http://tinyurl.com/"+long2short[longUrl];
        else
            return "http://tinyurl.com/"+shortUrl;
```
解码
```cpp
        string randStr = shortUrl.substr(shortUrl.find_last_of("/") + 1);        
        if (short2long.find(randStr)!=short2long.end())
            longUrl = short2long[randStr];
        else
            longUrl = shortUrl;
```


[Leetcode Link](https://leetcode.com/problems/encode-and-decode-tinyurl)