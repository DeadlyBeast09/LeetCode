SELECT Round(SUM(i1.tiv_2016),2) AS tiv_2016
FROM Insurance i1
WHERE EXISTS (
    SELECT 1
    FROM Insurance i2
    WHERE i1.tiv_2015 = i2.tiv_2015
      AND i1.pid <> i2.pid
)
AND NOT EXISTS (
    SELECT 1
    FROM Insurance i2
    WHERE i1.lat = i2.lat
      AND i1.lon = i2.lon
      AND i1.pid <> i2.pid
);
-- exists => true
-- not exists => false