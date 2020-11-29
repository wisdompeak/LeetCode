### 1670.Design-Front-Middle-Back-Queue

#### 解法1
考虑到如果使用最粗暴的数组来实现这个数据结构的话，数组里最多有1000个元素，每次增删一个元素最多调整1000个元素的位置。10^6的复杂度是足够解这道题了。

#### 解法2
更高级的数据结构是用双端链表，这样所有的增删操作都是o(1)。C++里面的list<int>就可以实现这样的功能。我们另外还需要维护一个迭代器list<int>::iterator mid用来存放middle元素所在的位置。

1. push_front:    
```
当n为偶数时，mid不用变化。
 OXOO
YOXOO 
```    
```
当n为奇数时，mid需要前移一位。 
 OOXOO
YOOXOO
```

2. push_back:        
```
当n为偶数时，mid需要后移一位。
OXOO
OXOOY
``` 
```
当n为奇数时，mid不用变化。
OOXOO
OOXOOY
```

3. push_middle:        
```
当n为偶数时，新mid会插在mid后面。
 OXOO
 OXYOO
``` 
```
当n为奇数时，新mid会插在mid前面。
OOXOO
OOYXOO
```

4. pop_front:        
```
当n为偶数时，mid需要后移一位。
OXOO
 XOO
``` 
```
当n为奇数时，mid不需要变化
OOXOO
 OXOO
```

5. pop_back:        
```
当n为偶数时，mid不需要变化
OXOO
OXO
``` 
```
当n为奇数时，mid需要前移一位
OOXOO
OOXO
```

6. pop_middle:        
```
当n为偶数时，mid需要后移一位。
OXOO
O OO
``` 
```
当n为奇数时，mid需要前移一位。
OOXOO
OO OO
```
