#include "pch.h"
#include "CGlobal.h"
bool CGlobal::showtitle = TRUE;
CString CGlobal::format;
CString CGlobal::font_name;
CString CGlobal::font_size;
bool CGlobal::font_autoajust;
bool CGlobal::font_bold;
bool CGlobal::font_italic;
bool CGlobal::font_unline;
bool CGlobal::font_delline;
COLORREF CGlobal::text_color;
COLORREF CGlobal::background_color;
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
int CGlobal::BoolToInt(bool v)
{
	if (v == TRUE) {
		return 1;
	}
	else {
		return 0;
	}
}