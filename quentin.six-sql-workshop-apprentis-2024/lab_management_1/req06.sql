SELECT login FROM assistant
WHERE login NOT IN (SELECT DISTINCT assistant from transaction)
ORDER BY login;
