#include <stdio.h>

int main(){

   int hours_worked;
   float hourly_wage;
   float salary;

   while(hours_worked != -1){

       printf("Enter # of hours worked (-1 to end): ");
       scanf("%d", &hours_worked);

       if(hours_worked != -1){

            printf("Enter hourly wage: $");
            scanf("%f", &hourly_wage);

            if(hours_worked>40){
                
                salary = (40 * hourly_wage) + ((hours_worked - 40) * 1.5 * hourly_wage);
                
            }else{
                    
                salary = hours_worked * hourly_wage;

            }

            printf("Salary: $%.2f\n", salary);

       }

   }


    return 0;

}