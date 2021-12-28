#include <stdio.h>
#include <math.h>

//1: managers = fixed weekly salary
//2: hourly workers =  fixed hourly wage up to 40 hours & 1.5x hourly wage for overtime
//3: commision workers = $250 + 5.7% of gross weekly sales
//4: pieceworkers = fixed amout of money for each of the items that they produce (works on only one type of item)

//use switch


int main(){

    int code;
    char position;

    //1
    float monthly_salary;
    float weekly_salary_1;

    //2
    float hours_worked_in_week;
    float hourly_wage;
    float weekly_salary_2;

    //3
    float gross_weekly_sales;
    float weekly_salary_3;

    //4
    float weekly_salary_4;
    int earnings_per_item;
    int number_of_items_produced;
    int piecework;

    puts("Please enter a pay code or enter the EOF character to end input.");
        
    while((code = getchar()) != EOF){

        switch(code){

            case '1':
                puts("Enter monthly salary: ");
                scanf("%f", &monthly_salary);
                weekly_salary_1 = monthly_salary/4;
                printf("Weekly salary: $%.2f\n", weekly_salary_1);
                break;



            case '2':
                puts("Enter hourly wage: ");
                scanf("%f", &hourly_wage);
                puts("Enter hours worked this week: ");
                scanf("%f", &hours_worked_in_week);
                if(hours_worked_in_week>40){
                    weekly_salary_2 = (40 * hourly_wage) + ((hours_worked_in_week - 40) * 1.5 * hourly_wage);
                }else{
                    weekly_salary_2 = hours_worked_in_week * hourly_wage;
                }
                printf("Weekly salary: $%.2f\n", weekly_salary_2);
                break;



            case '3':
                puts("Enter gross weekly sales: ");
                scanf("%f", &gross_weekly_sales);
                weekly_salary_3 = 250 + (gross_weekly_sales * .057);
                printf("Weekly salary: $%.2f\n", weekly_salary_3);
                break;



            case '4':
                puts("Enter number of items the employee produced this week: ");
                scanf("%d", &number_of_items_produced);
                puts("Enter how much money they earn per item: ");
                scanf("%d", &earnings_per_item);
                weekly_salary_3 = number_of_items_produced * earnings_per_item;
                printf("Weekly salary: $%.2f\n", weekly_salary_3);
                break;

            default:
                 puts("Invalid entry. Try again.");

        }

    }




    return 0;
}