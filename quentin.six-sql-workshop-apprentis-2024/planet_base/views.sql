CREATE VIEW view_nearest_planet_to_sun (planet) AS
SELECT planet.name FROM planet ORDER BY period 
LIMIT 3;

CREATE VIEW view_nb_satellite_per_planet (planet, "number of satellites") AS 
SELECT sub.planet AS planet, sub.result AS result 
FROM (SELECT DISTINCT planet.name AS planet, count(satellite.name) AS result FROM satellite, planet WHERE satellite.id_planet = planet.id AND satellite.radius > 499 GROUP BY planet.name UNION SELECT DISTINCT planet.name AS planet, 0 FROM planet, satellite WHERE planet.name NOT IN (SELECT DISTINCT planet.name FROM satellite, planet WHERE satellite.id_planet = planet.id AND satellite.radius > 499 GROUP BY planet.name) AND satellite.radius > 499 ORDER BY result, planet) AS sub ORDER BY result, planet;




CREATE VIEW view_average_period (system, average_period) AS
SELECT sub.sysname AS system, sub.result AS average_period FROM
(SELECT planetary_system.name AS sysname, round(avg(planet.period), 2) AS result FROM planet, planetary_system WHERE planetary_system.id = planet.id_system GROUP BY planetary_system.name UNION SELECT planetary_system.name AS sysname, 0 FROM planetary_system WHERE planetary_system.name NOT IN (SELECT planetary_system.name FROM planet, planetary_system WHERE planetary_system.id = planet.id_system GROUP BY planetary_system.name)) AS sub
ORDER BY result, sysname;



CREATE VIEW view_biggest_entities (type, system, name, radius) AS 
SELECT sub.type, sub.system, sub.name, sub.radius
FROM (SELECT 'planet' AS type, (SELECT planetary_system.name FROM planetary_system WHERE planetary_system.id = planet.id_system) AS system, name, radius FROM planet UNION SELECT 'satellite' AS type, (SELECT planetary_system.name FROM planetary_system, planet WHERE planetary_system.id = planet.id_system AND planet.id = satellite.id_planet) AS system, name, radius FROM satellite ORDER BY radius DESC, name LIMIT 10) AS sub;

