# Requirements

## Introduction

-   Recording data in any institution or place of work is typical, and more important for institution like Banks, where records and transaction is what drives the whole.
-   This topic was chosen as it allows me to implement data structures, and further helps me to get a deeper understanding of a structured programming language like C.

## Objective of the system

-   The main objective of the banking system is to provide a tool to efficiently record all data necessary, and also sort it.
-   The people using it only have to choose what they have to do, and enter the data,everything else is taken care of by the program.

## Features proposed in the current system

-   Two modes of logins provided namely admin and user.The 2 modes have different functionalities, elaborated below.

    -   User requires empty password
    -   Admin requires password 'admin' to login.

-   User mode consists of options:
    -   Create new Account, which requires the data
        -   Date of creation.
        -   Account number.
        -   Name of the Account holder.
        -   Date of birth.
        -   Age.
        -   Address.
        -   Citizenship number.
        -   Phone number.
        -   Amount to be deposited.
        -   Type of account:
            -   Savings
            -   Current
            -   Fixed1 (for 1 year)
            -   Fixed2 (for 2 years)
            -   Fixed3 (for 3 years)
    -   Update information of existing account. Which gives the choice of changing
        -   Address
        -   Phone
    -   For transations (Requires Account number). Gives you 2 choices:
        -   Deposit
        -   Withdraw
    -   Check details of existing account. Further gives you the choice to search using:
        -   Account number or,
        -   Name
    -   Exit
-   Admin mode has options:
    -   Removing existing account
        -   Requires the account number to be removed.
    -   View Customer's list
        -   Shows account number, name, address and phone number of all the accounts in a tabular format.
    -   Exit

## SWOT ANALYSIS

![SWOT Analysis](https://github.com/AdityaGautam05/LTTS-C-MiniProject/blob/main/images/swot.png)

# 3W&#39;s and 1&#39;H

## Who:

-   Banks.

## What:

-   An automated system to record, organise and maintain data for banks.

## When:

-   When Banks are crowded and staff to customer interactions are at an height, this system allows user to perform simple transactions on this system.

## How:

-   Effectively organises and maintains data which in return allows easy accessibility.

# Detail requirements

## High Level Requirements:

| ID   | Description                                              | Category  | Status      |
| ---- | -------------------------------------------------------- | --------- | ----------- |
| HR01 | User shall be able to login                              | Techincal | IMPLEMENTED |
| HR02 | Admin shall be able to login                             | Techincal | IMPLEMENTED |
| HR03 | User shall be able to create account.                    | Techincal | IMPLEMENTED |
| HR04 | User shall be able to update existing account            | Techincal | IMPLEMENTED |
| HR05 | User shall be able to perform transactions               | Techincal | IMPLEMENTED |
| HR06 | User shall be able to check details of existing account  | Techincal | IMPLEMENTED |
| HR07 | Admin shall be able to remove existing account           | Techincal | IMPLEMENTED |
| HR08 | Admin shall be able to view customer list                | Technical | IMPLEMENTED |
| HR09 | Logs will be maintained                                  | Scenario  | FUTURE      |
| HR10 | Admin shall be able to perform rollbacks of transactions | Technical | FUTURE      |

## Low level Requirements:

| ID   | Description                                                                                                                                                                    | HLR ID | Status (Implemented/Future) |
| ---- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------ | --------------------------- |
| LR01 | (1). New account shall be added by providing all the asked information (2). Id should be unique and validated from persistant file or else new account should not be accepted. | HR03   | IMPLEMENTED                 |
| LR02 | Must be able to login as User.                                                                                                                                                 | HR01   | IMPLEMENTED                 |
| LR03 | Must be able to login as Admin                                                                                                                                                 | HR02   | FUTURE                      |
| LR04 | If user tries to create an existing account then the system doesn't allow                                                                                                      | HR03   | IMPLEMENTED                 |
| LR05 | User can only update an existing account                                                                                                                                       | HR04   | IMPLEMENTED                 |
| LR06 | User needs to enter account number to perform transation, and if the account doesn't exist then it shows 'No record found'                                                     | HR05   | IMPLEMENTED                 |
| LR05 | User shall be able to check details of only existing account using account_number/name, if it doesn't exist then it shows 'No record found'                                    | HR06   | IMPLEMENTED                 |
| LR06 | Admin shall bew able to remove existing account on basis of account number, else 'Record not found'                                                                            | HR07   | IMPLEMENTED                 |
| LR07 | Admin shall be able to view all customer list in tabular format                                                                                                                | HR08   | IMPLEMENTED                 |
