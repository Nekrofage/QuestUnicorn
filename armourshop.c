/*
 *******************************************************************
 *** This software is copyright 1985-2007 by Michael H Riley     ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#include "header.h"

void armour_shop(char* name) {
  double mul;
  int option;
  double price;
  int item;
  char   buffer[80];
  int    i;

  void show_top() {
    textmode(3); gotoxy(27,1); textcolor(11);
    sprintf(buffer,"Welcome to %s",name);
    txt_write(buffer);
    textcolor(14);
    gotoxy(22,4);
    sprintf(buffer,"%2d  %s",1,objects[60].name);
    txt_write(buffer);
    gotoxy(50,4);
    sprintf(buffer,"%6.0f",objects[60].cost * mul);
    txt_write(buffer);
    gotoxy(22,5);
    sprintf(buffer,"%2d  %s",2,objects[66].name);
    txt_write(buffer);
    gotoxy(50,5);
    sprintf(buffer,"%6.0f",objects[66].cost * mul);
    txt_write(buffer);
    gotoxy(22,6);
    sprintf(buffer,"%2d  %s",3,objects[70].name);
    txt_write(buffer);
    gotoxy(50,6);
    sprintf(buffer,"%6.0f",objects[70].cost * mul);
    txt_write(buffer);
    gotoxy(22,7);
    sprintf(buffer,"%2d  %s",4,objects[74].name);
    txt_write(buffer);
    gotoxy(50,7);
    sprintf(buffer,"%6.0f",objects[74].cost * mul);
    txt_write(buffer);
    gotoxy(22,8);
    sprintf(buffer,"%2d  %s",5,objects[78].name);
    txt_write(buffer);
    gotoxy(50,8);
    sprintf(buffer,"%6.0f",objects[78].cost * mul);
    txt_write(buffer);
    gotoxy(22,9);
    sprintf(buffer,"%2d  %s",6,objects[82].name);
    txt_write(buffer);
    gotoxy(50,9);
    sprintf(buffer,"%6.0f",objects[82].cost * mul);
    txt_write(buffer);
    textcolor(14); gotoxy(35,24);
    sprintf(buffer,"Gold = %.0f",player.gold);
    txt_write(buffer);
  }

  mul = 1; 
  if (player.sex == 'F') mul = mul-0.05;
  mul = mul-(player.skill[14]/100);
  if (player.stat[6] >= 0 && player.stat[6] <= 7) mul += .08;
  if (player.stat[6] >= 8 && player.stat[6] <= 11) mul += .05;
  if (player.stat[6] >= 12 && player.stat[6] <= 14) mul += .01;
  if (player.stat[6] >= 17 && player.stat[6] <= 18) mul -= .02;
  if (player.stat[6] >= 19 && player.stat[6] <= 20) mul -= .03;
  if (player.stat[6] >= 21 && player.stat[6] <= 23) mul -= .05;
  if (player.stat[6] >= 24 && player.stat[6] <= 99) mul -= .1;
  if (player.class == 11) mul -= 0.2;
  show_top();
  option = 1;
  while (option != 0) {
    gotoxy(15,17); textcolor(10);
    txt_write("Which item would you like (0 to leave) ?        ");
    gotoxy(56,17); textcolor(15);
    p_read(buffer);
    sscanf(buffer,"%d",&option);
    for (i=17; i<=22; i++) {
      gotoxy(10,i); txt_write("                                              ");
      }
    if (option>0 && option < 7) {
      switch (option) {
        case 1:item = 60; break;
        case 2:item = 66;  break;
        case 3:item = 70; break;
        case 4:item = 74; break;
        case 5:item = 78; break;
        case 6:item = 82; break;
        }
      gotoxy(15,18); textcolor(12);
      sprintf(buffer,"Ah, a %s A fine selection!",objects[item].name);
      txt_write(buffer);
      price = objects[item].cost*mul;
      haggle(price,item);
      show_top();
      }
    }
  } /* void armour_shop(char* name) */
