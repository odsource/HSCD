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
static const char *ng0 = "C:/Users/user/HSCD/Uebung/timer.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3620187407;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
char *ieee_p_3620187407_sub_436279890_3965413181(char *, char *, char *, char *, int );


static void work_a_3669124147_2730021763_p_0(char *t0)
{
    char t11[16];
    char t16[16];
    char t17[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    int t18;
    unsigned int t19;
    int t20;
    char *t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;

LAB0:    xsi_set_current_line(38, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1152U);
    t3 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 3872);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(39, ng0);
    t1 = xsi_get_transient_memory(25U);
    memset(t1, 0, 25U);
    t5 = t1;
    memset(t5, (unsigned char)2, 25U);
    t6 = (t0 + 3952);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 25U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(40, ng0);
    t1 = (t0 + 4016);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 1672U);
    t5 = *((char **)t2);
    t12 = (24 - 1);
    t13 = (24 - t12);
    t14 = (t13 * 1U);
    t15 = (0 + t14);
    t2 = (t5 + t15);
    t7 = ((IEEE_P_2592010699) + 4024);
    t8 = (t17 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 23;
    t9 = (t8 + 4U);
    *((int *)t9) = 0;
    t9 = (t8 + 8U);
    *((int *)t9) = -1;
    t18 = (0 - 23);
    t19 = (t18 * -1);
    t19 = (t19 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t19;
    t6 = xsi_base_array_concat(t6, t16, t7, (char)99, (unsigned char)2, (char)97, t2, t17, (char)101);
    t9 = (t0 + 2568U);
    t10 = *((char **)t9);
    t20 = *((int *)t10);
    t9 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t11, t6, t16, t20);
    t21 = (t11 + 12U);
    t19 = *((unsigned int *)t21);
    t22 = (1U * t19);
    t4 = (25U != t22);
    if (t4 == 1)
        goto LAB7;

LAB8:    t23 = (t0 + 3952);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memcpy(t27, t9, 25U);
    xsi_driver_first_trans_fast(t23);
    xsi_set_current_line(43, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t12 = (24 - 24);
    t13 = (t12 * -1);
    t14 = (1U * t13);
    t15 = (0 + t14);
    t1 = (t2 + t15);
    t3 = *((unsigned char *)t1);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB9;

LAB11:
LAB10:    xsi_set_current_line(46, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB12;

LAB14:
LAB13:    goto LAB3;

LAB7:    xsi_size_not_matching(25U, t22, 0);
    goto LAB8;

LAB9:    xsi_set_current_line(44, ng0);
    t5 = (t0 + 4016);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t5);
    goto LAB10;

LAB12:    xsi_set_current_line(47, ng0);
    t1 = (t0 + 4016);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB13;

}


extern void work_a_3669124147_2730021763_init()
{
	static char *pe[] = {(void *)work_a_3669124147_2730021763_p_0};
	xsi_register_didat("work_a_3669124147_2730021763", "isim/system_tb_isim_beh.exe.sim/work/a_3669124147_2730021763.didat");
	xsi_register_executes(pe);
}
