/*
** ###################################################################
**     This code is generated by the Device Initialization Tool.
**     It is overwritten during code generation.
**     USER MODIFICATION ARE PRESERVED ONLY INSIDE EXPLICITLY MARKED SECTIONS.
**
**     Project     : DeviceInitialization
**     Processor   : MKL25Z128VLH4
**     Version     : Component 01.000, Driver 01.04, CPU db: 3.00.000
**     Datasheet   : KL25RM, Rev.1, Jun 2012
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-12-03, 16:55, # CodeGen: 0
**     Abstract    :
**
**     Contents    :
**         Function "MCU_init" initializes selected peripherals
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################
*/

#ifndef __DeviceInitialization_H
#define __DeviceInitialization_H 1

/* Include shared modules, which are used for whole project */


/* User declarations and definitions */
/*   Code, declarations and definitions here will be preserved during code generation */
/* End of user declarations and definitions */


#if !defined(PE_ISR)
  #define PE_ISR(ISR_name) void __attribute__ ((interrupt)) ISR_name(void)
#endif

void __attribute__ ((constructor)) __init_hardware(void);
/*
** ===================================================================
**     Method      :  __init_hardware (component MKL25Z128LH4)
**
**     Description :
**         Initialization code for CPU core and a clock source.
** ===================================================================
*/


void MCU_init(void);
/*
** ===================================================================
**     Method      :  MCU_init (component MKL25Z128LH4)
**
**     Description :
**         Device initialization code for selected peripherals.
** ===================================================================
*/


PE_ISR(isr_default);
/*
** ===================================================================
**     Interrupt handler : isr_default
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



PE_ISR(isrINT_NMI);
/*
** ===================================================================
**     Interrupt handler : isrINT_NMI
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/


/* My ISRs*/

PE_ISR(PORTA_ISR);
PE_ISR(systick);
PE_ISR(llwu);



/* END DeviceInitialization */

#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
