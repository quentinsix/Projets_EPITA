SELECT books.title, books.author as name from authors, books where books.author = authors.name AND books.release > authors.death_date order by title, author;

