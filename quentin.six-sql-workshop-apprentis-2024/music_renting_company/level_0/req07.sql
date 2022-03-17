DELETE FROM album
WHERE (name LIKE '%mm%') OR (MOD(length(name), 7) = 0) OR (name LIKE '%&%') OR (name LIKE '%P%P%' AND name NOT LIKE '%P%P%P%');

