/*
 자주 사용되는 일반 함수들
 */
#include "common.h"

// SQL Environment Variables
SQLHENV hEnv = NULL;
SQLHDBC hDbc = NULL;

bool DBConnect()
{
	SQLRETURN Ret;

	// Allocate the Environment Handle (hEnv)
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) != SQL_SUCCESS) {
		return false;
	}
	// Set attributes of the Environment Handle (hEnv)
	if (SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER) != SQL_SUCCESS)
	{
		return false;
	}
	// Allocate the Connection Handle (hDbc)
	if (SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc) != SQL_SUCCESS)
	{
		return false;
	}
	// Connect to the SQL Server with ODBC namd ID and PW
	Ret = SQLConnect(hDbc, (SQLCHAR *)"JH01_Server", SQL_NTS, (SQLCHAR *)"JH01", SQL_NTS, (SQLCHAR *)"qwer1234", SQL_NTS);
	if ((Ret != SQL_SUCCESS) && (Ret != SQL_SUCCESS_WITH_INFO))
	{
		return false;
	}
	return true;
}

void DBDisconnect()
{
	SQLDisconnect(hDbc);	// Disconnect from the SQL Server
	SQLFreeHandle(SQL_HANDLE_DBC, hDbc);	// Free the Connection Handle
	SQLFreeHandle(SQL_HANDLE_ENV, hEnv);	// Free the Environment Handle
}

int ExecQuery(char * input) {
	static SQLCHAR query[200];
	SQLHSTMT hStmt;
	SQLSMALLINT colCnt = -1;	// 컬럼 갯수를 저장할 변수
	SQLCHAR data[50][30];	//	컬럼 갯수는 최대 50개로 잡고 
	SQLINTEGER nulldata[50];
	SQLRETURN retcode;

	int i;
	//printf("*TEST* ExecQuery Function!\n");
	if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
	{
		//printf("Connection Success!!\n");
		sprintf((char *)query, "%s", input);

		retcode = SQLExecDirect(hStmt, query, SQL_NTS);
		SQLNumResultCols(hStmt, &colCnt);

		if (retcode == SQL_ERROR || retcode == SQL_NO_DATA_FOUND) {
			printf("SQL Query Execute Error \n");
			return 0;
		}
		strtok(input, " ");
		if (strncmp(input, "select", 7) == 0) {
			for (i = 0; i < colCnt; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}
			while (SQLFetch(hStmt) != SQL_NO_DATA)
			{
				for (i = 0; i < colCnt; i++) {
					if (nulldata[i] == SQL_NULL_DATA)
						printf("NULL  ");
					else
						printf("%-9s", data[i]);
				}
				printf("\n");
			}
		}
		SQLCloseCursor(hStmt);
		SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}
	else {
		printf("Fail to Connect!!\n");
	}
	return 0;
}

void MyGetChar() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}

void CheckExistingValues(char * tbl_name, char * col_name) {
	char chk_query[200] = "select distinct ";

	strcat(chk_query, col_name);
	strcat(chk_query, " from ");
	strcat(chk_query, tbl_name);

	printf("======  Existing Value List  ======\n");
	ExecQuery(chk_query);
	printf("===================================\n");
}