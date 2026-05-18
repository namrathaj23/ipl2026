#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[30];
    float marks;
};

/* Function declarations */
void writeRecords(struct Student s[], int n);
long* createSeekArray(FILE *fp, int n);
void displayRecord(FILE *fp, long pos);

int main() {

    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    /* Input records */
    for(i = 0; i < n; i++) {

        printf("\nEnter details of student %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &s[i].id);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    /* Store records in ASCII file */
    writeRecords(s, n);

    FILE *fp = fopen("student.txt", "r");

    if(fp == NULL) {
        printf("File cannot be opened\n");
        return 1;
    }

    /* Create seek position array */
    long *seekPos = createSeekArray(fp, n);

    printf("\nSeek positions of records:\n");

    for(i = 0; i < n; i++) {
        printf("Record %d -> %ld\n", i + 1, seekPos[i]);
    }

    int rec;

    printf("\nEnter record number to display: ");
    scanf("%d", &rec);

    if(rec >= 1 && rec <= n) {
        displayRecord(fp, seekPos[rec - 1]);
    }
    else {
        printf("Invalid record number\n");
    }

    free(seekPos);
    fclose(fp);

    return 0;
}

/* Function to store structures in ASCII format */
void writeRecords(struct Student s[], int n) {

    FILE *fp = fopen("student.txt", "w");

    int i;

    for(i = 0; i < n; i++) {

        fprintf(fp, "%d %s %.2f\n",
                s[i].id,
                s[i].name,
                s[i].marks);
    }

    fclose(fp);
}

/* Function to create array of seek positions */
long* createSeekArray(FILE *fp, int n) {

    long *pos = (long*)malloc(n * sizeof(long));

    int i;

    for(i = 0; i < n; i++) {

        pos[i] = ftell(fp);

        /* Skip current record */
        fscanf(fp, "%*d %*s %*f");
        fgetc(fp);   // move past newline
    }

    return pos;
}

/* Function to display record using seek position */
void displayRecord(FILE *fp, long pos) {

    struct Student s;

    fseek(fp, pos, SEEK_SET);

    fscanf(fp, "%d %s %f",
           &s.id,
           s.name,
           &s.marks);

    printf("\nRecord Details\n");

    printf("ID     : %d\n", s.id);
    printf("Name   : %s\n", s.name);
    printf("Marks  : %.2f\n", s.marks);
}
