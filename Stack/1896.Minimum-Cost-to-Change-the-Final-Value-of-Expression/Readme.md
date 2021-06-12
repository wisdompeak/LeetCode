### 1896.Minimum-Cost-to-Change-the-Final-Value-of-Expression

如果这道题给的不是序列，而是一个布尔表达树的话，题目就会简单很多。比如，对于```(0|(1|0&1))```，写成二叉树的话就是
```
  |
0    |
   1   &
      0  1   
```
现在考虑这个问题，如果要使整棵树最终eval的结果翻转，我们最少需要做多少次改动？这里的改动，就是将叶子节点（数值）的01互换、或者非叶子节点（逻辑运算符）的|&互换。

对于树而言，我们显然会用递归处理。对于每一对{subRoot，left, right}，我们可以有递归表达式对每一种情况进行分析：
```cpp
int minFlip(subRoot, left, right)
{
  left.flip = minFlip(left);
  right.flip = minFlip(right);
  
  if (subRoot.op == '&' && left.val + right.val == 0)  // 0 & 0  需要翻转一个数字，再翻转逻辑符
    return 1 + min(left.flip,  right.flip);
  if (subRoot.op == '&' && left.val + right.val == 1)  // 0 & 1， 只需要翻转逻辑符
    return 1;
  if (subRoot.op == '&' && left.val + right.val == 2)  // 1 & 1， 需要翻一个数字
    return min(left.flip,  right.flip);  

  if (subRoot.op == '|' && left.val + right.val == 0)  // 0 | 0  需要翻转一个数字
    return min(left.flip,  right.flip);
  if (subRoot.op == '|' && left.val + right.val == 1)  // 0 | 1， 只需要翻转逻辑符
    return 1;
  if (subRoot.op == '|' && left.val + right.val == 2)  // 1 | 1， 需要翻一个数字，再翻转逻辑符
    return 1 + min(left.flip,  right.flip);  
}
```
可以发现，对于每个节点node，其实我们都需要得到它的两个属性，一个就是以node为根的子树整体作为逻辑表达式得到的val，另一个就是将以node为根的子树的val翻转所需要的flip操作数。两个孩子节点的这两个属性，就可以得到父节点的两个属性。我们一路向下，再向上回溯，最终输出的答案就是root.flip，即将总结果翻转需要的flip次数。

那么我们如何将序列表达式转变成一棵逻辑树呢？递归的方法很简单，但是复杂度很高。比如```(xxxxxxxxxxxxxxxx)&(xxxxxxxxxxxxxxxxxxxx)```，你需要把整个序列都遍历一遍，才能确定两个子递归函数的范围。这样的建树方法会造成o(N^2)的复杂度。

所以适合本题的方法并不是显示地去构建这棵逻辑树，而是学习```224.Basic-Calculator```的方法，用栈来模拟递归。224的解法的三个关键是：
1. 维护两个变量，cur来存放当前已经eval的数值，op来存放当前待操作的逻辑运算。当我们遇到下一个数值nxt的时候，就可以进行操作```cur op nxt```，然后将结果用来更新cur。
2. 维护两个栈，当遇到左括号时，以往的结果都要暂存，故将当前的变量cur和op压入栈中。我们reset这两个变量，标记cur=-1, op='#'，“虚拟地”表示这是一个起始点。我们规定```cur # nxt = nxt```.
3. 当遇到右括号时，从这两个栈中读取last和op，这样就可以操作```last op cur```，然后将结果来更新cur。

于是，如果只是评估本题的表达式的最终结果，那么代码可以写成如下：
```cpp
    int minOperationsToFlip(string expression) 
    {
        stack<int>s1;
        stack<char>s2;
        int cur = -1;
        char op = '#';
         
        int ret = 0;
        expression = "(" + expression + ")";
        
        for (auto ch:expression)
        {
            if (ch=='&'||ch=='|')
                op = ch;
            else if (ch=='0' || ch=='1')
            {
                int nxt = ch-'0';
                int val = evalVal(op, cur, nxt);
                cur = val;
            }
            else if (ch=='(')
            {                
                s1.push(cur);
                s2.push(op);
                cur = -1;
                op = '#';
            }
            else
            {
                auto last = s1.top();
                s1.pop();
                char op = s2.top();
                s2.pop();
                                
                int val = evalVal(op, last, cur);
                cur = val;
            }
        }
        
        return cur; 
    }
```    


本题相比于224需要多一个操作，就是每步```cur op nxt```时，不仅计算该操作得到逻辑值val，还要计算如果想要翻转val所需要的最少flip。所以cur或者nxt，本质都需要包含两个属性，即{val, flip}. 更新之后的cur同样也包含这两个属性。具体的方法和上面的递归代码相同。

