/*
 * rtc.c
 *
 *  Created on: 2013-01-01
 *      Author: Bryce Klippenstein
 *                Carmanah Signs inc.
 */

#include "rtc.h"
#include "time.h"
#include "uart.h"

volatile struct tm calTime;

void rtcInit(void)
{
    extern volatile struct tm calTime;
    SIM_SCGC6 |= (uint32_t)0x20000000; // Turn on the RTC.

    //THe following actions configure port E0 to output a 1kHz signal based on the real-time clock.
    SIM_SCGC5 |= (uint32_t)0x00002000; // Turn on portE.
    SIM_SCGC5 |= (uint32_t)0x00000800; // Turn on portC.
    PORTE_PCR0 |= (uint32_t)0x00000402; // Set PTE0 to ALT4. With Pullup.
    PORTC_PCR3 |= (uint32_t)0x00000502; // Set PTC3 to Alt5 with pullup.
    SIM_SOPT2 |= (uint32_t)0x00000060; //

    RTC_IER |= 0x00000010; //Enable an interrupt to fire every second for debugging.

    calTime.tm_sec = 0;
    calTime.tm_min = 35;
    calTime.tm_hour = 11;
    calTime.tm_mday = 22;
    calTime.tm_mon = 0;
    calTime.tm_year = 113;
    calTime.tm_isdst = -1;
}

void rtcSet(time_t unixTime)
{
    RTC_TSR = unixTime;
}

time_t rtcGet(void)
{
    time_t now = 0;
    now = RTC_TSR;
    return(now);
}

void rtcStart(void)
{
    RTC_SR |= 0x0010;
}

void rtcStop(void)
{
    RTC_SR &= ~0x0010;
}

void printTime(void)
{
    time_t now = 0;
    now = rtcGet();
    uart0Send_n(ctime(&now));
}
