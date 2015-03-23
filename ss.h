/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2015. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1       /* callback function: panelCB */
#define  PANEL_GRAPH                      2       /* control type: graph, callback function: (none) */
#define  PANEL_BINARYSWITCH               3       /* control type: binary, callback function: (none) */
#define  PANEL_BINARYSWITCH_2             4       /* control type: binary, callback function: (none) */
#define  PANEL_COMMANDBUTTON              5       /* control type: command, callback function: sinGe */
#define  PANEL_COMMANDBUTTON_2            6       /* control type: command, callback function: (none) */
#define  PANEL_PICTURE                    7       /* control type: picture, callback function: (none) */
#define  PANEL_QUIT                       8       /* control type: command, callback function: quitCB */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK panelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK quitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK sinGe(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
