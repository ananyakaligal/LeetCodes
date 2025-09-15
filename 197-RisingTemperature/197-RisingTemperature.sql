-- Last updated: 9/16/2025, 12:08:02 AM
# Write your MySQL query statement below
SELECT w1.id
FROM Weather w1
JOIN Weather w2
    ON DATEDIFF(w1.recordDate, w2.recordDate) = 1
WHERE w1.temperature > w2.temperature;
