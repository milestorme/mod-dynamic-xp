DROP TABLE IF EXISTS item_upgrade_system;
CREATE TABLE item_upgrade_system(
  item_entry INTEGER UNSIGNED DEFAULT 0, -- entry from item_template 
  upgrade_entry INTEGER UNSIGNED DEFAULT 1, -- entry from item_template
  gold INTEGER UNSIGNED DEFAULT 0, -- gold
  honor INTEGER UNSIGNED DEFAULT 0, -- honor points
  arena INTEGER UNSIGNED DEFAULT 0, -- arena points
  success FLOAT UNSIGNED DEFAULT 100, -- success in procentage
  CONSTRAINT success_ck CHECK (success BETWEEN 0 AND 100),
  PRIMARY KEY (item_entry, upgrade_entry)
);

DROP TABLE IF EXISTS item_upgrade_system_requirements;
CREATE TABLE item_upgrade_system_requirements(
  item_entry INTEGER UNSIGNED REFERENCES item_upgrade_system(item_entry),
  upgrade_entry INTEGER UNSIGNED REFERENCES item_upgrade_system(upgrade_entry),
  req_item INTEGER UNSIGNED NOT NULL,
  amount SMALLINT UNSIGNED DEFAULT 1,
  PRIMARY KEY (item_entry, upgrade_entry, req_item)
);

-- !! TEST DATA !!

-- -- Chain

-- .additem 2092 1
-- .additem 2840 4
-- [Worn Dagger] to [Cross Dagger]
INSERT INTO item_upgrade_system VALUES (2092, 2819, 0, 0, 0, 100);
INSERT INTO item_upgrade_system_requirements VALUES (2092, 2819, 2840, 4); -- 4x [Copper Bar]

-- .mod money 200g
-- .additem 3575 4
-- .additem 3577 8
-- [Cross Dagger] to [Coldrage Dagger]
INSERT INTO item_upgrade_system VALUES (2819, 10761, 200, 0, 0, 100); -- 200 gold
INSERT INTO item_upgrade_system_requirements VALUES (2819, 10761, 3575, 4); -- 4x [Iron Bar]
INSERT INTO item_upgrade_system_requirements VALUES (2819, 10761, 3577, 8); -- 8x [Gold Bar]

-- -- Recipes

-- .additem 39793 2
-- .additem 4305 15
-- [Neckcharm of Mighty Mojo] to [Ring of Saviors]
INSERT INTO item_upgrade_system VALUES (39793, 1447, 0, 0, 0, 100);
INSERT INTO item_upgrade_system_requirements VALUES (39793, 1447, 4305, 10); -- 10x [Bolt of Silk Cloth]

-- .mod money 50g
-- .mod honor 50
-- .mod arena 50
-- [Neckcharm of Mighty Mojo] to [Memento of Tyrande]
INSERT INTO item_upgrade_system VALUES (39793, 32496, 50, 50, 50, 100);
INSERT INTO item_upgrade_system_requirements VALUES (39793, 32496, 4305, 5); -- 5x [Bolt of Silk Cloth]