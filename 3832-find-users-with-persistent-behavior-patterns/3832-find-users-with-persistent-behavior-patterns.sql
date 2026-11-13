# Write your MySQL query statement below
with firstTable as (select user_id , action_date , action from activity
group by user_id , action_date having count(*) = 1),
secondTable as (select user_id , action_date , dense_rank() over(partition by user_id , action order by action_date) as rK , action from firstTable),
thirdTable as (select user_id , action_date , date_sub(action_date , interval rk day) as consi , action from secondTable),
forthTable as (select user_id , action_date , consi , count(*) over(partition by user_id , consi , action) as streak_length , first_value(action_date) over(partition by user_id , consi , action order by action_date asc) as start_date , first_value(action_date) over(partition by user_id , consi , action order by action_date desc) as end_date , action from thirdTable),
fifthTable as (select user_id , action , streak_length , start_date , end_date , row_number() over(partition by user_id , consi , action order by streak_length desc , action asc , start_date asc) as number from forthTable)
select user_id , action , streak_length , start_date , end_date from fifthTable
where number = 1 and streak_length >= 5
order by streak_length desc , user_id asc
