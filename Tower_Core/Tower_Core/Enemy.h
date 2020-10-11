#pragma once
#include <iostream>


enum EnemyType
{
	GOBLIN,
	ORC,
	RAIDBOSS
};

enum ChemType {
	FIRE,
	WATER,
	LEAF
};

//Base Class
class Enemy
{
private:

	double m_HP;
	double m_Damage;
	
	double m_Worth;

	EnemyType m_StyleT;
	ChemType m_ChemT;

public:

	//Prevents coder from creating an enemy with no stats
	Enemy() = delete;

	//Base Constructor
	Enemy(
		const double h = 0,
		const double d = 0,
		const double c = 0, 
		const EnemyType et = GOBLIN,
		const ChemType ct = FIRE	);

	//Setters and Getters
	void SetHP(double x);
	double GetHP();

	void SetDamage(double x);
	double GetDamage();

	void SetWorth(double x);
	double GetWorth();

	std::string GetChemType() const;
	std::string GetEnemyType() const;


	//friend overloads
	//friend std::ostream& operator<<(std::ostream& out, const Enemy& Enemy);

	//Base Destructor
	~Enemy();

};

