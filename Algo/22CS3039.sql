
USE transactiondb;
CREATE TABLE transactions2 (
    tid INTEGER PRIMARY KEY,
    itemset TEXT
);

INSERT INTO transactions2 (tid, itemset) VALUES
(1, 'A,B,C'),
(2, 'A,C,D'),
(3, 'D,C,E'),
(4, 'A,B,C,E'),
(5, 'A,C,D,E');

CREATE TABLE items (
    tid INTEGER,
    item TEXT
);

INSERT INTO items (tid, item) VALUES
(1, 'A'), (1, 'B'), (1, 'C'),
(2, 'A'), (2, 'C'), (2, 'D'),
(3, 'D'), (3, 'C'), (3, 'E'),
(4, 'A'), (4, 'B'), (4, 'C'), (4, 'E'),
(5, 'A'), (5, 'C'), (5, 'D'), (5, 'E');
-- 1 frequent set 
SELECT item, COUNT(*) AS frequency
FROM items
GROUP BY item
ORDER BY frequency DESC;

-- 2 Frequent set 

SELECT i1.item AS item1, i2.item AS item2, COUNT(*) AS frequency
FROM items i1
JOIN items i2 ON i1.tid = i2.tid AND i1.item < i2.item
GROUP BY i1.item, i2.item
ORDER BY frequency DESC;

-- Maximal set

WITH frequentItemset AS (
    SELECT 
        t1.item AS item1, 
        t2.item AS item2, 
        COUNT(DISTINCT t1.tid) AS support
    FROM items t1 
    JOIN items t2 ON t1.tid = t2.tid AND t1.item < t2.item
    GROUP BY t1.item, t2.item
    HAVING COUNT(DISTINCT t1.tid) >= 2
)
SELECT f1.item1, f1.item2 
FROM frequentItemset f1 
LEFT JOIN frequentItemset f2 
ON f1.item1 = f2.item1 AND f1.item2 < f2.item2 
WHERE f2.item1 IS NULL;
