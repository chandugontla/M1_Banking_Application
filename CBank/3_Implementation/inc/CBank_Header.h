/**
 * @file CBank_Header.h
 * @author {chandrashekar} ({gontla.chandrashekar2000@gmail.com})
 * @brief 
 * @version 0.1
 * @date 2022-02-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _cbank_
void admin();
void main_screen();
void bank_menu();
void create_new_account();
void edit_details();
void compute_transaction();
float compute_interest(float t, float amount, int rate);
void compute_delay(int j);
void view_list();
void erase_details();
void see_details();
void close_application();
#endif
