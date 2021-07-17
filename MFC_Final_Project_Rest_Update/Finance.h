#pragma once
class Finance : public CObject
{
public:
	DECLARE_SERIAL(Finance)

	Finance();
	Finance(const double&);
	~Finance();

	double GetBalance();
	void SetBalance(const double&);
	void Witdhraw(const double&);
	void deposit(const double&);

	double GetProfitButcher();
	void SetProfitButcher(const double&);
	void AddProfitButcher(const double&);

	double GetProfitRest();
	void SetProfitRest(const double&);
	void AddProfitRest(const double&);

	double GetProfitPercent();

	void Serialize(CArchive& archive);

protected:
	double Balance;
	double ProfitRest;
	double ProfitButcher;
	double ProfitPercent;
};

