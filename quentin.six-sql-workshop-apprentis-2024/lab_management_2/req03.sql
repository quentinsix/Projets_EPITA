CREATE FUNCTION add_credit(name VARCHAR(64), amount NUMERIC(4,2))
RETURNS VOID AS
$$
BEGIN
UPDATE assistant
SET credit = credit + amount
WHERE login = name;
END
$$
LANGUAGE plpgsql;

SELECT add_credit(login, 10) FROM assistant;

SELECT add_credit('julien.clement', 40);
SELECT add_credit('nicolas.guerguadj', 20);
SELECT add_credit('thomas.joubert', 30);

