### 2019.The-Score-of-Students-Solving-Math-Expression

此题的本质就是```227. Basic Calculator II```和```241. Different Ways to Add Parentheses```的组合。

LC227的代码可以得到按照乘法优先的运算顺序的计算结果。LC241的代码求得的就是按照任何组合顺序得到的计算结果（因为任意组合的顺序总是对应着某种符号添加方案）。如果answers里面的数值是前者，就可以得5分；否则如果在后者里，得2分；除此之外就得零分。

此外，本题的一个坑就是，任何中间过程，我们只保留数值小于1000的结果。否则会TLE。
