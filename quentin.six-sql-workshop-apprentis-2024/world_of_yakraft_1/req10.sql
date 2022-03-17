SELECT creature.id FROM creature_template, creature
WHERE (creature_template.level > 10) AND (creature.gid = creature_template.id) 
ORDER BY creature.id;