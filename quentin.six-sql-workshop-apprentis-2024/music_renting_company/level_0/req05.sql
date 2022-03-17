CREATE FUNCTION add_track_1(titre VARCHAR(64), album_ VARCHAR(64), number INT)
RETURNS VOID AS
$$
BEGIN
INSERT INTO music_album (music_id, alb_id, track)
VALUES ((SELECT id FROM music WHERE title = titre), (SELECT id FROM album WHERE name = album_), number);
END
$$
LANGUAGE plpgsql;


SELECT add_track_1('Le Petit Pain au Chocolat','Joe Dassin (Les Champs-Élysées)', 2);
SELECT add_track_1('Comment lui dire','France Gall', 1);
SELECT add_track_1('C''est ta chance','Traces', 3);
