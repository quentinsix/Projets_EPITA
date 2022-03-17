SELECT id,
CASE WHEN now()::date < start_date THEN 'Booked'
WHEN now()::date > end_date THEN 'Done'
ELSE 'Ongoing' END AS "trip status"
FROM booking
ORDER BY id;
