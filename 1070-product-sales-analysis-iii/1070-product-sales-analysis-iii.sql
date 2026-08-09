SELECT 
    s.product_id,
    s.year AS first_year,
    s.quantity,
    s.price
FROM Sales s
JOIN (
    SELECT 
        product_id,
        MIN(year) AS first_year
    FROM Sales
    GROUP BY product_id
) f
ON s.product_id = f.product_id
AND s.year = f.first_year;

-- For each product, find the earliest year in which that product was sold. Then return every sale record for that product that occurred in that earliest year.

-- For each matching sale, return:

-- product_id
-- the earliest year as first_year
-- quantity sold in that sale
-- price of that sale

-- If a product has multiple sales in its earliest year, return all of those sales as separate rows.