SELECT MAX(num) AS num
FROM MyNumbers
WHERE num IN (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*) = 1
);
-- GROUP BY groups rows based on the values of the columns you specify, not based on the number of columns in the table.
-- GROUP will be 8->[8,8],3->[3,3] etc 