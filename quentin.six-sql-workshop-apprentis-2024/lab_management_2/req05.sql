CREATE OR REPLACE FUNCTION buy_can(_assistant VARCHAR(64), _can VARCHAR(32))
RETURNS BOOLEAN AS
$$
BEGIN
IF (SELECT credit FROM assistant WHERE login = _assistant) < (SELECT price FROM can WHERE name = _can) AND (SELECT stock FROM can WHERE name = _can) > 0 THEN RETURN FALSE;
END IF;
UPDATE can
SET stock = stock - 1
WHERE name = _can;
INSERT INTO transaction (assistant, can, timestamp)
VALUES (_assistant, _can, now()::timestamp);
UPDATE assistant
SET credit = credit - (SELECT price FROM can WHERE name = _can)
WHERE login = _assistant;
RETURN TRUE;
END
$$
LANGUAGE plpgsql;


SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
SELECT buy_can('julien.clement', 'Perrier');
