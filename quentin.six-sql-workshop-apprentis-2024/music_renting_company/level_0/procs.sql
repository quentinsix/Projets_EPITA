CREATE FUNCTION duration_to_string(duration INT) 
RETURNS VARCHAR(16) AS 
$$ 
BEGIN 
    IF (duration < 0 OR duration IS NULL) THEN RETURN '0:00'; 
END IF; 
RETURN(SELECT(DIV(duration, 60)) || ':' || RIGHT('0' || CAST(MOD(duration, 60) AS VARCHAR),2)); 
END 
$$ LANGUAGE plpgsql;

