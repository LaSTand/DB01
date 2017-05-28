/*
 select 쿼리문을 처리
 */

#include "common.h"
#include "menu.h"
#include "select.h"

/*  경찰관 검색  */
char * SelectOfficer() {
	char Police[2][25];
	char output[200] = "select * from POLICE";
	int sel;

	while (1) {
		SelectOfficerMenu();
		printf("Input Search Type : ");
		scanf("%d", &sel);
		MyGetChar();

		// Search with Police ID
		if (sel == 1) {	
			printf("Input Officer ID : ");
			scanf("%s", Police[0]);
			MyGetChar();
			strcat(output, " where POLID = ");
			strcat(output, Police[0]);
			return output;
		}
		// Search with police officer's name
		else if (sel == 2) {
			printf("Input Officer Name : ");
			scanf("%s", Police[1]);
			MyGetChar();
			strcat(output, " where POLNAME = '");
			strcat(output, Police[1]);
			strcat(output, "'");
			return output;
		}
		// Search all information
		else if (sel == 3) {	// select *
			return output;
		}
		else {
			printf("Wrong Type!!\nTry Again!!\n");
		}
	}
}

/*  경찰서 검색  */
char * SelectPolOffice() {
	char Office[3][20];
	char output[200] = "select * from POL_OFFICE";
	int sel;

	while (1) {
		SelectOfficeMenu();
		printf("Input Search Type : ");
		scanf("%d", &sel);
		MyGetChar();
		// Search with Office ID
		if (sel == 1) {
			printf("Input Office ID : ");
			scanf("%s", Office[0]);
			MyGetChar();
			strcat(output, " where OFFID = ");
			strcat(output, Office[0]);
			return output;
		}
		// Search with office address
		else if (sel == 2) {
			printf("Input Office Location : ");
			scanf("%s %s", Office[1], Office[2]);
			MyGetChar();
			strcat(output, " where CITY = '");
			strcat(output, Office[1]);
			strcat(output, "'");
			strcat(output, " and GU = '");
			strcat(output, Office[2]);
			strcat(output, "'");
			return output;
		}
		// Search all information
		else if (sel == 3) {	// select *
			return output;
		}
		else {
			printf("Wrong Type!!\nTry Again!!\n");
		}
	}
}
/*  업무 목록 검색  */
char * SelectTask() {
	char Task[2][30];
	char output[200] = "select * from TASK";
	int sel;

	while (1) {
		SelectTaskMenu();
		printf("Input Search Type : ");
		scanf("%d", &sel);
		MyGetChar();
		// search with Task ID
		if (sel == 1) {
			printf("Input Task ID : ");
			scanf("%s", Task[0]);
			MyGetChar();
			strcat(output, " where TASKID = ");
			strcat(output, Task[0]);
			return output;
		}
		// Search all information
		else if (sel == 2) {
			return output;
		}
		else {
			printf("Wrong Type!!\nTry Again!!\n");
		}
	}
}
/*  시간 코드 검색  */
char * SelectTime() {
	char Time[10];
	char output[200] = "select * from WORKTIME";
	int sel;

	while (1) {
		SelectTimeMenu();
		printf("Input Search Type : ");
		scanf("%d", &sel);
		MyGetChar();
		// Search with Timecode info.
		if (sel == 1) {
			printf("Input TimeCode : ");
			scanf("%s", Time);
			MyGetChar();
			strcat(output, " where TIMECODE = ");
			strcat(output, Time);
			return output;
		}
		// Search all information
		else if (sel == 2) {
			return output;
		}
		else {
			printf("Wrong Type!!\nTry Again!!\n");
		}
	}
}
/*  
 파출소장 검색  
 => 2개 테이블 조인
 */
char * SelectOfficeManager() {
	char OfficeId[10];
	char output[200] = "select OFFID, POLID, POLNAME, CITY, GU from POLICE P, POL_OFFICE O where P.POLID=O.MANAGER";
	int sel;

	while (1) {
		SelectManagerMenu();
		printf("Input Search Type : ");
		scanf("%d", &sel);
		MyGetChar();
		// Search with Office ID. Target specific office
		if (sel == 1) {
			printf("Input Office ID : ");
			scanf("%s", OfficeId);
			MyGetChar();
			strcat(output, " and O.OFFID=");
			strcat(output, OfficeId);
			return output;
		}
		// All manager info of all office
		else if (sel == 2) {
			return output;
		}
		else {
			printf("Wrong Type!!\nTry Again!!\n");
		}
	}
}
/*  
 지역 정보 검색  
 => 3개 테이블 조인
 */
char * SelectRegionInfo() {
	char OfficeId[10];
	char output1[200] = "select * from REGION";
	char output2[200] = "select R.OFFID, O.CITY, O.GU, R.POPUL, P.POLNAME, P.TITLE from REGION R, POL_OFFICE O, POLICE P where R.OFFID = O.OFFID and O.MANAGER = P.POLID";
	int sel;

	while (1) {
		SelectRegionInfoMenu();
		printf("Input Search Type : ");
		scanf("%d", &sel);
		MyGetChar();
		// Search all information
		if (sel == 1) {
			return output1;
		}
		// Search with specific office
		else if (sel == 2) {
			printf("Input Office ID : ");
			scanf("%s", OfficeId);
			MyGetChar();
			strcat(output2, " and O.OFFID=");
			strcat(output2, OfficeId);
			return output2;
		}
		// Search all info. A region's manager office Id, region address, region polpulation, and region cheif officer.
		else if (sel == 3) {
			return output2;
		}
		else {
			printf("Wrong Type!!\nTry Again!!\n");
		}
	}
}
/*  업무 시간표, 담당자 검색  */
char * SelectWorkInfo() {
	char polid[10];
	char taskname[30];
	char output[200] = "select P.POLID, P.POLNAME, P.TITLE, T.TASKNAME from POLICE P, TASK T, WORK W where P.POLID=W.POLID and T.TASKID=W.TASKID ";
	char output1[200] = "select T.TASKNAME, TM.TIMECODE, TM.START, TM.ENDT from TASK T, WORKTIME TM, BE_ASSIGNED A where T.TASKID=A.TSKID and TM.TIMECODE=A.TMCODE ";
	int sel;

	while (1) {
		SelectWorkInfoMenu();
		printf("Input Search Type : ");
		scanf("%d", &sel);
		MyGetChar();
		// All Officer's task info
		if (sel == 1) {
			return output;
		}
		// Specific officer's task info
		else if (sel == 2) {
			printf("Input Officer ID : ");
			scanf("%s", polid);
			MyGetChar();
			strcat(output, " and P.POLID=");
			strcat(output, polid);
			return output;
		}
		// Specific task's worker
		else if (sel == 3) {
			printf("Input Task Name : ");
			scanf("%[^\n]", taskname);
			MyGetChar();
			strcat(output1, " and T.TASKNAME='");
			strcat(output1, taskname);
			strcat(output1, "'");
			return output1;
		}
		else {
			printf("Wrong Type!!\nTry Again!!\n");
		}
	}
}

/*  Select Statement handle  */
void DoSelect() {
	char input[200];	// for raw query
	char output[200];
	int sel;

	while (1) {
		SelectMainMenu();
		printf("Select Menu : ");
		scanf("%d", &sel);
		MyGetChar();
		if (sel == 1) {			// Officer
			strcpy(output, SelectOfficer());
			ExecQuery(output);
		}
		else if (sel == 2) {	// Office
			strcpy(output, SelectPolOffice());
			ExecQuery(output);
		}
		else if (sel == 3) {	// Task
			strcpy(output, SelectTask());
			ExecQuery(output);
		}
		else if (sel == 4) {	// Time table
			strcpy(output, SelectTime());
			ExecQuery(output);
		}
		else if (sel == 5) {	// Office Manager
			strcpy(output, SelectOfficeManager());
			ExecQuery(output);
		}
		else if (sel == 6) {	// Region
			strcpy(output, SelectRegionInfo());
			ExecQuery(output);
		}
		else if (sel == 7) {	// Work 
			strcpy(output, SelectWorkInfo());
			ExecQuery(output);
		}
		else if (sel == 8) {	// Get raw query sentence
			printf("Input Raw Query : ");
			scanf("%[^\n]", input);
			MyGetChar();
			ExecQuery(input);
		}
		else if (sel == 9) {
			printf("Exit Select mode!!\n\n");
			break;
		}
		else {
			printf("Wrong Type!!\nTry Again!!\n");
		}
	}
}