SELECT DISTINCT customer_surname FROM booking
WHERE '2019-03-11'::date BETWEEN start_date AND end_date
ORDER BY customer_surname;
