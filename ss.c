#include <analysis.h>
#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ss.h"

static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "ss.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

int CVICALLBACK sinGe (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	double sinePattern[4096] = {0.0};
	FILE *Res = NULL;
	char strTemp[8] = {'\0'};
	int i = 0;
	switch (event)
	{
		case EVENT_COMMIT:
			SinePattern (4096, 2.5, 0.0, 1, sinePattern);
			PlotY(panelHandle, PANEL_GRAPH, sinePattern, 4096, VAL_DOUBLE, VAL_THIN_LINE,
				VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
			Res = fopen("result.txt", "w");
			for (i = 0; i < 4096; i++)
			{
				sprintf(strTemp, "%.2f\n", sinePattern[i]);
				fwrite(strTemp, sizeof(char), strlen(strTemp), Res);
			}
			fclose(Res);
			break;
	}
	return 0;
}

int CVICALLBACK quitCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface(0);				
			break;
	}
	return 0;
}

int CVICALLBACK panelCB (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	int button = 0;
	switch (event)
	{
		case EVENT_CLOSE:
			button = GenericMessagePopup ("选择", "您要退出还是隐藏？", "隐藏", "退出", 
				0, 0, 0, 0, VAL_GENERIC_POPUP_BTN1, VAL_GENERIC_POPUP_BTN1, VAL_GENERIC_POPUP_BTN2);
			if (button == VAL_GENERIC_POPUP_BTN1)
			{
				HidePanel(panelHandle);
			}
			else if (button == VAL_GENERIC_POPUP_BTN2)
			{
				QuitUserInterface (0);  
			}

			break;
	}
	return 0;
}
