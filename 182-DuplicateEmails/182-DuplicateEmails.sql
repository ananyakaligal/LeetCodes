-- Last updated: 9/16/2025, 12:08:11 AM
SELECT email
FROM Person
GROUP BY email
HAVING COUNT(email) > 1;
