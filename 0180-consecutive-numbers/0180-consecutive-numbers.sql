# Write your MySQL query statement below
with firstTable as (select num , lag(num) over(order by id) as prev_num , lead(num) over(order by id) as next_num from logs)
select distinct num as consecutiveNums from firstTable
where num = prev_num and num = next_num