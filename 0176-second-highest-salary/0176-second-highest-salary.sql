# Write your MySQL query statement below
with firstTable as (select null as salary , 2 as `rank`
union
select salary , dense_rank() over(order by salary desc) as `rank`
from employee)
select salary as secondhighestsalary
from firstTable
where `rank` = 2
order by `rank` asc , salary desc
limit 1

