#include <stdio.h>

struct Student {
	char name[50];
	int roll_no;
	char grade;
};

void read(struct Student students[], int n) {
	for (int i = 0; i < n; i++) {
		getchar();
		printf("Enter name: ");
		fgets(students[i].name, 50, stdin);
		printf("Enter roll_no: ");
		scanf("%d", &students[i].roll_no);
		getchar();
		printf("Enter grade: ");
		scanf("%c", &students[i].grade);
	}
}

void display(struct Student students[], int n) {
	for (int i = 0; i < n; i++) {
		printf("\n=============\n");
		printf("Name: ");
		puts(students[i].name);
		printf("Roll No: %d\n", students[i].roll_no);
		printf("Grade: %c\n", students[i].grade);
	}
}

void sort(struct Student students[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (students[j].roll_no > students[j+1].roll_no) {
				struct Student student = students[j];
				students[j] = students[j+1];
				students[j+1] = student;
			}
		}
	}
}

int main() {
	struct Student students[5];
	read(students, 3);
	sort(students, 3);
	display(students, 3);

	return 0;
}



