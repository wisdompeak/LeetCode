### 2121.Intervals-Between-Identical-Elements

此题是1685的升级版。我们需要对于每个数值，找出数组里存在该数值的index，然后直接用1685的思想，计算该index数组里所有元素到某一个元素的差的绝对值之和。利用结论转移的特性，我们用o(1)就可以更新一个ret[i].
