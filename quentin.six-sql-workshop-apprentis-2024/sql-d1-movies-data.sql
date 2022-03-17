-- Add the movie `The Usual Suspects` to the `movie` table
INSERT INTO movie (movie_title)
    VALUES ('The Usual Suspects');

-- Add the movie `Citizen Kane` to the `movie` table
INSERT INTO movie
    VALUES (DEFAULT, 'Citizen Kane');

-- Add a rating to Citizen Kane in the rating table
INSERT INTO rating (rating_author, rating_value, rating_comment, rating_movie)
    VALUES ('John Doe', 3, NULL, 2);

-- Add a rating to Citizen Kane in the rating table
INSERT INTO rating
    VALUES ('John Smith', 4, 'Breathtaking all the way to the end !', 2);

-- Add a rating to The Usual Suspects in the rating table
INSERT INTO rating (rating_author, rating_value, rating_movie)
    VALUES ('John Doe', 5, 1);

-- Add a rating to The Usual Suspects in the rating table
INSERT INTO rating
    VALUES ('John Smith', 4, 'One of the finest films ever made.', 1);

-- Add multiple movies with only one request:
INSERT INTO movie (movie_title) VALUES
    ('Pulp Fiction'),
    ('Fight Club'),
    ('Léon: The Professional');

-- Add multiple ratings
INSERT INTO rating VALUES
    ('John Smith', 5, 'Simply amazing !', 4),
    ('John Doe', 5, 'Very good movie.', 5),
    ('John Smith', 4, NULL, 3),
    ('John Smith', 3, NULL, 5);
