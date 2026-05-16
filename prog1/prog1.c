#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    char name[30];
    float marks;
};

// Function to display nth record
void getNthRecord(FILE *fp, int n)
{
    struct Student s;

    fseek(fp, (n - 1) * sizeof(struct Student), SEEK_SET);

    fread(&s, sizeof(struct Student), 1, fp);

    printf("\nRecord %d Details:\n", n);
    printf("ID    : %d\n", s.id);
    printf("Name  : %s\n", s.name);
    printf("Marks : %.2f\n", s.marks);
}

// Function to delete a record
void deleteRecord(int recNo, int total)
{
    FILE *fp1, *fp2;
    struct Student s;
    int i;

    fp1 = fopen("student.dat", "rb");
    fp2 = fopen("temp.dat", "wb");

    for(i = 1; i <= total; i++)
    {
        fread(&s, sizeof(struct Student), 1, fp1);

        // Copy all records except deleted one
        if(i != recNo)
        {
            fwrite(&s, sizeof(struct Student), 1, fp2);
        }
    }

    fclose(fp1);
    fclose(fp2);

    remove("student.dat");
    rename("temp.dat", "student.dat");

    printf("\nRecord %d deleted successfully.\n", recNo);
}

int main()
{
    FILE *fp;
    struct Student *s;

    int n, i, rec, delRec;

    printf("Enter number of records: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    s = (struct Student *)malloc(n * sizeof(struct Student));

    // Input records
    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &s[i].id);

        printf("Enter Name: ");
        scanf("%s", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }

    // Open binary file
    fp = fopen("student.dat", "wb");

    // Store records
    fwrite(s, sizeof(struct Student), n, fp);

    fclose(fp);

    // Read nth record
    fp = fopen("student.dat", "rb");

    printf("\nEnter record number to display: ");
    scanf("%d", &rec);

    getNthRecord(fp, rec);

    fclose(fp);

    // Delete record
    printf("\nEnter record number to delete: ");
    scanf("%d", &delRec);

    deleteRecord(delRec, n);

    free(s);

    return 0;
}
