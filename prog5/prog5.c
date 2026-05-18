#include <stdio.h>

/* Bit-field structure */
struct field {
    unsigned int your_choice : 1;
    unsigned int your_mothers_choice : 1;
    unsigned int your_fathers_choice : 1;
    unsigned int socially_acceptable : 1;
    unsigned int financially_viable : 1;
    unsigned int do_you_have_aptitude : 1;
    unsigned int do_you_like_it : 1;
    unsigned int decision : 1;
};

/* Union */
union decision {
    unsigned char flags;
    struct field bits;
};

/* Function declarations */
union decision input();
void make_decision(union decision *d);
void print_decision(union decision d);
void print_conclusion_based_on_flags(union decision d);

int main() {

    union decision d;

    d = input();

    make_decision(&d);

    print_decision(d);

    print_conclusion_based_on_flags(d);

    return 0;
}

/* Input function */
union decision input() {

    union decision d;

    d.flags = 0;

    printf("Enter your choice (0/1): ");
    scanf("%u", &d.bits.your_choice);

    printf("Enter your mother's choice (0/1): ");
    scanf("%u", &d.bits.your_mothers_choice);

    printf("Enter your father's choice (0/1): ");
    scanf("%u", &d.bits.your_fathers_choice);

    printf("Is it socially acceptable? (0/1): ");
    scanf("%u", &d.bits.socially_acceptable);

    printf("Is it financially viable? (0/1): ");
    scanf("%u", &d.bits.financially_viable);

    printf("Do you have aptitude? (0/1): ");
    scanf("%u", &d.bits.do_you_have_aptitude);

    printf("Do you like it? (0/1): ");
    scanf("%u", &d.bits.do_you_like_it);

    return d;
}

/* Decision making logic */
void make_decision(union decision *d) {

    if (
        d->bits.your_choice &&
        d->bits.socially_acceptable &&
        d->bits.financially_viable &&
        d->bits.do_you_have_aptitude &&
        d->bits.do_you_like_it
       )
    {
        d->bits.decision = 1;
    }
    else {
        d->bits.decision = 0;
    }
}

/* Print detailed narrative */
void print_decision(union decision d) {

    printf("\n----- Decision Report -----\n");

    printf("Your choice            : %d\n", d.bits.your_choice);
    printf("Mother's choice        : %d\n", d.bits.your_mothers_choice);
    printf("Father's choice        : %d\n", d.bits.your_fathers_choice);
    printf("Socially acceptable    : %d\n", d.bits.socially_acceptable);
    printf("Financially viable     : %d\n", d.bits.financially_viable);
    printf("You have aptitude      : %d\n", d.bits.do_you_have_aptitude);
    printf("You like it            : %d\n", d.bits.do_you_like_it);

    if (d.bits.decision)
        printf("\nFinal Decision : GO AHEAD!\n");
    else
        printf("\nFinal Decision : NOT RECOMMENDED.\n");
}

/* Using flags value */
void print_conclusion_based_on_flags(union decision d) {

    printf("\nFlags value = %u\n", d.flags);

    if (d.flags == 255)
        printf("Perfect alignment in every factor.\n");

    else if (d.flags > 100)
        printf("Most conditions are favorable.\n");

    else if (d.flags > 50)
        printf("Mixed situation. Think carefully.\n");

    else
        printf("Too many negative factors.\n");
}
