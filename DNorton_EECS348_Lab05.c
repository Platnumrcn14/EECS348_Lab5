#include <stdio.h>

int main() {
    float sales[12];
    int size = 12;
    char filename[100];
    float max = 0;
    char *minMonth;
    char *maxMonth;
    float min = 0;
    float mA1 = 0;
    float mA2 = 0;
    float mA3 = 0;
    float mA4 = 0;
    float mA5 = 0;
    float mA6 = 0;
    float mA7 = 0;
    char *months[] = {"January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December" };
    int i, j, k, l, m, index = 0;
    printf("***PROBLEM 1***\n");
    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }
    double number;
    printf("\nMonthly sales report for 2022:\n");
    printf("Month     Sales\n");
    while (fscanf(file, "%lf", &number) == 1) {
        printf("%s: $%.2lf\n", months[i], number);
        sales[i] = number;
        i = i + 1;
    }for(i = 0; i < 12; i++){
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = months[i];
        }if (min == 0) {
            min = sales[i];
            minMonth = months[i];
        }else if (sales[i] < min) {
            min = sales[i];
            minMonth = months[i];
        }
    }printf("\nSales summary\nMinimum sales:  $%.2lf  (%s)", min, minMonth);
    printf("\nMaximum sales:  $%.2lf  (%s)\n\n", max, maxMonth);
    
    for(i = 0; i < 12; i++){
        if (i < 6){
            mA1 = mA1 + sales[i];
        }if (i > 0 && i < 7){
            mA2 = mA2 + sales[i];
        }if (i > 1 && i < 8) {
            mA3 = mA3 + sales[i];
        }if (i > 2 && i < 9) {
            mA4 = mA4 + sales[i];
        }if (i > 3 && i < 10) {
            mA5 = mA5 + sales[i];
        }if (i > 4 && i < 11) {
            mA6 = mA6 + sales[i];
        }if (i > 5) {
            mA7 = mA7 + sales[i];
        }
    }printf("Six-Month Moving Average Report:\n");
    printf("%s     - %s  $%.2lf\n", months[0], months[5], mA1);
    printf("%s     - %s  $%.2lf\n", months[1], months[6], mA2);
    printf("%s     - %s  $%.2lf\n", months[2], months[7], mA3);
    printf("%s     - %s  $%.2lf\n", months[3], months[8], mA4);
    printf("%s     - %s  $%.2lf\n", months[4], months[9], mA5);
    printf("%s     - %s  $%.2lf\n", months[5], months[10], mA6);
    printf("%s     - %s  $%.2lf\n\n", months[6], months[11], mA7);
    
    printf("Sales Report (Highest to Lowest):\n");
    printf("  Month      Sales\n");
    for(i = 0; i < 12; i++) {
        for(j = 0; j < size; j++) {
            if(max < sales[j]);{
                max = sales[j];
                maxMonth = months[j];
                index = j;
            }
        }printf("%s  $%.2lf\n", maxMonth, max);
        for(j = index; j < size; j++) {
            sales[j] = sales[j+1];
        }size = size - 1;
        max = 0;
    }
    
    fclose(file); 
    printf("\n\n***PROBLEM 2***\n");
    int score;
    int loop = 1;
    while (loop != 0) {
        printf("Enter 1 to continue or 0 to stop: ");
        scanf("%d", &loop);
        if (loop == 1) {
            printf("Enter the score: ");
            scanf("%d", &score);
            for (i = 0; i <= score; i++) {
                for (j = 0; j <= score; j++) {
                    for (k = 0; k <= score; k++) {
                        for (l = 0; l <= score; l++) {
                            for (m = 0; m <= score; m++) {
                                if (8 * i + 7 * j + 6 * k + 3 * l + 2 * m == score) {
                                    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt, %d Safety\n", i, j, k, l, m);
                                }
                            }
                        }
                    }
                }
            }
        }else if (loop == 0){
            break;
        }else{
            printf("Invalid entry.\n");
        }
    }
    return 0;
}