SELECT title, creature_template.name FROM creature_template, creature, quest 
WHERE (quest.creature_start = creature.id) AND (creature.gid = creature_template.id)
ORDER BY title, creature_template.name;