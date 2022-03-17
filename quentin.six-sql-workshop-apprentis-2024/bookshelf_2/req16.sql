SELECT title, author, release FROM books 
WHERE (release < '1900-01-01'::date) OR (release > '2000-01-01'::date)
ORDER BY release DESC, title, author;

