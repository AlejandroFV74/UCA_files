SELECT * FROM DBA_TABLESPACES;

DROP TABLESPACE USERP1_TBS INCLUDING CONTENTS AND DATAFILES;
DROP TABLESPACE TABLESPACE1 INCLUDING CONTENTS AND DATAFILES;
DROP TABLESPACE TABLESPACE2 INCLUDING CONTENTS AND DATAFILES;
DROP TABLESPACE TB00067323LB2ABD INCLUDING CONTENTS AND DATAFILES;
DROP TABLESPACE TS_ONG INCLUDING CONTENTS AND DATAFILES;

CREATE TABLESPACE TS_LABORATORIO
DATAFILE 'C:\laboratorio\DF_LABORATORIO.dba'
SIZE 10M;

CREATE TABLE clientes (
    nombre VARCHAR2(100) NOT NULL,
    email VARCHAR2(100) UNIQUE NOT NULL,
    telefono VARCHAR2(15)
)TABLESPACE TS_LABORATORIO;


INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 1', 'cliente1@ejemplo.com', '555-0000001');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 2', 'cliente2@ejemplo.com', '555-0000002');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 3', 'cliente3@ejemplo.com', '555-0000003');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 4', 'cliente4@ejemplo.com', '555-0000004');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 5', 'cliente5@ejemplo.com', '555-0000005');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 6', 'cliente6@ejemplo.com', '555-0000006');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 7', 'cliente7@ejemplo.com', '555-0000007');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 8', 'cliente8@ejemplo.com', '555-0000008');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 9', 'cliente9@ejemplo.com', '555-0000009');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 10', 'cliente10@ejemplo.com', '555-0000010');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 11', 'cliente11@ejemplo.com', '555-0000011');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 12', 'cliente12@ejemplo.com', '555-0000012');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 13', 'cliente13@ejemplo.com', '555-0000013');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 14', 'cliente14@ejemplo.com', '555-0000014');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 15', 'cliente15@ejemplo.com', '555-0000015');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 16', 'cliente16@ejemplo.com', '555-0000016');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 17', 'cliente17@ejemplo.com', '555-0000017');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 18', 'cliente18@ejemplo.com', '555-0000018');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 19', 'cliente19@ejemplo.com', '555-0000019');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 20', 'cliente20@ejemplo.com', '555-0000020');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 21', 'cliente21@ejemplo.com', '555-0000021');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 22', 'cliente22@ejemplo.com', '555-0000022');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 23', 'cliente23@ejemplo.com', '555-0000023');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 24', 'cliente24@ejemplo.com', '555-0000024');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 25', 'cliente25@ejemplo.com', '555-0000025');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 26', 'cliente26@ejemplo.com', '555-0000026');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 27', 'cliente27@ejemplo.com', '555-0000027');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 28', 'cliente28@ejemplo.com', '555-0000028');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 29', 'cliente29@ejemplo.com', '555-0000029');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 30', 'cliente30@ejemplo.com', '555-0000030');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 31', 'cliente31@ejemplo.com', '555-0000031');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 32', 'cliente32@ejemplo.com', '555-0000032');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 33', 'cliente33@ejemplo.com', '555-0000033');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 34', 'cliente34@ejemplo.com', '555-0000034');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 35', 'cliente35@ejemplo.com', '555-0000035');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 36', 'cliente36@ejemplo.com', '555-0000036');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 37', 'cliente37@ejemplo.com', '555-0000037');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 38', 'cliente38@ejemplo.com', '555-0000038');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 39', 'cliente39@ejemplo.com', '555-0000039');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 40', 'cliente40@ejemplo.com', '555-0000040');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 41', 'cliente41@ejemplo.com', '555-0000041');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 42', 'cliente42@ejemplo.com', '555-0000042');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 43', 'cliente43@ejemplo.com', '555-0000043');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 44', 'cliente44@ejemplo.com', '555-0000044');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 45', 'cliente45@ejemplo.com', '555-0000045');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 46', 'cliente46@ejemplo.com', '555-0000046');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 47', 'cliente47@ejemplo.com', '555-0000047');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 48', 'cliente48@ejemplo.com', '555-0000048');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 49', 'cliente49@ejemplo.com', '555-0000049');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente 50', 'cliente50@ejemplo.com', '555-0000050');
COMMIT;

--PARTE 3
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente Error', 'clienteError@ejemplo.com', '555-6900049');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente Error2', 'clienteError2@ejemplo.com', '555-0006950');

SELECT * FROM CLIENTES;

--PARTE 4
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente Error3', 'clienteError3@ejemplo.com', '555-6904049');
INSERT INTO clientes (nombre, email, telefono) VALUES ('Cliente Error4', 'clienteError4@ejemplo.com', '555-0306950');