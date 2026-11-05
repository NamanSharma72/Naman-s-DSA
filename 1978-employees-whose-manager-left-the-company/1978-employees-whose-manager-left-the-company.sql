# Write your MySQL query statement below
select employee_id 
from employees e1
where salary < 30000 and not exists (select * from employees where employee_id = e1.manager_id) and manager_id is not null
order by employee_id