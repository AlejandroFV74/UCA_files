    --Ejercicios a trabajar en laboratorio 02

    --||  Bloque 1  ||

--Ejercicio 1

--Crear una función que retorne una tabla con toda la información de los trenes,
--además, la tabla debe incluir cuantos viajes ha realizado cada tren entre dos fechas
--que serán ingresadas como parámetros de la función. La función también de incluir el
--porcentaje de viajes de cada tren con respecto a todos los viajes acumulados entre las
--dos fechas.

--consulta información de los trenes
SELECT * FROM 
TREN t INNER JOIN VIAJE v
ON t.id = v.id_tren

--Tipo de colección
CREATE OR REPLACE TYPE coleccion_trenes AS OBJECT(
    id INT,
    serie VARCHAR(10),
    capacidad VARCHAR(15),
    cantidad INT,
    porcentaje DECIMAL(18,2)
);
--tipo de tabla objeto
CREATE OR REPLACE TYPE tabla_trenes AS TABLE OF coleccion_trenes;

--funcion
CREATE OR REPLACE FUNCTION coleccion_trenes_funcion(
    startdate TIMESTAMP, 
    finishdate TIMESTAMP
)
RETURN tabla_trenes AS
    tabla tabla_trenes;
BEGIN
    SELECT coleccion_trenes (
    TREN.ID, TREN.SERIE, TREN.CAPACIDAD, COUNT(VIAJE.ID),
    (COUNT(VIAJE.ID) / SUM(COUNT(VIAJE.ID)) OVER ()) * 100)
    
    BULK COLLECT INTO tabla
    FROM TREN
    INNER JOIN VIAJE ON VIAJE.ID_TREN = TREN.ID
    WHERE VIAJE.FECHA_SALIDA BETWEEN startdate AND finishdate
    GROUP BY TREN.ID, TREN.SERIE, TREN.CAPACIDAD;
    RETURN tabla;
END;

--Uso de la función del ejercicio 1
SELECT * FROM TABLE(coleccion_trenes_funcion(TIMESTAMP '2023-05-01 00:00:00', TIMESTAMP '2023-05-05 00:00:00'));





--Ejercicio 2 (Hecho como demostración en labo)

--Crear una función que retorne una tabla con toda la información de las estaciones,
--además, la tabla debe incluir cuantos viajes han iniciado en cada estación entre dos
--fechas que serán ingresadas como parámetros de la función. La función también debe
--incluir el porcentaje de viajes de cada estación con respecto a todos los viajes
--acumulados entre las dos fechas.

--consulta cantidad de viajes y porcentaje
SELECT e.id, e.nombre, COUNT(v.id_estacion_origen) "Cantidad viajes" ,
(COUNT (v.id_estacion_origen)/(SELECT COUNT(*) FROM VIAJE v))*100 Porcentaje
FROM ESTACION e 
LEFT JOIN VIAJE v 
ON e.id = v.id_estacion_origen
WHERE v.fecha_salida BETWEEN '01-05-23' AND '05/05/23'
GROUP BY e.id, e.nombre
ORDER BY e.id;

--subconsulta
SELECT COUNT(*) FROM VIAJE v;

--FUNCION
--OBJETO 
CREATE OR REPLACE TYPE ex_1_row AS OBJECT(
    id INT,
    nombre VARCHAR2(50),
    cantidad NUMBER,
    porcentaje NUMBER
);

--arreglo objetos "coleccion"


--funcion
CREATE OR REPLACE FUNCTION ex_funcion(
    --parametros
    start_date TIMESTAMP,
    end_date TIMESTAMP
) RETURN ex_1_collection 
AS tabla ex_1_collection;
    BEGIN
        SELECT 
        --objeto
        ex_1_row
        --columnas
        (e.id, e.nombre, COUNT(v.id_estacion_origen),
        --porcentaje
        (COUNT (v.id_estacion_origen)/(SELECT COUNT(*) FROM VIAJE v))*100)
        
        BULK COLLECT INTO tabla
        
        FROM ESTACION e 
        LEFT JOIN VIAJE v 
        ON e.id = v.id_estacion_origen
        WHERE v.fecha_salida BETWEEN start_date AND end_date
        GROUP BY e.id, e.nombre
        ORDER BY e.id;
        
        RETURN tabla;
        
    END;
    
    --Ejecutando funcion
    SELECT * FROM TABLE(ex_funcion('01/05/23','05/05/23'));
    
    
    --||  Bloque 2  ||

--Ejercicio 1

--Crear una función (y solo una) que calcule los puntos de viajero frecuente 
--generados por cada una de las reservas registradas en la tabla reserva. 
--La función no recibe ningún parámetro y debe retornar una tabla con el 
--detalle de las reservas actuales, la tabla retornada debe mostrar el 
--detalle de la reserva, los puntos calculados por cada criterio, y el 
--total de puntos acumulados por todos los criterios. La siguiente tabla 
--detalla los criterios.

CREATE OR REPLACE FUNCTION calcular_puntos_reservas
RETURN SYS_REFCURSOR
IS
    resultado SYS_REFCURSOR;
BEGIN
    OPEN resultado FOR
        SELECT 
            r.id AS id_reserva,
            p.id AS id_pasajero,
            p.nombre AS pasajero,
            p.identificacion,
            r.costo,
            
            -- Puntos por costo de reserva
            CASE 
                WHEN r.costo < 60 THEN 5
                WHEN r.costo BETWEEN 60 AND 80 THEN 10
                ELSE 15
            END AS puntos_costo,
            
            r.id_clase AS id_clase_reservada,
            
            -- Puntos por clase reservada
            CASE 
                WHEN r.id_clase = 1 THEN 1
                WHEN r.id_clase = 2 THEN 10
                WHEN r.id_clase = 3 THEN 50
            END AS puntos_clase,
            
            COUNT(e.id_servicio) AS cantidad_servicios_extra,
            
            -- Puntos por servicios extra
            COUNT(e.id_servicio) * 10 AS puntos_servicio_extra,
            
            -- Total de puntos
            (CASE 
                WHEN r.costo < 60 THEN 5
                WHEN r.costo BETWEEN 60 AND 80 THEN 10
                ELSE 15
            END) +
            (CASE 
                WHEN r.id_clase = 1 THEN 1
                WHEN r.id_clase = 2 THEN 10
                WHEN r.id_clase = 3 THEN 50
            END) +
            (COUNT(e.id_servicio) * 10) AS puntos_total
            
        FROM 
            RESERVA r
        JOIN 
            PASAJERO p ON r.id_pasajero = p.id
        LEFT JOIN 
            EXTRA e ON r.id = e.id_reserva
        GROUP BY 
            r.id, p.id, p.nombre, p.identificacion, r.costo, r.id_clase
        ORDER BY 
            r.id;
    
    RETURN resultado;
END;
/
DECLARE
    cur SYS_REFCURSOR;
BEGIN
    -- Llamar a la función
    cur := calcular_puntos_reservas;
    
    -- Mostrar los resultados como tabla
    DBMS_SQL.RETURN_RESULT(cur);
END;

--Por si se arruina la funcion
DROP FUNCTION calcular_puntos_reserva;


    
    
    --||  Desafío  ||
    
--Ejercicio 1
/*
Crear un bloque de programación que calcule para cada cliente el total de puntos
acumulados en todas las reservas registradas, para facilitar el trabajo, uno de los
requerimientos es que se debe hacer uso de la tabla que retorna la función creada en
el problema anterior. Cuando el procedimiento almacenado ha calculado el total de un
viajero, este procederá a actualizar la columna “puntos_viajero_frecuente” de la tabla
PASAJERO.
*/
CREATE OR REPLACE PROCEDURE actualizar_puntos_viajeros
IS
    cur SYS_REFCURSOR;

    v_id_reserva NUMBER;
    v_id_pasajero NUMBER;
    v_pasajero VARCHAR2(50);
    v_identificacion VARCHAR2(64);
    v_costo FLOAT;
    v_puntos_costo NUMBER;
    v_id_clase_reservada NUMBER;
    v_puntos_clase NUMBER;
    v_cantidad_servicios_extra NUMBER;
    v_puntos_servicio_extra NUMBER;
    v_puntos_total NUMBER;

BEGIN
    -- Abrir el cursor llamando a la función calcular_puntos_reservas
    cur := calcular_puntos_reservas;

    LOOP
        -- Extraer los valores del cursor
        FETCH cur INTO v_id_reserva, v_id_pasajero, v_pasajero, v_identificacion, 
                      v_costo, v_puntos_costo, v_id_clase_reservada, 
                      v_puntos_clase, v_cantidad_servicios_extra, 
                      v_puntos_servicio_extra, v_puntos_total;

        EXIT WHEN cur%NOTFOUND;

        -- Actualizar los puntos acumulados del pasajero en la tabla PASAJERO
        UPDATE PASAJERO
        SET puntos_viajero_frecuente = COALESCE(puntos_viajero_frecuente, 0) + v_puntos_total
        WHERE id = v_id_pasajero;

    END LOOP;

    CLOSE cur;
END actualizar_puntos_viajeros;
/

BEGIN
    actualizar_puntos_viajeros;
END;
/

SELECT 
    id AS id_pasajero,
    nombre AS pasajero,
    puntos_viajero_frecuente
FROM 
    PASAJERO
ORDER BY 
    id_pasajero DESC;
    
  
    

    