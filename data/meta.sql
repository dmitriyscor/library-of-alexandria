-- CREATE TABLE "pdfs" (
--         id INTEGER PRIMARY KEY,
--         title TEXT NOT NULL,
--         filename TEXT NOT NULL 
-- );

-- !!! to add new columns: 
-- ALTER TABLE pdfs ADD COLUMN new_column TEXT;
-- !!!to delete the table:
-- DROP TABLE pdfs

-- SELECT * FROM pdfs;



-- INSERT INTO pdfs (title, filename)
-- VALUES('Frankenstein', 'Frankenstein_Mary Shelley_1818.pdf'); 

-- INSERT INTO pdfs (title, filename)
-- VALUES('Crime and Punishment', 'Crime and Punishment_Dyodor Dostoevsky_1866.pdf'); 

-- INSERT INTO pdfs (title, filename)
-- VALUES('Raven', 'Raven_Allan Poe_1845.pdf'); 

SELECT * FROM pdfs;

-- !!! commands to find a specific entry
-- WHERE title='search';
-- LIMIT 2;
-- !!! update a specific parameter in a specific entry
-- UPDATE pdfs SET title = 'new title' WHERE id = 1;
-- !!! to delete a specific entry
-- DELETE FROM pdfs WHERE id = 2;

