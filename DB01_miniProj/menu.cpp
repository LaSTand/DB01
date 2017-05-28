/*
 메뉴 출력 모음
 */

#include "common.h"
#include "menu.h"

// Main Menu
void PrintMainMenu() {
	printf("====================================\n");
	printf("============= M E N U ==============\n");
	printf("====================================\n");
	printf("===  1. SELECT                   ===\n");
	printf("===  2. INSERT                   ===\n");
	printf("===  3. UPDATE                   ===\n");
	printf("===  4. DELETE                   ===\n");
	printf("===  5. Show Schema              ===\n");
	printf("===  6. Exit                     ===\n");
	printf("====================================\n");
	printf("====================================\n");
}

// Select Menu
void SelectMainMenu() {
	printf("====================================\n");
	printf("=========== S E L E C T ============\n");
	printf("====================================\n");
	printf("===  1. Refer Officer            ===\n");
	printf("===  2. Refer Office             ===\n");
	printf("===  3. Refer Task               ===\n");
	printf("===  4. Refer Time               ===\n");
	printf("===  5. Refer Manager            ===\n");
	printf("===  6. Refer Region             ===\n");
	printf("===  7. Refer Work               ===\n");
	printf("===  8. Input Raw Query          ===\n");
	printf("===  9. Exit                     ===\n");
	printf("====================================\n");
	printf("====================================\n");
}

void SelectOfficerMenu() {
	printf("====================================\n");
	printf("===  Search Police Officer       ===\n");
	printf("====================================\n");
	printf("===  1. Officer ID               ===\n");
	printf("===  2. Officer Name             ===\n");
	printf("===  3. Search All               ===\n");
	printf("====================================\n");
}
void SelectOfficeMenu() {
	printf("====================================\n");
	printf("===  Search Police Office        ===\n");
	printf("====================================\n");
	printf("===  1. Office ID                ===\n");
	printf("===  2. Location(City, Gu)       ===\n");
	printf("===  3. Search All               ===\n");
	printf("====================================\n");
}
void SelectTaskMenu() {
	printf("====================================\n");
	printf("===  Search Task List            ===\n");
	printf("====================================\n");
	printf("===  1. Task ID                  ===\n");
	printf("===  2. Search All               ===\n");
	printf("====================================\n");
}
void SelectTimeMenu() {
	printf("====================================\n");
	printf("===  Search Time Table           ===\n");
	printf("====================================\n");
	printf("===  1. TImeCode                 ===\n");
	printf("===  2. Search All               ===\n");
	printf("====================================\n");
}
void SelectManagerMenu() {
	printf("====================================\n");
	printf("===  Search Office Manager       ===\n");
	printf("====================================\n");
	printf("===  1. Office ID                ===\n");
	printf("===  2. Search All               ===\n");
	printf("====================================\n");
}
void SelectRegionInfoMenu() {
	printf("====================================\n");
	printf("===  Search Region Information   ===\n");
	printf("====================================\n");
	printf("===  1. All Region Info.         ===\n");
	printf("===  2. Region Manager Info.     ===\n");
	printf("===  3. Region Manager Info(All) ===\n");
	printf("====================================\n");
}
void SelectWorkInfoMenu() {
	printf("====================================\n");
	printf("===  Search Work Information     ===\n");
	printf("====================================\n");
	printf("===  1. All Work Info.           ===\n");
	printf("===  2. Officer ID               ===\n");
	printf("===  3. Task Work Time           ===\n");
	printf("====================================\n");
}

/* Insert Menu */
void InsertMainMenu() {
	printf("====================================\n");
	printf("=========== I N S E R T ============\n");
	printf("====================================\n");
	printf("===  1. New Officer              ===\n");
	printf("===  2. New Office               ===\n");
	printf("===  3. New Task                 ===\n");
	printf("===  4. New Time Table           ===\n");
	printf("===  5. New Region               ===\n");
	printf("===  6. Input Raw Query          ===\n");
	printf("===  7. Exit                     ===\n");
	printf("====================================\n");
	printf("====================================\n");
}
void NewOfficerMenu() {
	printf("====================================\n");
	printf("===  New Officer Add(Schema)     ===\n");
	printf("====================================\n");
	printf("===  1. POLID(PK, int)           ===\n");
	printf("===  2. POLNAME(char)            ===\n");
	printf("===  3. TITLE(char)              ===\n");
	printf("===  4. OFFICE(Office number)    ===\n");
	printf("====================================\n");
}
void NewOfficeMenu() {
	printf("====================================\n");
	printf("===  New Office Add(Schema)      ===\n");
	printf("====================================\n");
	printf("===  1. OFFID(PK, int)           ===\n");
	printf("===  2. CITY(char)               ===\n");
	printf("===  3. GU(char)                 ===\n");
	printf("===  4. DONG(char)               ===\n");
	printf("===  5. MANAGER(Officer ID)      ===\n");
	printf("====================================\n");
}
void NewTaskMenu() {
	printf("====================================\n");
	printf("===  New Task Add(Schema)        ===\n");
	printf("====================================\n");
	printf("===  1. TASKID(PK, int)          ===\n");
	printf("===  2. Task Name(char)          ===\n");
	printf("====================================\n");
}
void NewTimeTableMenu() {
	printf("====================================\n");
	printf("===  New Time Table Add(Schema)  ===\n");
	printf("====================================\n");
	printf("===  1. TASKID(PK, FK, int)      ===\n");
	printf("===  2. TMCODE(PK, FK, char)     ===\n");
	printf("====================================\n");
	}
void NewRegionMenu() {
	printf("====================================\n");
	printf("===  New Region Add(Schema)      ===\n");
	printf("====================================\n");
	printf("===  1. OFFID(PK, FK, int)       ===\n");
	printf("===  2. Region Name(char)        ===\n");
	printf("===  3. Population(int)          ===\n");
	printf("====================================\n");
}

// Update Main Menu
void UpdateMainMenu() {
	printf("====================================\n");
	printf("=========== U P D A T E ============\n");
	printf("====================================\n");
	printf("===  1. Officer Promotion        ===\n");
	printf("===  2. Officer Transfer         ===\n");
	printf("===  3. Manager Change           ===\n");
	printf("===  4. Assigend Work Change     ===\n");
	printf("===  5. Time Table Change        ===\n");
	printf("===  6. Input Raw Query          ===\n");
	printf("===  7. Exit                     ===\n");
	printf("====================================\n");
	printf("====================================\n");
}

// Delete Main Menu
void DeleteMainMenu() {
	printf("====================================\n");
	printf("=========== D E L E T E ============\n");
	printf("====================================\n");
	printf("===  1. Officer Retire           ===\n");
	printf("===  2. Office Close             ===\n");
	printf("===  3. Task delete              ===\n");
	printf("===  4. Time code delete         ===\n");
	printf("===  5. Input Raw Query          ===\n");
	printf("===  6. Exit                     ===\n");
	printf("====================================\n");
	printf("====================================\n");
}

// Print Database Schema
void PrintSchema() {
	printf("============================================================\n");
	printf("================== TRAFFIC CONTROL POLICE ==================\n");
	printf("============================================================\n");
	printf("=== POLICE : POLID(PK), POLNAME, TITLE, OFFICE(FK)       ===\n");
	printf("=== POL_OFFICE : OFFID(PK), CITY, GU, DONG, MANAGER(FK)  ===\n");
	printf("=== REGION : OFFID(FK, PK), NAME(PK), POPUL              ===\n");
	printf("=== TASK : TASKID(PK), TASKNAME                          ===\n");
	printf("=== WORKTIME : TIMECODE(PK), START, ENDT                 ===\n");
	printf("=== WORK : POLID(PK, FK), TASKID(PK, FK)                 ===\n");
	printf("=== BE_ASSIGNED : TSKID(PK, FK), TMCODE(PK, FK)          ===\n");
	printf("============================================================\n");
	printf("============================================================\n");
}