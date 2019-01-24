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
static const char *ng0 = "C:/Users/user/HSCD/Uebung/Aufgabe3/insertsort.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_2754736641_2730021763_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned char t10;
    unsigned char t11;
    unsigned char t12;
    unsigned char t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    int t17;
    char *t18;
    int t20;
    char *t21;
    int t23;
    char *t24;
    char *t25;
    int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned char t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;

LAB0:    xsi_set_current_line(54, ng0);
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
LAB3:    t1 = (t0 + 5280);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(55, ng0);
    t1 = (t0 + 5376);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(56, ng0);
    t1 = xsi_get_transient_memory(8U);
    memset(t1, 0, 8U);
    t2 = t1;
    memset(t2, (unsigned char)2, 8U);
    t5 = (t0 + 5440);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 8U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(57, ng0);
    t1 = xsi_get_transient_memory(11U);
    memset(t1, 0, 11U);
    t2 = t1;
    memset(t2, (unsigned char)2, 11U);
    t5 = (t0 + 5504);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 11U);
    xsi_driver_first_trans_fast(t5);
    goto LAB3;

LAB5:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 1832U);
    t5 = *((char **)t2);
    t10 = *((unsigned char *)t5);
    t11 = (t10 == (unsigned char)3);
    if (t11 == 1)
        goto LAB10;

LAB11:    t4 = (unsigned char)0;

LAB12:    if (t4 != 0)
        goto LAB7;

LAB9:
LAB8:    goto LAB3;

LAB7:    xsi_set_current_line(60, ng0);
    t2 = (t0 + 1352U);
    t7 = *((char **)t2);
    t14 = (7 - 1);
    t15 = (t14 * 1U);
    t16 = (0 + t15);
    t2 = (t7 + t16);
    t8 = (t0 + 8366);
    t17 = xsi_mem_cmp(t8, t2, 2U);
    if (t17 == 1)
        goto LAB14;

LAB18:    t18 = (t0 + 8368);
    t20 = xsi_mem_cmp(t18, t2, 2U);
    if (t20 == 1)
        goto LAB15;

LAB19:    t21 = (t0 + 8370);
    t23 = xsi_mem_cmp(t21, t2, 2U);
    if (t23 == 1)
        goto LAB16;

LAB20:
LAB17:    xsi_set_current_line(64, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t1 = (t0 + 5440);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 8U);
    xsi_driver_first_trans_fast(t1);

LAB13:    goto LAB8;

LAB10:    t2 = (t0 + 1992U);
    t6 = *((char **)t2);
    t12 = *((unsigned char *)t6);
    t13 = (t12 == (unsigned char)3);
    t4 = t13;
    goto LAB12;

LAB14:    xsi_set_current_line(61, ng0);
    t24 = (t0 + 1512U);
    t25 = *((char **)t24);
    t26 = (0 - 7);
    t27 = (t26 * -1);
    t28 = (1U * t27);
    t29 = (0 + t28);
    t24 = (t25 + t29);
    t30 = *((unsigned char *)t24);
    t31 = (t0 + 5376);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    *((unsigned char *)t35) = t30;
    xsi_driver_first_trans_fast(t31);
    goto LAB13;

LAB15:    xsi_set_current_line(62, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t1 = (t0 + 5504);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 8U);
    xsi_driver_first_trans_delta(t1, 3U, 8U, 0LL);
    goto LAB13;

LAB16:    xsi_set_current_line(63, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t14 = (7 - 2);
    t15 = (t14 * 1U);
    t16 = (0 + t15);
    t1 = (t2 + t16);
    t5 = (t0 + 5504);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 3U);
    xsi_driver_first_trans_delta(t5, 0U, 3U, 0LL);
    goto LAB13;

LAB21:;
}

static void work_a_2754736641_2730021763_p_1(char *t0)
{
    char t21[16];
    char t23[16];
    char t33[16];
    char *t1;
    char *t2;
    char *t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    char *t7;
    char *t8;
    int t9;
    char *t10;
    char *t11;
    int t12;
    char *t13;
    char *t14;
    int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned char t20;
    char *t22;
    char *t24;
    char *t25;
    int t26;
    unsigned int t27;
    unsigned char t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;

LAB0:    t1 = (t0 + 4960U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 1352U);
    t3 = *((char **)t2);
    t4 = (7 - 1);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t2 = (t3 + t6);
    t7 = (t0 + 8372);
    t9 = xsi_mem_cmp(t7, t2, 2U);
    if (t9 == 1)
        goto LAB5;

LAB9:    t10 = (t0 + 8374);
    t12 = xsi_mem_cmp(t10, t2, 2U);
    if (t12 == 1)
        goto LAB6;

LAB10:    t13 = (t0 + 8376);
    t15 = xsi_mem_cmp(t13, t2, 2U);
    if (t15 == 1)
        goto LAB7;

LAB11:
LAB8:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 3432U);
    t3 = *((char **)t2);
    t2 = (t0 + 5568);
    t7 = (t2 + 56U);
    t8 = *((char **)t7);
    t10 = (t8 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 8U);
    xsi_driver_first_trans_fast_port(t2);

LAB4:    xsi_set_current_line(70, ng0);

LAB19:    t2 = (t0 + 5296);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB20;

LAB1:    return;
LAB5:    xsi_set_current_line(71, ng0);
    t16 = (t0 + 8378);
    t18 = (t0 + 3112U);
    t19 = *((char **)t18);
    t20 = *((unsigned char *)t19);
    t22 = ((IEEE_P_2592010699) + 4024);
    t24 = (t23 + 0U);
    t25 = (t24 + 0U);
    *((int *)t25) = 0;
    t25 = (t24 + 4U);
    *((int *)t25) = 6;
    t25 = (t24 + 8U);
    *((int *)t25) = 1;
    t26 = (6 - 0);
    t27 = (t26 * 1);
    t27 = (t27 + 1);
    t25 = (t24 + 12U);
    *((unsigned int *)t25) = t27;
    t18 = xsi_base_array_concat(t18, t21, t22, (char)97, t16, t23, (char)99, t20, (char)101);
    t27 = (7U + 1U);
    t28 = (8U != t27);
    if (t28 == 1)
        goto LAB13;

LAB14:    t25 = (t0 + 5568);
    t29 = (t25 + 56U);
    t30 = *((char **)t29);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    memcpy(t32, t18, 8U);
    xsi_driver_first_trans_fast_port(t25);
    goto LAB4;

LAB6:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 3272U);
    t3 = *((char **)t2);
    t4 = (10 - 7);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t2 = (t3 + t6);
    t7 = (t0 + 5568);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    t11 = (t10 + 56U);
    t13 = *((char **)t11);
    memcpy(t13, t2, 8U);
    xsi_driver_first_trans_fast_port(t7);
    goto LAB4;

LAB7:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 8385);
    t7 = (t0 + 3272U);
    t8 = *((char **)t7);
    t4 = (10 - 10);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t7 = (t8 + t6);
    t11 = ((IEEE_P_2592010699) + 4024);
    t13 = (t23 + 0U);
    t14 = (t13 + 0U);
    *((int *)t14) = 0;
    t14 = (t13 + 4U);
    *((int *)t14) = 4;
    t14 = (t13 + 8U);
    *((int *)t14) = 1;
    t9 = (4 - 0);
    t27 = (t9 * 1);
    t27 = (t27 + 1);
    t14 = (t13 + 12U);
    *((unsigned int *)t14) = t27;
    t14 = (t33 + 0U);
    t16 = (t14 + 0U);
    *((int *)t16) = 10;
    t16 = (t14 + 4U);
    *((int *)t16) = 8;
    t16 = (t14 + 8U);
    *((int *)t16) = -1;
    t12 = (8 - 10);
    t27 = (t12 * -1);
    t27 = (t27 + 1);
    t16 = (t14 + 12U);
    *((unsigned int *)t16) = t27;
    t10 = xsi_base_array_concat(t10, t21, t11, (char)97, t2, t23, (char)97, t7, t33, (char)101);
    t27 = (5U + 3U);
    t20 = (8U != t27);
    if (t20 == 1)
        goto LAB15;

LAB16:    t16 = (t0 + 5568);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t22 = *((char **)t19);
    memcpy(t22, t10, 8U);
    xsi_driver_first_trans_fast_port(t16);
    goto LAB4;

LAB12:;
LAB13:    xsi_size_not_matching(8U, t27, 0);
    goto LAB14;

LAB15:    xsi_size_not_matching(8U, t27, 0);
    goto LAB16;

LAB17:    t3 = (t0 + 5296);
    *((int *)t3) = 0;
    goto LAB2;

LAB18:    goto LAB17;

LAB20:    goto LAB18;

}


extern void work_a_2754736641_2730021763_init()
{
	static char *pe[] = {(void *)work_a_2754736641_2730021763_p_0,(void *)work_a_2754736641_2730021763_p_1};
	xsi_register_didat("work_a_2754736641_2730021763", "isim/insertsort_tb_isim_beh.exe.sim/work/a_2754736641_2730021763.didat");
	xsi_register_executes(pe);
}
