# Write your MySQL query statement below
with firstTable as (select id , email , row_number() over(partition by email order by id asc) as number from person)
delete from person
where id in (select id from firstTable where number > 1)