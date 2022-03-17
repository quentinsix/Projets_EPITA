INSERT INTO creature (gid, pos_x, pos_y, pos_z)
VALUES ((select id from creature_template where name = 'Young wolf'), 5, 6, 7),
((select id from creature_template where name = 'Young wolf'),-3, -2, -1),
((select id from creature_template where name = 'Young wolf'), 42, 43, 44);
