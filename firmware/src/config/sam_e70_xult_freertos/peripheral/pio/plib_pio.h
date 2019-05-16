/*******************************************************************************
  PIO PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_pio.h

  Summary:
    PIO PLIB Header File

  Description:
    This library provides an interface to control and interact with Parallel
    Input/Output controller (PIO) module.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#ifndef PLIB_PIO_H
#define PLIB_PIO_H

#include "device.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data types and constants
// *****************************************************************************
// *****************************************************************************


/*** Macros for BUTTON_3 pin ***/
#define BUTTON_3_Set()               (PIOC_REGS->PIO_SODR = (1<<13))
#define BUTTON_3_Clear()             (PIOC_REGS->PIO_CODR = (1<<13))
#define BUTTON_3_Toggle()            (PIOC_REGS->PIO_ODSR ^= (1<<13))
#define BUTTON_3_Get()               ((PIOC_REGS->PIO_PDSR >> 13) & 0x1)
#define BUTTON_3_OutputEnable()      (PIOC_REGS->PIO_OER = (1<<13))
#define BUTTON_3_InputEnable()       (PIOC_REGS->PIO_ODR = (1<<13))
#define BUTTON_3_PIN                  PIO_PIN_PC13

/*** Macros for BUTTON_2 pin ***/
#define BUTTON_2_Set()               (PIOD_REGS->PIO_SODR = (1<<30))
#define BUTTON_2_Clear()             (PIOD_REGS->PIO_CODR = (1<<30))
#define BUTTON_2_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<30))
#define BUTTON_2_Get()               ((PIOD_REGS->PIO_PDSR >> 30) & 0x1)
#define BUTTON_2_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<30))
#define BUTTON_2_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<30))
#define BUTTON_2_PIN                  PIO_PIN_PD30

/*** Macros for DISPLAY_SS_N pin ***/
#define DISPLAY_SS_N_Set()               (PIOD_REGS->PIO_SODR = (1<<27))
#define DISPLAY_SS_N_Clear()             (PIOD_REGS->PIO_CODR = (1<<27))
#define DISPLAY_SS_N_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<27))
#define DISPLAY_SS_N_Get()               ((PIOD_REGS->PIO_PDSR >> 27) & 0x1)
#define DISPLAY_SS_N_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<27))
#define DISPLAY_SS_N_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<27))
#define DISPLAY_SS_N_PIN                  PIO_PIN_PD27

/*** Macros for LED_2 pin ***/
#define LED_2_Set()               (PIOD_REGS->PIO_SODR = (1<<26))
#define LED_2_Clear()             (PIOD_REGS->PIO_CODR = (1<<26))
#define LED_2_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<26))
#define LED_2_Get()               ((PIOD_REGS->PIO_PDSR >> 26) & 0x1)
#define LED_2_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<26))
#define LED_2_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<26))
#define LED_2_PIN                  PIO_PIN_PD26

/*** Macros for DISPLAY_RESET pin ***/
#define DISPLAY_RESET_Set()               (PIOA_REGS->PIO_SODR = (1<<24))
#define DISPLAY_RESET_Clear()             (PIOA_REGS->PIO_CODR = (1<<24))
#define DISPLAY_RESET_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<24))
#define DISPLAY_RESET_Get()               ((PIOA_REGS->PIO_PDSR >> 24) & 0x1)
#define DISPLAY_RESET_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<24))
#define DISPLAY_RESET_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<24))
#define DISPLAY_RESET_PIN                  PIO_PIN_PA24

/*** Macros for SWITCH pin ***/
#define SWITCH_Set()               (PIOA_REGS->PIO_SODR = (1<<11))
#define SWITCH_Clear()             (PIOA_REGS->PIO_CODR = (1<<11))
#define SWITCH_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<11))
#define SWITCH_Get()               ((PIOA_REGS->PIO_PDSR >> 11) & 0x1)
#define SWITCH_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<11))
#define SWITCH_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<11))
#define SWITCH_PIN                  PIO_PIN_PA11

/*** Macros for LED2 pin ***/
#define LED2_Set()               (PIOA_REGS->PIO_SODR = (1<<5))
#define LED2_Clear()             (PIOA_REGS->PIO_CODR = (1<<5))
#define LED2_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<5))
#define LED2_Get()               ((PIOA_REGS->PIO_PDSR >> 5) & 0x1)
#define LED2_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<5))
#define LED2_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<5))
#define LED2_PIN                  PIO_PIN_PA5

/*** Macros for LED1 pin ***/
#define LED1_Set()               (PIOC_REGS->PIO_SODR = (1<<8))
#define LED1_Clear()             (PIOC_REGS->PIO_CODR = (1<<8))
#define LED1_Toggle()            (PIOC_REGS->PIO_ODSR ^= (1<<8))
#define LED1_Get()               ((PIOC_REGS->PIO_PDSR >> 8) & 0x1)
#define LED1_OutputEnable()      (PIOC_REGS->PIO_OER = (1<<8))
#define LED1_InputEnable()       (PIOC_REGS->PIO_ODR = (1<<8))
#define LED1_PIN                  PIO_PIN_PC8

/*** Macros for BUTTON_1 pin ***/
#define BUTTON_1_Set()               (PIOA_REGS->PIO_SODR = (1<<2))
#define BUTTON_1_Clear()             (PIOA_REGS->PIO_CODR = (1<<2))
#define BUTTON_1_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<2))
#define BUTTON_1_Get()               ((PIOA_REGS->PIO_PDSR >> 2) & 0x1)
#define BUTTON_1_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<2))
#define BUTTON_1_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<2))
#define BUTTON_1_PIN                  PIO_PIN_PA2

/*** Macros for LED_3 pin ***/
#define LED_3_Set()               (PIOD_REGS->PIO_SODR = (1<<11))
#define LED_3_Clear()             (PIOD_REGS->PIO_CODR = (1<<11))
#define LED_3_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<11))
#define LED_3_Get()               ((PIOD_REGS->PIO_PDSR >> 11) & 0x1)
#define LED_3_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<11))
#define LED_3_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<11))
#define LED_3_PIN                  PIO_PIN_PD11

/*** Macros for DATA_CMD_SEL pin ***/
#define DATA_CMD_SEL_Set()               (PIOA_REGS->PIO_SODR = (1<<6))
#define DATA_CMD_SEL_Clear()             (PIOA_REGS->PIO_CODR = (1<<6))
#define DATA_CMD_SEL_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<6))
#define DATA_CMD_SEL_Get()               ((PIOA_REGS->PIO_PDSR >> 6) & 0x1)
#define DATA_CMD_SEL_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<6))
#define DATA_CMD_SEL_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<6))
#define DATA_CMD_SEL_PIN                  PIO_PIN_PA6

/*** Macros for LED_1 pin ***/
#define LED_1_Set()               (PIOC_REGS->PIO_SODR = (1<<19))
#define LED_1_Clear()             (PIOC_REGS->PIO_CODR = (1<<19))
#define LED_1_Toggle()            (PIOC_REGS->PIO_ODSR ^= (1<<19))
#define LED_1_Get()               ((PIOC_REGS->PIO_PDSR >> 19) & 0x1)
#define LED_1_OutputEnable()      (PIOC_REGS->PIO_OER = (1<<19))
#define LED_1_InputEnable()       (PIOC_REGS->PIO_ODR = (1<<19))
#define LED_1_PIN                  PIO_PIN_PC19

/*** Macros for LED3 pin ***/
#define LED3_Set()               (PIOB_REGS->PIO_SODR = (1<<8))
#define LED3_Clear()             (PIOB_REGS->PIO_CODR = (1<<8))
#define LED3_Toggle()            (PIOB_REGS->PIO_ODSR ^= (1<<8))
#define LED3_Get()               ((PIOB_REGS->PIO_PDSR >> 8) & 0x1)
#define LED3_OutputEnable()      (PIOB_REGS->PIO_OER = (1<<8))
#define LED3_InputEnable()       (PIOB_REGS->PIO_ODR = (1<<8))
#define LED3_PIN                  PIO_PIN_PB8


// *****************************************************************************
/* PIO Port

  Summary:
    Identifies the available PIO Ports.

  Description:
    This enumeration identifies the available PIO Ports.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all ports are available on all devices.  Refer to the specific
    device data sheet to determine which ports are supported.
*/

typedef enum
{
    PIO_PORT_A = PIOA_BASE_ADDRESS,
    PIO_PORT_B = PIOB_BASE_ADDRESS,
    PIO_PORT_C = PIOC_BASE_ADDRESS,
    PIO_PORT_D = PIOD_BASE_ADDRESS,
    PIO_PORT_E = PIOE_BASE_ADDRESS
} PIO_PORT;

// *****************************************************************************
/* PIO Port Pins

  Summary:
    Identifies the available PIO port pins.

  Description:
    This enumeration identifies the available PIO port pins.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all pins are available on all devices.  Refer to the specific
    device data sheet to determine which pins are supported.
*/

typedef enum
{
    PIO_PIN_PA0 = 0,
    PIO_PIN_PA1 = 1,
    PIO_PIN_PA2 = 2,
    PIO_PIN_PA3 = 3,
    PIO_PIN_PA4 = 4,
    PIO_PIN_PA5 = 5,
    PIO_PIN_PA6 = 6,
    PIO_PIN_PA7 = 7,
    PIO_PIN_PA8 = 8,
    PIO_PIN_PA9 = 9,
    PIO_PIN_PA10 = 10,
    PIO_PIN_PA11 = 11,
    PIO_PIN_PA12 = 12,
    PIO_PIN_PA13 = 13,
    PIO_PIN_PA14 = 14,
    PIO_PIN_PA15 = 15,
    PIO_PIN_PA16 = 16,
    PIO_PIN_PA17 = 17,
    PIO_PIN_PA18 = 18,
    PIO_PIN_PA19 = 19,
    PIO_PIN_PA20 = 20,
    PIO_PIN_PA21 = 21,
    PIO_PIN_PA22 = 22,
    PIO_PIN_PA23 = 23,
    PIO_PIN_PA24 = 24,
    PIO_PIN_PA25 = 25,
    PIO_PIN_PA26 = 26,
    PIO_PIN_PA27 = 27,
    PIO_PIN_PA28 = 28,
    PIO_PIN_PA29 = 29,
    PIO_PIN_PA30 = 30,
    PIO_PIN_PA31 = 31,
    PIO_PIN_PB0 = 32,
    PIO_PIN_PB1 = 33,
    PIO_PIN_PB2 = 34,
    PIO_PIN_PB3 = 35,
    PIO_PIN_PB4 = 36,
    PIO_PIN_PB5 = 37,
    PIO_PIN_PB6 = 38,
    PIO_PIN_PB7 = 39,
    PIO_PIN_PB8 = 40,
    PIO_PIN_PB9 = 41,
    PIO_PIN_PB12 = 44,
    PIO_PIN_PB13 = 45,
    PIO_PIN_PC0 = 64,
    PIO_PIN_PC1 = 65,
    PIO_PIN_PC2 = 66,
    PIO_PIN_PC3 = 67,
    PIO_PIN_PC4 = 68,
    PIO_PIN_PC5 = 69,
    PIO_PIN_PC6 = 70,
    PIO_PIN_PC7 = 71,
    PIO_PIN_PC8 = 72,
    PIO_PIN_PC9 = 73,
    PIO_PIN_PC10 = 74,
    PIO_PIN_PC11 = 75,
    PIO_PIN_PC12 = 76,
    PIO_PIN_PC13 = 77,
    PIO_PIN_PC14 = 78,
    PIO_PIN_PC15 = 79,
    PIO_PIN_PC16 = 80,
    PIO_PIN_PC17 = 81,
    PIO_PIN_PC18 = 82,
    PIO_PIN_PC19 = 83,
    PIO_PIN_PC20 = 84,
    PIO_PIN_PC21 = 85,
    PIO_PIN_PC22 = 86,
    PIO_PIN_PC23 = 87,
    PIO_PIN_PC24 = 88,
    PIO_PIN_PC25 = 89,
    PIO_PIN_PC26 = 90,
    PIO_PIN_PC27 = 91,
    PIO_PIN_PC28 = 92,
    PIO_PIN_PC29 = 93,
    PIO_PIN_PC30 = 94,
    PIO_PIN_PC31 = 95,
    PIO_PIN_PD0 = 96,
    PIO_PIN_PD1 = 97,
    PIO_PIN_PD2 = 98,
    PIO_PIN_PD3 = 99,
    PIO_PIN_PD4 = 100,
    PIO_PIN_PD5 = 101,
    PIO_PIN_PD6 = 102,
    PIO_PIN_PD7 = 103,
    PIO_PIN_PD8 = 104,
    PIO_PIN_PD9 = 105,
    PIO_PIN_PD10 = 106,
    PIO_PIN_PD11 = 107,
    PIO_PIN_PD12 = 108,
    PIO_PIN_PD13 = 109,
    PIO_PIN_PD14 = 110,
    PIO_PIN_PD15 = 111,
    PIO_PIN_PD16 = 112,
    PIO_PIN_PD17 = 113,
    PIO_PIN_PD18 = 114,
    PIO_PIN_PD19 = 115,
    PIO_PIN_PD20 = 116,
    PIO_PIN_PD21 = 117,
    PIO_PIN_PD22 = 118,
    PIO_PIN_PD23 = 119,
    PIO_PIN_PD24 = 120,
    PIO_PIN_PD25 = 121,
    PIO_PIN_PD26 = 122,
    PIO_PIN_PD27 = 123,
    PIO_PIN_PD28 = 124,
    PIO_PIN_PD29 = 125,
    PIO_PIN_PD30 = 126,
    PIO_PIN_PD31 = 127,
    PIO_PIN_PE0 = 128,
    PIO_PIN_PE1 = 129,
    PIO_PIN_PE2 = 130,
    PIO_PIN_PE3 = 131,
    PIO_PIN_PE4 = 132,
    PIO_PIN_PE5 = 133,

    /* This element should not be used in any of the PIO APIs.
       It will be used by other modules or application to denote that none of the PIO Pin is used */
    PIO_PIN_NONE = -1

} PIO_PIN;


void PIO_Initialize(void);

// *****************************************************************************
// *****************************************************************************
// Section: PIO Functions which operates on multiple pins of a port
// *****************************************************************************
// *****************************************************************************

uint32_t PIO_PortRead(PIO_PORT port);

void PIO_PortWrite(PIO_PORT port, uint32_t mask, uint32_t value);

uint32_t PIO_PortLatchRead ( PIO_PORT port );

void PIO_PortSet(PIO_PORT port, uint32_t mask);

void PIO_PortClear(PIO_PORT port, uint32_t mask);

void PIO_PortToggle(PIO_PORT port, uint32_t mask);

void PIO_PortInputEnable(PIO_PORT port, uint32_t mask);

void PIO_PortOutputEnable(PIO_PORT port, uint32_t mask);

// *****************************************************************************
// *****************************************************************************
// Section: PIO Functions which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

static inline void PIO_PinWrite(PIO_PIN pin, bool value)
{
    PIO_PortWrite(PIOA_BASE_ADDRESS + (0x200 * (pin>>5)), (uint32_t)(0x1) << (pin & 0x1f), (uint32_t)(value) << (pin & 0x1f));
}

static inline bool PIO_PinRead(PIO_PIN pin)
{
    return (bool)((PIO_PortRead(PIOA_BASE_ADDRESS + (0x200 * (pin>>5))) >> (pin & 0x1F)) & 0x1);
}

static inline bool PIO_PinLatchRead(PIO_PIN pin)
{
    return (bool)((PIO_PortLatchRead(PIOA_BASE_ADDRESS + (0x200 * (pin>>5))) >> (pin & 0x1F)) & 0x1);
}

static inline void PIO_PinToggle(PIO_PIN pin)
{
    PIO_PortToggle(PIOA_BASE_ADDRESS + (0x200 * (pin>>5)), 0x1 << (pin & 0x1F));
}

static inline void PIO_PinSet(PIO_PIN pin)
{
    PIO_PortSet(PIOA_BASE_ADDRESS + (0x200 * (pin>>5)), 0x1 << (pin & 0x1F));
}

static inline void PIO_PinClear(PIO_PIN pin)
{
    PIO_PortClear(PIOA_BASE_ADDRESS + (0x200 * (pin>>5)), 0x1 << (pin & 0x1F));
}

static inline void PIO_PinInputEnable(PIO_PIN pin)
{
    PIO_PortInputEnable(PIOA_BASE_ADDRESS + (0x200 * (pin>>5)), 0x1 << (pin & 0x1F));
}

static inline void PIO_PinOutputEnable(PIO_PIN pin)
{
    PIO_PortOutputEnable(PIOA_BASE_ADDRESS + (0x200 * (pin>>5)), 0x1 << (pin & 0x1F));
}


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END
#endif // PLIB_PIO_H
