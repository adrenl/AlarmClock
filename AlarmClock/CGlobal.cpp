#include "pch.h"
#include "CGlobal.h"
bool CGlobal::showtitle = TRUE;
CString CGlobal::font_name;
CString CGlobal::font_size;
bool CGlobal::font_sizeauto;
bool CGlobal::font_bold;
bool CGlobal::font_italic;
bool CGlobal::font_unline;
bool CGlobal::font_delline;
int CGlobal::text_color;
int CGlobal::background_color;
CString CGlobal::inipath = L".\\AlarmClock.ini";
CGlobal::CGlobal()
{
}
CGlobal::~CGlobal()
{
}
bool CGlobal::IntToBool(int v) {
	if (v == 0) {
		return FALSE;
	}else {
		return TRUE;
	}
}
/*int CGlobal::BoolToInt(bool v) {
	if (v == TRUE) {
		return 1;
	}
	else {
		return 0;
	}
}*/
int CGlobal::BoolToInt(bool v)
{
	if (v == TRUE) {
		return 1;
	}
	else {
		return 0;
	}
}