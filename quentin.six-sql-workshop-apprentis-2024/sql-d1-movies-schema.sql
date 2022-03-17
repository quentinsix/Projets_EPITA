DROP TABLE IF EXISTS movie CASCADE;
DROP TABLE IF EXISTS rating CASCADE;

CREATE TABLE movie
(
    movie_id                    SERIAL,
    movie_title                 VARCHAR(64) NOT NULL,
    PRIMARY KEY(movie_id)       -- movie_id is the primary key
);

CREATE TABLE rating
(
    rating_author       VARCHAR(64) NOT NULL,
    rating_value        INT NOT NULL,
    rating_comment      VARCHAR(64),
    rating_movie        INT REFERENCES movie(movie_id),         -- foreign key
    -- shorthand of 'rating_movie INT, FOREIGN KEY(rating_movie) REFERENCES movie(movie_id),'
    PRIMARY KEY(rating_author, rating_movie)
);
