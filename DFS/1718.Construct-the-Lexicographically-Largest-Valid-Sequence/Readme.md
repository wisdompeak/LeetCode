### 1718.Construct-the-Lexicographically-Largest-Valid-Sequence

本题的原型来自于 https://leetcode-cn.com/leetbook/read/interesting-algorithm-puzzles-for-programmers/9umkfd/

这种题并没有特殊的技巧，就是贪心暴搜。我们希望这个数最大，那么自然希望最高位最大，我们第一步贪心地在ret[0]放置n，根据题意要求在ret[n]也放置n；第二步，我们尝试在ret[1]放置第二大的元素，也就是n-1，那么根据题意ret[n]也必须放置n-1，但发现该位置已经放置了n，所以我们的第二步尝试失败；于是我们重新尝试第二步，在ret[1]放置第三大的元素n-2，发现可以继续推进下去...

就是这样从高位到低位不断地尝试，每次位置优先尝试放置较大的元素。直至我们找到一种方法能把```2*n-1```个位置都填充满，自然就是我们所能构造的最大答案。
