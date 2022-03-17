CREATE FUNCTION add_new_song(title VARCHAR(64), name_art VARCHAR(64), duration INT)
RETURNS VOID AS
$$
BEGIN
INSERT INTO music (title, art_id, duration)
VALUES (title, (SELECT id FROM artist WHERE name = name_art), duration);
END
$$
LANGUAGE plpgsql;

SELECT add_new_song('Le Petit Pain au Chocolat','Joe DASSIN',3*60+30);
SELECT add_new_song('Comment lui dire','France GALL',3*60+30);
SELECT add_new_song('C''est ta chance','Jean-Jacques GOLDMAN',6*60+31);
SELECT add_new_song('Siffler sur la colline','Joe DASSIN',2*60+32);
