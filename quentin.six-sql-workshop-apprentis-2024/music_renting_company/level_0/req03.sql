CREATE FUNCTION add_new_album(name VARCHAR(64))
RETURNS VOID AS
$$
BEGIN
INSERT INTO album (name)
VALUES (name);
END
$$
LANGUAGE plpgsql;

SELECT add_new_album('Traces');
SELECT add_new_album('France Gall');
SELECT add_new_album('Joe Dassin (Les Champs-Élysées)');
SELECT add_new_album('Dark Passion Play');
SELECT add_new_album('Rammstein');
SELECT add_new_album('Tribe of Force');
SELECT add_new_album('The Deep & The Dark');
