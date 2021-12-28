#include <stdio.h>
#include <math.h>
#define ACCT_NUM 12345678
#define PIN 12123240
#define START_BAL 1000.00

double current_balance = START_BAL;

void viewTransactions();
void depositMoney();
void withdrawMoney();
void showCurrentBalance();
void transferMoney();

int main(){

        

        int code;

        while((code = getchar()) != '6'){

                switch(code){

                        case '1':
                                viewTransactions();
                                break;

                        case '2':
                                depositMoney();
                                break;

                        case '3':
                                withdrawMoney();
                                break;

                        case '4':
                                transferMoney();
                                break;

                        case '5':
                                showCurrentBalance();
                                break;

                        default:
                                printf("\n\nPlease enter a valid option: ");
                                break;
                }

                
        }

        printf("\nThank you for using the ATM. Goodbye.");

        return 0;
}



void viewTransactions(){

        double displayed_balance = current_balance;

        puts("\n\n***************** CURRENT TRANSACTIONS *****************\n");
        puts("DATE\t\t\tDESCRIPTION\t\tAMOUNT\t\tBALANCE");

        FILE *transactions;
        transactions = fopen("c:/users/lolal/onedrive/documents/school/12th_grade/de_c/project_3/bank_transactions.txt", "r");

        while(!feof(transactions))
        {
                char date[10] = {0};
                char tran[50] = {0};
                double amount = 0.0;

                fscanf(transactions, "%8s%25s%lf", date, tran, &amount);

                if(tran[0] == 'D' && tran[6] == 'T'){ //is label is "deposit"

                        displayed_balance = displayed_balance + amount;
                        printf("\n%s%25s%20.2+lf%18.2lf", date, tran, amount, displayed_balance);
                        

                } else {

                        displayed_balance = displayed_balance - amount;
                        printf("\n%s%25s%20.2lf%18.2lf", date, tran, -amount, displayed_balance);
                }

        }

        fclose(transactions);
}



void depositMoney(){

        double deposit;

        printf("\n***************** DEPOSIT *****************\n");
        printf("How much money would you like to deposit? $");
        scanf("%lf", &deposit);

        current_balance = current_balance + deposit;

        printf("Your NEW available balance is: $%.2lf", current_balance);


}


void withdrawMoney(){

        double withdrawal;

        printf("\n***************** WITHDRAWAL *****************\n");
        printf("How much money would you like to withdraw? $");
        scanf("%lf", &withdrawal);


        if(current_balance - withdrawal < 0){

                printf("You do not have enough money to make this transaction. Please go back to the main menu and try again.");

        } else {

                current_balance = current_balance - withdrawal;
                printf("You withdrew $%.2lf. Your current balance is: $%.2lf", withdrawal, current_balance);

        }
}

void transferMoney(){

        int pin;
        double transfer;

        printf("\n***************** TRANSFER MONEY *****************\n");
        printf("Enter your pin to proceed: ");
        scanf("%d", &pin);

        if( (pin > 99999999 || pin < 10000000) || pin % 2 != 0){ //if not 8 digits or odd

                printf("That PIN number is not correct. Please go back to the main menu and try again.");

        } else {

                printf("How much money would you like to transfer? $");
                scanf("%lf", &transfer);
                current_balance = current_balance - transfer;
                printf("You transferred $%.2lf. Your current balance is: $%.2lf", transfer, current_balance);
        }

}


void showCurrentBalance(){

        printf("\n***************** VIEW BALANCE *****************\n");
        printf("Your current balance is: $%.lf", current_balance);
}


