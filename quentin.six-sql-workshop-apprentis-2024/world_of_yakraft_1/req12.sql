SELECT DISTINCT creature_template.name FROM creature_template, creature, quest
WHERE (quest.creature_start = creature.id) AND (creature.gid = creature_template.id) AND (quest.creature_start = creature_end) 
ORDER BY creature_template.name;