-- Last updated: 9/16/2025, 12:02:22 AM
SELECT 
    event_day AS day,
    emp_id,
    SUM(out_time - in_time) AS total_time
FROM Employees
GROUP BY emp_id, event_day;
