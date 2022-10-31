### 2454.Next-Greater-Element-IV

我们已经知道，常规的Next Greater Element可以用单调栈实现o(n)的解法。我们维护一个单调递减的栈，如果遇到新元素大于栈顶元素，就意味着栈顶元素遇到了next greater element，于是就可以退栈。

在此题里，栈顶元素遇到了next greater selement，并不意味着它就可以一劳永逸地舍弃。我们需要的是the second greater element，于是我们应该对这些元素进行标记，表示他们已经看到了一次next greater。当它们再次遇到greater element的时候，才能记录答案。

那么如何标记呢？如果把常规的单调栈记做stk1，那么我们可以把遇到过next greater的元素拿出来，放入另外一个单调栈里，记做stk2。每次新来一个元素nums[i]，先看stk2的栈顶元素是否小于num[i]，是的话就意味着这些栈顶元素遇到了the second greater element，就可以记录答案并退栈了。接下来看stk1的栈顶元素是否小于nums[i]，同理，是的话就意味着这些栈顶元素遇到过了next greater element，并将其移至stk2中。

这里要注意一定，将stk1的元素移至stk2的过程中，是否会干扰stk2的单调顺序？是不会的。stk2经过退栈之后，栈顶元素一定是大于nums[i]的；而从stk1转移至stk2的这些元素都是小于nums[i]的，所以我们可以放心将转移的元素都堆在stk1的栈顶，依然能保持stk2的递减性质。
