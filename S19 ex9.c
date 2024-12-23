#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

#define MAX_STUDENTS 100

void printStudents(Student students[], int size) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

void addStudent(Student students[], int *size) {
    if (*size >= MAX_STUDENTS) {
        printf("Khong the them sinh vien. Danh sach da day\n");
        return;
    }
    printf("Nhap thong tin sinh vien moi:\n");
    printf("ID: ");
    scanf("%d", &students[*size].id);
    printf("Name: ");
    scanf("%s", students[*size].name);
    printf("Age: ");
    scanf("%d", &students[*size].age);
    printf("Phone: ");
    scanf("%s", students[*size].phoneNumber);
    (*size)++;
}

void editStudent(Student students[], int size) {
    int id;
    printf("Nhap ID cua sinh vien can sua: ");
    scanf("%d", &id);
    for (int i = 0; i < size; i++) {
        if (students[i].id == id) {
            printf("Nhap thong tin moi:\n");
            printf("Name: ");
            scanf("%s", students[i].name);
            printf("Age: ");
            scanf("%d", &students[i].age);
            printf("Phone: ");
            scanf("%s", students[i].phoneNumber);
            printf("Thong tin da duoc cap nhat\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %d\n", id);
}

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

// Hàm tìm ki?m sinh viên
void searchStudent(Student students[], int size) {
    char name[50];
    printf("Nhap ten sinh vien can tim: ");
    scanf("%s", name);
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
                   students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ten %s\n", name);
}

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
    printf("Danh sach sinh vien da duoc sap xep theo ten	\n");
}

int main() {
    Student students[MAX_STUDENTS];
    int size = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printStudents(students, size);
                break;
            case 2:
                addStudent(students, &size);
                break;
            case 3:
                editStudent(students, size);
                break;
            case 4: {
                int id;
                printf("Nhap ID cua sinh vien can xoa: ");
                scanf("%d", &id);
                if (deleteStudentById(id, students, &size)) {
                    printf("Sinh vien da duoc xoa\n");
                }
                break;
            }
            case 5:
                searchStudent(students, size);
                break;
            case 6:
                sortStudentsByName(students, size);
                break;
            case 7:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai\n");
        }
    } while (choice != 7);

    return 0;
}

