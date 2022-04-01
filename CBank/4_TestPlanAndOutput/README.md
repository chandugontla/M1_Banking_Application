# TEST PLAN:

| **Test ID** | **Description**                          | **Exp I/P**                | **Exp O/P** | **Actual Out** | **Type Of Test**   |
| ----------- | ---------------------------------------- | -------------------------- | ----------- | -------------- | ------------------ |
| H_01        | Check if when month entered less than 0  | -1                         | FAIL        | FAIL           | Technical based    |
| H_02        | Check if when month entered more than 12 | 13                         | FAIL        | FAIL           | Scenario/Technical |
| H_03        | Check if when month entered less than 0  | -1                         | FAIL        | FAIL           | Technical based    |
| H_04        | Check if when month entered more than 31 | 32                         | FAIL        | FAIL           | Scenario/Technical |
| H_05        | Check if when year passed less than 0    | -1                         | FAIL        | FAIL           | Scenario/Technical |
| H_06        | Check if Account number greater than 0   | -1                         | FAIL        | FAIL           | Technical based    |
| H_07        | Check if Age is greater than 0           | -1                         | FAIL        | FAIL           | Technical          |
| H_08        | Check if Age is less than 110            | 115                        | FAIL        | FAIL           | Technical based    |
| H_09        | Check if amt greater than 0              | -1                         | FAIL        | FAIL           | Technical          |
| H_10        | Check if amt less than 1000000           | 1000                       | PASS        | PASS           | Technical          |
| H_11        | Check if amt less than 1000000           | 1220000                    | FAIL        | FAIL           | Technical          |
| H_12        | Check if computes interest correctly     | (P,R,T)=(2.0f, 2000.0f, 2) | 80          | 80             | Technical          |
| H_13        | Check if computes interest correctly     | (P,R,T)=(3.0f, 3300.0f, 1) | 99          | 99             | Technical          |
