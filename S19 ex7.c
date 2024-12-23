#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

int deleteStudentById(int id, Student students[], int *size) {
    int index = -1;
 
    for (int i = 0; i < *size; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Sinh vien voi ID %d khong ton tai\n", id);
        return 0;
    }

    for (int i = index; i < *size - 1; i++) {
        students[i] = students[i + 1];
    }

    (*size)--; 
    return 1;
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
        {2, "Bob", 21, "987654321"},
        {3, "Charlie", 22, "456123789"},
        {4, "Diana", 23, "789123456"},
        {5, "Eve", 24, "321654987"}
    };
    int size = 5;

    printStudents(students, size);

    int idToDelete = 3;
    if (deleteStudentById(idToDelete, students, &size)) {
        printf("\nSinh vien voi ID %d da duoc xoa\n", idToDelete);
    }

    printStudents(students, size);

    return 0;
}

