/**
 * @file CBank_Header.c
 * @author {Chandrashekar} ({gontla.chandrashekar2000@gmail.com})
 * @brief 
 * @version 0.1
 * @date 2022-03-1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../inc/CBank_Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j;
int main_exit;

struct date
{
    int month, day, year;
};

struct
{
    char name[60];
    int acc_no, age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

} add, upd, check, rem, transaction;

/**
 * @brief compute interest
 * 
 * @param time 
 * @param amount 
 * @param rate 
 * @return float 
 */
float compute_interest(float time, float amount, int rate)
{
    float SI;
    SI = (rate * time * amount) / 100.0;
    return (SI);
}

/**
 * @brief delays execution
 * 
 * @param j 
 */
void compute_delay(int j)
{
    int i, k;
    for (i = 0; i < j; i++)
        k = i;
}

/**
 * @brief Create a new account object
 * 
 */
void create_new_account()
{
    int choice;
    FILE *ptr;

    ptr = fopen("CBankRecord.dat", "a+");
account_no:
    system("clear");
    printf("\t\t\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 ADD RECORD \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1");
    printf("\n\n\n Enter today's date (mm/dd/yyyy) : ");
    scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
    printf("\n Enter the account number : ");
    scanf("%d", &check.acc_no);
    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            printf(" Account no. already in use ! ");
            compute_delay(1000000000);
            goto account_no;
        }
    }
    add.acc_no = check.acc_no;
    printf("\n Enter the name : ");
    scanf("%s", add.name);
    printf("\n Enter the date of birth (mm/dd/yyyy) : ");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    printf("\n Enter the age : ");
    scanf("%d", &add.age);
    printf("\n Enter the address : ");
    scanf("%s", add.address);
    printf("\n Enter the citizenship number : ");
    scanf("%s", add.citizenship);
    printf("\n Enter the phone number : ");
    scanf("%lf", &add.phone);
    printf("\n Enter the amount to deposit : $");
    scanf("%f", &add.amt);
    printf("\n Type of account : \n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\t Enter your choice : ");
    scanf("%s", add.acc_type);

    fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

    fclose(ptr);
    printf("\n Account created successfully ! ");
add_invalid:
    printf("\n\n\n\t\t Enter 1 to go to the main menu and 0 to exit : ");
    scanf("%d", &main_exit);
    system("clear");
    if (main_exit == 1)
        bank_menu();
    else if (main_exit == 0)
        main_screen();
    else
    {
        printf("\n Invalid ! \a");
        goto add_invalid;
    }
}

/**
 * @brief View the record list
 * 
 */
void view_list()
{
    FILE *view;
    view = fopen("CBankRecord.dat", "r");
    int test = 0;
    system("clear");
    printf("\n ACC. NO. \tNAME\t\t\t ADDRESS \t\t\t PHONE \n");

    while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf", add.acc_no, add.name, add.address, add.phone);
        test++;
    }

    fclose(view);
    if (test == 0)
    {
        system("clear");
        printf("\n NO RECORDS !! \n");
    }

    view_list_invalid:
    printf("\n\n Enter 1 to go to the main menu and 0 to exit : ");
    scanf("%d", &main_exit);
    system("clear");
    if (main_exit == 1)
        admin();
    else if (main_exit == 0)
        main_screen();
    else
    {
        printf("\n Invalid ! \a");
        goto view_list_invalid;
    }
}

/**
 * @brief Edit Details
 * 
 */
void edit_details(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("CBankRecord.dat", "r");
    newrec = fopen("new.dat", "w");

    printf("\n Enter the account no. of the customer whose info you want to change : ");
    scanf("%d", &upd.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_no == upd.acc_no)
        {
            test = 1;
            printf("\n Which information do you want to change?\n1. Address \n2. Phone \n\n Enter your choice (1 for address and 2 for phone) : ");
            scanf("%d", &choice);
            system("clear");
            if (choice == 1)
            {
                printf(" Enter the new address :");
                scanf("%s", upd.address);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, upd.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                system("clear");
                printf(" Changes saved ! ");
            }
            else if (choice == 2)
            {
                printf(" Enter the new phone number :");
                scanf("%lf", &upd.phone);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, upd.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                system("clear");
                printf(" Changes saved ! ");
            }
        }
        else
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("CBankRecord.dat");
    rename("new.dat", "CBankRecord.dat");

    if (test != 1)
    {
        system("clear");
        printf("\n Record not found !! \a\a\a");
    edit_invalid:
        printf("\n Enter 0 to try again, 1 to return to main menu and 2 to exit : ");
        scanf("%d", &main_exit);
        system("clear");
        if (main_exit == 1)

            bank_menu();
        else if (main_exit == 2)
            main_screen();
        else if (main_exit == 0)
            edit_details();
        else
        {
            printf("\n Invalid !\a");
            goto edit_invalid;
        }
    }
    else
    {
        printf("\n\n\n Enter 1 to go to the main menu and 0 to exit : ");
        scanf("%d", &main_exit);
        system("clear");
        if (main_exit == 1)
            bank_menu();
        else
            main_screen();
    }
}

/**
 * @brief compute_transaction
 * 
 */
void compute_transaction(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("CBankRecord.dat", "r");
    newrec = fopen("CBankRecord.dat", "w");

    printf(" Enter the account no. of the customer : ");
    scanf("%d", &transaction.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {

        if (add.acc_no == transaction.acc_no)
        {
            test = 1;
            if (strcmp(add.acc_type, "fixed1") == 0 || strcmp(add.acc_type, "fixed2") == 0 || strcmp(add.acc_type, "fixed3") == 0)
            {
                printf("\a\a\a\n\n YOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS !!!!!");
                compute_delay(1000000000);
                system("clear");
                bank_menu();
            }
            printf("\n\n Do you want to \n1. Deposit\n2. Withdraw ?\n\n Enter your choice (1 for deposit and 2 for withdraw ) :");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf(" Enter the amount you want to deposit : $ ");
                scanf("%f", &transaction.amt);
                add.amt += transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\n Deposited successfully !");
            }
            else
            {
                printf(" Enter the amount you want to withdraw : $ ");
                scanf("%f", &transaction.amt);
                add.amt -= transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\n Withdrawn successfully ! ");
            }
        }
        else
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("CBankRecord.dat");
    rename("new.dat", "CBankRecord.dat");
    if (test != 1)
    {
        printf("\n\n Record not found !!");
    transact_invalid:
        printf("\n\n\n Enter 0 to try again, 1 to return to main menu and 2 to exit :");
        scanf("%d", &main_exit);
        system("clear");
        if (main_exit == 0)
            compute_transaction();
        else if (main_exit == 1)
            bank_menu();
        else if (main_exit == 2)
            main_screen();
        else
        {
            printf("\n Invalid ! ");
            goto transact_invalid;
        }
    }
    else
    {
        printf("\n Enter 1 to go to the main menu and 0 to exit : ");
        scanf("%d", &main_exit);
        system("clear");
        if (main_exit == 1)
            bank_menu();
        else
            main_screen();
    }
}

/**
 * @brief erase the records
 * 
 */
void erase_details(void)
{
    FILE *old, *newrec;
    int test = 0;
    old = fopen("CBankRecord.dat", "r");
    newrec = fopen("new.dat", "w");
    printf(" Enter the account no. of the customer you want to delete :");
    scanf("%d", &rem.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_no != rem.acc_no)
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

        else
        {
            test++;
            printf("\n Record deleted successfully ! \n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("CBankRecord.dat");
    rename("new.dat", "CBankRecord.dat");
    if (test == 0)
    {
        printf("\nRecord not found!!\a\a\a");
    erase_invalid:
        printf("\n Enter 0 to try again,1 to return to main menu and 2 to exit : ");
        scanf("%d", &main_exit);

        if (main_exit == 1)
            admin();
        else if (main_exit == 2)
            main_screen();
        else if (main_exit == 0)
            erase_details();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
    }
    else
    {
        printf("\n Enter 1 to go to the main menu and 0 to exit :");
        scanf("%d", &main_exit);
        system("clear");
        if (main_exit == 1)
            admin();
        else
            main_screen();
    }
}

/**
 * @brief see the records
 * 
 */
void see_details(void)
{
    FILE *ptr;
    int test = 0, rate;
    int choice;
    float time;
    float intrst;
    ptr = fopen("CBankRecord.dat", "r");
    printf(" Do you want to check by\n1.Account no\n2.Name\nEnter your choice :");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf(" Enter the account number :");
        scanf("%d", &check.acc_no);

        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (add.acc_no == check.acc_no)
            {
                system("clear");
                test = 1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone,
                       add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                if (strcmp(add.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = compute_interest(time, add.amt, rate);
                    printf("\n\n You will get $%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                }
                else if (strcmp(add.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = compute_interest(time, add.amt, rate);
                    printf("\n\n You will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);
                }
                else if (strcmp(add.acc_type, "fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = compute_interest(time, add.amt, rate);
                    printf("\n\n You will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);
                }
                else if (strcmp(add.acc_type, "saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = compute_interest(time, add.amt, rate);
                    printf("\n\n You will get $.%.2f as interest on %d of every month ", intrst, add.deposit.day);
                }
                else if (strcmp(add.acc_type, "current") == 0)
                {

                    printf("\n\n You will get no interest \a\a");
                }
            }
        }
    }
    else if (choice == 2)
    {
        printf(" Enter the name :");
        scanf("%s", &check.name);
        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (strcmp(add.name, check.name) == 0)
            {
                system("clear");
                test = 1;
                printf("\n Account No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone,
                       add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                if (strcmp(add.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = compute_interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                }
                else if (strcmp(add.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = compute_interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);
                }
                else if (strcmp(add.acc_type, "fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = compute_interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);
                }
                else if (strcmp(add.acc_type, "saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = compute_interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d of every month", intrst, add.deposit.day);
                }
                else if (strcmp(add.acc_type, "current") == 0)
                {

                    printf("\n\n You will get no interest \a\a");
                }
            }
        }
    }

    fclose(ptr);
    if (test != 1)
    {
        system("clear");
        printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("clear");
        if (main_exit == 1)
            bank_menu();
        else if (main_exit == 2)
            main_screen();
        else if (main_exit == 0)
            see_details();
        else
        {
            system("clear");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
    }
    if (main_exit == 1)
    {
        system("clear");
        main_screen();
    }

    else
    {

        system("clear");
        main_screen();
    }
}

/**
 * @brief close_application
 * 
 */
void close_application(void)
{
    system("clear");
    printf("\n\n\n\n\t\t\t\t\t\t\xB3 Creator : Aditya Gautam \xB3\n\n");
}

/**
 * @brief Main Bank Menu
 * 
 */
void bank_menu(void)
{
    int choice;
    system("clear");
    printf("\n\n\t\t\tC BANK ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create a new account\n\t\t2.Update the information of existing account\n\t\t3.Select for transactions\n\t\t4.Check the details of existing account\n\t\t5.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d", &choice);

    system("clear");
    switch (choice)
    {
    case 1:
        create_new_account();
        break;
    case 2:
        edit_details();
        break;
    case 3:
        compute_transaction();
        break;
    case 4:
        see_details();
        break;
    case 5:
        main_screen();
        break;
    }
}

/**
 * @brief admin mode
 * 
 */
void admin(void)
{
    int choice;
    system("clear");
    printf("\n\n\t\t\t\tADMININSTRATOR MODE");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME ADMIN ! \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Removing existing account\n\t\t2.View customer's list\n\t\t3.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d", &choice);

    system("clear");
    switch (choice)
    {
    case 1:
        erase_details();
        break;
    case 2:
        view_list();
        break;
    case 3:
        main_screen();
        break;
    }
}

/**
 * @brief Main Menu
 * 
 */
void main_screen()
{
    fflush(stdin);
    //clearing input buffer
    system("clear");
    char pass[10];
    int i = 0;
    printf("\n\n\t\t\t\t\tEnter the password to login : ");
    fgets(pass, 10, stdin);

    //Enter as user
    if (strcmp(pass, "\n") == 0) 
    {
        printf("\n\n\t\t\t\tPassword Matched!\n\nLOADING");
        for (i = 0; i <= 6; i++)
        {
            compute_delay(500000000);
            printf(".");
        }
        system("clear");
        bank_menu();
    } else if (strcmp(pass, "admin\n") == 0) {
        printf("\n\n\t\t\t\tPassword Match!\n\nLOADING");
        // Enter as admin
        for (i = 0; i <= 6; i++)
        {
            compute_delay(500000000);
            printf(".");
        }
        system("clear");
        admin();
    } else if (strcmp(pass, "close\n") == 0) {
        //close program
        close_application();
    } else {
        printf("\n\nWrong password!!\a\a\a\n");
        main_screen();
    }
}
