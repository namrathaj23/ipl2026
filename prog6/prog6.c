#include <stdio.h>
#include <math.h>

#define WIDTH 40
#define HEIGHT 20

/* Structure for Circle */
struct Circle {
    int centerX;
    int centerY;
    int radius;
};

/* Function Declarations */
void initializeBuffer(char buffer[HEIGHT][WIDTH]);

void drawCircle(char buffer[HEIGHT][WIDTH], struct Circle c);

void displayBuffer(char buffer[HEIGHT][WIDTH]);

int isCirclePoint(int x, int y, struct Circle c);

int main() {

    char buffer[HEIGHT][WIDTH];

    struct Circle c;

    /* Input circle details */
    printf("Enter center X: ");
    scanf("%d", &c.centerX);

    printf("Enter center Y: ");
    scanf("%d", &c.centerY);

    printf("Enter radius: ");
    scanf("%d", &c.radius);

    initializeBuffer(buffer);

    drawCircle(buffer, c);

    displayBuffer(buffer);

    return 0;
}

/* Fill buffer with spaces */
void initializeBuffer(char buffer[HEIGHT][WIDTH]) {

    int i, j;

    for (i = 0; i < HEIGHT; i++) {

        for (j = 0; j < WIDTH; j++) {

            buffer[i][j] = ' ';
        }
    }
}

/* Check whether point lies on circle boundary */
int isCirclePoint(int x, int y, struct Circle c) {

    int dx = x - c.centerX;

    int dy = y - c.centerY;

    int value = dx * dx + dy * dy;

    int rSquare = c.radius * c.radius;

    /* Small tolerance for proper shape */
    if (abs(value - rSquare) <= c.radius) {

        return 1;
    }

    return 0;
}

/* Draw circle using '*' */
void drawCircle(char buffer[HEIGHT][WIDTH], struct Circle c) {

    int x, y;

    for (y = 0; y < HEIGHT; y++) {

        for (x = 0; x < WIDTH; x++) {

            if (isCirclePoint(x, y, c)) {

                buffer[y][x] = '*';
            }
        }
    }
}

/* Print buffer */
void displayBuffer(char buffer[HEIGHT][WIDTH]) {

    int i, j;

    for (i = 0; i < HEIGHT; i++) {

        for (j = 0; j < WIDTH; j++) {

            printf("%c", buffer[i][j]);
        }

        printf("\n");
    }
}
