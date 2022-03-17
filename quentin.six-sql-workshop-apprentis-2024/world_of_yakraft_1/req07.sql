UPDATE character
SET level=15
WHERE name = 'Tilon';

UPDATE character
SET level = level +1
WHERE name = 'Kuro';

UPDATE character
SET max_health = CASE 
WHEN blessed = 1 THEN (level+1)*10
ELSE level * 10
END;

