------------------------------------------------------------------------------
--------------------------------- TABLES -------------------------------------
------------------------------------------------------------------------------

DROP TABLE IF EXISTS shop_can CASCADE;
DROP TABLE IF EXISTS student_can_shop CASCADE;
DROP TABLE IF EXISTS shop CASCADE;
DROP TABLE IF EXISTS can CASCADE;
DROP TABLE IF EXISTS student CASCADE;
DROP TABLE IF EXISTS address CASCADE;

CREATE TABLE can (
    id          SERIAL,
    name        VARCHAR(64)  NOT NULL,
    capacity_cl INT          NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE address (
    id          SERIAL,
    number      INTEGER       NOT NULL,
    street      VARCHAR(64)   NOT NULL,
    city        VARCHAR(64)   NOT NULL,
    zip_code    VARCHAR(5)    NOT NULL,
    country     VARCHAR(64)   NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE student (
    login       VARCHAR(64),
    firstname   VARCHAR(64),
    lastname    VARCHAR(64),
    assistant   BOOLEAN      NOT NULL,
    address_id  INTEGER,
    PRIMARY KEY (login),
    FOREIGN KEY (address_id) REFERENCES address(id)
);

CREATE TABLE shop (
    id          SERIAL,
    name        VARCHAR(64) NOT NULL UNIQUE,
    PRIMARY KEY (id)
);

CREATE TABLE shop_can (
    shop_id         SERIAL,
    can_id          SERIAL,
    price           REAL    NOT NULL,
    PRIMARY KEY (shop_id, can_id),
    FOREIGN KEY (shop_id) REFERENCES shop(id),
    FOREIGN KEY (can_id) REFERENCES can(id)
);

CREATE TABLE student_can_shop (
    id              SERIAL,
    login           VARCHAR(64),
    can_id          SERIAL,
    shop_id         SERIAL,
    purchase_time   TIMESTAMP,
    PRIMARY KEY (id),
    FOREIGN KEY (login) REFERENCES student(login),
    FOREIGN KEY (can_id) REFERENCES can(id),
    FOREIGN KEY (shop_id) REFERENCES shop(id)
);


------------------------------------------------------------------------------
------------------------------- INSERTIONS -----------------------------------
------------------------------------------------------------------------------

-- Cans
INSERT INTO can VALUES
    (DEFAULT, 'Coke', 25),          -- 1
    (DEFAULT, 'Oasis', 25),         -- 2
    (DEFAULT, 'Diet Coke', 25),     -- 3
    (DEFAULT, 'Orangina', 25),      -- 4
    (DEFAULT, 'Sprite', 25),        -- 5
    (DEFAULT, 'Pepsi', 25),         -- 6
    (DEFAULT, 'Ice Tea', 25),       -- 7
    (DEFAULT, 'Water', 50),         -- 8
    (DEFAULT, 'Fanta', 25),         -- 9
    (DEFAULT, 'Orange Juice', 33);  -- 10


-- Addresses
INSERT INTO address VALUES
    (DEFAULT, 12, 'rue de la Paix', 'Paris', '75002', 'FRANCE'),        -- 1
    (DEFAULT, 1, 'rue de la Paix', 'Paris', '75002', 'FRANCE'),         -- 2
    (DEFAULT, 115, 'Bld de Belleville', 'paris', '75011', 'France'),    -- 3
    (DEFAULT, 103, 'Bld de Belleville', 'paris', '75011', 'France'),    -- 4
    (DEFAULT, 3, 'Bld de la Villette', 'Paris', '75011', 'France'),     -- 5
    (DEFAULT, 4, 'Bld de la Villette', 'Paris', '75011', 'France'),     -- 6
    (DEFAULT, 5, 'Avenue de Neuilly', 'Paris', '75017', 'france'),      -- 7
    (DEFAULT, 18, 'Place Pigalle', 'PARIS', '75009', 'france'),         -- 8
    (DEFAULT, 1, 'Alexanderstrasse', 'Berlin', '10178', 'Deutschland'), -- 9
    (DEFAULT, 3, 'Eagle Road', 'Greenhithe', 'DA99Q', 'United Kingdom'),--10
    (DEFAULT, 15, 'Place de la Bourse', 'PARIS', '75002', 'france'),    --11
    (DEFAULT, 5, 'Avenue Matignon', 'PARIS', '75008', 'France'),        --12
    (DEFAULT, 48, 'Avenue Foch', 'Paris', '75116', 'France'),           --13
    (DEFAULT, 50, 'Boulevard Malesherbes', 'Paris', '75008', 'France'), --14
    (DEFAULT, 3, 'Boulevard Malesherbes', 'Paris', '75008', 'France'),  --15
    (DEFAULT, 14, 'Rue Voltaire', 'Kremlin-Bicêtre', '94270', 'France');--16

-- Students
INSERT INTO student VALUES
    ('florian.barber', 'Florian', 'Barber', FALSE, 1),
    ('lea.bellis', 'Léa', 'Bellis', FALSE, 2),
    ('stephane.boyer', 'Stéphane', 'Boyer', FALSE, 3),
    ('frederic.brun', 'Frédéric', 'Brun', FALSE, 4),
    ('claude.chevalier', 'Claude', 'Chevalier', FALSE, 5),
    ('clement.erith', 'Clément', 'Erith', FALSE, 6),
    ('lucas.dubois', 'Lucas', 'Dubois', FALSE, 7),
    ('georges.dupont', 'Georges', 'Dupont', FALSE, 8),
    ('jean-michel.fabre', 'Jean-Michel', 'Fabre', FALSE, 9),
    ('alexandre.faure', 'Alexandre', 'Faure', FALSE, 10),
    ('guillaume.fauret', 'Guillaume', 'Fauret', FALSE, 11),
    ('louis.gautier', 'Louis', 'Gautier', FALSE, 12),
    ('jonathan.girard', 'Jonathan', 'Girard', FALSE, 13),
    ('quentin.guerin', 'Quentin', 'Guerin', FALSE, 14),
    ('sandra.guerin', 'Sandra', 'Guerin', FALSE, 5),
    ('severine.khey', 'Severine', 'Khey', FALSE, 6),
    ('robert.lemoine', 'Robert', 'Lemoine', FALSE, 7),
    ('gregory.marie', 'Grégory', 'Marie', FALSE, 8),
    ('marie.masson', 'Marie', 'Masson', FALSE, 9),
    ('sarah.mei', 'Sarah', 'Mei', FALSE, 10),
    ('guillaume.mouton', 'Guillaume', 'Mouton', FALSE, 11),
    ('josiane.phouson', 'Josiane', 'Phouson', FALSE, 12),
    ('françois.rolland', 'François', 'Rolland', FALSE, 13),
    ('annick.rousseau', 'Annick', 'Rousseau', FALSE, 14),
    ('marc.toret', 'Marc', 'Toret', FALSE, 5),
    ('romain.vidal', 'Romain', 'Vidal', FALSE, 4),

    ('mathilde.anders', 'Mathilde', 'Anders', TRUE, 16),
    ('alexandra.fauvet', 'Alexandra', 'Fauvet', TRUE, 16),
    ('joseph.marchand', 'Joseph', 'Marchand', TRUE, 16),
    ('patrice.riviere', 'Patrice', 'Riviere', TRUE, 16),
    ('login_x', NULL, NULL, FALSE, NULL);

-- Shops
INSERT INTO shop VALUES
    (DEFAULT, 'Lidl'),      -- 1
    (DEFAULT, 'Carrefour'), -- 2
    (DEFAULT, 'Aldi');      -- 3

INSERT INTO shop_can VALUES
    (1, 1, 1.10),
    (1, 2, 1.10),
    (1, 4, 1.10),
    (1, 5, 1.10),
    (1, 7, 1.10),
    (1, 8, 1.10),

    (2, 1, 1.20),
    (2, 2, 1.20),
    (2, 3, 1.20),
    (2, 4, 1.20),
    (2, 5, 1.20),
    (2, 6, 1.20),
    (2, 7, 1.20),
    (2, 8, 1.20),
    (2, 9, 1.20),
    (2, 10, 1.20),

    (3, 1, 1.00),
    (3, 2, 1.00),
    (3, 3, 1.00),
    (3, 4, 1.00),
    (3, 5, 1.00),
    (3, 6, 1.00),
    (3, 7, 1.00),
    (3, 8, 1.00),
    (3, 9, 1.00),
    (3, 10, 1.00);

INSERT INTO student_can_shop VALUES
    (DEFAULT, 'joseph.marchand', 2, 1, TIMESTAMP '2019-11-15 10:04:00'),
    (DEFAULT, 'joseph.marchand', 2, 1, TIMESTAMP '2019-10-16 11:18:00'),
    (DEFAULT, 'joseph.marchand', 2, 1, TIMESTAMP '2021-10-16 20:07:00'),
    (DEFAULT, 'joseph.marchand', 2, 1, TIMESTAMP '2021-10-17 11:30:00'),
    (DEFAULT, 'joseph.marchand', 2, 1, TIMESTAMP '2021-10-20 14:00:00'),
    (DEFAULT, 'joseph.marchand', 2, 1, TIMESTAMP '2021-10-20 15:03:00'),
    (DEFAULT, 'joseph.marchand', 1, 1, TIMESTAMP '2021-10-21 23:02:00'),
    (DEFAULT, 'joseph.marchand', 1, 1, TIMESTAMP '2022-01-02 11:46:00'),
    (DEFAULT, 'joseph.marchand', 1, 1, TIMESTAMP '2022-01-02 13:53:00'),
    (DEFAULT, 'joseph.marchand', 7, 1, TIMESTAMP '2021-01-28 12:04:00'),
    (DEFAULT, 'joseph.marchand', 7, 2, TIMESTAMP '2021-01-29 16:15:00'),
    (DEFAULT, 'joseph.marchand', 7, 3, TIMESTAMP '2021-02-01 17:30:00'),
    (DEFAULT, 'joseph.marchand', 8, 1, TIMESTAMP '2022-01-01 17:40:00'),
    (DEFAULT, 'joseph.marchand', 8, 1, TIMESTAMP '2022-01-02 18:42:00'),

    (DEFAULT, 'mathilde.anders', 7, 1, TIMESTAMP '2022-01-03 17:03:00'),
    (DEFAULT, 'mathilde.anders', 7, 1, TIMESTAMP '2021-12-01 17:30:00'),
    (DEFAULT, 'mathilde.anders', 7, 1, TIMESTAMP '2021-12-05 18:15:00'),
    (DEFAULT, 'mathilde.anders', 7, 1, TIMESTAMP '2022-01-01 18:30:00'),

    (DEFAULT, 'patrice.riviere', 9, 1, TIMESTAMP '2022-01-02 17:03:00'),
    (DEFAULT, 'patrice.riviere', 9, 1, TIMESTAMP '2022-01-02 18:14:00'),
    (DEFAULT, 'patrice.riviere', 9, 1, TIMESTAMP '2021-11-12 19:39:00'),
    (DEFAULT, 'patrice.riviere', 9, 1, TIMESTAMP '2021-11-15 10:20:00'),
    (DEFAULT, 'patrice.riviere', 9, 1, TIMESTAMP '2021-11-23 11:19:00'),
    (DEFAULT, 'patrice.riviere', 9, 1, TIMESTAMP '2021-11-25 12:29:00'),
    (DEFAULT, 'patrice.riviere', 7, 1, TIMESTAMP '2022-01-01 17:30:00'),
    (DEFAULT, 'patrice.riviere', 7, 1, TIMESTAMP '2022-01-03 23:46:00'),

    (DEFAULT, 'claude.chevalier', 1, 1, TIMESTAMP '2021-10-28 09:20:00'),
    (DEFAULT, 'claude.chevalier', 1, 1, TIMESTAMP '2021-10-29 14:56:00'),
    (DEFAULT, 'claude.chevalier', 1, 3, TIMESTAMP '2022-01-01 21:48:00'),

    (DEFAULT, 'sandra.guerin', 7, 1, TIMESTAMP '2022-01-02 16:46:00'),
    (DEFAULT, 'sandra.guerin', 7, 1, TIMESTAMP '2022-01-01 13:24:00'),

    (DEFAULT, 'annick.rousseau', 10, 2, TIMESTAMP '2022-01-01 16:23:00'),
    (DEFAULT, 'annick.rousseau', 10, 2, TIMESTAMP '2022-01-02 17:42:00'),
    (DEFAULT, 'annick.rousseau', 10, 2, TIMESTAMP '2022-01-02 00:37:00'),
    (DEFAULT, 'annick.rousseau', 10, 2, TIMESTAMP '2022-01-01 18:30:00'),
    (DEFAULT, 'annick.rousseau', 10, 2, TIMESTAMP '2022-01-02 04:13:00'),
    (DEFAULT, 'annick.rousseau', 10, 2, TIMESTAMP '2022-01-03 17:09:00'),
    (DEFAULT, 'annick.rousseau', 10, 2, TIMESTAMP '2022-01-03 19:24:00'),

    (DEFAULT, 'guillaume.fauret', 8, 1, TIMESTAMP '2021-01-25 12:13:00'),
    (DEFAULT, 'guillaume.fauret', 8, 1, TIMESTAMP '2022-01-13 12:24:00'),
    (DEFAULT, 'guillaume.fauret', 3, 1, TIMESTAMP '2022-01-03 17:24:00');
