SELECT transaction.assistant, sum(can.price) AS price 
FROM transaction
INNER JOIN can
ON transaction.can=can.name
GROUP BY transaction.assistant
ORDER BY price DESC
LIMIT 3;

