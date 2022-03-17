CREATE FUNCTION add_new_artist_(name VARCHAR(64), birthdate DATE)
RETURNS VOID AS
$$
BEGIN
INSERT INTO artist (name, birth_date)
VALUES (name, birthdate);
END
$$
LANGUAGE plpgsql;

SELECT add_new_artist_('Edith PIAF', '1915-12-19'::date);
SELECT add_new_artist_('France GALL', '1947-10-09'::date);
SELECT add_new_artist_('Joe DASSIN', '1938-11-05'::date);
SELECT add_new_artist_('Jean-Jacques GOLDMAN', '1951-10-11'::date);
