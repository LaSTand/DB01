#include "update.h"
#include "common.h"
#include "menu.h"

// A officer promotion
char * OfficerPromotion() {
	char Police[2][25];
	char output[200] = "update POLICE set TITLE = '";
	char yesorno;

	printf("=========  POLICE OFFICER  ========\n");
	CheckExistingValues("POLICE", "*");
	while (1) {
		printf("Input Officer ID : ");
		scanf("%[^\n]", Police[0]);	MyGetChar();
		if (Police[0][0] == NULL) {
			printf("POLID should not be NULL!!\n");
			continue;
		}
		printf("Input New Title : ");
		scanf("%[^\n]", Police[1]);	MyGetChar();
		break;
	}
	strcat(output, Police[1]);
	strcat(output, "' where POLID = ");
	strcat(output, Police[0]);

	return output;
}
// Officer Transfer
char * OfficerTransfer() {
	char Police[2][25];
	char output[200] = "update POLICE set OFFICE = '";
	char yesorno;

	printf("=========  POLICE OFFICER  ========\n");
	CheckExistingValues("POLICE", "*");
	while (1) {
		printf("Input Officer ID : ");
		scanf("%[^\n]", Police[0]);	MyGetChar();
		if (Police[0][0] == NULL) {
			printf("POLID should not be NULL!!\n");
			continue;
		}
		printf("Input New Office ID\n");
		printf("(Check the Office Info?) (y/n) : ");
		scanf("%c", &yesorno);	MyGetChar();
		if (yesorno == 'y' || yesorno == 'Y') {
			CheckExistingValues("POL_OFFICE", "*");
		}
		printf("Input New Office ID : ");
		scanf("%[^\n]", Police[1]);	MyGetChar();
		break;
	}
	strcat(output, Police[1]);
	strcat(output, "' where POLID = ");
	strcat(output, Police[0]);
	
	return output;
}
// Office manager change
char * ManagerChange() {
	char Office[2][25];
	char output[200] = "update POL_OFFICE set MANAGER = ";
	char yesorno;

	printf("=========   POLICE OFFICE   ========\n");
	CheckExistingValues("POL_OFFICE", "*");
	while (1) {
		printf("Input Office ID : ");
		scanf("%[^\n]", Office[0]);	MyGetChar();
		if (Office[0][0] == NULL) {
			printf("Office ID should not be NULL!!\n");
			continue;
		}
		printf("Input New Manager's Police ID\n");
		printf("(Check the Police Officers Info?) (y/n) : ");
		scanf("%c", &yesorno);	MyGetChar();
		if (yesorno == 'y' || yesorno == 'Y') {
			CheckExistingValues("POLICE", "*");
		}
		printf("Input New Manager's Police ID : ");
		scanf("%[^\n]", Office[1]);	MyGetChar();
		break;
	}
	strcat(output, Office[1]);
	strcat(output, " where OFFID = ");
	strcat(output, Office[0]);
	
	return output;
}
// Assigned work change
char * AssignedWorkChange() {
	char Work[3][20];
	char output[200] = "update WORK set TASKID = ";
	char yesorno;

	printf("=========   Assigend Work   ========\n");
	CheckExistingValues("WORK", "*");
	while (1) {
		printf("Input Officer ID : ");
		scanf("%[^\n]", Work[0]);	MyGetChar();
		if (Work[0][0] == NULL) {
			printf("Officer ID should not be NULL!!\n");
			continue;
		}
		printf("(Check the Task Info?) (y/n) : ");
		scanf("%c", &yesorno);	MyGetChar();
		if (yesorno == 'y' || yesorno == 'Y') {
			CheckExistingValues("TASK", "*");
		}
		printf("Input the Officer's Task ID : ");
		scanf("%[^\n]", Work[1]);	MyGetChar();
		printf("Input New Task ID : ");
		scanf("%[^\n]", Work[2]);	MyGetChar();
		break;
	}
	strcat(output, Work[2]);
	strcat(output, " where POLID = ");
	strcat(output, Work[0]);
	strcat(output, "and TASKID = ");
	strcat(output, Work[1]);
	
	return output;
}
// Work time chanage
char * WorkTimeChange() {
	char Time[3][20];
	char output[200] = "update WORKTIME set START = ";
	char yesorno;

	printf("=========   Work Time   ========\n");
	CheckExistingValues("WORKTIME", "*");
	while (1) {
		printf("Input Time Code : ");
		scanf("%[^\n]", Time[0]);	MyGetChar();
		if (Time[0][0] == NULL) {
			printf("Task ID should not be NULL!!\n");
			continue;
		}
		printf("Input New Start Time : (0 ~ 24) ");
		scanf("%[^\n]", Time[1]);	MyGetChar();
		printf("Input New End Time : (1 ~ 24) ");
		scanf("%[^\n]", Time[2]);	MyGetChar();
		break;
	}
	strcat(output, Time[1]);
	strcat(output, " and ENDT = ");
	strcat(output, Time[2]);
	strcat(output, " where TIMECODE = '");
	strcat(output, Time[0]);
	strcat(output, "'");
	
	return output;
}

void DoUpdate() {
	char input[200];	// for raw query
	char output[200];
	int sel;
	while (1) {
		UpdateMainMenu();
		printf("Select Menu : ");
		scanf("%d", &sel);
		MyGetChar();
		if (sel == 1) {			// Officer promotion
			strcpy(output, OfficerPromotion());
			ExecQuery(output);
		}
		else if (sel == 2) {	// Officer Transfer
			strcpy(output, OfficerTransfer());
			ExecQuery(output);
		}
		else if (sel == 3) {	// Manager Change
			strcpy(output, ManagerChange());
			ExecQuery(output);
		}
		else if (sel == 4) {	// Assigned Work change
			strcpy(output, AssignedWorkChange());
			ExecQuery(output);
		}
		else if (sel == 5) {	// Work Time change
			strcpy(output, WorkTimeChange());
			ExecQuery(output);
		}
		else if (sel == 6) {	// Get raw query sentence
			printf("Input Raw Query : ");
			scanf("%[^\n]", input);
			MyGetChar();
			ExecQuery(input);
		}
		else if (sel == 7) {
			printf("Exit Update mode!!\n\n");
			break;
		}
		else {
			printf("Wrong Type!!\nTry Again!!\n");
		}
	}
}