-- Last updated: 9/16/2025, 12:05:55 AM
# Write your MySQL query statement below
SELECT name
FROM Customer
WHERE referee_id IS NULL OR referee_id<>2;