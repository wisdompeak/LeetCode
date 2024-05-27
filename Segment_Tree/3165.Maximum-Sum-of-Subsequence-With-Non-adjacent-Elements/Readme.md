### 3165.Maximum-Sum-of-Subsequence-With-Non-adjacent-Elements

本题的基础是经典的house robber，但是如果从house robber的常规解法去思考，那么本题是做不下去的。事实上，house robber有另一种适合拓展的做法，即递归分治。

我们令dp00[i][j]表示[i:j]区间内的最大收益，并且要求左右端点都不取到。同理，定义dp11[i][j]为区间[i:j]两个端点都取到时的最大收益，定义dp10[i][j]为区间[i:j]仅左端点都取到时的最大收益，定义dp01[i][j]为区间[i:j]仅右端点都取到时的最大收益。

我们不难发现，对于[i:j]内的任意一个点k，我们可以将[i:j]的收益分为[i:k]和[k+1:j]两端区间的收益之和。更具体地，要满足“不同时取相邻节点”的原则，针对分割处取或不取的决策，我们可以有对dp00[i][j]的三种分解
```
dp00[i][j] = max{dp00[i][k]+dp00[k+1][j], dp01[i][k]+dp00[k+1][j], dp00[i][k]+dp10[k+1][j],}
```
同理，我们可以写出dp01,dp10,dp11的分解。

至此我们可以发现这是一个可以自上而下分治解决的问题。边界条件就是`dp00[i][i]=0, dp11[i][i]=1, dp01[i][i]=dp10[i][i]=-inf`.

写成这样分治的结构，我们明显可以搞成线段树，它有两个好处：
1. 线段树可以用log(n)的时间求任意一段区间内的最大收益。
2. 对于任何单点的变动后，我们依然可以用log(n)的时间更新整棵线段树。

注意，这样的线段树，懒标记是不能用的。每次单点的变动，必须将更新传播到最底层，再把区间最大收益反向传播上去。

本题的线段树不需要queryRange方法，最终只需要返回`root->info00,root->info10,root->info01,root->info11`的最大值即可。

数据结构如下：
```cpp
class SegTreeNode
{
    public:
    SegTreeNode* left = NULL;
    SegTreeNode* right = NULL;
    int start, end;
    LL info00, info11, info10, info01;
        
    SegTreeNode(int a, int b, vector<int>& vals)  // init for range [a,b] with val
    {                 
        start = a, end = b;
        if (a==b)
        {
            info11 = vals[start], info01 = -1e18, info10 = -1e18, info00 = 0;
            return;
        }        
        int mid = (a+b)/2;

        left = new SegTreeNode(a, mid, vals);
        right = new SegTreeNode(mid+1, b, vals);            
        info11 = max({left->info10 + right->info01, left->info11 + right->info01, left->info10 + right->info11});
        info00 = max({left->info00 + right->info00, left->info01 + right->info00, left->info00 + right->info10});
        info10 = max({left->info10 + right->info00, left->info10 + right->info10, left->info11 + right->info00});
        info01 = max({left->info00 + right->info01, left->info01 + right->info01, left->info00 + right->info11});
    }
    
    void updateRange(int a, int val)     // set range [a,b] with val
    {        
        if (a < start || a > end ) // not covered by [a,b] at all
            return;        
        if (start==end)  // completely covered within [a,b]
        {
            info00 = 0;
            info11 = val;
            return;
        }

        left->updateRange(a, val);
        right->updateRange(a, val);
        info11 = max({left->info10 + right->info01, left->info11 + right->info01, left->info10 + right->info11});
        info00 = max({left->info00 + right->info00, left->info01 + right->info00, left->info00 + right->info10});
        info10 = max({left->info10 + right->info00, left->info10 + right->info10, left->info11 + right->info00});
        info01 = max({left->info00 + right->info01, left->info01 + right->info01, left->info00 + right->info11});
    }
};
```
