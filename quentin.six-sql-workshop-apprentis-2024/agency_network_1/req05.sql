SELECT REGEXP_REPLACE(country, '[^a-zA-Z]', '', 'g') as country,REGEXP_REPLACE(city, '[^a-zA-Z]', '', 'g') AS city FROM destination
ORDER BY country, city;
