

#ifndef _PAGE_MANAGER_H
#define _PAGE_MANAGER_H

#include <input_manager.h>
#include <disp_manager.h>

typedef struct Layout {
	int iTopLeftX;
	int iTopLeftY;
	int iBotRightX;
	int iBotRightY;
	char *strIconName;
}T_Layout, *PT_Layout;

typedef struct PageLayout {
	int iTopLeftX;        /* 这个区域的左上角、右下角坐标 */
	int iTopLeftY;
	int iBotRightX;
	int iBotRightY;
	int iBpp;
	int iMaxTotalBytes;
	PT_Layout atLayout;  /* 这个区域分成好几个小区域 */
}T_PageLayout, *PT_PageLayout;

typedef struct PageAction {
	char *name;
	void (*Run)(void);
	int (*GetInputEvent)(PT_PageLayout ptPageLayout, PT_InputEvent ptInputEvent);
	int (*Prepare)(void);
	struct PageAction *ptNext;
}T_PageAction, *PT_PageAction;



//#define ID(name)   (int(name[0]) + int(name[1]) + int(name[2]) + int(name[3]))

int ID(char *strName);
int MainPageInit(void);
int SettingPageInit(void);
int IntervalPageInit(void);
int BrowsePageInit(void);
int AutoPageInit(void);
int RegisterPageAction(PT_PageAction ptPageAction);
int PagesInit(void);
int GeneratePage(PT_PageLayout ptPageLayout, PT_VideoMem ptVideoMem);
int GenericGetInputEvent(PT_PageLayout ptPageLayout, PT_InputEvent ptInputEvent);
PT_PageAction Page(char *pcName);
int TimeMSBetween(struct timeval tTimeStart, struct timeval tTimeEnd);

#endif /* _PAGE_MANAGER_H */

