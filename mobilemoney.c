#include <stdio.h>

int main()
 {
    
    double balance = 50000.0;
    double withdrawalAmount = 20000.0;

    if (withdrawalAmount <= balance) 
    {
        balance = balance - withdrawalAmount;
        printf("Withdrawal successful: %.2f\n", withdrawalAmount);
    } else {
        printf("Insufficient funds! You cannot withdraw: %.2f\n", withdrawalAmount);
    }

    // Display the remaining balance
    printf("Remaining balance: %.2f\n", balance);

    return 0;
}
