# Write your MySQL query statement below
with firstTable as (
select salary , dense_rank() over(order by salary desc) as `rank`
from employee)
select max(salary) as secondhighestsalary
from firstTable
where `rank` = 2

