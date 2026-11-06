# Write your MySQL query statement below
with useJoinTable as (
    select e.id , e.name as employee , e.salary , d.name as department
    from employee e left join department d
        on e.departmentId = d.id
),
nextTable as (
    select department , employee , salary , dense_rank() over(partition by department order by salary desc) as dep_rank
    from useJoinTable
)

select department , employee , salary
from nextTable
where dep_rank <= 3