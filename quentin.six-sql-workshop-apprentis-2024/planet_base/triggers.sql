CREATE TABLE event (id SERIAL, date_ Varchar(50), old BIGINT, new BIGINT);

CREATE VIEW view_earth_population_evolution (id, "date", "old population", "new population") AS
SELECT id, date_, old, new
FROM event;

CREATE FUNCTION fonction()
RETURNS TRIGGER AS
$$ 
BEGIN 
INSERT INTO event (date_, old, new)
VALUES (TO_CHAR(NOW()::timestamp, 'DD/MM/YYYY HH24:MI:SS'), OLD.population, NEW.population); 
RETURN NEW; 
END 
$$ LANGUAGE plpgsql;

CREATE TRIGGER store_earth_population_updates BEFORE 
UPDATE ON planet FOR EACH ROW 
WHEN (OLD.population IS DISTINCT FROM NEW.population AND OLD.name = 'Earth') 
EXECUTE PROCEDURE fonction();

