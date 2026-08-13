# Write your MySQL query statement below
select c1.visited_on,sum(c2.amount) as amount,round(avg(c2.amount),2) as average_amount
from(
select visited_on,sum(amount) as amount
from Customer
group by visited_on
) c1
join(
    select visited_on,sum(amount) as amount
from Customer
group by visited_on
) c2
on c2.visited_on between DATE_SUB(c1.visited_on,INTERVAL 6 DAY) and c1.visited_on
group by c1.visited_on
having count(c1.visited_on)=7
order by c1.visited_on;

