### 3594.Minimum-Time-to-Transport-All-Individuals

这道题的陷阱在于，只能纯粹地用暴力去解决，而不存在任何贪心的优化。

比如说，是否可以每次我都派那个全局速度最快的人负责来回摆渡？实际上是不行的，因为速度快的人虽然可以有更少的过河时间，但是可能会恰好遇到更不利的流速加成（mul）。同理，我们是否每次渡河的时候，都要尽量坐满k个人呢？这也是不确定的。

所以我们必须用bit mask穷举每种过河的策略。令dist[mask][stage]表示已经有mask对应的人过了河，并且此时河流环境的状态阶段处于stage时，可以花费的最少时间。为了求得最早实现`(1<<n)-1`的状态的时间，显然我们可以套用dijsktra的最短路径算法。

对于PQ里面的状态，我们需要设计一下结构：
```
struct State {
    int mask, stage;
    double dist;
    bool operator<(State const& o) const {
        return dist > o.dist;
    }
};
```
注意对于运算符<的重载，这样我们定义`priority_queue<State>`的时候，就会自动将dist最小的state排在top。

每次从PQ里拿出一组{mask, stage, d}，我们需要在mask的补集(rem)里面枚举子集sub。将sub对应的人渡河之后（此时状态更新为`mask2=mask+sub`），再在“所有已经渡河的人”里（即mask2）选一个人i将传开回来，由此得到该回合最终的`mask3=mask2-(1<<i)`. 类似地我们可以计算相应的stage2和stage3。

特别注意，我们遇到某次mask2成为最终状态`(1<<n)-1`之后，不需要再考虑返回了。
