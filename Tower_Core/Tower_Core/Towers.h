#pragma once

#include <iostream>
#include "Values.h"


//Base Class
class Towers
{
private:

	std::string m_Name{};

	int m_CurrentLvl{ 1 };

	double m_HP;
	double m_Damage;

	double m_UpCost;

public:
	
	//Prevents coder from creating a Tower with no stats
	Towers() = delete;
	
	//Base Constructor
	Towers(const double h = 0, const double d = 0, const double c = 0);


	//Setters and Getters
	void SetName(std::string x);
	std::string GetName() const;

	void SetHP(double x);
	double GetHP() const;

	void SetDamage(double x);
	double GetDamage()const;

	void SetUpCost(double x);
	double GetUpCost()const;

	void IncreaseLvl();
	int GetCurrentLvl()const;

	//Pure Virtual defined in Derived Classes
	virtual void Upgrade() = 0;
		
	void ResetStats();

	//Pure Virtual Getters defined in Derived Classes
	virtual double GetGrassMulti() = 0;
	virtual double GetWaterMulti() = 0;
	virtual double GetFireMulti() = 0;
	
	//Overloaded friend 
	//friend std::ostream& operator<<(std::ostream& out, const Towers& Tower);

	//Base Destructor
	~Towers();

};




//Derived Class
class Hydro : public Towers
{
private:
	
	double GrassTypeMulti{ WEAK_BONUS };
	double WaterTypeMulti{ NORMAL_BONUS };
	double FireTypeMulti{ STRONG_BONUS };
	
public:
	
	//Prevents coder forgetting to initialise a tower
	Hydro() = delete;

	//Derived Constructor
	Hydro(const double h = 0, const double d = 0, const double c = 0);

	//Requires Player Coin. Sets new Tower: HP, Damage, Cost
	virtual void Upgrade() override final;

	//Getters, DO NOT ALLOW SETTERS to the Multi Bonus
	virtual double GetGrassMulti() override final
	{
		return GrassTypeMulti;
	}
	virtual double GetWaterMulti() override final
	{
		return WaterTypeMulti;
	}
	virtual double GetFireMulti() override final
	{
		return FireTypeMulti;
	}

	//Derived Destructor
	~Hydro();
	
};






//Derived Class 
class Fire : public Towers
{
private:
	int CurrentLevel{ 1 };

	double WaterTypeMulti{ WEAK_BONUS };
	double FireTypeMulti{ NORMAL_BONUS };
	double GrassTypeMulti{ STRONG_BONUS };

public:

	//Prevents coder forgetting to initialise a tower
	Fire() = delete;

	//Derived Constructor
	Fire(const double h = 0, const double d = 0, const double c = 0);

	//Requires Player Coin. Sets new Tower: HP, Damage, Cost
	virtual void Upgrade() override final;

	//Getters, DO NOT ALLOW SETTERS to the Multi Bonus
	virtual double GetGrassMulti() override final
	{
		return GrassTypeMulti;
	}
	virtual double GetWaterMulti() override final
	{
		return WaterTypeMulti;
	}
	virtual double GetFireMulti() override final
	{
		return FireTypeMulti;
	}
	
	//Derived Destructor
	~Fire();

};