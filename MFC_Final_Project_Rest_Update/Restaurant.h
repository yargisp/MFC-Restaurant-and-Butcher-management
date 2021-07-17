#pragma once
#include "Business.h"

class Restaurant : public Business {
public:
	Restaurant();
	Restaurant(const CString&, const CString&, const CString&, const CString&, const CString&);
	~Restaurant();

	void show();

private:

};

