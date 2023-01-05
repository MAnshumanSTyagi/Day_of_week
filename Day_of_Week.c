#include<stdio.h>
int is_leap_year(int year);
int days_in_month(int year,int month);
int day_of_the_week(int year,int month,int day);
void print_calendar(int year,int month);



int is_leap_year(int year){
int flag=0;
if(year%100==0){
    if(year%400==0)    // To check leap Year
    flag=1;
}
else if(year%100!=0){
    if(year%4==0)
        flag=1;
}
return flag;
}


int days_in_month(int year,int month){
if(month==1)
return 31;
if(month==2){
    int flag=is_leap_year(year);
    if(flag==0)
        return 28;
    else if(flag==1)
        return 29;
}
if(month==3)
return 31;
if(month==4)
return 30;
if(month==5)
return 31;
if(month==6)
return 30;
if(month==7)
return 31;
if(month==8)
return 31;
if(month==9)
return 30;
if(month==10)
return 31;
if(month==11)
return 30;
if(month==12)
return 31;
}


int day_of_the_week(int year,int month,int day){
int y=1589,count=0,flag,m,p;
while(y<=year)
{ flag=is_leap_year(y); //Starting day will be Sunday on Jan 1 1589
 if(flag==0)            //We know after a normal year only one day get added up mon->tue
    count+=1;            //In leap year 2 day get added up mon-->wed
 else if(flag==1)
    count+=2;
 if(count>7)
 count=count%7;         // If it exceeds greater than 7 than again give it a no according to weekday
 y++;
}
for(int i=1;i<month;i++){
    m=days_in_month(year,i); //Getting the  no day from each month adding to previous count


    count+=m%7;        //modulus by 7 to get the extra day and add it to the count

       if(count>7)    // If it exceeds greater than 7 than again give it a no according to weekday
        count=count%7;
}
if(day>7)
day=day%7;         // If day exceeds greater than 7 than again give it a no according to weekday
p=count+day-1;     // day-1 beacuse that day of date had already been counted in previous task which gives weekday of first day on month
if(p>7)
    p=p%7;
return p;
}

void print_calendar(int year,int month){



int i,j,k,day,dt=1;
day=days_in_month(year,month);
int checker=day_of_the_week(year,month,1);
printf("\n\nThe first day of this month is  ");

if(is_leap_year(year)==1)    // Beacuse our function was add two days in leap year bur it need to be added in year following leap year
    checker--;
if(checker==1)
    printf("Sunday");
if(checker==2)
    printf("Monday");
if(checker==3)
    printf("Tuesday");
if(checker==4)
    printf("Wednesday");
if(checker==5)
    printf("Thursday");
if(checker==6)
    printf("Friday");
if(checker==7)
    printf("Saturday");
if(checker==0)             // If it is leap year and firstday and day_of_week functions returns 1 then it will become 0for saturday
    printf("Saturday");

    printf("\nSo now Select no accordingly for above day \n");

   printf("\n\nEnter First Day Start From <0-Mon....5-Sat & 6-Sun> End With Sunday : ");
    scanf("%d",&k);

    printf("\nMon \tTue \tWed \tThu \tFri \tSat \tSun \n\n");
    printf(" _________________________________________________\n\n");

    for(j=k;j>0;j--)
    {
        printf("\t");
    }

    while(dt<=day)
    {
        if(k!=0)
        {
         if(k%7==0)
         printf("\n");
        }

  printf("%d\t",dt);
        dt++;
        k++;
    }






}





int main(){
int year,month,day,checker,geter;
printf("Enter the year ");
scanf("%d",&year);
printf("Enter the month ");
scanf("%d",&month);
printf("Enter the day of month ");
scanf("%d",&day);
checker=day_of_the_week(year,month,day);
printf("The Dayof Week for given date is   ");

    if(is_leap_year(year)==1)    // Beacuse our function was add two days in leap year bur it need to be added in year following leap year
    checker--;
if(checker==1)
    printf("Sunday");
if(checker==2)
    printf("Monday");
if(checker==3)
    printf("Tuesday");
if(checker==4)
    printf("Wednesday");
if(checker==5)
    printf("Thursday");
if(checker==6)
    printf("Friday");
if(checker==7)
    printf("Saturday");
if(checker==0)             // If it is leap year and firstday and day_of_week functions returns 1 then it will become 0for saturday
    printf("Saturday");

printf("\n\n\nDo you want to print calender for this month and year also");
printf("\n\nEnter 1 for YES any other no for NO--> \n");
int q;
scanf("%d",&q);
if(q==1)
{print_calendar(year,month);}



}








