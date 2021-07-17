#pragma once

class Business 
{

public:
	// Constructurs

	Business();
	Business(const CString &, const CString &, const CString &, const CString&, const CString&);
	virtual ~Business();

	// Get's Functions

	CString GetName();
	CString GetAddress();
	CString GetTel();
	CString GetOpenH();
	CString GetCloseH();

	// Set's Functions

	void SetName(const CString&);
	void SetAddress(const CString&);
	void SetTel(const CString&);
	void SetOpenH(const CString&);
	void SetCloseH(const CString&);

	// Services Functions

	virtual void show() = 0; // Abstract Class


private:
	// Rest Details
	CString Name;
	CString Address;
	CString Telephone;
	CString OpenHours;
	CString CloseHours;

};

