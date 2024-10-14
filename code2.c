#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Given: 12 months of sales figures
// Monthly sales: display month column and sales column
// 6 month moving average
// Sales report: highest to lowest


// Swap two floats in an array
void swapFloat(float *float1, float *float2) {
    float temp = *float1;
    *float1 = *float2;
    *float2 = temp;
}

// Swap two strings in an array
void swapString(const char **str1, const char **str2) {
    const char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

// Bubble sorting an array from highest to lowest
void sortSales(float sales[], const char *months[], int n) {
    for (int i=0; i < n-1; i++) {
        for (int j=0; j < n-1; j++) {
            if (sales[j] < sales[j+1]) {
                // Swap the values of the months and sales in the arrays
                swapFloat(&sales[j], &sales[j+1]);
                swapString(&months[j], &months[j+1]);
            }
        }
    }
}

// Find average of an array
float findAvg(int length, float sales[length]) {
    float saleSum = 0;
    for (int i=0; i<length; i++) {
        saleSum += sales[i]; // Add to sum
    }
    return saleSum/length; // Compute and return average
}

// Find minimum month in the sale sarray
int findMinMonth(float sales[12]) {
    int minSaleMonth = 1;
    float minSale = sales[0];
    for (int i=1; i<12; i++) {
        if (sales[i] < minSale) {
            // Reassign the minimum sale and month
            minSale = sales[i];
            minSaleMonth = i+1;
        }
    }
    return minSaleMonth;
}
 
// Find max month of sales in the sales array
int findMaxMonth(float sales[12]) {
    int maxSaleMonth = 1;
    float maxSale = sales[0];
    for (int i=1; i<12; i++) {
        if (sales[i] > maxSale) {
            // Reassign max sale and month
            maxSale = sales[i];
            maxSaleMonth = i+1;
        }
    }
    return maxSaleMonth;
}

// Print sales summary
void genSalesSummary(float sales[12], const char *months[12]) {
    // Call appropriate functions to assign values
    int maxMonth = findMaxMonth(sales);
    float maxSales = sales[maxMonth-1];
    int minMonth = findMinMonth(sales);
    float minSales = sales[minMonth-1];
    float avgSales = findAvg(12, sales);

    // Print relevant values
    printf("Sales Summary Report:\n\n\n");
    printf("Minimum sales: %f (%s)\n", minSales, months[minMonth-1]);
    printf("Maximum Sales: %f (%s)\n", maxSales, months[maxMonth-1]);
    printf("Average Sales: %f\n\n\n", avgSales);
}

// Print monthly sales report
void genSalesReport(float sales[12], const char *months[12]) {
    printf("Monthly Sales Report for 2024\n\n");
    printf("Month\t\tSales\n");

    // Print each month's sales
    for (int i=0; i<12; i++) {
        printf("%s\t\t%f\n", months[i], sales[i]);
    }
    printf("\n\n");
}

// Calculate and print 6-month moving averages
void movingAvg(float sales[12], const char *months[12]) {
    printf("Six-month moving average report:\n\n");

    // Calculate each 6-month average
    for (int i=0; i<=6; i++) {
        float sum = 0.0;

        for (int j=i; j<i+6; j++) { // Iterate through next 6 months starting at i
            sum += sales[j];
        }
        
        // Calculate and print the 6-month average
        float average = sum/6.0;
        printf("%s-%s: %f\n", months[i], months[i+5], average);

    }
    printf("\n\n");
}

int main() {
    int n = 12;
    float salesTest[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    const char* months[12] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
        };
    float sales[12];
    
    // Opening file portion borrowed from geeksforgeeks.org:
    // Defining file pointer and opening the file.
    FILE *file_ptr;
    char str[50];

    // Open file in read mode
    file_ptr = fopen("test.txt", "r");

    if (NULL == file_ptr) {
        // File was not found or was invalid
        printf("File can't be opened \n");
    }

    int i=0;
    while (fgets(str, 50, file_ptr) != NULL) {
        str[strcspn(str, "\n")] = '\0'; // Strip line
        float flt = atof(str); // Convert line to float
        printf("%s", str);
        sales[i] = flt;
        i += 1;
    }

    fclose(file_ptr);
    
    genSalesReport(sales, months); 
    genSalesSummary(sales, months);
    movingAvg(sales, months);

    printf("Sales Report (highest to lowest)\n");

    // Make copy of sales and months arrays
    float salesCopy[12];
    const char *monthsCopy[12];
    for (int i=0; i<12; i++) {
        salesCopy[i] = sales[i];
    }
    for (int i=0; i<12; i++) {
        monthsCopy[i] = months[i];
    }

    // Sort sales high to low and print results
    sortSales(salesCopy, monthsCopy, 12);
    for (int i=0; i<n; i++) {
        printf("%s: %f\n", months[i], sales[i]);
    }

    return 0;
}