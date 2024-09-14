/*
 ============================================================================
 Name        : Database_students with linked_list
 Author      : Mahmoud Eldwakhly
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// To solve IDE Problems
#define DPRINTF(...) { fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin); }


// Effective data
struct Sdata {
	int ID;
	char name[40];
	float height;
};

// Linked list node
struct SStudent {
	struct Sdata student;
	struct SStudent* P_next_student;   // Pointer to next student
};

struct SStudent* GPFirststudent = NULL;   // Global pointer to first student initialized to null

// Function to add a student to the list
void Add_student() {
	struct SStudent* PNewstudent; // Pointer to new student
	struct SStudent* PLaststudent; // Pointer to the last student
	char temp_text[40];

	// Check if list is empty
	if (GPFirststudent == NULL) {
		// Create new record
		PNewstudent = (struct SStudent*) malloc(sizeof(struct SStudent));  // Allocate memory for the new student
		// Assign it to GPFirst
		GPFirststudent = PNewstudent;
	}
	// If list already has records
	else {
		// Navigate until reaching the last record
		PLaststudent = GPFirststudent; // Start from the first student
		while (PLaststudent->P_next_student) {  // Continue until the next pointer is NULL
			PLaststudent = PLaststudent->P_next_student;
		}
		// Create new record
		PNewstudent = (struct SStudent*) malloc(sizeof(struct SStudent));  // Allocate memory for the new student
		PLaststudent->P_next_student = PNewstudent; // Link the last student to the new student
	}

	DPRINTF("\nEnter the student ID: ");
	gets(temp_text);
	PNewstudent->student.ID = atoi(temp_text); // Convert string to integer

	DPRINTF("\nEnter the student full name: ");
	gets(PNewstudent->student.name);

	DPRINTF("\nEnter the student height: ");
	gets(temp_text);
	PNewstudent->student.height = atof(temp_text);  // Convert string to float

	// Set the next pointer of the new student to NULL
	PNewstudent->P_next_student = NULL;
}

// Function to delete a student by ID
int Delete_student() {
	char temp_text[40];
	unsigned int selected_ID;

	// Get the selected ID from the user
	DPRINTF("\nEnter the selected ID to be deleted: ");
	gets(temp_text);
	selected_ID = atoi(temp_text);

	// Check if list is empty
	if (GPFirststudent) {
		struct SStudent* PSelectedStudent = GPFirststudent;
		struct SStudent* PPreviouStudent = NULL;

		// Loop through all the records
		while (PSelectedStudent) {
			// Compare each node with the selected ID
			if (PSelectedStudent->student.ID == selected_ID) {
				if (PPreviouStudent) {  // If the previous student exists, link it to the next student
					PPreviouStudent->P_next_student = PSelectedStudent->P_next_student;
				} else {   // If the first student is the one to be deleted
					GPFirststudent = PSelectedStudent->P_next_student;
				}
				free(PSelectedStudent); // Free the memory allocated for the student
				return 1; // Deletion successful
			}

			PPreviouStudent = PSelectedStudent;
			PSelectedStudent = PSelectedStudent->P_next_student;
		}
		// If ID is not found
		DPRINTF("\nStudent ID not found!");
		return 0; // Deletion failed
	}

	DPRINTF("\nThe list is empty!");
	return 0; // Deletion failed
}

// Function to view all students
void view_students() {
	struct SStudent* PCurrentStudent = GPFirststudent;
	int count = 0;

	// Check if the list is empty
	if (GPFirststudent == NULL) {
		DPRINTF("\nEmpty List");
	} else {
		// Loop through all the students and print their details
		while (PCurrentStudent) {
			DPRINTF("\nRecord number %d", count + 1);
			DPRINTF("\n\tID: %d", PCurrentStudent->student.ID);
			DPRINTF("\n\tName: %s", PCurrentStudent->student.name);
			DPRINTF("\n\tHeight: %f", PCurrentStudent->student.height);
			PCurrentStudent = PCurrentStudent->P_next_student;
			count++;
		}
	}
}

// Function to delete all students
void Delete_all() {
	struct SStudent* PCurrentStudent = GPFirststudent;

	// Check if the list is empty
	if (GPFirststudent == NULL) {
		DPRINTF("\nEmpty List");
	} else {
		// Loop through all the students and free the memory allocated for each one
		while (PCurrentStudent) {
			struct SStudent* PTemp_student = PCurrentStudent;
			PCurrentStudent = PCurrentStudent->P_next_student;
			free(PTemp_student);
		}
		GPFirststudent = NULL; // Reset the list to empty
	}
}

int main() {
	char temp_text[40];

	while (1) {
		DPRINTF("\n===================================");
		DPRINTF("\n\tChoose one of the following options\n");
		DPRINTF("\n\t1- Add Student");
		DPRINTF("\n\t2- Delete Student");
		DPRINTF("\n\t3- View Students");
		DPRINTF("\n\t4- Delete All");
		DPRINTF("\nEnter option number: ");
		gets(temp_text);
		DPRINTF("\n==========================================");

		switch (atoi(temp_text)) {
		case 1:
			Add_student();
			break;
		case 2:
			Delete_student();
			break;
		case 3:
			view_students();
			break;
		case 4:
			Delete_all();
			break;
		default:
			DPRINTF("\nWrong option");
			break;
		}
	}

	return 0; // Main function should return an integer
}
