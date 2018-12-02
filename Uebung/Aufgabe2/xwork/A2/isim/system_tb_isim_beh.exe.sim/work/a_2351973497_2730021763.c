/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/user/HSCD/Uebung/Aufgabe2/testbench/system_tb.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3499444699;
extern char *STD_STANDARD;
extern char *IEEE_P_3620187407;

unsigned char ieee_p_2592010699_sub_1690584930_503743352(char *, unsigned char );
char *ieee_p_3499444699_sub_2213602152_3536714472(char *, char *, int , int );
int ieee_p_3620187407_sub_514432868_3965413181(char *, char *, char *);


static void work_a_2351973497_2730021763_p_0(char *t0)
{
    char *t1;
    char *t2;
    int64 t3;
    int64 t4;
    char *t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    int64 t13;
    int64 t14;
    char *t15;
    unsigned char t16;
    unsigned char t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;

LAB0:    xsi_set_current_line(51, ng0);

LAB3:    t1 = (t0 + 3968U);
    t2 = *((char **)t1);
    t3 = *((int64 *)t2);
    t4 = (5 * t3);
    t1 = (t0 + 3728U);
    t5 = *((char **)t1);
    t6 = *((unsigned char *)t5);
    t1 = (t0 + 7040);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = t6;
    xsi_driver_first_trans_delta(t1, 0U, 1, t4);
    t11 = (t0 + 3968U);
    t12 = *((char **)t11);
    t13 = *((int64 *)t12);
    t14 = (15 * t13);
    t11 = (t0 + 3728U);
    t15 = *((char **)t11);
    t16 = *((unsigned char *)t15);
    t17 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t16);
    t11 = (t0 + 7040);
    t18 = (t11 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    *((unsigned char *)t21) = t17;
    xsi_driver_subsequent_trans_delta(t11, 0U, 1, t14);
    t22 = (t0 + 7040);
    xsi_driver_intertial_reject(t22, t4, t4);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2351973497_2730021763_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    int64 t6;
    int64 t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned char t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;

LAB0:    xsi_set_current_line(52, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB3;

LAB4:
LAB5:    t16 = (t0 + 1352U);
    t17 = *((char **)t16);
    t18 = *((unsigned char *)t17);
    t16 = (t0 + 7104);
    t19 = (t16 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    *((unsigned char *)t22) = t18;
    xsi_driver_first_trans_fast(t16);

LAB2:    t23 = (t0 + 6864);
    *((int *)t23) = 1;

LAB1:    return;
LAB3:    t1 = (t0 + 3968U);
    t5 = *((char **)t1);
    t6 = *((int64 *)t5);
    t7 = (t6 / 2);
    t1 = (t0 + 1352U);
    t8 = *((char **)t1);
    t9 = *((unsigned char *)t8);
    t10 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t9);
    t1 = (t0 + 7104);
    t11 = (t1 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = t10;
    xsi_driver_first_trans_delta(t1, 0U, 1, t7);
    t15 = (t0 + 7104);
    xsi_driver_intertial_reject(t15, t7, t7);
    goto LAB2;

LAB6:    goto LAB2;

}

unsigned char work_a_2351973497_2730021763_sub_1651148518_1977239504(char *t1, unsigned char t2)
{
    char t4[8];
    unsigned char t0;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    unsigned char t8;
    unsigned char t9;
    unsigned char t10;
    unsigned char t11;
    unsigned char t12;
    unsigned char t13;
    unsigned char t14;
    unsigned char t15;
    unsigned char t16;

LAB0:    t5 = (t4 + 4U);
    *((unsigned char *)t5) = t2;
    t9 = (t2 >= (unsigned char)48);
    if (t9 == 1)
        goto LAB8;

LAB9:    t8 = (unsigned char)0;

LAB10:    if (t8 == 1)
        goto LAB5;

LAB6:    t12 = (t2 >= (unsigned char)97);
    if (t12 == 1)
        goto LAB11;

LAB12:    t11 = (unsigned char)0;

LAB13:    t7 = t11;

LAB7:    if (t7 == 1)
        goto LAB2;

LAB3:    t15 = (t2 >= (unsigned char)65);
    if (t15 == 1)
        goto LAB14;

LAB15:    t14 = (unsigned char)0;

LAB16:    t6 = t14;

LAB4:    t0 = t6;

LAB1:    return t0;
LAB2:    t6 = (unsigned char)1;
    goto LAB4;

LAB5:    t7 = (unsigned char)1;
    goto LAB7;

LAB8:    t10 = (t2 <= (unsigned char)57);
    t8 = t10;
    goto LAB10;

LAB11:    t13 = (t2 <= (unsigned char)122);
    t11 = t13;
    goto LAB13;

LAB14:    t16 = (t2 <= (unsigned char)90);
    t14 = t16;
    goto LAB16;

LAB17:;
}

void work_a_2351973497_2730021763_sub_2379598880_1977239504(char *t0, char *t1, unsigned char t2)
{
    char t3[128];
    char t4[8];
    char t5[16];
    char t12[8];
    char t38[16];
    char *t6;
    char *t7;
    int t8;
    unsigned int t9;
    char *t10;
    char *t11;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    int64 t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    int64 t33;
    int64 t34;
    int64 t35;
    int64 t36;
    int64 t37;
    int t39;
    int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned char t43;

LAB0:    t6 = (t5 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 7;
    t7 = (t6 + 4U);
    *((int *)t7) = 0;
    t7 = (t6 + 8U);
    *((int *)t7) = -1;
    t8 = (0 - 7);
    t9 = (t8 * -1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    t7 = (t3 + 4U);
    t10 = (t0 + 7888);
    t11 = (t7 + 88U);
    *((char **)t11) = t10;
    t13 = (t7 + 56U);
    *((char **)t13) = t12;
    xsi_type_set_default_value(t10, t12, 0);
    t14 = (t7 + 64U);
    t15 = (t10 + 80U);
    t16 = *((char **)t15);
    *((char **)t14) = t16;
    t17 = (t7 + 80U);
    *((unsigned int *)t17) = 8U;
    t18 = (t4 + 4U);
    *((unsigned char *)t18) = t2;
    t19 = (t0 + 4208U);
    t20 = *((char **)t19);
    t21 = *((int64 *)t20);
    xsi_process_wait(t1, t21);

LAB5:    t19 = (t1 + 88U);
    t22 = *((char **)t19);
    t23 = (t22 + 2480U);
    *((unsigned int *)t23) = 1U;
    t24 = (t1 + 88U);
    t25 = *((char **)t24);
    t26 = (t25 + 0U);
    getcontext(t26);
    t27 = (t1 + 88U);
    t28 = *((char **)t27);
    t29 = (t28 + 2480U);
    t9 = *((unsigned int *)t29);
    if (t9 == 1)
        goto LAB6;

LAB7:    t30 = (t1 + 88U);
    t31 = *((char **)t30);
    t32 = (t31 + 2480U);
    *((unsigned int *)t32) = 3U;

LAB3:
LAB4:
LAB2:    t6 = (t0 + 7296);
    t10 = (t6 + 56U);
    t11 = *((char **)t10);
    t13 = (t11 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = t2;
    xsi_driver_first_trans_fast(t6);
    t6 = (t0 + 7232);
    t10 = (t6 + 56U);
    t11 = *((char **)t10);
    t13 = (t11 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)2;
    xsi_driver_first_trans_fast(t6);
    t6 = (t0 + 4208U);
    t10 = *((char **)t6);
    t21 = *((int64 *)t10);
    t33 = (7 * t21);
    t34 = (t33 / 16);
    t6 = (t0 + 7360);
    t11 = (t6 + 56U);
    t13 = *((char **)t11);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)3;
    xsi_driver_first_trans_delta(t6, 0U, 1, t34);
    t16 = (t0 + 4208U);
    t17 = *((char **)t16);
    t35 = *((int64 *)t17);
    t36 = (8 * t35);
    t37 = (t36 / 16);
    t16 = (t0 + 7360);
    t19 = (t16 + 56U);
    t20 = *((char **)t19);
    t22 = (t20 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = (unsigned char)2;
    xsi_driver_subsequent_trans_delta(t16, 0U, 1, t37);
    t24 = (t0 + 7360);
    xsi_driver_intertial_reject(t24, t34, t34);
    t6 = (t0 + 4208U);
    t10 = *((char **)t6);
    t21 = *((int64 *)t10);
    xsi_process_wait(t1, t21);

LAB11:    t6 = (t1 + 88U);
    t11 = *((char **)t6);
    t13 = (t11 + 2480U);
    *((unsigned int *)t13) = 1U;
    t14 = (t1 + 88U);
    t15 = *((char **)t14);
    t16 = (t15 + 0U);
    getcontext(t16);
    t17 = (t1 + 88U);
    t19 = *((char **)t17);
    t20 = (t19 + 2480U);
    t9 = *((unsigned int *)t20);
    if (t9 == 1)
        goto LAB12;

LAB13:    t22 = (t1 + 88U);
    t23 = *((char **)t22);
    t24 = (t23 + 2480U);
    *((unsigned int *)t24) = 3U;

LAB9:
LAB10:
LAB8:    t6 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t38, ((int)(t2)), 8);
    t10 = (t7 + 56U);
    t11 = *((char **)t10);
    t10 = (t11 + 0);
    t13 = (t38 + 12U);
    t9 = *((unsigned int *)t13);
    t9 = (t9 * 1U);
    memcpy(t10, t6, t9);
    t8 = 0;
    t39 = 7;

LAB14:    if (t8 <= t39)
        goto LAB15;

LAB17:    t6 = (t0 + 7232);
    t10 = (t6 + 56U);
    t11 = *((char **)t10);
    t13 = (t11 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)3;
    xsi_driver_first_trans_fast(t6);

LAB1:    return;
LAB6:    xsi_saveStackAndSuspend(t1);
    goto LAB7;

LAB12:    xsi_saveStackAndSuspend(t1);
    goto LAB13;

LAB15:    t6 = (t7 + 56U);
    t10 = *((char **)t6);
    t40 = (t8 - 7);
    t9 = (t40 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, t8);
    t41 = (1U * t9);
    t42 = (0 + t41);
    t6 = (t10 + t42);
    t43 = *((unsigned char *)t6);
    t11 = (t0 + 7232);
    t13 = (t11 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    *((unsigned char *)t16) = t43;
    xsi_driver_first_trans_fast(t11);
    t6 = (t0 + 4208U);
    t10 = *((char **)t6);
    t21 = *((int64 *)t10);
    xsi_process_wait(t1, t21);

LAB21:    t6 = (t1 + 88U);
    t11 = *((char **)t6);
    t13 = (t11 + 2480U);
    *((unsigned int *)t13) = 1U;
    t14 = (t1 + 88U);
    t15 = *((char **)t14);
    t16 = (t15 + 0U);
    getcontext(t16);
    t17 = (t1 + 88U);
    t19 = *((char **)t17);
    t20 = (t19 + 2480U);
    t9 = *((unsigned int *)t20);
    if (t9 == 1)
        goto LAB22;

LAB23:    t22 = (t1 + 88U);
    t23 = *((char **)t22);
    t24 = (t23 + 2480U);
    *((unsigned int *)t24) = 3U;

LAB19:
LAB20:
LAB18:
LAB16:    if (t8 == t39)
        goto LAB17;

LAB24:    t40 = (t8 + 1);
    t8 = t40;
    goto LAB14;

LAB22:    xsi_saveStackAndSuspend(t1);
    goto LAB23;

}

void work_a_2351973497_2730021763_sub_2130168365_1977239504(char *t0, char *t1, char *t2, char *t3)
{
    char t5[24];
    char *t6;
    unsigned char t7;
    char *t8;
    char *t9;
    int t10;
    char *t11;
    int t12;
    int t13;
    int t14;
    char *t15;
    int t16;
    char *t17;
    int t18;
    int t19;
    unsigned int t20;
    char *t21;
    int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned char t26;

LAB0:    t6 = (t5 + 4U);
    t7 = (t2 != 0);
    if (t7 == 1)
        goto LAB3;

LAB2:    t8 = (t5 + 12U);
    *((char **)t8) = t3;
    t9 = (t3 + 4U);
    t10 = *((int *)t9);
    t11 = (t3 + 0U);
    t12 = *((int *)t11);
    t13 = t12;
    t14 = t10;

LAB4:    if (t13 <= t14)
        goto LAB5;

LAB7:
LAB1:    return;
LAB3:    *((char **)t6) = t2;
    goto LAB2;

LAB5:    t15 = (t3 + 0U);
    t16 = *((int *)t15);
    t17 = (t3 + 8U);
    t18 = *((int *)t17);
    t19 = (t13 - t16);
    t20 = (t19 * t18);
    t21 = (t3 + 4U);
    t22 = *((int *)t21);
    xsi_vhdl_check_range_of_index(t16, t22, t18, t13);
    t23 = (1U * t20);
    t24 = (0 + t23);
    t25 = (t2 + t24);
    t26 = *((unsigned char *)t25);
    work_a_2351973497_2730021763_sub_2379598880_1977239504(t0, t1, t26);

LAB6:    if (t13 == t14)
        goto LAB7;

LAB8:    t10 = (t13 + 1);
    t13 = t10;
    goto LAB4;

}

void work_a_2351973497_2730021763_sub_2636828196_1977239504(char *t0, char *t1, char *t2)
{
    char t3[488];
    char t4[16];
    char t8[8];
    char t21[8];
    char t24[16];
    char t31[8];
    char t40[8];
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    int64 t11;
    char *t12;
    char *t13;
    int t14;
    char *t15;
    int t16;
    int t17;
    int64 t18;
    char *t19;
    char *t20;
    char *t22;
    char *t23;
    char *t25;
    char *t26;
    int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t55;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    unsigned char t60;
    unsigned char t61;
    unsigned int t62;
    unsigned int t63;

LAB0:    t5 = (t3 + 4U);
    t6 = ((STD_STANDARD) + 832);
    t7 = (t5 + 88U);
    *((char **)t7) = t6;
    t9 = (t5 + 56U);
    *((char **)t9) = t8;
    *((int *)t8) = 16;
    t10 = (t5 + 80U);
    *((unsigned int *)t10) = 4U;
    t11 = (1 * 1000000000000LL);
    t12 = (t5 + 56U);
    t13 = *((char **)t12);
    t14 = *((int *)t13);
    t12 = (t0 + 4088U);
    t15 = *((char **)t12);
    t16 = *((int *)t15);
    t17 = (t14 * t16);
    t18 = (t11 / (((double)(t17))));
    t12 = (t3 + 124U);
    t19 = ((STD_STANDARD) + 576);
    t20 = (t12 + 88U);
    *((char **)t20) = t19;
    t22 = (t12 + 56U);
    *((char **)t22) = t21;
    *((int64 *)t21) = t18;
    t23 = (t12 + 80U);
    *((unsigned int *)t23) = 8U;
    t25 = (t24 + 0U);
    t26 = (t25 + 0U);
    *((int *)t26) = 7;
    t26 = (t25 + 4U);
    *((int *)t26) = 0;
    t26 = (t25 + 8U);
    *((int *)t26) = -1;
    t27 = (0 - 7);
    t28 = (t27 * -1);
    t28 = (t28 + 1);
    t26 = (t25 + 12U);
    *((unsigned int *)t26) = t28;
    t26 = (t3 + 244U);
    t29 = (t0 + 7888);
    t30 = (t26 + 88U);
    *((char **)t30) = t29;
    t32 = (t26 + 56U);
    *((char **)t32) = t31;
    xsi_type_set_default_value(t29, t31, 0);
    t33 = (t26 + 64U);
    t34 = (t29 + 80U);
    t35 = *((char **)t34);
    *((char **)t33) = t35;
    t36 = (t26 + 80U);
    *((unsigned int *)t36) = 8U;
    t37 = (t3 + 364U);
    t38 = ((STD_STANDARD) + 192);
    t39 = (t37 + 88U);
    *((char **)t39) = t38;
    t41 = (t37 + 56U);
    *((char **)t41) = t40;
    xsi_type_set_default_value(t38, t40, 0);
    t42 = (t37 + 80U);
    *((unsigned int *)t42) = 1U;
    t43 = (t4 + 4U);
    *((char **)t43) = t2;
    t44 = (t0 + 1632U);
    xsi_add_dynamic_wait(t1, t44, -1, -1);

LAB5:    t45 = (t1 + 224U);
    t45 = *((char **)t45);
    xsi_wp_set_status(t45, 1);
    t46 = (t1 + 88U);
    t47 = *((char **)t46);
    t48 = (t47 + 2480U);
    *((unsigned int *)t48) = 1U;
    t49 = (t1 + 88U);
    t50 = *((char **)t49);
    t51 = (t50 + 0U);
    getcontext(t51);
    t52 = (t1 + 88U);
    t53 = *((char **)t52);
    t54 = (t53 + 2480U);
    t28 = *((unsigned int *)t54);
    if (t28 == 1)
        goto LAB6;

LAB7:    t55 = (t1 + 88U);
    t56 = *((char **)t55);
    t57 = (t56 + 2480U);
    *((unsigned int *)t57) = 3U;

LAB3:
LAB4:    t58 = (t0 + 1672U);
    t59 = *((char **)t58);
    t60 = *((unsigned char *)t59);
    t61 = (t60 == (unsigned char)2);
    if (t61 == 1)
        goto LAB2;
    else
        goto LAB5;

LAB2:    xsi_remove_dynamic_wait(t1, t44);
    t6 = (t12 + 56U);
    t7 = *((char **)t6);
    t11 = *((int64 *)t7);
    t18 = (8 * t11);
    xsi_process_wait(t1, t18);

LAB11:    t6 = (t1 + 88U);
    t9 = *((char **)t6);
    t10 = (t9 + 2480U);
    *((unsigned int *)t10) = 1U;
    t13 = (t1 + 88U);
    t15 = *((char **)t13);
    t19 = (t15 + 0U);
    getcontext(t19);
    t20 = (t1 + 88U);
    t22 = *((char **)t20);
    t23 = (t22 + 2480U);
    t28 = *((unsigned int *)t23);
    if (t28 == 1)
        goto LAB12;

LAB13:    t25 = (t1 + 88U);
    t29 = *((char **)t25);
    t30 = (t29 + 2480U);
    *((unsigned int *)t30) = 3U;

LAB9:
LAB10:
LAB8:    t6 = (t0 + 1672U);
    t7 = *((char **)t6);
    t60 = *((unsigned char *)t7);
    t61 = (t60 == (unsigned char)2);
    if (t61 == 0)
        goto LAB14;

LAB15:    t6 = (t0 + 7424);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    t10 = (t9 + 56U);
    t13 = *((char **)t10);
    *((unsigned char *)t13) = (unsigned char)3;
    xsi_driver_first_trans_delta(t6, 0U, 1, 0LL);
    t11 = (100 * 1000LL);
    t15 = (t0 + 7424);
    t19 = (t15 + 56U);
    t20 = *((char **)t19);
    t22 = (t20 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = (unsigned char)2;
    xsi_driver_subsequent_trans_delta(t15, 0U, 1, t11);
    t14 = 0;
    t16 = 7;

LAB16:    if (t14 <= t16)
        goto LAB17;

LAB19:    t6 = (t26 + 56U);
    t7 = *((char **)t6);
    t14 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t7, t24);
    t60 = ((unsigned char)(t14));
    t6 = (t37 + 56U);
    t9 = *((char **)t6);
    t6 = (t9 + 0);
    *((unsigned char *)t6) = t60;
    t6 = (t37 + 56U);
    t7 = *((char **)t6);
    t60 = *((unsigned char *)t7);
    t6 = (t2 + 0);
    *((unsigned char *)t6) = t60;
    t6 = (t37 + 56U);
    t7 = *((char **)t6);
    t60 = *((unsigned char *)t7);
    t6 = (t0 + 7488);
    t9 = (t6 + 56U);
    t10 = *((char **)t9);
    t13 = (t10 + 56U);
    t15 = *((char **)t13);
    *((unsigned char *)t15) = t60;
    xsi_driver_first_trans_fast(t6);
    t6 = (t12 + 56U);
    t7 = *((char **)t6);
    t11 = *((int64 *)t7);
    t18 = (16 * t11);
    xsi_process_wait(t1, t18);

LAB30:    t6 = (t1 + 88U);
    t9 = *((char **)t6);
    t10 = (t9 + 2480U);
    *((unsigned int *)t10) = 1U;
    t13 = (t1 + 88U);
    t15 = *((char **)t13);
    t19 = (t15 + 0U);
    getcontext(t19);
    t20 = (t1 + 88U);
    t22 = *((char **)t20);
    t23 = (t22 + 2480U);
    t28 = *((unsigned int *)t23);
    if (t28 == 1)
        goto LAB31;

LAB32:    t25 = (t1 + 88U);
    t29 = *((char **)t25);
    t30 = (t29 + 2480U);
    *((unsigned int *)t30) = 3U;

LAB28:
LAB29:
LAB27:    t6 = (t0 + 7424);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    t10 = (t9 + 56U);
    t13 = *((char **)t10);
    *((unsigned char *)t13) = (unsigned char)3;
    xsi_driver_first_trans_delta(t6, 0U, 1, 0LL);
    t11 = (100 * 1000LL);
    t15 = (t0 + 7424);
    t19 = (t15 + 56U);
    t20 = *((char **)t19);
    t22 = (t20 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = (unsigned char)2;
    xsi_driver_subsequent_trans_delta(t15, 0U, 1, t11);
    t6 = (t0 + 1672U);
    t7 = *((char **)t6);
    t60 = *((unsigned char *)t7);
    t61 = (t60 == (unsigned char)3);
    if (t61 == 0)
        goto LAB33;

LAB34:
LAB1:    return;
LAB6:    xsi_saveStackAndSuspend(t1);
    goto LAB7;

LAB12:    xsi_saveStackAndSuspend(t1);
    goto LAB13;

LAB14:    t6 = (t0 + 11364);
    xsi_report(t6, 15U, (unsigned char)2);
    goto LAB15;

LAB17:    t6 = (t12 + 56U);
    t7 = *((char **)t6);
    t11 = *((int64 *)t7);
    t18 = (16 * t11);
    xsi_process_wait(t1, t18);

LAB23:    t6 = (t1 + 88U);
    t9 = *((char **)t6);
    t10 = (t9 + 2480U);
    *((unsigned int *)t10) = 1U;
    t13 = (t1 + 88U);
    t15 = *((char **)t13);
    t19 = (t15 + 0U);
    getcontext(t19);
    t20 = (t1 + 88U);
    t22 = *((char **)t20);
    t23 = (t22 + 2480U);
    t28 = *((unsigned int *)t23);
    if (t28 == 1)
        goto LAB24;

LAB25:    t25 = (t1 + 88U);
    t29 = *((char **)t25);
    t30 = (t29 + 2480U);
    *((unsigned int *)t30) = 3U;

LAB21:
LAB22:
LAB20:    t6 = (t0 + 7424);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    t10 = (t9 + 56U);
    t13 = *((char **)t10);
    *((unsigned char *)t13) = (unsigned char)3;
    xsi_driver_first_trans_delta(t6, 0U, 1, 0LL);
    t11 = (100 * 1000LL);
    t15 = (t0 + 7424);
    t19 = (t15 + 56U);
    t20 = *((char **)t19);
    t22 = (t20 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = (unsigned char)2;
    xsi_driver_subsequent_trans_delta(t15, 0U, 1, t11);
    t6 = (t0 + 1672U);
    t7 = *((char **)t6);
    t60 = *((unsigned char *)t7);
    t6 = (t26 + 56U);
    t9 = *((char **)t6);
    t17 = (t14 - 7);
    t28 = (t17 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, t14);
    t62 = (1U * t28);
    t63 = (0 + t62);
    t6 = (t9 + t63);
    *((unsigned char *)t6) = t60;

LAB18:    if (t14 == t16)
        goto LAB19;

LAB26:    t17 = (t14 + 1);
    t14 = t17;
    goto LAB16;

LAB24:    xsi_saveStackAndSuspend(t1);
    goto LAB25;

LAB31:    xsi_saveStackAndSuspend(t1);
    goto LAB32;

LAB33:    t6 = (t0 + 11379);
    xsi_report(t6, 14U, (unsigned char)2);
    goto LAB34;

}

void work_a_2351973497_2730021763_sub_2313382871_1977239504(char *t0, char *t1, char *t2, char *t3)
{
    char t4[272];
    char t5[24];
    char t8[16];
    char t34[8];
    char *t6;
    unsigned int t7;
    char *t9;
    unsigned int t10;
    char *t11;
    char *t12;
    int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    int t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    char *t35;
    char *t36;
    char *t37;
    unsigned char t38;
    char *t39;
    char *t40;
    unsigned int t41;
    int t42;
    int t43;
    char *t44;
    char *t45;
    int t46;
    char *t47;
    int t48;
    int t49;
    unsigned int t50;
    char *t51;
    int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    unsigned char t56;
    unsigned char t57;
    char *t58;
    char *t59;

LAB0:    t6 = (t3 + 12U);
    t7 = *((unsigned int *)t6);
    t7 = (t7 * 1U);
    t9 = (t3 + 12U);
    t10 = *((unsigned int *)t9);
    t11 = (t8 + 0U);
    t12 = (t11 + 0U);
    *((int *)t12) = 1;
    t12 = (t11 + 4U);
    *((unsigned int *)t12) = t10;
    t12 = (t11 + 8U);
    *((int *)t12) = 1;
    t13 = (t10 - 1);
    t14 = (t13 * 1);
    t14 = (t14 + 1);
    t12 = (t11 + 12U);
    *((unsigned int *)t12) = t14;
    t12 = (t4 + 4U);
    t15 = ((STD_STANDARD) + 1008);
    t16 = (t12 + 88U);
    *((char **)t16) = t15;
    t17 = xsi_get_memory(t7);
    t18 = (t12 + 56U);
    *((char **)t18) = t17;
    memcpy(t17, t2, t7);
    t19 = (t12 + 64U);
    *((char **)t19) = t8;
    t20 = (t12 + 80U);
    *((unsigned int *)t20) = t7;
    t21 = (t12 + 136U);
    *((char **)t21) = t17;
    t22 = (t12 + 124U);
    *((int *)t22) = 0;
    t23 = (t12 + 128U);
    t24 = (t8 + 12U);
    t14 = *((unsigned int *)t24);
    t25 = (t14 - 1);
    *((int *)t23) = t25;
    t26 = (t12 + 120U);
    t28 = (t7 > 2147483644);
    if (t28 == 1)
        goto LAB2;

LAB3:    t29 = (t7 + 3);
    t30 = (t29 / 16);
    t27 = t30;

LAB4:    *((unsigned int *)t26) = t27;
    t31 = (t4 + 148U);
    t32 = ((STD_STANDARD) + 192);
    t33 = (t31 + 88U);
    *((char **)t33) = t32;
    t35 = (t31 + 56U);
    *((char **)t35) = t34;
    xsi_type_set_default_value(t32, t34, 0);
    t36 = (t31 + 80U);
    *((unsigned int *)t36) = 1U;
    t37 = (t5 + 4U);
    t38 = (t2 != 0);
    if (t38 == 1)
        goto LAB6;

LAB5:    t39 = (t5 + 12U);
    *((char **)t39) = t3;
    t40 = (t8 + 12U);
    t41 = *((unsigned int *)t40);
    t42 = 1;
    t43 = t41;

LAB7:    if (t42 <= t43)
        goto LAB8;

LAB10:
LAB1:    t6 = (t12 + 80);
    t13 = *((int *)t6);
    t9 = (t12 + 136U);
    t11 = *((char **)t9);
    xsi_put_memory(t13, t11);
    return;
LAB2:    t27 = 2147483647;
    goto LAB4;

LAB6:    *((char **)t37) = t2;
    goto LAB5;

LAB8:    t44 = (t12 + 56U);
    t45 = *((char **)t44);
    t44 = (t8 + 0U);
    t46 = *((int *)t44);
    t47 = (t8 + 8U);
    t48 = *((int *)t47);
    t49 = (t42 - t46);
    t50 = (t49 * t48);
    t51 = (t8 + 4U);
    t52 = *((int *)t51);
    xsi_vhdl_check_range_of_index(t46, t52, t48, t42);
    t53 = (1U * t50);
    t54 = (0 + t53);
    t55 = (t45 + t54);
    t56 = *((unsigned char *)t55);
    t57 = work_a_2351973497_2730021763_sub_1651148518_1977239504(t0, t56);
    if (t57 != 0)
        goto LAB11;

LAB13:
LAB12:
LAB9:    if (t42 == t43)
        goto LAB10;

LAB16:    t13 = (t42 + 1);
    t42 = t13;
    goto LAB7;

LAB11:    t58 = (t31 + 56U);
    t59 = *((char **)t58);
    t58 = (t59 + 0);
    work_a_2351973497_2730021763_sub_2636828196_1977239504(t0, t1, t58);
    t6 = (t12 + 56U);
    t9 = *((char **)t6);
    t6 = (t8 + 0U);
    t13 = *((int *)t6);
    t11 = (t8 + 8U);
    t25 = *((int *)t11);
    t46 = (t42 - t13);
    t7 = (t46 * t25);
    t15 = (t8 + 4U);
    t48 = *((int *)t15);
    xsi_vhdl_check_range_of_index(t13, t48, t25, t42);
    t10 = (1U * t7);
    t14 = (0 + t10);
    t16 = (t9 + t14);
    t38 = *((unsigned char *)t16);
    t17 = (t31 + 56U);
    t18 = *((char **)t17);
    t56 = *((unsigned char *)t18);
    t57 = (t38 == t56);
    if (t57 == 0)
        goto LAB14;

LAB15:    goto LAB12;

LAB14:    t17 = (t0 + 11393);
    xsi_report(t17, 15U, (unsigned char)2);
    goto LAB15;

}

void work_a_2351973497_2730021763_sub_3084858156_1977239504(char *t0, char *t1, int t2, char *t3, char *t4)
{
    char t5[152];
    char t6[24];
    char t9[16];
    char t14[16];
    char t16[16];
    char t23[16];
    char t25[16];
    char t31[16];
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t15;
    char *t17;
    char *t18;
    int t19;
    unsigned int t20;
    char *t22;
    char *t24;
    char *t26;
    char *t27;
    int t28;
    unsigned int t29;
    unsigned int t30;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    unsigned int t43;
    int t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    char *t50;
    char *t51;
    unsigned char t52;
    char *t53;
    char *t54;
    char *t55;
    unsigned int t56;

LAB0:    t7 = (t0 + 11408);
    t10 = ((STD_STANDARD) + 384);
    t11 = xsi_int_to_mem(t2);
    t12 = xsi_string_variable_get_image(t9, t10, t11);
    t15 = ((STD_STANDARD) + 1008);
    t17 = (t16 + 0U);
    t18 = (t17 + 0U);
    *((int *)t18) = 1;
    t18 = (t17 + 4U);
    *((int *)t18) = 5;
    t18 = (t17 + 8U);
    *((int *)t18) = 1;
    t19 = (5 - 1);
    t20 = (t19 * 1);
    t20 = (t20 + 1);
    t18 = (t17 + 12U);
    *((unsigned int *)t18) = t20;
    t13 = xsi_base_array_concat(t13, t14, t15, (char)97, t7, t16, (char)97, t12, t9, (char)101);
    t18 = (t0 + 11413);
    t24 = ((STD_STANDARD) + 1008);
    t26 = (t25 + 0U);
    t27 = (t26 + 0U);
    *((int *)t27) = 1;
    t27 = (t26 + 4U);
    *((int *)t27) = 4;
    t27 = (t26 + 8U);
    *((int *)t27) = 1;
    t28 = (4 - 1);
    t20 = (t28 * 1);
    t20 = (t20 + 1);
    t27 = (t26 + 12U);
    *((unsigned int *)t27) = t20;
    t22 = xsi_base_array_concat(t22, t23, t24, (char)97, t13, t14, (char)97, t18, t25, (char)101);
    t27 = (t9 + 12U);
    t20 = *((unsigned int *)t27);
    t29 = (5U + t20);
    t30 = (t29 + 4U);
    memcpy(t31, t23, 16U);
    t32 = (t5 + 4U);
    t33 = ((STD_STANDARD) + 1008);
    t34 = (t32 + 88U);
    *((char **)t34) = t33;
    t35 = xsi_get_memory(t30);
    t36 = (t32 + 56U);
    *((char **)t36) = t35;
    memcpy(t35, t22, t30);
    t37 = (t32 + 64U);
    *((char **)t37) = t31;
    t38 = (t32 + 80U);
    *((unsigned int *)t38) = t30;
    t39 = (t32 + 136U);
    *((char **)t39) = t35;
    t40 = (t32 + 124U);
    *((int *)t40) = 0;
    t41 = (t32 + 128U);
    t42 = (t31 + 12U);
    t43 = *((unsigned int *)t42);
    t44 = (t43 - 1);
    *((int *)t41) = t44;
    t45 = (t32 + 120U);
    t47 = (t30 > 2147483644);
    if (t47 == 1)
        goto LAB2;

LAB3:    t48 = (t30 + 3);
    t49 = (t48 / 16);
    t46 = t49;

LAB4:    *((unsigned int *)t45) = t46;
    t50 = (t6 + 4U);
    *((int *)t50) = t2;
    t51 = (t6 + 8U);
    t52 = (t3 != 0);
    if (t52 == 1)
        goto LAB6;

LAB5:    t53 = (t6 + 16U);
    *((char **)t53) = t4;
    t54 = (t32 + 56U);
    t55 = *((char **)t54);
    t54 = (t31 + 12U);
    t56 = *((unsigned int *)t54);
    t56 = (t56 * 1U);
    xsi_report(t55, t56, 0);
    t7 = (t4 + 12U);
    t20 = *((unsigned int *)t7);
    t20 = (t20 * 1U);
    t8 = (char *)alloca(t20);
    memcpy(t8, t3, t20);
    work_a_2351973497_2730021763_sub_2130168365_1977239504(t0, t1, t8, t4);
    t7 = (t4 + 12U);
    t20 = *((unsigned int *)t7);
    t20 = (t20 * 1U);
    t10 = (char *)alloca(t20);
    memcpy(t10, t3, t20);
    work_a_2351973497_2730021763_sub_2313382871_1977239504(t0, t1, t10, t4);

LAB1:    t7 = (t32 + 80);
    t19 = *((int *)t7);
    t11 = (t32 + 136U);
    t12 = *((char **)t11);
    xsi_put_memory(t19, t12);
    return;
LAB2:    t46 = 2147483647;
    goto LAB4;

LAB6:    *((char **)t51) = t3;
    goto LAB5;

}

static void work_a_2351973497_2730021763_p_2(char *t0)
{
    char t12[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned char t7;
    unsigned char t8;
    unsigned char t9;
    unsigned char t10;
    int64 t11;
    int t13;
    unsigned int t14;
    int64 t15;

LAB0:    t1 = (t0 + 6048U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(142, ng0);
    t2 = (t0 + 7168);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(143, ng0);
    t2 = (t0 + 7232);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(144, ng0);

LAB6:    t2 = (t0 + 6880);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    t3 = (t0 + 6880);
    *((int *)t3) = 0;
    xsi_set_current_line(145, ng0);
    t2 = (t0 + 4208U);
    t3 = *((char **)t2);
    t11 = *((int64 *)t3);
    t2 = (t0 + 5856);
    xsi_process_wait(t2, t11);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t7 = *((unsigned char *)t4);
    t3 = (t0 + 3728U);
    t5 = *((char **)t3);
    t8 = *((unsigned char *)t5);
    t9 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t8);
    t10 = (t7 == t9);
    if (t10 == 1)
        goto LAB4;
    else
        goto LAB6;

LAB7:    goto LAB5;

LAB8:    xsi_set_current_line(147, ng0);
    t2 = (t0 + 5856);
    t3 = (t0 + 11417);
    t5 = (t12 + 0U);
    t6 = (t5 + 0U);
    *((int *)t6) = 1;
    t6 = (t5 + 4U);
    *((int *)t6) = 16;
    t6 = (t5 + 8U);
    *((int *)t6) = 1;
    t13 = (16 - 1);
    t14 = (t13 * 1);
    t14 = (t14 + 1);
    t6 = (t5 + 12U);
    *((unsigned int *)t6) = t14;
    work_a_2351973497_2730021763_sub_3084858156_1977239504(t0, t2, 1, t3, t12);
    xsi_set_current_line(148, ng0);
    t2 = (t0 + 5856);
    t3 = (t0 + 11433);
    t5 = (t12 + 0U);
    t6 = (t5 + 0U);
    *((int *)t6) = 1;
    t6 = (t5 + 4U);
    *((int *)t6) = 16;
    t6 = (t5 + 8U);
    *((int *)t6) = 1;
    t13 = (16 - 1);
    t14 = (t13 * 1);
    t14 = (t14 + 1);
    t6 = (t5 + 12U);
    *((unsigned int *)t6) = t14;
    work_a_2351973497_2730021763_sub_3084858156_1977239504(t0, t2, 2, t3, t12);
    xsi_set_current_line(149, ng0);
    t2 = (t0 + 5856);
    t3 = (t0 + 11449);
    t5 = (t12 + 0U);
    t6 = (t5 + 0U);
    *((int *)t6) = 1;
    t6 = (t5 + 4U);
    *((int *)t6) = 16;
    t6 = (t5 + 8U);
    *((int *)t6) = 1;
    t13 = (16 - 1);
    t14 = (t13 * 1);
    t14 = (t14 + 1);
    t6 = (t5 + 12U);
    *((unsigned int *)t6) = t14;
    work_a_2351973497_2730021763_sub_3084858156_1977239504(t0, t2, 3, t3, t12);
    xsi_set_current_line(150, ng0);
    t2 = (t0 + 5856);
    t3 = (t0 + 11465);
    t5 = (t12 + 0U);
    t6 = (t5 + 0U);
    *((int *)t6) = 1;
    t6 = (t5 + 4U);
    *((int *)t6) = 16;
    t6 = (t5 + 8U);
    *((int *)t6) = 1;
    t13 = (16 - 1);
    t14 = (t13 * 1);
    t14 = (t14 + 1);
    t6 = (t5 + 12U);
    *((unsigned int *)t6) = t14;
    work_a_2351973497_2730021763_sub_3084858156_1977239504(t0, t2, 4, t3, t12);
    xsi_set_current_line(152, ng0);
    t2 = (t0 + 4208U);
    t3 = *((char **)t2);
    t11 = *((int64 *)t3);
    t15 = (10 * t11);
    t2 = (t0 + 5856);
    xsi_process_wait(t2, t15);

LAB14:    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB12:    xsi_set_current_line(153, ng0);
    t2 = (t0 + 7168);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(154, ng0);
    t2 = (t0 + 11481);
    xsi_report(t2, 8U, 0);
    xsi_set_current_line(155, ng0);

LAB18:    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

LAB16:    goto LAB2;

LAB17:    goto LAB16;

LAB19:    goto LAB17;

}

static void work_a_2351973497_2730021763_p_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    unsigned char t5;
    char *t6;
    unsigned char t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    int t11;
    int t12;
    double t13;
    char *t14;
    char *t15;

LAB0:    t1 = (t0 + 6296U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(164, ng0);

LAB6:    t2 = (t0 + 6896);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    t3 = (t0 + 6896);
    *((int *)t3) = 0;
    xsi_set_current_line(165, ng0);
    t2 = (t0 + 7552);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t10 = *((char **)t6);
    *((double *)t10) = 0.00000000000000000;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(166, ng0);

LAB10:    t2 = (t0 + 6912);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t3 = (t0 + 3728U);
    t6 = *((char **)t3);
    t7 = *((unsigned char *)t6);
    t8 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t7);
    t9 = (t5 == t8);
    if (t9 == 1)
        goto LAB4;
    else
        goto LAB6;

LAB7:    goto LAB5;

LAB8:    t3 = (t0 + 6912);
    *((int *)t3) = 0;
    xsi_set_current_line(167, ng0);

LAB12:
LAB13:    xsi_set_current_line(168, ng0);
    t2 = (t0 + 4448U);
    t3 = *((char **)t2);
    t2 = (t3 + 0);
    *((int *)t2) = 0;
    xsi_set_current_line(169, ng0);

LAB16:    t2 = (t0 + 3112U);
    t3 = *((char **)t2);
    t5 = *((unsigned char *)t3);
    t7 = (t5 == (unsigned char)2);
    if (t7 != 0)
        goto LAB17;

LAB19:    xsi_set_current_line(173, ng0);
    t2 = (t0 + 4448U);
    t3 = *((char **)t2);
    t11 = *((int *)t3);
    t2 = (t0 + 4328U);
    t4 = *((char **)t2);
    t2 = (t4 + 0);
    *((int *)t2) = t11;
    xsi_set_current_line(174, ng0);

LAB24:    t2 = (t0 + 2952U);
    t3 = *((char **)t2);
    t5 = *((unsigned char *)t3);
    t7 = (t5 == (unsigned char)2);
    if (t7 != 0)
        goto LAB25;

LAB27:    xsi_set_current_line(178, ng0);
    t2 = (t0 + 4448U);
    t3 = *((char **)t2);
    t11 = *((int *)t3);
    t2 = (t0 + 4328U);
    t4 = *((char **)t2);
    t12 = *((int *)t4);
    t13 = ((((double)(t11))) / (((double)(t12))));
    t2 = (t0 + 7552);
    t6 = (t2 + 56U);
    t10 = *((char **)t6);
    t14 = (t10 + 56U);
    t15 = *((char **)t14);
    *((double *)t15) = t13;
    xsi_driver_first_trans_fast(t2);
    goto LAB12;

LAB9:    t3 = (t0 + 2952U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t7 = (t5 == (unsigned char)3);
    if (t7 == 1)
        goto LAB8;
    else
        goto LAB10;

LAB11:    goto LAB9;

LAB14:;
LAB15:    xsi_set_current_line(180, ng0);

LAB34:    *((char **)t1) = &&LAB35;
    goto LAB1;

LAB17:    xsi_set_current_line(170, ng0);

LAB22:    t2 = (t0 + 6928);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB18:;
LAB20:    t4 = (t0 + 6928);
    *((int *)t4) = 0;
    xsi_set_current_line(171, ng0);
    t2 = (t0 + 4448U);
    t3 = *((char **)t2);
    t11 = *((int *)t3);
    t12 = (t11 + 1);
    t2 = (t0 + 4448U);
    t4 = *((char **)t2);
    t2 = (t4 + 0);
    *((int *)t2) = t12;
    goto LAB16;

LAB21:    t4 = (t0 + 1352U);
    t6 = *((char **)t4);
    t8 = *((unsigned char *)t6);
    t9 = (t8 == (unsigned char)3);
    if (t9 == 1)
        goto LAB20;
    else
        goto LAB22;

LAB23:    goto LAB21;

LAB25:    xsi_set_current_line(175, ng0);

LAB30:    t2 = (t0 + 6944);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB31;
    goto LAB1;

LAB26:;
LAB28:    t4 = (t0 + 6944);
    *((int *)t4) = 0;
    xsi_set_current_line(176, ng0);
    t2 = (t0 + 4328U);
    t3 = *((char **)t2);
    t11 = *((int *)t3);
    t12 = (t11 + 1);
    t2 = (t0 + 4328U);
    t4 = *((char **)t2);
    t2 = (t4 + 0);
    *((int *)t2) = t12;
    goto LAB24;

LAB29:    t4 = (t0 + 1352U);
    t6 = *((char **)t4);
    t8 = *((unsigned char *)t6);
    t9 = (t8 == (unsigned char)3);
    if (t9 == 1)
        goto LAB28;
    else
        goto LAB30;

LAB31:    goto LAB29;

LAB32:    goto LAB2;

LAB33:    goto LAB32;

LAB35:    goto LAB33;

}

static void work_a_2351973497_2730021763_p_4(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    int t4;
    char *t5;
    double t6;
    double t7;
    char *t8;
    double t9;
    double t10;
    char *t11;
    int t12;
    double t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;

LAB0:    xsi_set_current_line(196, ng0);
    t1 = (t0 + 4568U);
    t2 = *((char **)t1);
    t3 = *((int *)t2);
    t4 = (t3 - 1);
    t1 = (t0 + 3432U);
    t5 = *((char **)t1);
    t6 = *((double *)t5);
    t7 = ((((double)(t4))) * t6);
    t1 = (t0 + 3272U);
    t8 = *((char **)t1);
    t9 = *((double *)t8);
    t10 = (t7 + t9);
    t1 = (t0 + 4568U);
    t11 = *((char **)t1);
    t12 = *((int *)t11);
    t13 = (t10 / (((double)(t12))));
    t1 = (t0 + 7616);
    t14 = (t1 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    *((double *)t17) = t13;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(197, ng0);
    t1 = (t0 + 4568U);
    t2 = *((char **)t1);
    t3 = *((int *)t2);
    t4 = (t3 + 1);
    t1 = (t0 + 4568U);
    t5 = *((char **)t1);
    t1 = (t5 + 0);
    *((int *)t1) = t4;
    t1 = (t0 + 6960);
    *((int *)t1) = 1;

LAB1:    return;
}


void ieee_p_2592010699_sub_3130575329_503743352();

extern void work_a_2351973497_2730021763_init()
{
	static char *pe[] = {(void *)work_a_2351973497_2730021763_p_0,(void *)work_a_2351973497_2730021763_p_1,(void *)work_a_2351973497_2730021763_p_2,(void *)work_a_2351973497_2730021763_p_3,(void *)work_a_2351973497_2730021763_p_4};
	static char *se[] = {(void *)work_a_2351973497_2730021763_sub_1651148518_1977239504,(void *)work_a_2351973497_2730021763_sub_2379598880_1977239504,(void *)work_a_2351973497_2730021763_sub_2130168365_1977239504,(void *)work_a_2351973497_2730021763_sub_2636828196_1977239504,(void *)work_a_2351973497_2730021763_sub_2313382871_1977239504,(void *)work_a_2351973497_2730021763_sub_3084858156_1977239504};
	xsi_register_didat("work_a_2351973497_2730021763", "isim/system_tb_isim_beh.exe.sim/work/a_2351973497_2730021763.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
	xsi_register_resolution_function(1, 2, (void *)ieee_p_2592010699_sub_3130575329_503743352, 6);
}
