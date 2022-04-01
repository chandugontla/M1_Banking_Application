#include "../unity/unity.h"
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


void setUp()
{
}

void tearDown()
{
}
void create_new_account_1(int month,int day,int year,int account_no,int age,int deposit);
void create_new_account_1(int month,int day,int year,int account_no,int age,int deposit)
{
    
    add.deposit.month = month;
    add.deposit.day = day;
    add.deposit.year = year;
    check.acc_no = account_no;
    add.age = age;
    add.amt = deposit;
    
    TEST_ASSERT_TRUE_MESSAGE (add.deposit.month > 0,"Month is invalid, less than 0");
    TEST_ASSERT_TRUE_MESSAGE (add.deposit.month < 12,"Month is invalid, greater than 12");
    TEST_ASSERT_TRUE_MESSAGE (add.deposit.day > 0,"Day is invalid,less than 0");
    TEST_ASSERT_TRUE_MESSAGE (add.deposit.day < 31,"Day is invalid,greater than 31");
    TEST_ASSERT_TRUE_MESSAGE (add.deposit.year > 0,"Year is invalid.lesser than 0");
    TEST_ASSERT_TRUE_MESSAGE (check.acc_no > 0,"Account is valid");
    TEST_ASSERT_TRUE_MESSAGE (add.age > 0,"Age is invalid,less than zero");
    TEST_ASSERT_TRUE_MESSAGE (add.age < 110,"Age is invalid, greater than 110 years");
    TEST_ASSERT_TRUE_MESSAGE (add.amt > 0,"Deposit is invalid, lesser than zero");
    TEST_ASSERT_TRUE_MESSAGE (add.amt < 1000000,"Deposit is invalid, greater than 10 lakhs");
    

}

void test_acc_create_11(void)
{
    create_new_account_1(4,23,1979,15678,45,10000);
}

void test_compute_interest_01()
{
    TEST_ASSERT_EQUAL(80, compute_interest(2.0f, 2000.0f, 2));
}



int main()
{
    UNITY_BEGIN();

    RUN_TEST(test_acc_create_11);
    RUN_TEST(test_compute_interest_01);
    
    return UNITY_END();
}