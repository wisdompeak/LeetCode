### 726.Number-of-Atoms

典型的栈的应用。此题的特别之处在于stack的元素应该是map<string,int>.

遍历formula的元素，分别对formula[i]=='(', ')', '大写字母'三种情况进行讨论。注意分子式中的下标数字为1时会缺省。


[Leetcode Link](https://leetcode.com/problems/number-of-atoms)