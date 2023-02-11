### 日期类型的操作

#### year()
取一个date数据类型的年份
```sql
where year(date) = 1997
```

#### between
```sql
purchase_date between Prices.start_date and Prices.end_date
```

#### left/right
选择一个date数据“2020-19-12”的左七位数字作为month的标记。
```sql
left(trans_date, 7) as month
```

#### datediff
计算两个时间之差（前者减后者）
```sql
join XXX on datediff(a.visited_on, b.visited_on) between 0 and 6
```
