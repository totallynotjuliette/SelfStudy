#include <stdio.h>

int main(){
    
    int account_num;
    float balance;
    float charges;
    float credits;
    float limit;
    float new_balance;


    while(account_num != -1){

        printf("Enter account number (-1 to end): ");
        scanf("%d", &account_num);

        if(account_num != -1){

            printf("Enter beginning balance: ");
            scanf("%f", &balance);

            printf("Enter total charges: ");
            scanf("%f", &charges);

            printf("Enter total credits: ");
            scanf("%f", &credits);

            printf("Enter credit limit: ");
            scanf("%f", &limit);

            new_balance = balance + charges - credits;

            if(new_balance > limit){
                
                printf("Account: %d\n", account_num);
                printf("Credit limit: %.2f\n", limit);
                printf("Balance: %.2f\n", new_balance);
                printf("Credit Limit Exceeded.");

            }



        }

    }




    return 0;
}