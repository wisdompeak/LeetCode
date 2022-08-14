### 357.Count-Numbers-with-Unique-Digits

本题长度不超过n的数字里有多少是所有digit都不同的。

对于长度固定为n的数字，就是在10个不同的digit里（从0到9）里选n个随意排列即可。也就是A(10,n)。但是注意到不能有leading zero，所以必须刨去其中以0开头的排列，这些有A(9,n-1)个。故答案是`A(10,n)-A(9,n-1)`.

特别注意，需要单独考虑0。长度为1的数字里是允许leading zero的。
