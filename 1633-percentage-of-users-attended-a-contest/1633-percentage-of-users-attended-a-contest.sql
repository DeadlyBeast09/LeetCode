# Write your MySQL query statement below

# Write your MySQL query statement below
select r.contest_id,round((count(r.user_id)/(select count(*) from Users) * 100),2) as percentage
from Register r
group by r.contest_id 
order by percentage desc, r.contest_id;



-- select r.contest_id,round((count(r.user_id)/count(distinct(u.user_id))*100),2) as percentage
-- from Users as u
-- right join Register r
-- on u.user_id = r.user_id
-- group by r.contest_id 
-- order by percentage desc;
