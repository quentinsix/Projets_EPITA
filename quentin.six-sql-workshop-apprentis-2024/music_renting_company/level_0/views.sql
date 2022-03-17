CREATE VIEW view_artists (artist, birthdate, songs) AS 
SELECT artist.name, artist.birth_date, count(music.title) AS songs FROM artist, music 
WHERE music.art_id = artist.id 
GROUP BY artist.name, artist.birth_date UNION SELECT artist.name AS name, artist.birth_date AS BD, 0 AS songs FROM artist, music 
WHERE artist.name NOT IN (SELECT artist.name AS name FROM artist, music WHERE music.art_id = artist.id GROUP BY artist.name) ORDER BY name;


CREATE VIEW view_albums (album, songs, duration) AS
SELECT album.name as album, count(music.title) as songs, duration_to_string(music.duration) as duration
from music, album, music_album
where music.id = music_album.music_id AND music_album.alb_id = album.id 
GROUP BY album.name, music.duration UNION
SELECT album.name as album, 0 as songs, '0:00' from music, album, music_album 
where album.name not in (Select album.name as album from music, album, music_album where music.id = music_album.music_id AND music_album.alb_id = album.id) 
ORDER BY album;


CREATE VIEW view_songs (music, artist, duration) AS 
SELECT music.title, artist.name, duration_to_string(music.duration)
FROM artist, music 
WHERE music.art_id = artist.id 
ORDER BY music.title, artist.name;

