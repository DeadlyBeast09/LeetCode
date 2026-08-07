# Write your MySQL query statement below

# count(*) will count the for each group
# use case for counting of rating < 3 

select query_name, round(avg(rating/position),2) as quality, 
        round(
            sum(case when rating < 3 then 1 else 0 end)/count(*) * 100,
            2
        ) as poor_query_percentage
from Queries 
-- where query_name is not null
group by query_name;