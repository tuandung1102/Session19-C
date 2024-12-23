#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void sortStudentsByName(Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void printStudents(Student students[], int size) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
  
    Student students[5] = {
        {1, "Alice", 20, "123456789"},
        {2, "Charlie", 21, "987654321"},
        {3, "Bob", 22, "456123789"},
        {4, "Eve", 23, "789123456"},
        {5, "Diana", 24, "321654987"}
    };
    int size = 5;

    printf("Danh sach ban dau:\n");
    printStudents(students, size);

    sortStudentsByName(students, size);

    printf("\nDanh sach sau khi sap xep:\n");
    printStudents(students, size);

    return 0;
}

