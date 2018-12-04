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

#include "xsi.h"

struct XSI_INFO xsi_info;

char *IEEE_P_2592010699;
char *STD_STANDARD;
char *IEEE_P_3499444699;
char *IEEE_P_3620187407;
char *UNISIM_P_0947159679;
char *STD_TEXTIO;
char *IEEE_P_2717149903;
char *IEEE_P_1367372525;
char *UNISIM_P_3222816464;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    ieee_p_2592010699_init();
    ieee_p_3499444699_init();
    ieee_p_3620187407_init();
    unisim_p_0947159679_init();
    std_textio_init();
    ieee_p_2717149903_init();
    ieee_p_1367372525_init();
    unisim_p_3222816464_init();
    unisim_a_1836616293_3089378898_init();
    work_a_2999129483_0632001823_init();
    unisim_a_1205172842_3616886268_init();
    work_a_3669124147_2730021763_init();
    unisim_a_2121384304_3723259517_init();
    unisim_a_2261302797_3723259517_init();
    unisim_a_1941169844_3118875749_init();
    unisim_a_3833799735_3676810390_init();
    unisim_a_3062228385_3676810390_init();
    unisim_a_0188497665_3676810390_init();
    unisim_a_3755426337_3676810390_init();
    unisim_a_1947044788_3676810390_init();
    unisim_a_2421151189_3676810390_init();
    unisim_a_1180420372_3676810390_init();
    unisim_a_2363982922_3676810390_init();
    unisim_a_1232727138_3676810390_init();
    unisim_a_2519065512_3676810390_init();
    unisim_a_1450766165_3676810390_init();
    unisim_a_0105042994_3676810390_init();
    unisim_a_3333324666_3676810390_init();
    unisim_a_1483097298_3676810390_init();
    unisim_a_3482490113_3676810390_init();
    unisim_a_2729128116_3676810390_init();
    unisim_a_4264168962_3676810390_init();
    unisim_a_3791686227_3676810390_init();
    unisim_a_2356631957_3676810390_init();
    unisim_a_3024534166_3676810390_init();
    unisim_a_0094910559_3676810390_init();
    unisim_a_0350208134_1521797606_init();
    unisim_a_3519694068_2693788048_init();
    unisim_a_3208337549_3731405331_init();
    unisim_a_1093176041_3731405331_init();
    unisim_a_2629718892_3731405331_init();
    unisim_a_3506866874_3731405331_init();
    unisim_a_0900199298_3731405331_init();
    unisim_a_0028422682_3731405331_init();
    unisim_a_0006958716_3731405331_init();
    unisim_a_0587692967_3731405331_init();
    unisim_a_2622885206_3731405331_init();
    unisim_a_0868425105_1864968857_init();
    unisim_a_0891762854_3752513572_init();
    unisim_a_3822252837_3752513572_init();
    unisim_a_0576466149_3752513572_init();
    unisim_a_2161033271_3752513572_init();
    unisim_a_1646226234_1266530935_init();
    unisim_a_3484885994_2523279426_init();
    unisim_a_3055263662_1392679692_init();
    unisim_a_2001057742_2388994713_init();
    unisim_a_0039681122_1945201939_init();
    unisim_a_2496767846_3807856483_init();
    unisim_a_3163574381_0086195937_init();
    unisim_a_2425416179_1721142233_init();
    work_a_0962375630_2111220564_init();
    unisim_a_4192964655_0762929208_init();
    work_a_0477659144_2111220564_init();
    unisim_a_2086151099_1768247982_init();
    work_a_1450063494_0632001823_init();
    work_a_2351973497_2730021763_init();


    xsi_register_tops("work_a_2351973497_2730021763");

    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    STD_STANDARD = xsi_get_engine_memory("std_standard");
    IEEE_P_3499444699 = xsi_get_engine_memory("ieee_p_3499444699");
    IEEE_P_3620187407 = xsi_get_engine_memory("ieee_p_3620187407");
    UNISIM_P_0947159679 = xsi_get_engine_memory("unisim_p_0947159679");
    STD_TEXTIO = xsi_get_engine_memory("std_textio");
    IEEE_P_2717149903 = xsi_get_engine_memory("ieee_p_2717149903");
    IEEE_P_1367372525 = xsi_get_engine_memory("ieee_p_1367372525");
    UNISIM_P_3222816464 = xsi_get_engine_memory("unisim_p_3222816464");

    return xsi_run_simulation(argc, argv);

}
