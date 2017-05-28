/*
delete 쿼리문을 처리
*/

#include "common.h"
#include "menu.h"
#include "delete.h"

// Officer retire
char * OfficerRetire() {
	char Police[25] = { NULL };
	char output[200] = "delete from POLICE where POLID = ";
	char yesorno;

	printf("=========  POLICE OFFICER  ========\n");
	CheckExistingValues("POLICE", "*");
	while (1) {
		printf("Input Retired Police Officer's ID : ");
		scanf("%[^\n]", Police);	MyGetChar();
		if (Police[0] == NULL) {
			printf("POLID should not be NULL!!\n");
			continue;
		}
		break;
	}
	strcat(output, Police);

	return output;
}
// Office Close
char * OfficeClose() {
	char Office[25] = { NULL };
	char output[200] = "delete from POL_OFFICE where OFFID = ";
	char yesorno;

	printf("=========  POLICE OFFICE  ========\n");
	CheckExistingValues("POL_OFFICE", "*");
	while (1) {
		printf("*** WARNING ***\n Don't Delete 'Seoul JungAng'(Offid 200)\n");
		printf("Input Closed Office ID : ");
		scanf("%[^\n]", Office);	MyGetChar();
		if (Office[0] == NULL) {
			printf("POLID should not be NULL!!\n");
			continue;
		}
		break;
	}
	strcat(output, Office);

	return output;
}
// Task Delete
char * TaskDelete() {
	char Task[10] = { NULL };
	char output[200] = "delete from TASK where TASKID = ";
	char yesorno;

	printf("=========  TASK LIST  ========\n");
	CheckExistingValues("TASK", "*");
	while (1) {
		printf("Input Deleting Task ID : ");
		scanf("%[^\n]", Task);	MyGetChar();
		if (Task[0] == NULL) {
			printf("TASKID should not be NULL!!\n");
			continue;
		}
		break;
	}
	strcat(output, Task);

	return output;
}
// Time Code Delete
char * TimeCodeDelete() {
	char tmcd[10] = { NULL };
	char output[200] = "delete from WORKTIME where TIMECODE = '";
	char yesorno;

	printf("=========  TIME CODE LIST  ========\n");
	CheckExistingValues("WORKTIME", "*");
	while (1) {
		printf("Input Deleting TIME CODE : ");
		scanf("%[^\n]", tmcd);	MyGetChar();
		if (tmcd[0] == NULL) {
			printf("TIME CODE should not be NULL!!\n");
			continue;
		}
		break;
	}
	strcat(output, tmcd);
	strcat(output, "'");

	return output;
}

void DoDelete() {
	char raw[200] = { NULL };
	char output[200];
	int sel;

	while (1) {
		DeleteMainMenu();
		printf("Input Delete Type : ");
		scanf("%d", &sel);	MyGetChar();

		if (sel == 1) {	// Officer Retire
			strcpy(output, OfficerRetire());
			ExecQuery(output);
		}
		else if (sel == 2) {	// Office close
			strcpy(output, OfficeClose());
			ExecQuery(output);
		}
		else if (sel == 3) {	// Task delete
			strcpy(output, TaskDelete());
			ExecQuery(output);
		}
		else if (sel == 4) {	// Time code delete
			strcpy(output, TimeCodeDelete());
			ExecQuery(output);
		}
		else if (sel == 5) {	// Work time table delete
		}
		else if (sel == 6) {
			printf("Exit Insert mode!!\n\n");
			break;
		}
		else {
			printf("Wrong Type!!\nTry Again!!\n");
		}
	}
}