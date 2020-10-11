#include "Towers.h"

//Base Constructor - with default values that zero values
Towers::Towers(const double h, const double d, const double c)
	: m_HP{ h }, m_Damage{ d }, m_UpCost{ c }
{
}

//Setters and Getters
void Towers::SetName(std::string x)
{
	m_Name = x;
}
std::string Towers::GetName()const
{
	return m_Name;
}

void Towers::SetHP(double x)
{
	m_HP = x;
}
double Towers::GetHP() const
{
	return m_HP;
}

void Towers::SetDamage(double x)
{
	m_Damage = x;
}
double Towers::GetDamage() const
{
	return m_Damage;
}

void Towers::SetUpCost(double x)
{
	m_UpCost = x;
}
double Towers::GetUpCost() const
{
	return m_UpCost;
}

void Towers::IncreaseLvl()
{
	++m_CurrentLvl;
}
int Towers::GetCurrentLvl() const
{
	return m_CurrentLvl;
}

void Towers::ResetStats()
{
	m_HP = 0;
	m_Damage = 0;
	m_UpCost = 0;
}



//Base Destructor
Towers::~Towers()
{

}





//Derived Constructor
Hydro::Hydro(const double h, const double d, const double c)
	: Towers{h, d, c}
{
	SetName("Hydro");
}

void Hydro::Upgrade()
{
	//TODO Create if for player coin count
	this->IncreaseLvl();
	this->SetHP(static_cast<double>(GetCurrentLvl()) * 100);
	this->SetDamage(GetDamage() * UPGRADE_STAT_MULTI);
	this->SetUpCost(GetUpCost() * COST_STAT_MULTI);

}


//Derived Destructor
Hydro::~Hydro()
{

}




//Derived Constructor
Fire::Fire(const double h, const double d, const double c)
	: Towers{h, d, c}
{
	SetName("FireBall");
}

//Requires Player Coin. Sets new Tower: HP, Damage, Cost
void Fire::Upgrade()
{
	//TODO: Create if for player coin count
	this->IncreaseLvl();
	this->SetHP(static_cast<double>(GetCurrentLvl()) * 100);
	this->SetDamage(GetDamage() * UPGRADE_STAT_MULTI);
	this->SetUpCost(GetUpCost() * COST_STAT_MULTI);

}

//Derived Destructor
Fire::~Fire()
{

}