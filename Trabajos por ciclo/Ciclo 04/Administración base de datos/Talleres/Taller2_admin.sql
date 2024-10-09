/*
Equipo: BigDataInc
Integrante 1: 00067323, sección 01, Abraham Alejandro Flores Vásquez
Integrante 2:
Integrante 3:
*/


ALTER SESSION SET "_ORACLE_SCRIPT"=true;  
-------------------------------------------------------------------
-- Tarea 1.
--
-- Creacion de tablespace
CREATE TABLESPACE TS_ONG
DATAFILE 'C:\taller2\ts_ong.dbf' SIZE 8M
AUTOEXTEND ON NEXT 4M MAXSIZE 512M;

SELECT * FROM DBA_TABLESPACES;
SELECT * FROM DBA_DATA_FILES;


--privilegios para el perfil de ongdba
CREATE PROFILE Acces_to_ONGDBA  LIMIT 
  SESSIONS_PER_USER 1  
  IDLE_TIME 5      
  CONNECT_TIME 30 
  FAILED_LOGIN_ATTEMPTS 3
  PASSWORD_LIFE_TIME 60 
  PASSWORD_LOCK_TIME 0.125; --conversion de horas a dias
  --verificación contraseña segura
  ALTER PROFILE Acces_to_ONGDBA LIMIT PASSWORD_VERIFY_FUNCTION ora12c_strong_verify_function;
  
--Creación de usuario Ongdba
CREATE USER ONGDBA_ --notar "_"
IDENTIFIED BY ora12c_strong_verify_function
DEFAULT TABLESPACE TS_ONG
TEMPORARY TABLESPACE TEMP
PROFILE Acces_to_ONGDBA 
QUOTA UNLIMITED ON TS_ONG;

--cambio a contraseña segura
  ALTER USER ONGDBA_ IDENTIFIED BY "ContrasenaMuySegura_2024$";

--privilegios necesarios para el CRUD al usuario
GRANT CONNECT, RESOURCE, DBA TO ONGDBA_;

-------------------------------------------------------------------
-- Tarea 2.
--
-- Conexion con el usuario ONGDBA_ con contraseña: ContrasenaMuySegura_2024$

--Creación del perfil "perfil_empleado"
CREATE PROFILE perfil_empleado  LIMIT 
  SESSIONS_PER_USER 10  
  IDLE_TIME 10 --minutos      
  CONNECT_TIME 60 --minutos
  FAILED_LOGIN_ATTEMPTS 3
  PASSWORD_LIFE_TIME 30 --dias 
  PASSWORD_LOCK_TIME 1; --dia = 24 horas
  
--verificación contraseña segura
  ALTER PROFILE perfil_empleado LIMIT PASSWORD_VERIFY_FUNCTION ora12c_strong_verify_function;
  
--Creación de usuarios:

--Director
CREATE USER DIRECTOR
IDENTIFIED BY YoSoyInevitable_77$ --Contraseña!!!
DEFAULT TABLESPACE TS_ONG
TEMPORARY TABLESPACE TEMP
PROFILE perfil_empleado 
QUOTA UNLIMITED ON TS_ONG;

--Coordinador
CREATE USER COORDINADOR
IDENTIFIED BY No_me_quiero_ir_senor_Stark_10# --Contraseña!!!
DEFAULT TABLESPACE TS_ONG
TEMPORARY TABLESPACE TEMP
PROFILE perfil_empleado 
QUOTA 250M ON TS_ONG;

--Asistente
CREATE USER ASISTENTE
IDENTIFIED BY "Nunca_vais_A_adivinadme_45&" --Contraseña!!!
DEFAULT TABLESPACE USERS
TEMPORARY TABLESPACE TEMP
PROFILE perfil_empleado
QUOTA 100M ON TS_ONG
QUOTA UNLIMITED ON USERS;

--RRHH
--Asistente
CREATE USER RRHH
IDENTIFIED BY "El-ciclo-esta-Fuerte__90!!" --Contraseña!!!
DEFAULT TABLESPACE USERS
TEMPORARY TABLESPACE TEMP
PROFILE perfil_empleado
QUOTA 100M ON TS_ONG
QUOTA 0 ON USERS;

--RREE
CREATE USER RREE
IDENTIFIED BY "#yo_Soy_INEV!TABLE-503" --Contraseña!!!
DEFAULT TABLESPACE TS_ONG
TEMPORARY TABLESPACE TEMP
PROFILE perfil_empleado
QUOTA 100M ON TS_ONG;

--mostrar todos los usuarios
SELECT * FROM DBA_USERS;


-------------------------------------------------------------------
-- Tarea 3.
--


-------------------------------------------------------------------
-- Tarea 4.
--
-- 