/*******************************************************************************

Author : Emiliano Mazza
Version : 1.0
Created on Date : 15/18/2020
Last update     : 31/01/2023

CopyRight 2006-2015 all rights are reserved

THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE AUTHOR SHALL NOT,
IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.

This Header contains all functions for used with CCP2 module
 
- Frequency counter. 

*******************************************************************************/

#ifndef CCP2_H
#define	CCP2_H

#include <xc.h>
#include "globals.h"

#include <CCPLIb.h>

/**
 * @brief Take the time capture and return to the frequency in KHz
 *
 * @param capture_time CCPx capture Time
 * @param capture_mode Capture mode used :
 * 
 * @note
 * CCPx_CAPTURE_1_FALL, CCPx_CAPTURE_1_RISE
 * CCPx_CAPTURE_4_RISE, CCPx_CAPTURE_16_RISE
 * 
 * @param timer_prescale Is ratio to set to Timer's prescaler.
 * 
 * @note
 * CCPx_TIMER_PRESCALE_1, CCPx_TIMER_PRESCALE_2
 * CCPx_TIMER_PRESCALE_4, CCPx_TIMER_PRESCALE_8
 *
 * @return The Signal frequency 
 * 
 */
volatile double getFrequencyFromTimer(uint16_t capture_time, uint8_t capture_mode, uint8_t timer_prescale);

/**
 * @brief
 * This macro function configure and initialize the CCP module
 * in capture mode for every 16th rising edge and
 * Timer prescaler a 1:1
 * 
 * Parameters for capture HVCO Frequencies
 * 
 * @note
 * CCPx_CAPTURE_16_RISE  Capture every 16th rising edge
 * CCPx_TIMER_PRESCALE_1 1:1 Prescale
 *
 * @param void
 *
 * @return void
 * 
 */
void CCP2_HVCO_init (void);

/**
 * @brief
 * This macro function configure and initialize the CCP module
 * in capture mode for every 4th rising edge and
 * Timer prescaler a 1:1
 * 
 * Parameters for capture VCO Frequencies
 * 
 * @note
 * CCPx_CAPTURE_4_RISE  Capture every 4th rising edge
 * CCPx_TIMER_PRESCALE_1 1:1 Prescale
 *
 * @param void
 *
 * @return void
 * 
 */
void CCP2_VCO_init (void);

/**
 * @brief
 * This macro function configure and initialize the CCP module
 * in capture mode for every rising edge and
 * Timer prescaler a 1:4
 * 
 * Parameters for capture LFO Frequencies
 * 
 * @note
 * CCPx_CAPTURE_1_RISE   Capture every rising edge
 * CCPx_TIMER_PRESCALE_4 1:4 Prescale
 *
 * @param void
 *
 * @return void
 * 
 */
void CCP2_LFO_init (void);

/**
 * @brief
 * This macro function configure and initialize the CCP module
 * in capture mode for every rising edge and
 * Timer prescaler a 1:8
 * 
 * Parameters for capture VLFO Frequencies
 * 
 * @note
 * CCPx_CAPTURE_1_RISE   Capture every rising edge
 * CCPx_TIMER_PRESCALE_8 1:8 Prescale
 *
 * @param void
 *
 * @return void
 * 
 */
void CCP2_VLFO_init (void);

/**
 * @brief This macro function is called in interrupt request
 *
 * @param uiTimer16OverflowCounter How many times has the 16 bit Timer overflow.
 *
 * @return The 32bit value of (uiTimer16OverflowCounter * 64K) + CCP2 last register.
 * 
 */
uint32_t CCP2CaptureTask(uint16_t uiTimer16OverflowCounter);

#endif	/* CCP2_H */

