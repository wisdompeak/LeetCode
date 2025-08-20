### 3655.XOR-After-Range-Multiplication-Queries-II

如果我们用暴力的解法，对于一个query我们需要处理n/k个数据，总共时间复杂度q*n/k（约1e10/k数量级）。显然只有处理跨度k很大的query时才能承受。

那么对于那些k很小的query怎么办呢？这是我们需要利用k数值小的特点，将这些query按照k分组。对那些相同跨度k的queries，我们可以用差分数组的思想来解决“区间”的整体倍增。

具体地说，假如一个query的作用范围是[a1,a2,..at]，其中ai就是第一个作用点即l，at是离r最近的最后一个作用点即`at = (r-l)/k*k+l`. 类似于差分数组的思想，我们将[a1,at]想象成一个区间，如果这个区间被要求整体倍增v，我们其实只需要记录两个阶跃点：`diff[a1]*=v, diff[at+1]/=v`. 这样在a1处的倍增系数multiplier增大v倍，在at处的倍增系数multiplier减小v倍即可，中间部分的倍增系数multiplier总保持不变。这样对于每个query我们只需要更新两个端点的diff，最后遍历一遍所有位置的diff来更新每一处的multiplier，即`multiplier[i] = multiplier[i-1]*diff[i]`，得到`nums[i]*multiplier[i]`。

但事实上本题里并不是整个区间统一倍增，而是间隔地倍增，怎么处理呢？我们发现，multiplier[i]只与multiplier[i-k]相关。由此我们知道更新的公式其实是`multiplier[i] = multiplier[i-k]*diff[i]`.

综上，对于k很小的时候，相同k的queries可以处理成同一组diff数组，然后根据diff更新multiplier数组。时间复杂度就是k*(q+n).

既然我们对于k很小与k很大两种情况我们有不同的策略，那么分解点在哪里呢？就是sqrt(n).此时两种情况的时间复杂度都是1e5*sqrt(1e5)，恰好符合要求。

另外，因为本题要求计算的是MOD，diff里涉及的除以v的运算，应该替换为乘以v的逆元。
