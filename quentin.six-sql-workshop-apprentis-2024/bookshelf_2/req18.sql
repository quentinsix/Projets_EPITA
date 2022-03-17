CREATE FUNCTION add_author(name VARCHAR(64), birth_date DATE, death_date DATE, country VARCHAR(64))
RETURNS BOOLEAN AS
$$ 
BEGIN
IF name IS NULL OR birth_date IS NULL OR death_date IS NULL OR country IS NULL
THEN RETURN FALSE;
END IF;
INSERT INTO authors (name, birth_date, death_date, country)
VALUES (name, birth_date, death_date, country);
RETURN TRUE; 
END
$$ 
LANGUAGE plpgsql;
