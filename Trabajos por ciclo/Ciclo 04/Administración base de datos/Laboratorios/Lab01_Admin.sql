DROP USER ONGDBA CASCADE;

SELECT tablespace_name, bytes, max_bytes
FROM DBA_TS_QUOTAS
WHERE username = 'ONGDBA_';

SELECT username, account_status, created, expiry_date, default_tablespace, temporary_tablespace
FROM DBA_USERS
WHERE username = 'ONGDBA_';

SELECT * FROM DBA_SYS_PRIVS WHERE GRANTEE = 'ONGDBA';

SELECT * FROM dba_profiles WHERE resource_name = 'PASSWORD_VERIFY_FUNCTION' AND profile = 'Acces_to_ONGDBA';


