#include <stdio.h>
#include <math.h>

int main() {
    char name[30];
    int numbers[10];
    int count = 0;
    int num;
    int max = 0;
    int min = 0;
    double sum = 0.0;
    double avg = 0.0;
    double stdDev = 0.0;
    double squares = 0.0;

    printf("Please enter your first name: ");
    scanf("%s", name);
    
    while (count < 10) {
        printf("%s, enter a positive integer (or -1 to quit): ", name);
        scanf("%d", &num);
        
        if (num == -1) {
            break;
        }
        if (num<= 0) {
            printf("Please enter a positive integer.\n");
        }else{
            numbers[count] = num;
            count++;
            sum += num;
        }

        if (count == 1) {
            max = num;
            min = num;
        } else if (num > max) {
            max = num;
        } else if (num < min) {
            min = num;
        }
    }
    
    avg = (double) (sum / count);
    for (int i = 0; i < count; i++) {
        squares += (numbers[i] - avg) * (numbers[i] - avg);
    }

    stdDev = sqrt(squares / count);

    printf("The maximum is: %11.2f\n", (double)max);
    printf("The minimum is: %8d\n", min);
    printf("The average is: %12.3f\n", avg);
    printf("The standard deviation is: %.3f\n", stdDev);

    return 0;
}