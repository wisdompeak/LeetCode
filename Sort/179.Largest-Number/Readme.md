### 179.Largest-Number

本题的本质是一个非常有用的知识点：给你一个字符串数组，如何排序拼接这些字符串实现字典序最大？方法是设计一个巧妙的排序函数：
```
static bool cmp(string a, string b)
{
    string c=a+b;
    string d=b+a;
    return stoll(c)>stoll(d);
}

sort(Nums.begin(),Nums.end(),cmp);
```
将以此排序的字符串拼接起来，就是字典序最大的！
