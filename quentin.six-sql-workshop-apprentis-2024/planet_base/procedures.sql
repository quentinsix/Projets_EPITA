CREATE FUNCTION space_travel(origin INT, destination INT, quantity BIGINT)
RETURNS BOOLEAN AS 
$$ 
BEGIN 
IF quantity < 0 THEN RETURN FALSE; 
ELSIF (SELECT population FROM planet WHERE id = origin) < quantity THEN RETURN FALSE; 
ELSIF ((SELECT id_system FROM planet WHERE id = origin) <> (SELECT id_system FROM planet WHERE id = destination)) THEN RETURN FALSE; 
END IF; 
UPDATE planet 
SET population = population + quantity 
WHERE id = destination; 
UPDATE planet 
SET population = population - quantity 
WHERE id = origin; 
RETURN TRUE; 
END 
$$ LANGUAGE plpgsql;




CREATE FUNCTION list_satellite_inf_750(syst INT) 
RETURNS TABLE(satellite VARCHAR(32), planet VARCHAR(32), radius INT) AS 
$$
BEGIN 
RETURN QUERY SELECT DISTINCT satellite.name AS satellite, planet.name AS planet, satellite.radius AS radium FROM satellite, planet, planetary_system WHERE satellite.radius <= 750 AND satellite.id_planet = planet.id AND planetary_system.id = planet.id_system AND planetary_system.id = syst ORDER BY planet.name, satellite.radius DESC, satellite.name;
END 
$$ LANGUAGE plpgsql;
