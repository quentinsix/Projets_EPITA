INSERT INTO can (name, stock, capacity, price)
VALUES ('Dr Pepper', 100, 330, 0.70);

UPDATE can
SET stock = 99
WHERE name = 'Dr Pepper';

INSERT INTO transaction (assistant, can, timestamp)
VALUES ('helene.chelin', 'Dr Pepper', '2022-01-05 17:43:00');


