/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mmi.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <string.h>
#include <stdio.h>
#include "mmi.h"
#include "../gfx_mono/gfx_definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
extern struct font sysfont;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the MMI_Initialize function.

    Application strings and buffers are be defined outside this structure.
 */

MMI_DATA mmiData;

const char VM_Items[][20] = {"1.Coca-Cola", "2.Diet-Coke", "3.Pepsi", "4.Dr Pepper", "5.Sprite", "6.Fanta", "7.Dasani"};
static unsigned int VM_Count[7] = {5, 9, 3, 8, 4, 1, 4};

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
 */

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
 */


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void MMI_Initialize ( void )

  Remarks:
    See prototype in mmi.h.
 */

void MMI_Initialize(void) {
    /* Place the App state machine in its initial state. */
    mmiData.state = MMI_STATE_INIT;



    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

/******************************************************************************
  Function:
    void MMI_Tasks ( void )

  Remarks:
    See prototype in mmi.h.
 */

void MMI_Tasks(void) {
    char Oled_Text[20];
    unsigned int CurrentIndex = 0;
    uint32_t xx1 = 15, yy1 = 15;

    /* Check the application's current state. */
    switch (mmiData.state) {
            /* Application's initial state. */
        case MMI_STATE_INIT:
        {
            bool appInitialized = true;

            gfx_mono_ssd1306_init();

            if (appInitialized) {

                mmiData.state = MMI_STATE_SERVICE_TASKS;
            }
            break;
        }

        case MMI_STATE_SERVICE_TASKS:
        {

            /****************************Circle to and fro***********************/
            for (unsigned int i = 0; i < 5; i++) {
                for (xx1 = 14; xx1 < (128 - 14); xx1 += 2) {
                    gfx_mono_generic_draw_circle(xx1, yy1, 14, GFX_PIXEL_SET, GFX_WHOLE);
                    vTaskDelay( pdMS_TO_TICKS( 5 ) );
                    gfx_mono_generic_draw_circle(xx1, yy1, 14, GFX_PIXEL_CLR, GFX_WHOLE);
                }

                for (xx1 = (128 - 15); xx1 > 14; xx1 -= 2) {
                    gfx_mono_generic_draw_circle(xx1, yy1, 14, GFX_PIXEL_SET, GFX_WHOLE);
                    vTaskDelay( pdMS_TO_TICKS( 5 ) );
                    gfx_mono_generic_draw_circle(xx1, yy1, 14, GFX_PIXEL_CLR, GFX_WHOLE);
                }
            }

            /**********************Text at the start*****************************/
            gfx_mono_draw_string("Rock and Roll\n"
                    "   ==> <==    ", 0, 0, &sysfont);
            vTaskDelay( pdMS_TO_TICKS( 3000 ) );

            gfx_mono_draw_filled_rect(0, 0, 128, 32, GFX_PIXEL_CLR);
            gfx_mono_draw_string("  Welcome to \n"
                    "  23075 IoT6 ", 0, 0, &sysfont);
            vTaskDelay( pdMS_TO_TICKS( 3000 ) );

            gfx_mono_draw_filled_rect(0, 0, 128, 32, GFX_PIXEL_CLR);
            gfx_mono_draw_string("Vending \n"
                    "      Machine", 0, 0, &sysfont);
            vTaskDelay( pdMS_TO_TICKS( 3000 ) );

            gfx_mono_draw_filled_rect(0, 0, 128, 32, GFX_PIXEL_CLR);
            gfx_mono_draw_string("B1-Up,B2-Down \n"
                    "   B3-Select Item  ", 0, 0, &sysfont);
            vTaskDelay( pdMS_TO_TICKS( 5000 ) );


            /*************Display VM ITEMs***************************************************/

            gfx_mono_draw_filled_rect(0, 0, 128, 32, GFX_PIXEL_CLR);
            gfx_mono_draw_string(VM_Items[CurrentIndex], 0, 0, &sysfont);
            sprintf(Oled_Text, "%d", VM_Count[CurrentIndex]);
            gfx_mono_draw_string(Oled_Text, 117, 3, &sysfont);
            gfx_mono_generic_draw_rect(112, 0, 16, 20, GFX_PIXEL_SET);
            while (1) {
                /***************B2-Scroll down for next item*******/
                if (BUTTON_2_Get() == 0) {
                    CurrentIndex = CurrentIndex + 1;
                    if (CurrentIndex > 6) {
                        CurrentIndex = 0;
                    }
                    gfx_mono_draw_filled_rect(0, 0, 128, 32, GFX_PIXEL_CLR);
                    gfx_mono_draw_string(VM_Items[CurrentIndex], 0, 0, &sysfont);
                    sprintf(Oled_Text, "%d", VM_Count[CurrentIndex]);
                    gfx_mono_draw_string(Oled_Text, 117, 0, &sysfont);
                    gfx_mono_generic_draw_rect(112, 0, 16, 20, GFX_PIXEL_SET);
                    LED_2_Toggle();
                    vTaskDelay( pdMS_TO_TICKS( 500 ) );
                    LED_2_Toggle();
                }                    /*****************B1-Scroll up for previous item******************/
                else if (BUTTON_1_Get() == 0) {
                    CurrentIndex = CurrentIndex - 1;
                    if (CurrentIndex < 0 || CurrentIndex > 6) {
                        CurrentIndex = 6;
                    }
                    gfx_mono_draw_filled_rect(0, 0, 128, 32, GFX_PIXEL_CLR);
                    gfx_mono_draw_string(VM_Items[CurrentIndex], 0, 0, &sysfont);
                    sprintf(Oled_Text, "%d", VM_Count[CurrentIndex]);
                    gfx_mono_draw_string(Oled_Text, 117, 0, &sysfont);
                    gfx_mono_generic_draw_rect(112, 0, 16, 20, GFX_PIXEL_SET);
                    LED_1_Toggle();
                    vTaskDelay( pdMS_TO_TICKS( 500 ) );
                    LED_1_Toggle();

                }                    /********************Select an Item Decrement by 1**************/
                else if (BUTTON_3_Get() == 0) {
                    if (VM_Count[CurrentIndex] <= 0) {
                        VM_Count[CurrentIndex] = 0;
                    } else {
                        VM_Count[CurrentIndex] = VM_Count[CurrentIndex] - 1;
                    }

                    sprintf(Oled_Text, "%d", VM_Count[CurrentIndex]);
                    gfx_mono_draw_string(Oled_Text, 117, 0, &sysfont);
                    gfx_mono_generic_draw_rect(112, 0, 16, 20, GFX_PIXEL_SET);
                    LED_3_Toggle();
                    vTaskDelay( pdMS_TO_TICKS( 500 ) );
                    LED_3_Toggle();
                }
            }

            break;
        }

            /* TODO: implement your application state machine.*/


            /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */