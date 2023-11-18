### 2931.Maximum-Spending-After-Buying-Items

非常直观地贪心。为了使得总和最大，我们会将尽量小的d与尽量小的value相乘，而相对大的d与相对大的value相乘。证明如下：令a<b, x<y，则`a*x+b*y - a*y-b*x = (a-b)(x-y)>0`.

所以我们将所有shop里当前available的物品放入一个小顶堆，每次取最小值与当前的d相乘即可。取完一个最小值，就把它对应的shop的下一件available的物品放入PQ。直至取完所有m*n件物品。
