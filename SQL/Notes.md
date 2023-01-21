#### greatest, least
在同一行的多个列中选择最大/最小的一个
```sql
greatest(columnA, columnB)
least(columnA, columnB)
```

#### Union
```sql
将两段类型相同的列纵向拼接起来（组成新表）。在第一个select里可以重命名。
with temp as
(
    select user1_id as id
    from Friendship
    where user2_id = 1
    union
    select user2_id
    from Friendship
    where user1_id = 1
)
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

### Join
#### out join
不指定`on`的话，会将表A与表B的所有row都两两配对。
```sql
select *
from A
join B
```
