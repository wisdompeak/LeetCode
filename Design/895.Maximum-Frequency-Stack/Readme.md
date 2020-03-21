### 895.Maximum-Frequency-Stack

很显然我们会设计```unordered_map<int, vector<int>> freq2nums```用来记录当前拥有相同频次的那些数。然后用```unordered_map<int, int> count```来记录每个元素对应出现的频次也是很好想的。

那么我们push(x)的时候，提取```freq=count[x]```，然后会更新```freq2nums[freq+1].push_back(x)```。但是注意，我们不需要对freq2nums[freq]做任何关于x的改动（指从里面删去x的记录）。事实上，我们需要保留x在freq2nums[freq]中的位置，这样当maxFreq再次回落到freq的时候，我们就可以从freq2nums[freq]对应的数组里面得到应该优先弹出哪个元素。

同理，我们pop()的时候，提取```x=freq2nums[maxFreq].back()```，然后我们会更新```freq2nums[maxFreq].pop_back()```。但是注意，我们不需要再对freq2nums[maxFreq-1]做任何关于x的改动（指从里面增加x的记录）。这是因为在之前加入第maxFreq-1个x的时候，我们已经在freq2nums[maxFreq-1]里面保留了关于x的位置。现在最高频次回落了，我们就可以从freq2nums[maxFreq-1]的末尾直接得到以后应该弹出的元素（因此它是最后一个放入freq2nums[maxFreq-1]里面的）。


[Leetcode Link](https://leetcode.com/problems/maximum-frequency-stack)