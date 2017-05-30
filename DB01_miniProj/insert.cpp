/*
insert 쿼리문을 처리
*/
#include "insert.h"
#include "common.h"
#include "menu.h"

// New Officer
char * NewOfficer() {
	char Police[4][25] = { NULL };
	char output[200] = "insert into POLICE values(";
	char yesorno;
	
	NewOfficerMenu();
	while (1) {
		printf("Input POLID : ");
		scanf("%[^\n]", Police[0]);	MyGetChar();
		if (Police[0][0] == NULL) {
			printf("POLID should not be NULL!!\n");
			continue;
		}
		printf("Input POLNAME : ");
		scanf("%[^\n]", Police[1]);	MyGetChar();

		printf("Input TITLE\n");
		printf("(Check existing values? y/n ) : ");
		scanf("%c", &yesorno);	MyGetChar();
		if (yesorno == 'y') {
			CheckExistingValues("POLICE", "TITLE");
		}
		printf("Input Title : ");
		scanf("%[^\n]", Police[2]);	MyGetChar();

		printf("Input Office Number\n");
		printf("(Check existing values? y/n ) : ");
		scanf("%d", &yesorno);	MyGetChar();
		if (yesorno == 'y') {
			CheckExistingValues("POL_OFFICE", "OFFID");
		}
		printf("Input number : ");
		scanf("%[^\n]", Police[3]);	MyGetChar();

		break;
	}
	strcat(output, Police[0]);
	strcat(output, ", '");
	strcat(output, Police[1]);
	strcat(output, "','");
	strcat(output, Police[2]);
	strcat(output, "',");
	strcat(output, Police[3]);
	strcat(output, ")");
	
	return output;
}
// New Office
char * NewOffice() {
	char Office[5][20] = { NULL };
	char output[200] = "insert into POL_OFFICE values(";
	char yesorno;

	NewOfficeMenu();
	while (1) {
		printf("Input Office ID : ");
		scanf("%[^\n]", Office[0]);	MyGetChar();
		if (Office[0][0] == NULL) {
			printf("Office ID should not be NULL!!\n");
			continue;
		}
		printf("Input City : ");
		scanf("%[^\n]", Office[1]);	MyGetChar();
		printf("Input Gu : ");
		scanf("%[^\n]", Office[2]);	MyGetChar();
		printf("Input Dong : ");
		scanf("%[^\n]", Office[3]);	MyGetChar();

		printf("Input Manager's Police ID\n");
		printf("(Check existing values? y/n ) : ");
		scanf("%c", &yesorno);	MyGetChar();
		if (yesorno == 'y' || yesorno == 'Y') {
			CheckExistingValues("POLICE where TITLE='Inspector'", "*");
		}
		printf("Input Manager's Police ID : ");
		scanf("%[^\n]", Office[4]);	MyGetChar();
		break;
	}
	strcat(output, Office[0]);
	strcat(output, ", '");
	strcat(output, Office[1]);
	strcat(output, "','");
	strcat(output, Office[2]);
	strcat(output, "','");
	strcat(output, Office[3]);
	strcat(output, "',");
	strcat(output, Office[4]);
	strcat(output, ")");

	return output;
}
// New Task
char * NewTask() {
	char Task[2][20] = { NULL };
	char output[200] = "insert into TASK values(";
	char yesorno;

	NewTaskMenu();
	while (1) {
		printf("Input Task ID\n");
		printf("(Check existing values? y/n ) : ");
		scanf("%c", &yesorno);	MyGetChar();
		if (yesorno == 'y' || yesorno == 'Y') {
			CheckExistingValues("TASK", "TASKID");
		}
		printf("Input Task ID : ");
		scanf("%[^\n]", Task[0]);	MyGetChar();
		if (Task[0][0] == NULL) {
			printf("Task ID should not be NULL!!\n");
			continue;
		}
		printf("Input Task Name : ");
		scanf("%[^\n]", Task[1]);	MyGetChar();
		
		break;
	}
	strcat(output, Task[0]);
	strcat(output, ",'");
	strcat(output, Task[1]);
	strcat(output, "')");
	return output;
}
// New Work Assigning
char * NewTimeTable() {
	char Beassign[2][20] = { NULL };
	char output[200] = "insert into BE_ASSIGNED values(";
	char yesorno;

	NewTimeTableMenu();
	while (1) {
		printf("(Check existing values? y/n ) : ");
		scanf("%c", &yesorno);	MyGetChar();
		if (yesorno == 'y' || yesorno == 'Y') {
			CheckExistingValues("BE_ASSIGNED", "*");
		}
		printf("Input Task ID : ");
		scanf("%[^\n]", Beassign[0]);	MyGetChar();
		printf("Input Time Code : \n");
		printf("(Check Time Code Info? y/n ) : ");
		scanf("%c", &yesorno);	MyGetChar();
		if (yesorno == 'y' || yesorno == 'Y') {
			CheckExistingValues("WORKTIME", "*");
		}
		printf("Input Time Code : ");
		scanf("%[^\n]", Beassign[1]);	MyGetChar();
		if (Beassign[0][0] == NULL || Beassign[1][0] == NULL) {
			printf("Task ID should not be NULL!!\n");
			continue;
		}
		break;
	}
	strcat(output, Beassign[0]);
	strcat(output, ",'");
	strcat(output, Beassign[1]);
	strcat(output, "')");
	return output;
}
// New Region
char * NewRegion() {
	char Region[3][20] = { NULL };
	char output[200] = "insert into REGION values(";
	char yesorno;

	NewRegionMenu();
	while (1) {
		printf("Input Office ID \n");
		printf("(Check existing values? y/n ) : ");
		scanf("%c", &yesorno);	MyGetChar();
		if (yesorno == 'y' || yesorno == 'Y') {
			CheckExistingValues("POL_OFFICE", "OFFID, CITY, GU");
		}
		printf("Input Office ID : ");
		scanf("%[^\n]", Region[0]);	MyGetChar();
		if (Region[0][0] == NULL) {
			printf("Office ID should not be NULL!!\n");
			continue;
		}
		printf("Input Region Name : ");
		scanf("%[^\n]", Region[1]);	MyGetChar();
		printf("Input Population : ");
		scanf("%[^\n]", Region[2]);	MyGetChar();
		
		break;
	}
	strcat(output, Region[0]);
	strcat(output, ",'");
	strcat(output, Region[1]);
	strcat(output, "',");
	strcat(output, Region[2]);
	strcat(output, ")");
	return output;
}

/*  Insert Statement handle  */
void DoInsert() {
	char raw[200] = { NULL };
	char output[200];
	int sel;

	while (1) {
		InsertMainMenu();
		printf("Select Menu : ");
		scanf("%d", &sel);
		MyGetChar();
		if (sel == 1) {	// Officer
			strcpy(output, NewOfficer());
			ExecQuery(output);
		}
		else if (sel == 2) {	// Office
			strcpy(output, NewOffice());
			ExecQuery(output);
		}
		else if (sel == 3) {	// Task
			strcpy(output, NewTask());
			ExecQuery(output);
		}
		else if (sel == 4) {	// Time table
			strcpy(output, NewTimeTable());
			ExecQuery(output);
		}
		else if (sel == 5) {	// Region
			strcpy(output, NewRegion());
			ExecQuery(output);
		}
		else if (sel == 6) {	// Get raw query sentence
			printf("Input Raw Query : ");
			scanf("%[^\n]", raw);
			MyGetChar();
			ExecQuery(raw);
		}
		else if (sel == 7) {
			printf("Exit Insert mode!!\n\n");
			break;
		}
		else {
			printf("Wrong Type!!\nTry Again!!\n");
		}
	}
}