/**
 * @file Test_CBank.c
 * @author {chandrashekar} ({gontla.chandrashekar2000@gmail.com})
 * @brief 
 * @version 0.1
 * @date 2022-02-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../inc/CBank_Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../unity/unity.h"

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
void test_acc_create_01(void)
{
    create_new_account_1(-1,20,2000,123456,69,1500);
}
void test_acc_create_02(void)
{
    create_new_account_1(13,20,1999,123456,22,200);
}
void test_acc_create_03(void)
{
    create_new_account_1(4,-1,2001,123456,34,20345);
}
void test_acc_create_04(void)
{
    create_new_account_1(4,45,1970,20301,45,98765);
}
void test_acc_create_05(void)
{
    create_new_account_1(4,23,-1,543627,45,98765);
}
void test_acc_create_06(void)
{
    create_new_account_1(4,23,1993,-1,27,9000);
}
void test_acc_create_07(void)
{
    create_new_account_1(4,23,1996,1234567,-9,98765);
}
void test_acc_create_08(void)
{
    create_new_account_1(4,23,1982,1234567,115,98765);
}
void test_acc_create_09(void)
{
    create_new_account_1(4,23,1979,15678,45,-1);
}
void test_acc_create_10(void)
{
    create_new_account_1(4,23,1979,15678,45,1220000);
}
void test_acc_create_11(void)
{
    create_new_account_1(4,23,1979,15678,45,10000);
}

void test_compute_interest_01()
{
    TEST_ASSERT_EQUAL(80, compute_interest(2.0f, 2000.0f, 2));
}

void test_compute_interest_02()
{
    TEST_ASSERT_EQUAL_MESSAGE(69, compute_interest(3.0f, 3300.0f, 1),"Interest not computed correctly");
}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(test_acc_create_01);
    RUN_TEST(test_acc_create_02);
    RUN_TEST(test_acc_create_03);
    RUN_TEST(test_acc_create_04);
    RUN_TEST(test_acc_create_05);
    RUN_TEST(test_acc_create_06);
    RUN_TEST(test_acc_create_07);
    RUN_TEST(test_acc_create_08);
    RUN_TEST(test_acc_create_09);
    RUN_TEST(test_acc_create_10);
    RUN_TEST(test_acc_create_11);
    RUN_TEST(test_compute_interest_01);
    RUN_TEST(test_compute_interest_02);

    return UNITY_END();
}
