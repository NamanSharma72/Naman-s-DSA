# Write your MySQL query statement below
with firstTable as(
    select e.name , e.salary , d.name as department
    from employee e left join department d
        on e.departmentId = d.id
),
secondTable as(
    select department , name , salary , rank() over(partition by department order by salary desc) as `rank`
    from firstTable
)
select department , name as employee , salary
from secondTable
where  `rank` = 1