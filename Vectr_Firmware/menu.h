/* 
 * File:   menu.h
 * Author: matthewheins
 *
 * Created on April 19, 2014, 10:05 PM
 */

#ifndef MENU_H
#define	MENU_H

#include "FreeRTOS.h"
#include "queue.h"

typedef struct{
    uint16_t u16Port;
    uint16_t u16PortState;
}portChangeStruct;

//Main Menu States
enum{
    X_MENU = 0,
    Y_MENU,
    Z_MENU,
    LOAD_MENU,
    STORE_MENU,
    RECORD_MENU,
    PLAYBACK_MENU,
    OVERDUB_MENU,
    EFFECT_MENU,
    CLOCK_MENU
};

//X,Y,Z Submenus
enum{
    RANGE = 1,
    QUANTIZATION,
    LINEARITY,
    SLEW_RATE,
    TRACK_BEHAVIOR
};

//Record,Playback,Overdub Submenus
enum{
    SOURCE = 1,
    CONTROL,
    LOOP
};

#define CLK_NUMBER 5 //Clock number is the fourth setting for the record overdub, but it's the fifth LED

//Clock submenus
enum{
    SYNC = 4,
    NUMBER
};

#define NUM_OF_MAIN_MENUS       10
#define SUBMENU_NOT_SELECTED    0
#define NUM_OF_XYZ_SUBMENUS     5
#define NUM_OF_REC_ODUB_SUBMENUS   3
#define NUM_OF_PLAYBACK_SUBMENUS   3
#define MAX_NUM_OF_LOAD_STORE_LOCATIONS 5
#define NUM_OF_BOTTOM_PARAMETERS 5
#define NUM_OF_PLAYBACK_CONTROL_SETTINGS  3
#define NUM_OF_LOOP_SETTINGS    5
#define NUM_OF_CLOCK_SETTINGS 5
#define NUM_OF_EFFECT_SETTINGS 5

#define LIVE_PLAY_ACTIVATION_CLICKS 2
#define HOLD_ACTIVATION_CLICKS  2

uint16_t getEncState(void);
void setEncState(uint16_t newState);
void menuHandlerInit(void);
void encoderHandler(uint16_t u16newState);
void setMenuKeyPressFlag(void);
void encoderLiveInteraction(void);
void encoderInit(void);

#endif	/* MENU_H */

