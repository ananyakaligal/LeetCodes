-- Last updated: 9/16/2025, 12:03:50 AM
SELECT 
    player_id,
    MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id;
