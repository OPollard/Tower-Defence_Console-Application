#include "Enemy.h"

//Base Constructor
Enemy::Enemy(const double h, const double d, const double c, const EnemyType et, const ChemType ct)
    : m_HP{h}, m_Damage{d}, m_Worth{c}, m_ChemT{ct}, m_StyleT{et}
{
}

//Setters and Getters
void Enemy::SetHP(double x)
{
	m_HP = x;
}
double Enemy::GetHP()
{
	return m_HP;
}

void Enemy::SetDamage(double x)
{
	m_Damage = x;
}
double Enemy::GetDamage()
{
	return m_Damage;
}

void Enemy::SetWorth(double x)
{
	m_Worth = x;
}
double Enemy::GetWorth()
{
	return m_Worth;
}

std::string Enemy::GetChemType() const
{
	if (m_ChemT == FIRE) { return "Fire"; }
	else if (m_ChemT == WATER) { return "Water"; }
	else if (m_ChemT == LEAF) { return "Leaf"; }
	else { return "Unknown"; }
}

std::string Enemy::GetEnemyType() const
{
	if (m_StyleT == GOBLIN) { return "Goblin"; }
	else if (m_StyleT == ORC) { return "Orc"; }
	else if (m_StyleT == RAIDBOSS) { return "RaidBoss"; }
	else { return "Unknown"; }
	
}



//Base Destructor
Enemy::~Enemy()
{
}