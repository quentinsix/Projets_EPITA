SELECT title, author, extract(year FROM release) AS release_year FROM books
ORDER BY release_year DESC, title, author;
