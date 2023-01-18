#### greatest, least
在同一行的多个列中选择最大/最小的一个
```sql
greatest(columnA, columnB)
least(columnA, columnB)
```

#### 日期类型的操作
##### between
```sql
purchase_date between Prices.start_date and Prices.end_date
```
##### left
选择一个date数据“2020-19-12”的左七位数字作为month的标记。
```sql
left(trans_date, 7) as month
```

#### Join
##### Join Condition 可以有复杂的表达式
```sql
join UnitsSold on Prices.product_id = UnitsSold.product_id 
    and UnitsSold.purchase_date between Prices.start_date and Prices.end_date  
```    
