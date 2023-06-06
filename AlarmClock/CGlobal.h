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
	static bool font_sizeauto;
	static int text_color;
	static int background_color;
};
