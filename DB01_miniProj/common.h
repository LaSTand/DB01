/* 
 Define common functions
 */

#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>

bool DBConnect();
void DBDisconnect();

int ExecQuery(char * input);

void MyGetChar();

void CheckExistingValues(char * tbl_name, char * col_name);

#endif 
