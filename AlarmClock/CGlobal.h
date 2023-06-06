#pragma once
class CGlobal
{
public:
	CGlobal();
	virtual ~CGlobal();
public:
	static bool showtitle;
	static CString font_name;
	static CString font_size;
	static bool font_autoajust;
	static bool font_bold;
	static bool font_italic;
	static bool font_unline;
	static bool font_delline;
	static COLORREF text_color;
	static COLORREF background_color;
	static CString inipath;
	static int BoolToInt(bool v);
	static bool IntToBool(int v);
};