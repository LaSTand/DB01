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
		if (strncmp(Office, "200", 3) == 0) {
			printf("Don't Delete Offid id '200'!!\n");
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
// Assigned Task Delete
// 2개 테이블 join
char * AssignedTaskDelete() {
	char as_task[2][20] = { NULL };
	char output[200] = "delete WORK from POLICE P where P.POLID=WORK.POLID and P.TITLE <> '";

	printf("=========  Assigned Work Table  ========\n");
	CheckExistingValues("WORK W, POLICE P where P.POLID=W.POLID", "*");
	printf("==================== D E S C R I P T I O N ====================\n");
	printf("This menu offers delete the assigned work of police officers.\n");
	printf("You can give an exception title\n");
	printf("Ex) If you want to delete the assigned work 'Patrol',\n");
	printf("    but you want to except the 'Assistant Inspector'.\n");
	printf("    Then, the 'Patrol' task will be assinged to only 'Assistant Inspector's\n");
	while (1) {
		printf("Input the Title(To be excepted) : ");
		scanf("%[^\n]", as_task[0]);	MyGetChar();
		CheckExistingValues("TASK", "*");
		printf("Input task ID : ");
		scanf("%s", as_task[1]);	MyGetChar();
		if (as_task[0][0] == NULL || as_task[1][0] == NULL) {
			printf("Please input the Title info and Task ID !!\n");
			printf("These values should not be empty(null value) !!\n");
			continue;
		}
		break;
	}
	strcat(output, as_task[0]);
	strcat(output, "' and WORK.TASKID=");
	strcat(output, as_task[1]);
	//printf("%s\n", output);
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
		else if (sel == 5) {	// Assigned Task delete
			strcpy(output, AssignedTaskDelete());
			ExecQuery(output);
		}
		else if (sel == 6) {	// Input Raw Query
			printf("Input Raw Query : ");
			scanf("%[^\n]", raw);
			MyGetChar();
			ExecQuery(raw);
		}
		else if (sel == 7) {
			printf("Exit Delete mode!!\n\n");
			break;
		}
		else {
			printf("Wrong Type!!\nTry Again!!\n");
		}
	}
}