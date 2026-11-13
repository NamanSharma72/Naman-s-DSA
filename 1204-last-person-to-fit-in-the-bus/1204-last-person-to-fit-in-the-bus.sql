# Write your MySQL query statement below
with firstTable as 
(select person_name , sum(weight) over(order by turn) as cumulativeWeight from queue)

select person_name from firstTable
where cumulativeWeight <= 1000
order by cumulativeWeight desc
limit 1