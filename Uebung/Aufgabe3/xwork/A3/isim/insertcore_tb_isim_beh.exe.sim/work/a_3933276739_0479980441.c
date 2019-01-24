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
static const char *ng0 = "C:/Users/user/HSCD/Uebung/Aufgabe3/testbench/insertcore_tb.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3620187407;
extern char *IEEE_P_3499444699;

unsigned char ieee_p_2592010699_sub_1690584930_503743352(char *, unsigned char );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
char *ieee_p_3499444699_sub_2213602152_3536714472(char *, char *, int , int );
int ieee_p_3620187407_sub_514432868_3965413181(char *, char *, char *);


static void work_a_3933276739_0479980441_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    int64 t10;
    int64 t11;
    char *t12;
    unsigned char t13;
    unsigned char t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;

LAB0:    xsi_set_current_line(60, ng0);

LAB3:    t1 = (t0 + 3568U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 6352);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_delta(t1, 0U, 1, 0LL);
    t8 = (t0 + 3808U);
    t9 = *((char **)t8);
    t10 = *((int64 *)t9);
    t11 = (15 * t10);
    t8 = (t0 + 3568U);
    t12 = *((char **)t8);
    t13 = *((unsigned char *)t12);
    t14 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t13);
    t8 = (t0 + 6352);
    t15 = (t8 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    *((unsigned char *)t18) = t14;
    xsi_driver_subsequent_trans_delta(t8, 0U, 1, t11);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3933276739_0479980441_p_1(char *t0)
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

LAB0:    xsi_set_current_line(61, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB3;

LAB4:
LAB5:    t16 = (t0 + 1512U);
    t17 = *((char **)t16);
    t18 = *((unsigned char *)t17);
    t16 = (t0 + 6416);
    t19 = (t16 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    *((unsigned char *)t22) = t18;
    xsi_driver_first_trans_fast(t16);

LAB2:    t23 = (t0 + 6224);
    *((int *)t23) = 1;

LAB1:    return;
LAB3:    t1 = (t0 + 3808U);
    t5 = *((char **)t1);
    t6 = *((int64 *)t5);
    t7 = (t6 / 2);
    t1 = (t0 + 1512U);
    t8 = *((char **)t1);
    t9 = *((unsigned char *)t8);
    t10 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t9);
    t1 = (t0 + 6416);
    t11 = (t1 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = t10;
    xsi_driver_first_trans_delta(t1, 0U, 1, t7);
    t15 = (t0 + 6416);
    xsi_driver_intertial_reject(t15, t7, t7);
    goto LAB2;

LAB6:    goto LAB2;

}

static void work_a_3933276739_0479980441_p_2(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    int t5;
    int t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned char t11;

LAB0:    xsi_set_current_line(64, ng0);
    t1 = (t0 + 1472U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 6240);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(65, ng0);
    t3 = (t0 + 1832U);
    t4 = *((char **)t3);
    t5 = *((int *)t4);
    t6 = (t5 + 1);
    t3 = (t0 + 6480);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((int *)t10) = t6;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(66, ng0);
    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t11 = (t2 == (unsigned char)3);
    if (t11 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(67, ng0);
    t1 = (t0 + 6480);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

}

static void work_a_3933276739_0479980441_p_3(char *t0)
{
    char t13[16];
    char t14[16];
    char t17[16];
    char t21[16];
    char t23[16];
    char t29[16];
    char t31[16];
    char t37[16];
    char t39[16];
    char t45[16];
    char t47[16];
    char t53[16];
    char t55[16];
    char t61[16];
    char t63[16];
    char t69[16];
    char t71[16];
    char t77[16];
    char t79[16];
    char t85[16];
    char t87[16];
    char t93[16];
    char t95[16];
    char t101[16];
    char t103[16];
    char t109[16];
    char t111[16];
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    int t15;
    unsigned int t16;
    int t18;
    char *t19;
    char *t20;
    char *t22;
    char *t24;
    char *t25;
    int t26;
    char *t28;
    char *t30;
    char *t32;
    char *t33;
    int t34;
    char *t36;
    char *t38;
    char *t40;
    char *t41;
    int t42;
    char *t44;
    char *t46;
    char *t48;
    char *t49;
    int t50;
    char *t52;
    char *t54;
    char *t56;
    char *t57;
    int t58;
    char *t60;
    char *t62;
    char *t64;
    char *t65;
    int t66;
    char *t68;
    char *t70;
    char *t72;
    char *t73;
    int t74;
    char *t76;
    char *t78;
    char *t80;
    char *t81;
    int t82;
    char *t84;
    char *t86;
    char *t88;
    char *t89;
    int t90;
    char *t92;
    char *t94;
    char *t96;
    char *t97;
    int t98;
    char *t100;
    char *t102;
    char *t104;
    char *t105;
    int t106;
    char *t108;
    char *t110;
    char *t112;
    char *t113;
    int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    char *t127;
    char *t128;
    char *t129;
    char *t130;
    unsigned char t131;

LAB0:    xsi_set_current_line(75, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 3568U);
    t4 = *((char **)t1);
    t5 = *((unsigned char *)t4);
    t6 = (t3 == t5);
    if (t6 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1472U);
    t3 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t3 != 0)
        goto LAB7;

LAB8:
LAB3:    t1 = (t0 + 6256);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(76, ng0);
    t1 = xsi_get_transient_memory(8U);
    memset(t1, 0, 8U);
    t7 = t1;
    memset(t7, (unsigned char)2, 8U);
    t8 = (t0 + 6544);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 8U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(77, ng0);
    t1 = (t0 + 11528);
    t4 = (t0 + 11548);
    t9 = (t0 + 7200);
    t10 = (t14 + 0U);
    t11 = (t10 + 0U);
    *((int *)t11) = 0;
    t11 = (t10 + 4U);
    *((int *)t11) = 19;
    t11 = (t10 + 8U);
    *((int *)t11) = 1;
    t15 = (19 - 0);
    t16 = (t15 * 1);
    t16 = (t16 + 1);
    t11 = (t10 + 12U);
    *((unsigned int *)t11) = t16;
    t11 = (t17 + 0U);
    t12 = (t11 + 0U);
    *((int *)t12) = 0;
    t12 = (t11 + 4U);
    *((int *)t12) = 19;
    t12 = (t11 + 8U);
    *((int *)t12) = 1;
    t18 = (19 - 0);
    t16 = (t18 * 1);
    t16 = (t16 + 1);
    t12 = (t11 + 12U);
    *((unsigned int *)t12) = t16;
    t8 = xsi_base_array_concat(t8, t13, t9, (char)97, t1, t14, (char)97, t4, t17, (char)101);
    t12 = (t0 + 11568);
    t22 = (t0 + 7200);
    t24 = (t23 + 0U);
    t25 = (t24 + 0U);
    *((int *)t25) = 0;
    t25 = (t24 + 4U);
    *((int *)t25) = 19;
    t25 = (t24 + 8U);
    *((int *)t25) = 1;
    t26 = (19 - 0);
    t16 = (t26 * 1);
    t16 = (t16 + 1);
    t25 = (t24 + 12U);
    *((unsigned int *)t25) = t16;
    t20 = xsi_base_array_concat(t20, t21, t22, (char)97, t8, t13, (char)97, t12, t23, (char)101);
    t25 = (t0 + 11588);
    t30 = (t0 + 7200);
    t32 = (t31 + 0U);
    t33 = (t32 + 0U);
    *((int *)t33) = 0;
    t33 = (t32 + 4U);
    *((int *)t33) = 19;
    t33 = (t32 + 8U);
    *((int *)t33) = 1;
    t34 = (19 - 0);
    t16 = (t34 * 1);
    t16 = (t16 + 1);
    t33 = (t32 + 12U);
    *((unsigned int *)t33) = t16;
    t28 = xsi_base_array_concat(t28, t29, t30, (char)97, t20, t21, (char)97, t25, t31, (char)101);
    t33 = (t0 + 11608);
    t38 = (t0 + 7200);
    t40 = (t39 + 0U);
    t41 = (t40 + 0U);
    *((int *)t41) = 0;
    t41 = (t40 + 4U);
    *((int *)t41) = 19;
    t41 = (t40 + 8U);
    *((int *)t41) = 1;
    t42 = (19 - 0);
    t16 = (t42 * 1);
    t16 = (t16 + 1);
    t41 = (t40 + 12U);
    *((unsigned int *)t41) = t16;
    t36 = xsi_base_array_concat(t36, t37, t38, (char)97, t28, t29, (char)97, t33, t39, (char)101);
    t41 = (t0 + 11628);
    t46 = (t0 + 7200);
    t48 = (t47 + 0U);
    t49 = (t48 + 0U);
    *((int *)t49) = 0;
    t49 = (t48 + 4U);
    *((int *)t49) = 19;
    t49 = (t48 + 8U);
    *((int *)t49) = 1;
    t50 = (19 - 0);
    t16 = (t50 * 1);
    t16 = (t16 + 1);
    t49 = (t48 + 12U);
    *((unsigned int *)t49) = t16;
    t44 = xsi_base_array_concat(t44, t45, t46, (char)97, t36, t37, (char)97, t41, t47, (char)101);
    t49 = (t0 + 11648);
    t54 = (t0 + 7200);
    t56 = (t55 + 0U);
    t57 = (t56 + 0U);
    *((int *)t57) = 0;
    t57 = (t56 + 4U);
    *((int *)t57) = 19;
    t57 = (t56 + 8U);
    *((int *)t57) = 1;
    t58 = (19 - 0);
    t16 = (t58 * 1);
    t16 = (t16 + 1);
    t57 = (t56 + 12U);
    *((unsigned int *)t57) = t16;
    t52 = xsi_base_array_concat(t52, t53, t54, (char)97, t44, t45, (char)97, t49, t55, (char)101);
    t57 = (t0 + 11668);
    t62 = (t0 + 7200);
    t64 = (t63 + 0U);
    t65 = (t64 + 0U);
    *((int *)t65) = 0;
    t65 = (t64 + 4U);
    *((int *)t65) = 19;
    t65 = (t64 + 8U);
    *((int *)t65) = 1;
    t66 = (19 - 0);
    t16 = (t66 * 1);
    t16 = (t16 + 1);
    t65 = (t64 + 12U);
    *((unsigned int *)t65) = t16;
    t60 = xsi_base_array_concat(t60, t61, t62, (char)97, t52, t53, (char)97, t57, t63, (char)101);
    t65 = (t0 + 11688);
    t70 = (t0 + 7200);
    t72 = (t71 + 0U);
    t73 = (t72 + 0U);
    *((int *)t73) = 0;
    t73 = (t72 + 4U);
    *((int *)t73) = 19;
    t73 = (t72 + 8U);
    *((int *)t73) = 1;
    t74 = (19 - 0);
    t16 = (t74 * 1);
    t16 = (t16 + 1);
    t73 = (t72 + 12U);
    *((unsigned int *)t73) = t16;
    t68 = xsi_base_array_concat(t68, t69, t70, (char)97, t60, t61, (char)97, t65, t71, (char)101);
    t73 = (t0 + 11708);
    t78 = (t0 + 7200);
    t80 = (t79 + 0U);
    t81 = (t80 + 0U);
    *((int *)t81) = 0;
    t81 = (t80 + 4U);
    *((int *)t81) = 19;
    t81 = (t80 + 8U);
    *((int *)t81) = 1;
    t82 = (19 - 0);
    t16 = (t82 * 1);
    t16 = (t16 + 1);
    t81 = (t80 + 12U);
    *((unsigned int *)t81) = t16;
    t76 = xsi_base_array_concat(t76, t77, t78, (char)97, t68, t69, (char)97, t73, t79, (char)101);
    t81 = (t0 + 11728);
    t86 = (t0 + 7200);
    t88 = (t87 + 0U);
    t89 = (t88 + 0U);
    *((int *)t89) = 0;
    t89 = (t88 + 4U);
    *((int *)t89) = 19;
    t89 = (t88 + 8U);
    *((int *)t89) = 1;
    t90 = (19 - 0);
    t16 = (t90 * 1);
    t16 = (t16 + 1);
    t89 = (t88 + 12U);
    *((unsigned int *)t89) = t16;
    t84 = xsi_base_array_concat(t84, t85, t86, (char)97, t76, t77, (char)97, t81, t87, (char)101);
    t89 = (t0 + 11748);
    t94 = (t0 + 7200);
    t96 = (t95 + 0U);
    t97 = (t96 + 0U);
    *((int *)t97) = 0;
    t97 = (t96 + 4U);
    *((int *)t97) = 19;
    t97 = (t96 + 8U);
    *((int *)t97) = 1;
    t98 = (19 - 0);
    t16 = (t98 * 1);
    t16 = (t16 + 1);
    t97 = (t96 + 12U);
    *((unsigned int *)t97) = t16;
    t92 = xsi_base_array_concat(t92, t93, t94, (char)97, t84, t85, (char)97, t89, t95, (char)101);
    t97 = (t0 + 11768);
    t102 = (t0 + 7200);
    t104 = (t103 + 0U);
    t105 = (t104 + 0U);
    *((int *)t105) = 0;
    t105 = (t104 + 4U);
    *((int *)t105) = 19;
    t105 = (t104 + 8U);
    *((int *)t105) = 1;
    t106 = (19 - 0);
    t16 = (t106 * 1);
    t16 = (t16 + 1);
    t105 = (t104 + 12U);
    *((unsigned int *)t105) = t16;
    t100 = xsi_base_array_concat(t100, t101, t102, (char)97, t92, t93, (char)97, t97, t103, (char)101);
    t105 = (t0 + 11788);
    t110 = (t0 + 7200);
    t112 = (t111 + 0U);
    t113 = (t112 + 0U);
    *((int *)t113) = 0;
    t113 = (t112 + 4U);
    *((int *)t113) = 19;
    t113 = (t112 + 8U);
    *((int *)t113) = 1;
    t114 = (19 - 0);
    t16 = (t114 * 1);
    t16 = (t16 + 1);
    t113 = (t112 + 12U);
    *((unsigned int *)t113) = t16;
    t108 = xsi_base_array_concat(t108, t109, t110, (char)97, t100, t101, (char)97, t105, t111, (char)101);
    t16 = (20U + 20U);
    t115 = (t16 + 20U);
    t116 = (t115 + 20U);
    t117 = (t116 + 20U);
    t118 = (t117 + 20U);
    t119 = (t118 + 20U);
    t120 = (t119 + 20U);
    t121 = (t120 + 20U);
    t122 = (t121 + 20U);
    t123 = (t122 + 20U);
    t124 = (t123 + 20U);
    t125 = (t124 + 20U);
    t126 = (t125 + 20U);
    t3 = (280U != t126);
    if (t3 == 1)
        goto LAB5;

LAB6:    t113 = (t0 + 6608);
    t127 = (t113 + 56U);
    t128 = *((char **)t127);
    t129 = (t128 + 56U);
    t130 = *((char **)t129);
    memcpy(t130, t108, 280U);
    xsi_driver_first_trans_delta(t113, 0U, 280U, 0LL);
    goto LAB3;

LAB5:    xsi_size_not_matching(280U, t126, 0);
    goto LAB6;

LAB7:    xsi_set_current_line(93, ng0);
    t2 = (t0 + 3272U);
    t4 = *((char **)t2);
    t7 = ((IEEE_P_2592010699) + 4024);
    t8 = (t0 + 10400U);
    t2 = xsi_base_array_concat(t2, t13, t7, (char)99, (unsigned char)2, (char)97, t4, t8, (char)101);
    t15 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t2, t13);
    t9 = (t0 + 3928U);
    t10 = *((char **)t9);
    t9 = (t10 + 0);
    *((int *)t9) = t15;
    xsi_set_current_line(94, ng0);
    t1 = (t0 + 2632U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t5 = (t3 == (unsigned char)3);
    if (t5 != 0)
        goto LAB9;

LAB11:
LAB10:    goto LAB3;

LAB9:    xsi_set_current_line(95, ng0);
    t1 = (t0 + 1032U);
    t4 = *((char **)t1);
    t1 = (t0 + 3928U);
    t7 = *((char **)t1);
    t15 = *((int *)t7);
    t18 = (t15 - 0);
    t16 = (t18 * 1);
    xsi_vhdl_check_range_of_index(0, 1023, 1, t15);
    t115 = (1U * t16);
    t116 = (0 + t115);
    t1 = (t4 + t116);
    t6 = *((unsigned char *)t1);
    t8 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t13, ((int)(t6)), 8);
    t9 = (t13 + 12U);
    t117 = *((unsigned int *)t9);
    t117 = (t117 * 1U);
    t131 = (8U != t117);
    if (t131 == 1)
        goto LAB12;

LAB13:    t10 = (t0 + 6544);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t19 = (t12 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t8, 8U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(96, ng0);
    t1 = (t0 + 2792U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t5 = (t3 == (unsigned char)3);
    if (t5 != 0)
        goto LAB14;

LAB16:
LAB15:    goto LAB10;

LAB12:    xsi_size_not_matching(8U, t117, 0);
    goto LAB13;

LAB14:    xsi_set_current_line(97, ng0);
    t1 = (t0 + 3112U);
    t4 = *((char **)t1);
    t7 = ((IEEE_P_2592010699) + 4024);
    t8 = (t0 + 10384U);
    t1 = xsi_base_array_concat(t1, t13, t7, (char)99, (unsigned char)2, (char)97, t4, t8, (char)101);
    t15 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t1, t13);
    t6 = ((unsigned char)(t15));
    t9 = (t0 + 3928U);
    t10 = *((char **)t9);
    t18 = *((int *)t10);
    t26 = (t18 - 0);
    t16 = (t26 * 1);
    t115 = (1 * t16);
    t116 = (0U + t115);
    t9 = (t0 + 6608);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t12 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = t6;
    xsi_driver_first_trans_delta(t9, t116, 1, 0LL);
    goto LAB15;

}

void work_a_3933276739_0479980441_sub_729878686_1761483606(char *t0, char *t1, int t2)
{
    char t4[8];
    char *t5;
    int t6;
    int t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    unsigned char t25;
    unsigned char t26;
    int t27;

LAB0:    t5 = (t4 + 4U);
    *((int *)t5) = t2;
    t6 = 1;
    t7 = t2;

LAB2:    if (t6 <= t7)
        goto LAB3;

LAB5:
LAB1:    return;
LAB3:    t8 = (t0 + 1472U);
    xsi_add_dynamic_wait(t1, t8, -1, -1);

LAB9:    t9 = (t1 + 224U);
    t9 = *((char **)t9);
    xsi_wp_set_status(t9, 1);
    t10 = (t1 + 88U);
    t11 = *((char **)t10);
    t12 = (t11 + 2480U);
    *((unsigned int *)t12) = 1U;
    t13 = (t1 + 88U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    getcontext(t15);
    t16 = (t1 + 88U);
    t17 = *((char **)t16);
    t18 = (t17 + 2480U);
    t19 = *((unsigned int *)t18);
    if (t19 == 1)
        goto LAB10;

LAB11:    t20 = (t1 + 88U);
    t21 = *((char **)t20);
    t22 = (t21 + 2480U);
    *((unsigned int *)t22) = 3U;

LAB7:
LAB8:    t23 = (t0 + 1512U);
    t24 = *((char **)t23);
    t25 = *((unsigned char *)t24);
    t26 = (t25 == (unsigned char)3);
    if (t26 == 1)
        goto LAB6;
    else
        goto LAB9;

LAB4:    if (t6 == t7)
        goto LAB5;

LAB12:    t27 = (t6 + 1);
    t6 = t27;
    goto LAB2;

LAB6:    xsi_remove_dynamic_wait(t1, t8);
    goto LAB4;

LAB10:    xsi_saveStackAndSuspend(t1);
    goto LAB11;

}

void work_a_3933276739_0479980441_sub_3060801988_1761483606(char *t0, char *t1, int t2, int t3)
{
    char t5[16];
    char t13[16];
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    unsigned int t17;
    unsigned char t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned char t27;

LAB0:    t6 = (t5 + 4U);
    *((int *)t6) = t2;
    t7 = (t5 + 8U);
    *((int *)t7) = t3;
    t8 = (t0 + 6672);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = (unsigned char)2;
    xsi_driver_first_trans_fast(t8);
    t8 = (t0 + 10352U);
    t9 = (t8 + 12U);
    t14 = *((unsigned int *)t9);
    t10 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t13, t2, ((t14)));
    t11 = (t0 + 10352U);
    t12 = (t11 + 12U);
    t15 = *((unsigned int *)t12);
    t15 = (t15 * 1U);
    t16 = (t13 + 12U);
    t17 = *((unsigned int *)t16);
    t17 = (t17 * 1U);
    t18 = (t15 != t17);
    if (t18 == 1)
        goto LAB2;

LAB3:    t19 = (t0 + 6736);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t0 + 10352U);
    t25 = (t24 + 12U);
    t26 = *((unsigned int *)t25);
    t26 = (t26 * 1U);
    memcpy(t23, t10, t26);
    xsi_driver_first_trans_fast(t19);
    t8 = (t0 + 10336U);
    t9 = (t8 + 12U);
    t14 = *((unsigned int *)t9);
    t10 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t13, t3, ((t14)));
    t11 = (t0 + 10336U);
    t12 = (t11 + 12U);
    t15 = *((unsigned int *)t12);
    t15 = (t15 * 1U);
    t16 = (t13 + 12U);
    t17 = *((unsigned int *)t16);
    t17 = (t17 * 1U);
    t18 = (t15 != t17);
    if (t18 == 1)
        goto LAB4;

LAB5:    t19 = (t0 + 6800);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t0 + 10336U);
    t25 = (t24 + 12U);
    t26 = *((unsigned int *)t25);
    t26 = (t26 * 1U);
    memcpy(t23, t10, t26);
    xsi_driver_first_trans_fast(t19);
    t8 = (t0 + 6864);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = (unsigned char)3;
    xsi_driver_first_trans_fast(t8);
    work_a_3933276739_0479980441_sub_729878686_1761483606(t0, t1, 1);
    t8 = (t0 + 6864);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = (unsigned char)2;
    xsi_driver_first_trans_fast(t8);
    work_a_3933276739_0479980441_sub_729878686_1761483606(t0, t1, 1);

LAB6:    t8 = (t0 + 2152U);
    t9 = *((char **)t8);
    t18 = *((unsigned char *)t9);
    t27 = (t18 == (unsigned char)2);
    if (t27 != 0)
        goto LAB7;

LAB9:    t8 = (t0 + 6672);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = (unsigned char)3;
    xsi_driver_first_trans_fast(t8);

LAB1:    return;
LAB2:    xsi_size_not_matching(t15, t17, 0);
    goto LAB3;

LAB4:    xsi_size_not_matching(t15, t17, 0);
    goto LAB5;

LAB7:    work_a_3933276739_0479980441_sub_729878686_1761483606(t0, t1, 1);
    goto LAB6;

LAB8:;
}

static void work_a_3933276739_0479980441_p_4(char *t0)
{
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

LAB0:    t1 = (t0 + 5904U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(128, ng0);
    t2 = (t0 + 6672);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(129, ng0);

LAB6:    t2 = (t0 + 6272);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    t3 = (t0 + 6272);
    *((int *)t3) = 0;
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 5712);
    work_a_3933276739_0479980441_sub_3060801988_1761483606(t0, t2, 0, 20);
    xsi_set_current_line(133, ng0);
    t2 = (t0 + 5712);
    work_a_3933276739_0479980441_sub_3060801988_1761483606(t0, t2, 20, 20);
    xsi_set_current_line(134, ng0);
    t2 = (t0 + 5712);
    work_a_3933276739_0479980441_sub_3060801988_1761483606(t0, t2, 40, 20);
    xsi_set_current_line(139, ng0);
    t2 = (t0 + 6928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(140, ng0);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t7 = *((unsigned char *)t4);
    t3 = (t0 + 3568U);
    t5 = *((char **)t3);
    t8 = *((unsigned char *)t5);
    t9 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t8);
    t10 = (t7 == t9);
    if (t10 == 1)
        goto LAB4;
    else
        goto LAB6;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}


extern void work_a_3933276739_0479980441_init()
{
	static char *pe[] = {(void *)work_a_3933276739_0479980441_p_0,(void *)work_a_3933276739_0479980441_p_1,(void *)work_a_3933276739_0479980441_p_2,(void *)work_a_3933276739_0479980441_p_3,(void *)work_a_3933276739_0479980441_p_4};
	static char *se[] = {(void *)work_a_3933276739_0479980441_sub_729878686_1761483606,(void *)work_a_3933276739_0479980441_sub_3060801988_1761483606};
	xsi_register_didat("work_a_3933276739_0479980441", "isim/insertcore_tb_isim_beh.exe.sim/work/a_3933276739_0479980441.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
