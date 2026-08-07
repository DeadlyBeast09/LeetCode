# Write your MySQL query statement below
# group by userid of confirmation table then count timeout and confirmed of each userid
#then caculate rate
#then return table with user_id

select s.user_id, Round(
    COALESCE(
        SUM(CASE WHEN c.action = 'confirmed' THEN 1 ELSE 0 END)/COUNT(c.action),
        0
    )
    ,2
) as confirmation_rate
from Signups as s
LEFT JOIN Confirmations as c
ON s.user_id = c.user_id
GROUP BY s.user_id;