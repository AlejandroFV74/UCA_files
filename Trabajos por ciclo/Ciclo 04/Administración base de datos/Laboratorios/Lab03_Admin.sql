    --Ejemplos
    CREATE TABLESPACE tablespace1
    DATAFILE 'C:\ArchivosOracle\ejercicio1.dbf' SIZE 10M;
    
    CREATE TABLESPACE tablespace2
    DATAFILE 'C:\ArchivosOracle\ejercicio2.dbf' SIZE 10M
    AUTOEXTEND ON NEXT 1M MAXSIZE 20M;
    
    SELECT * FROM DBA_TABLESPACES;
    SELECT * FROM DBA_DATA_FILES;
    
    --TABLA PARA EJERCICIO 5
    
    
    --Ejercicio 1
    CREATE SMALLFILE TABLESPACE TB00067323LB2ABD
    DATAFILE 'C:\ArchivosOracle\ex1.dbf' SIZE 8M
    AUTOEXTEND ON NEXT 2M MAXSIZE 36M;
    
    --Ejercicio 2
    ALTER TABLESPACE TB00067323LB2ABD
    ADD DATAFILE 'C:\ArchivosOracle\ex2.dbf' SIZE 10M AUTOEXTEND OFF;
    
      
    --Ejercicio 3
    ALTER DATABASE DATAFILE 'C:\ArchivosOracle\ex2.dbf' RESIZE 8M;
    
    --Para borrar las tablas
    DROP TABLESPACE TB00067323LB2ABD;
    DROP TABLESPACE TB00067323LB2ABD INCLUDING CONTENTS AND DATAFILES;
    
    --Administración de usuarios
    
    --Ejercicio 4
    --para evitar codigo Ascci
    alter session set "_ORACLE_SCRIPT" = true;
    
    CREATE USER user00067323
    IDENTIFIED BY contrasena
    DEFAULT TABLESPACE TB00067323LB2ABD
    TEMPORARY TABLESPACE TEMP
    QUOTA 4M ON TB00067323LB2ABD;
    
    --Ejercicio 5
    CREATE ROLE HACKER;
    --añadiendo privilegios
    GRANT CONNECT, RESOURCE
    TO HACKER;
    
     CREATE ROLE DEVELOPER;
    --añadiendo privilegios
    GRANT CONNECT, INSERT ANY TABLE
    TO DEVELOPER;
    
    --Role a usuario creado
      GRANT HACKER  TO user00067323;

    --Ejercicio 6
    CREATE PROFILE FCLD_ABD
    LIMIT FAILED_LOGIN_ATTEMPTS 3 
    PASSWORD_LIFE_TIME 20
    IDLE_TIME 30
    PASSWORD_REUSE_MAX 5;
    
    --asignando perfil a usuario creado
    
    ALTER USER user00067323 PROFILE FCLD_ABD;
    

    

    
    