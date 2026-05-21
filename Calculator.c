#include <stdio.h>
int main() {
    int choice;
    float a, b;

    while (1) {
        printf("\n CALCULATOR \n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting...\n");
            break;
        }
        printf("Enter two numbers: ");
        scanf("%f %f", &a, &b);

        switch (choice) {
            case 1:
                printf("Result = %.2f\n", a + b);
                break;
            case 2:
                printf("Result = %.2f\n", a - b);
                break;
            case 3:
                printf("Result = %.2f\n", a * b);
                break;
            case 4:
                if (b != 0)
                    printf("Result = %.2f\n", a / b);
                else
                    printf("Cannot divide by zero!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}