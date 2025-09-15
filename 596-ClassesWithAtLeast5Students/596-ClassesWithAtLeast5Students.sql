-- Last updated: 9/16/2025, 12:05:52 AM
SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(student) >=5;