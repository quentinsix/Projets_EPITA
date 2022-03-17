SELECT DISTINCT quest.title, character.name FROM character_quests, quest, character
WHERE (character_quests.complete = 0) AND (character_quests.quest_id = quest.id) AND (character_quests.character_id = character.id) 
ORDER BY quest.title, character.name;