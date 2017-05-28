/*
DB01_HW5_122290.cpp
정보보호학과 122290 이재환
*/

#include <stdio.h>
#include "common.h"
#include "menu.h"
#include "select.h"
#include "insert.h"
#include "update.h"
#include "delete.h"

int main(int argc, char *argv[])
{
	int sel;
	if (DBConnect() == true)
	{
		// Main codes
		while (1) {
			PrintMainMenu();
			printf("Input Menu : ");
			scanf("%d", &sel);
			MyGetChar();
			if (sel == 1) {	//select
				DoSelect();
			}
			else if (sel == 2) {	// insert
				DoInsert();
			}
			else if (sel == 3) {	// update
				DoUpdate();
			}
			else if (sel == 4) {	// delete
				DoDelete();
			}
			else if (sel == 5) {	// Show Schema
				PrintSchema();
			}
			else if (sel == 6) {	// Exit
				printf("Exit Program !\n");
				break;
			}
			else {
				printf("Wrong Selection !!\n Tryp Again!!\n");
			}
		}
		// Dissconect from the SQL Server
		DBDisconnect();
	}
	return 0;
}