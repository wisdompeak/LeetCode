### 1904.The-Number-of-Full-Rounds-You-Have-Played

一个比较精巧的解法是，将startTime调整到下一个quarter time，将finishTime调整到上一个quarter time。这样就可以将两个时刻的时间差直接除以15就是答案了。

注意如果finishTime跨越了零点，那么就将它加上24h的时间。但是切记，这一步需要在最开始（即调整到quarter time之前）完成。
