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

#### 临时表
```sql
with Temp1 as
(
    select winner_id
    from Winners
), Temp2 as
(
    select player_id
    from Players
)

select
    Round((select count(*) from Winner) / (select count(*) from Players), 2) AS fraction
```

#### 分组最大
在原表里插入rank存为新表。再在新表里选择rank=1的行。
```sql
with temp as 
(
    select *, rank() over (partition by student_id order by grade desc, course_id) as rnk
    from Enrollments
)
select student_id, course_id, grade
from temp
where rnk = 1
```
