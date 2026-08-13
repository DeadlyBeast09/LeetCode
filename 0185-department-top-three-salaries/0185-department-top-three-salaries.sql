SELECT
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary
FROM Employee e
JOIN Department d
    ON e.departmentId = d.id
    where 3 > (select count(distinct e1.salary)
                from Employee e1
                    WHERE e1.departmentId = e.departmentId
      AND e1.salary > e.salary
                )
order by d.name,e.salary;