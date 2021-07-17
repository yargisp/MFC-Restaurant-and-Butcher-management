#pragma once
class Supply {
public:
	Supply();
	~Supply();
	Supply(const double*, const int*, const int*, const int*, const int*);

	void SetMeat(const double*);
	const double* GetMeat();

	void SetDrink(const int&,const int&);
	void SetMeat(const int&, const double&);
	void SetBread(const int&, const int&);
	void SetVegs(const int&, const int&);
	void SetSide(const int&, const int&);

	int GetDrink(const int& i) { return Drink[i]; };
	double GetMeat(const int& i) { return Meat[i]; };
	int GetBread(const int& i) { return Breads[i]; };
	int GetVegs(const int& i) { return Vegetables[i]; };
	int GetSide(const int& i) { return Extras[i]; };

	void SetDrinks(const int*);
	const int* GetDrinks();

	void SetVegetables(const int*);
	const int* GetVegetables();

	void SetBreads(const int*);
	const int* GetBreads();

	void SetExtras(const int*);
	const int* GetExtras();

	//int GetBurgerSupply();
	//int GetWagyuSupply();
	//int GetAngusSupply();
	//int GetRibsSupply();


protected:
	enum Meat{Burger,Wagyu,Angus,Ribs};
	enum Drink{Cola,Soda,Lemonade,PinkLemonade};
	enum Vegetables{Tomato,Pickle,Onion,Lettuce,Potato};
	enum Breads{White,WholeWheat};
	enum Extras{French_Fries,Onion_Rings};

	double Meat[4];
	int Drink[4];
	int Vegetables[5];
	int Breads[2];
	int Extras[2];
};

