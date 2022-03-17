SELECT sub.name as name,
CASE WHEN sub.stocks > 1 THEN sub.stocks || ' books'
ELSE '1 book'
END AS stocks
FROM (SELECT author as name, count(*) AS stocks FROM books GROUP BY name ORDER BY name) sub 
ORDER BY name;


