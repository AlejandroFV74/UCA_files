--ejercicio 1
CREATE OR REPLACE FUNCTION calcular_subtotal_factura(p_id_factura NUMBER)
RETURN NUMBER
IS
    v_subtotal NUMBER;
BEGIN
    SELECT SUM(P.precio)
    INTO v_subtotal
    FROM FACTURA F
    LEFT JOIN DETALLE_PLATO DP ON DP.ID_FACTURA = F.ID
    LEFT JOIN PLATO P ON P.ID = DP.ID_PLATO
    WHERE F.ID = p_id_factura
    GROUP BY F.ID;

    RETURN NVL(v_subtotal, 0); -- Si no hay platillos, devuelve 0
END;
/
SELECT calcular_subtotal_factura(1) FROM dual;

CREATE OR REPLACE FUNCTION calcular_subtotal_postre(p_id_factura NUMBER)
RETURN NUMBER
IS
    v_subtotal NUMBER;
BEGIN
    SELECT SUM(P.precio)
    INTO v_subtotal
    FROM DETALLE_POSTRE DP
    LEFT JOIN POSTRE P ON P.ID = DP.ID_POSTRE
    WHERE DP.ID_FACTURA = p_id_factura
    GROUP BY DP.ID_FACTURA;

    RETURN NVL(v_subtotal, 0); -- Si no hay postres, devuelve 0
END;
/



--Ejercicio 2
CREATE OR REPLACE TYPE factura_info AS OBJECT (
    id_factura NUMBER,
    fecha DATE,
    id_cliente NUMBER,
    id_restaurante NUMBER,
    sub_platos NUMBER,
    sub_postres NUMBER,
    total NUMBER
);
/
CREATE OR REPLACE TYPE factura_info_table AS TABLE OF factura_info;
/
CREATE OR REPLACE FUNCTION subtotal_postres_y_platos_por_fecha(fecha_inicio DATE, fecha_fin DATE)
RETURN factura_info_table PIPELINED
IS
BEGIN
    FOR rec IN (
        SELECT 
            F.ID, 
            F.FECHA, 
            F.ID_CLIENTE, 
            F.ID_RESTAURANTE,
            calcular_subtotal_factura(F.ID) AS sub_platos,
            calcular_subtotal_postre(F.ID) AS sub_postres,
            (calcular_subtotal_factura(F.ID) + calcular_subtotal_postre(F.ID)) AS total
        FROM 
            FACTURA F
        WHERE 
            F.FECHA BETWEEN fecha_inicio AND fecha_fin
    ) 
    LOOP
        -- Usamos PIPE ROW para devolver cada fila una por una
        PIPE ROW(factura_info(
            rec.ID, 
            rec.FECHA, 
            rec.ID_CLIENTE, 
            rec.ID_RESTAURANTE, 
            rec.sub_platos, 
            rec.sub_postres, 
            rec.total
        ));
    END LOOP;
    
    RETURN;
END;
/

SELECT * 
FROM TABLE(subtotal_postres_y_platos_por_fecha(TO_DATE('2022-01-01', 'YYYY-MM-DD'), TO_DATE('2022-01-30', 'YYYY-MM-DD')));






--Hola
CREATE OR REPLACE TRIGGER verificar_estacion_plato
BEFORE INSERT ON DETALLE_PLATO
FOR EACH ROW
DECLARE
  v_fecha_factura DATE;
  v_estacion_factura VARCHAR2(20);
  v_estacion_plato VARCHAR2(20);
  v_mes_dia_factura VARCHAR2(5);
BEGIN
  -- Obtener la fecha de la factura
  SELECT f.fecha INTO v_fecha_factura
  FROM FACTURA f
  WHERE id = :NEW.id_factura;

  -- Extraer el mes y día de la fecha de la factura (formato MM-DD)
  v_mes_dia_factura := TO_CHAR(v_fecha_factura, 'MM-DD');

  -- Determinar la estación correspondiente a la fecha de la factura
  IF v_mes_dia_factura BETWEEN '03-21' AND '06-21' THEN
    v_estacion_factura := 'primavera';
  ELSIF v_mes_dia_factura BETWEEN '06-22' AND '09-23' THEN
    v_estacion_factura := 'verano';
  ELSIF v_mes_dia_factura BETWEEN '09-24' AND '12-21' THEN
    v_estacion_factura := 'otoño';
  ELSE
    v_estacion_factura := 'invierno';
  END IF;

  -- Obtener la estación del plato a partir de su menú
  SELECT m.estacion INTO v_estacion_plato
  FROM PLATO p
  JOIN MENU m ON p.id_menu = m.id
  WHERE p.id = :NEW.id_plato;

  -- Comparar la estación de la factura con la del plato
  IF v_estacion_factura != v_estacion_plato THEN
    RAISE_APPLICATION_ERROR(-20001, 'La estación del plato no corresponde con la estación de la fecha de la factura.');
  END IF;
END;
/


select * from factura;
INSERT INTO FACTURA VALUES (31, TO_DATE('05/07/2022', 'DD/MM/YYYY'),
3, 2); --prueba
INSERT INTO DETALLE_PLATO VALUES (31, 1); --debe dar error
INSERT INTO DETALLE_PLATO VALUES (31, 12); --debe funcionar


delete from factura where factura.id = 32;
select * from menu;
drop trigger verificar_estacion_plato;


--codigo raro de Alex
DECLARE SUBTYPE DEC_10_2 IS DECIMAL(10,2);


CREATE OR REPLACE FUNCTION obtenerSubtotal (id_factura NUMBER)
    RETURN NUMBER
as
  subtotal NUMBER;
BEGIN
 SELECT SUM(P.precio) INTO subtotal
 FROM FACTURA F , DETALLE_PLATO DP, PLATO P
 where f.id = dp.id_factura and p.id = dp.id_plato and f.id = id_factura;
    RETURN subtotal;
END;

SELECT obtenerSubtotal(1) subtotal FROM dual;