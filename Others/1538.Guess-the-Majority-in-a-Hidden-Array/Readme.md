### 1538.Guess-the-Majority-in-a-Hidden-Array

本题的本质就是以元素0为标准，用```query(0,1,2,3)==query(1,2,3,i)```来判断元素i>=4和元素0是否相等。

对于元素1,2,3，需要用下面的方式单独特判：
```
if (reader.query(0,2,3,4) == reader.query(1,2,3,4))
if (reader.query(0,1,3,4) == reader.query(1,2,3,4))
if (reader.query(0,1,2,4) == reader.query(1,2,3,4))
```
