# Write your MySQL query statement below
with firstTable as (
    select pid , tiv_2016 , count(*) over(partition by tiv_2015) as totalInGroup , count(*) over(partition by lat , lon) as sameCity from insurance
)
select round(sum(tiv_2016),2) as tiv_2016 from firstTable
where totalInGroup > 1 and sameCity = 1