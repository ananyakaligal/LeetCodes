-- Last updated: 9/16/2025, 12:05:54 AM
# Write your MySQL query statement below
SELECT name, population, area
FROM World
WHERE area >= 3000000
   OR population >= 25000000;