#pragma once
#include "Business.h"
class Butcher : public Business {
public:
	Butcher();
	Butcher(const CString&, const CString&, const CString&, const CString&, const CString&);
	~Butcher();

	void show();

private:

};

