--Ejercicios Parcial

--Grupo A
--Tarea 2
--Crear un procedimiento almacenado que reciba como par�metro de entrada el id de un
--empleado. El procedimiento almacenado deber� retornar la cantidad de reservas en las que el
--empleado ha sido asignado responsable. Considerar todos los datos disponibles en el banco de
--datos.

--Respuesta:

create or replace procedure cant_res_empleado

begin

exception

end



--Grupo B
--Tarea 2
--Crear una funci�n que reciba como par�metros dos fechas, la funci�n retornar� la lista
--de servicios extra ordenados por popularidad para las fechas ingresadas. Para calcular este
--indicador, el �ndice de popularidad de los servicios estar� basado en el porcentaje de adquisici�n de
--los servicios extra en cada reserva

--Respuesta:
create or replace function servicios_extra( date, date)
return decimal

begin
end




--Grupo C
--Tarea 2
--Crear un Trigger que valide que cada vez que se cree una nueva reserva y se asigne un
--empleado responsable de esa reserva, el empleado no tenga asignada una reserva en la fecha y hora
--en la que se intenta crear la nueva reserva. Si no se cumple la condici�n el trigger deber� lanzar una
--excepci�n personalizada.

select * from reserva;
--Respuesta:

CREATE OR REPLACE TRIGGER trg_validate_reserva_empleado
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
    FROM SYS.RESERVA
    WHERE ID_EMPLEADO_RESPONSABLE = :NEW.ID_EMPLEADO_RESPONSABLE
    AND FECHA_RESERVADA = :NEW.FECHA_RESERVADA;

    IF v_count > 0 THEN
        -- Si ya existe una reserva con ese empleado en la misma fecha y hora, lanza excepci�n
        RAISE_APPLICATION_ERROR(-20001, 'El empleado ya tiene una reserva asignada en esa fecha y hora.');
    END IF;
END;
/

puedes probar con datos ficticios si funciona


