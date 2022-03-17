SELECT books.title, books.author FROM authors, books
WHERE (books.author = authors.name) AND (authors.country = 'France') AND (books.genre = 'Poem') 
ORDER BY books.title, books.author;
