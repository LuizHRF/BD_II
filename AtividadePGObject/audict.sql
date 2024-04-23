CREATE TABLE IF NOT EXISTS sales_item_audict(
	op varchar(15) not null,
	old_value integer not null,
	new_value integer,
	op_date TIMESTAMP NOT NULL,
	op_user varchar(40) NOT NULL);
	

CREATE OR REPLACE FUNCTION trg_audict()
	RETURNS TRIGGER
	AS $$
	DECLARE
		new_operation sales_item_audict%rowtype;
		new_value sale_item.sqty%type;
		cuser varchar(40);
		
BEGIN

		IF (TG_OP = 'UPDATE') THEN
			new_value := NEW.sqty;
		ELSE
			new_value:= NULL;
		END IF;
		
		INSERT INTO sales_item_audict SELECT TG_OP, OLD.sqty, new_value, now(), current_user;
		
		RETURN NULL;
		
END; $$ LANGUAGE plpgsql;


CREATE TRIGGER trg_audict_saleItem
	AFTER UPDATE OR DELETE
	ON sale_item
	FOR EACH ROW EXECUTE PROCEDURE trg_audict();
