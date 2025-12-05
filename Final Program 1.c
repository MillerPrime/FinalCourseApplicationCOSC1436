#include <stdio.h>

// Function declarations
float calculateManagerPay(float yearlySalary, int weeksInYear);
float calculateHourlyPay(int hoursWorked, float hourlyWage);
float calculateCommissionPay(float sales, float basePay, float commissionRate);

int main() 
{
   // Variables and Arrays
    int employeeID[7];
    float grossPay[7];
    float taxPaid[7];
    float netPay[7];
    float totalPay = 0;
    float basePay = 375.00;
    float commissionRate = 0.072;
    float taxRate = 0.08625;
    int weeksInYear = 52;
    
    // Input data and calculate pay
    for (int i = 0; i < 7; i++) 
	{
        int payCode;
        printf("Enter employee %d's ID: \n", i + 1);
        scanf("%d", &employeeID[i]);
        printf("Enter employee %d's Pay Code (1 = Manager, 2 = Hourly, 3 = Commission): \n", i + 1);
        scanf("%d", &payCode);

        // Declare variables for input data
        float yearlySalary = 0.0;
        int hoursWorked = 0;
        float hourlyWage = 0.0;
        float sales = 0.0;

        switch (payCode) 
		{
            case 1: // Manager
                printf("Enter yearly salary: \n");
                scanf("%f", &yearlySalary);
                grossPay[i] = calculateManagerPay(yearlySalary, weeksInYear);
                break;
            case 2: // Hourly worker
                printf("Enter hours worked: \n");
                scanf("%d", &hoursWorked);
                printf("Enter hourly wage: \n");
                scanf("%f", &hourlyWage);
                grossPay[i] = calculateHourlyPay(hoursWorked, hourlyWage);
                break;
            case 3: // Commission worker
                printf("Enter gross weekly sales: \n");
                scanf("%f", &sales);
                grossPay[i] = calculateCommissionPay(sales, basePay, commissionRate);
                break;
            default:
                printf("Invalid pay code\n");
                grossPay[i] = 0;
                taxPaid[i] = 0;
                netPay[i] = 0;
                continue;
        }
		
        taxPaid[i] = grossPay[i] * taxRate; // Calculates taxes paid
        netPay[i] = grossPay[i] - taxPaid[i]; // Calculates the net pay
        totalPay += netPay[i]; // Adds each employees pay to the total company pay
    }

    // Print employee details
    printf("\nEmployee ID\tGross Pay\tTax Paid\tNet Pay\n");
    for (int i = 0; i < 7; i++) 
	{
        printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\n", employeeID[i], grossPay[i], taxPaid[i], netPay[i]);
    }

    // Print total pay for the company
    printf("\nTotal pay for the company this week: %.2f\n", totalPay);

    return 0;
}

// Function to calculate manager's pay
float calculateManagerPay(float yearlySalary, int weeksInYear) 
{
    return yearlySalary / weeksInYear;
}

// Function to calculate hourly worker's pay
float calculateHourlyPay(int hoursWorked, float hourlyWage) 
{
    float pay;
    if (hoursWorked <= 40) 
	{
        pay = hoursWorked * hourlyWage;
    } else {
        pay = 40 * hourlyWage + (hoursWorked - 40) * (hourlyWage * 1.5);
    }
    return pay;
}

// Function to calculate commission worker's pay
float calculateCommissionPay(float sales, float basePay, float commissionRate) 
{
    return basePay + sales * commissionRate;
}



