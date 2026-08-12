#include <stdio.h>
#include <string.h>

struct Student {
	char name[50];
	int roll_no;
	float marks;
};

void read(struct Student *student) {
	getchar();
	fgets(student->name, 50, stdin);
	student->name[strcspn(student->name, "\n")] = '\0';
	scanf("%d", &(student->roll_no));
	scanf("%f", &(student->marks));
}

void display(struct Student *student) {
	puts(student->name);
	printf("%d\n", student->roll_no);
	printf("%f\n", student->marks);
}

int main() {
	int n;
	printf("Enter no of students: ");
	scanf("%d", &n);

	struct Student students[n];

	for (int i = 0; i<n; i++) {
		read(&students[i]);
	}

	for (int i = 0; i < n; i++) {
		display(&students[i]);
	}

	struct Student *highest = &students[0];
	for (int i = 1; i < n; i++) {
		if (highest->marks < students[i].marks) {
			highest = &students[i];
		}
	}

	printf("Highest: ");
	display(highest);
}