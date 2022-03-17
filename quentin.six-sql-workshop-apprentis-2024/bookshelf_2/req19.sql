CREATE FUNCTION add_book(title VARCHAR(64), author VARCHAR(64), genre VARCHAR(64), release_date DATE)
RETURNS BOOLEAN AS 
$$ 
BEGIN
IF title IS NULL OR author IS NULL OR genre IS NULL OR release_date IS NULL
THEN RETURN FALSE;
END IF;
INSERT INTO books (title, author, genre, release) 
VALUES (title, author, genre, release_date); 
RETURN TRUE; 
END 
$$ LANGUAGE plpgsql;

