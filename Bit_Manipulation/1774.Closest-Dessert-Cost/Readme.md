### 1774.Closest-Dessert-Cost

本题需要暴力枚举所有toppings的选配方案。枚举时对每种topping的数量都在0，1，2中选择，所以可以将topping的组合用一个含有m个bit的三进制数表示。我们对0到3^m进行循环，查看每个三进制数所对应的topping组合方案需要的cost，记录在toppingsSet里去重，并对按照从小到大排序。

然后我们遍历base，显然我们在toppingsSet里希望找与target-base最接近的topping，这里就可以用二分搜索。
