SELECT title, author FROM 
(SELECT title, author, release, (SELECT min(release) FROM books one WHERE one.author = two.author GROUP BY author) AS firstbook FROM books two)
subque WHERE subque.firstbook = release
ORDER BY title, author;
