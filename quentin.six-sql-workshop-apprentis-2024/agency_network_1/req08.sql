SELECT customer_surname AS "best customers", count(customer_surname) AS "number of travels" FROM booking
GROUP BY "best customers"
ORDER BY "number of travels" DESC, "best customers" DESC
LIMIT 3;
