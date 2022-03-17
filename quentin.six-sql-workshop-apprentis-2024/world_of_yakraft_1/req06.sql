SELECT title FROM quest
WHERE (creature_end = creature_start OR gold > 100) AND (level_min BETWEEN 8 AND 10) 
ORDER BY title;

