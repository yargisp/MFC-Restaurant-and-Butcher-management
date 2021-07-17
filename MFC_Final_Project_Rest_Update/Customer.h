#pragma once

class Customer
{
protected:
	CString FirstName;
	CString LastName;
	CString PhoneNum;
	CString Adress;
	CString City;
	int id;
	static int ActiveCustomers;

public:
	//const's
	Customer();
	Customer(const CString&, const CString&, const CString&, const CString&, const CString&);
	Customer(const Customer&);
	~Customer();

	//get's
	CString getFirstN() const;
	CString  getLastN() const;
	CString getPhone() const;
	CString getAdress() const;
	CString getCity() const;
	int getID() const;
	int getActiveCustomers() const;

	//set's
	void setFirstN(const CString&);
	void setLastN(const CString&);
	void setPhoneN(const CString&);
	void setAdress(const CString&);
	void setCity(const CString&);

	//Methods
	


};
