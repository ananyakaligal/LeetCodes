-- Last updated: 9/16/2025, 12:05:48 AM
SELECT id,movie,description,rating
FROM Cinema
WHERE description<>"boring" AND id MOD 2 = 1
ORDER BY rating DESC;