SELECT name FROM creature_template WHERE id NOT IN (SELECT DISTINCT gid FROM creature);

