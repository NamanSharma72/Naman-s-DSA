# Write your MySQL query statement below
with firstTable as (select id , visit_date , people , lag(people , 1 , -1) over(order by id) as prev_people , lag(people , 2 , -1) over(order by id) as prev2_people , lead(people , 1 , -1) over(order by id) as next_people , lead(people , 2 , -1) over(order by id) as next2_people from stadium)

select id , visit_date , people from firstTable
where people >= 100 and ((prev_people >= 100 and prev2_people >= 100) or (next_people >= 100 and next2_people >= 100) or (prev_people >= 100 and next_people >=100))