SELECT title FROM quest WHERE id IN (SELECT id FROM character_quests WHERE character_id = (SELECT id FROM character WHERE name = 'Kuro') AND complete = 1)
ORDER BY title;

