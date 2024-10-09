--Ejercicios Parcial

--Grupo A
--Tarea 2
--Crear un procedimiento almacenado que reciba como parámetro de entrada el id de un
--empleado. El procedimiento almacenado deberá retornar la cantidad de reservas en las que el
--empleado ha sido asignado responsable. Considerar todos los datos disponibles en el banco de
--datos.

--Respuesta:
CREATE OR REPLACE PROCEDURE obtener_cantidad_reservas_empleado(
    p_id_empleado IN NUMBER,
    p_cantidad_reservas OUT NUMBER
)
IS
BEGIN
    -- Calcular reservas asignadas al empleado
    SELECT COUNT(*)
    INTO p_cantidad_reservas
    FROM RESERVA
    WHERE ID_EMPLEADO_RESPONSABLE = p_id_empleado;

EXCEPTION
    WHEN NO_DATA_FOUND THEN
        p_cantidad_reservas := 0;
    WHEN OTHERS THEN
        RAISE_APPLICATION_ERROR(-20001, 'Error al consultar la cantidad de reservas');
END;


--Ejemplo de uso
DECLARE
    v_cantidad_reservas NUMBER;
BEGIN
    
    obtener_cantidad_reservas_empleado(12, v_cantidad_reservas);
    
    -- Mostrar el resultado, (en salida DBMS)
    DBMS_OUTPUT.PUT_LINE('El empleado tiene ' || v_cantidad_reservas || ' reservas asignadas.');
END;
/







--Grupo B
--Tarea 2
--Crear una función que reciba como parámetros dos fechas, la función retornará la lista
--de servicios extra ordenados por popularidad para las fechas ingresadas. Para calcular este
--indicador, el índice de popularidad de los servicios estará basado en el porcentaje de adquisición de
--los servicios extra en cada reserva

--Respuesta:
CREATE OR REPLACE TYPE servicio_popular AS OBJECT (
    servicio               VARCHAR2(30),
    veces_adquirido        NUMBER,
    porcentaje_popularidad NUMBER
);


CREATE OR REPLACE TYPE tabla_servicios_populares AS TABLE OF servicio_popular;


CREATE OR REPLACE FUNCTION obtener_servicios_populares (
    fecha_inicio IN DATE,
    fecha_fin IN DATE
) RETURN tabla_servicios_populares
AS
    v_tabla_servicios tabla_servicios_populares := tabla_servicios_populares();
    total_reservas    NUMBER;
BEGIN
    -- Contar el total de reservas en el rango de fechas
    SELECT COUNT(*)
    INTO total_reservas
    FROM RESERVA
    WHERE FECHA_RESERVADA BETWEEN fecha_inicio AND fecha_fin;

    -- Agregar los servicios populares a la tabla
    FOR r IN (
        SELECT s.SERVICIO, COUNT(e.ID_SERVICIO) AS veces_adquirido, 
               (COUNT(e.ID_SERVICIO) / total_reservas) * 100 AS porcentaje_popularidad
        FROM EXTRA e
        JOIN SERVICIO s ON e.ID_SERVICIO = s.ID
        JOIN RESERVA r ON e.ID_RESERVA = r.ID
        WHERE r.FECHA_RESERVADA BETWEEN fecha_inicio AND fecha_fin
        GROUP BY s.SERVICIO
        ORDER BY veces_adquirido DESC
    )
    LOOP
        -- Agregar cada registro a la tabla de resultados
        v_tabla_servicios.EXTEND;
        v_tabla_servicios(v_tabla_servicios.COUNT) := servicio_popular(r.SERVICIO, r.veces_adquirido, r.porcentaje_popularidad);
    END LOOP;

    -- Devolver la tabla con los resultados
    RETURN v_tabla_servicios;
END;

--tabla:
SELECT * FROM SERVICIO;

--prueba funcion;
SELECT * 
FROM TABLE(obtener_servicios_populares(TO_DATE('01/04/2024', 'DD/MM/YYYY'), TO_DATE('05/04/2024', 'DD/MM/YYYY')));












--Grupo C
--Tarea 2
--Crear un Trigger que valide que cada vez que se cree una nueva reserva y se asigne un
--empleado responsable de esa reserva, el empleado no tenga asignada una reserva en la fecha y hora
--en la que se intenta crear la nueva reserva. Si no se cumple la condición el trigger deberá lanzar una
--excepción personalizada.

select * from reserva;
--Respuesta:

CREATE OR REPLACE TRIGGER trg_validar_reserva_empleado
BEFORE INSERT ON RESERVA
FOR EACH ROW
DECLARE
    v_count NUMBER;
    ex_reserva_duplicada EXCEPTION;
    PRAGMA EXCEPTION_INIT(ex_reserva_duplicada, -20001);
BEGIN
    -- Validar si el empleado ya tiene una reserva en la misma fecha y hora
    SELECT COUNT(*)
    INTO v_count
    FROM RESERVA
    WHERE ID_EMPLEADO_RESPONSABLE = :NEW.ID_EMPLEADO_RESPONSABLE
    AND FECHA_RESERVADA = :NEW.FECHA_RESERVADA;

    IF v_count > 0 THEN
        -- Si ya existe una reserva con ese empleado en la misma fecha y hora, lanza excepción,
        RAISE_APPLICATION_ERROR(-20001, 'El empleado ya tiene una reserva asignada en esa fecha y hora.');
    END IF;
END;
/

--mostrar tabla
SELECT * FROM RESERVA ORDER BY RESERVA.ID;

--Prueba con dato erroneo: muestra la excepcion:
INSERT INTO RESERVA (ID, ID_VEHICULO, ID_EMPLEADO_RESPONSABLE, FECHA_TRANSACCION, FECHA_RESERVADA, FECHA_SERVICIO_APLICADO)
VALUES (755, 8, 12, TO_TIMESTAMP('01/04/24 10:00:00 AM', 'DD/MM/YY HH:MI:SS AM'), TO_TIMESTAMP('05/04/24 02:30:00 PM', 'DD/MM/YY HH:MI:SS PM'), TO_TIMESTAMP('05/04/24 03:00:00 PM', 'DD/MM/YY HH:MI:SS PM'));

--Prueba con datos correcto: no muestra la excepcion: (UTLIMO ID ES 753)

INSERT INTO RESERVA (ID, ID_VEHICULO, ID_EMPLEADO_RESPONSABLE, FECHA_TRANSACCION, FECHA_RESERVADA, FECHA_SERVICIO_APLICADO)
VALUES (754, 8, 12, TO_TIMESTAMP('01/04/24 10:00:00 AM', 'DD/MM/YY HH:MI:SS AM'), TO_TIMESTAMP('06/04/24 02:30:00 PM', 'DD/MM/YY HH:MI:SS PM'), TO_TIMESTAMP('06/04/24 03:00:00 PM', 'DD/MM/YY HH:MI:SS PM'));

--Valor con id 754 se insertó