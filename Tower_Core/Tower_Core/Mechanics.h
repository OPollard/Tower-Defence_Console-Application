#pragma once
#include "Enemy.h"
#include "Towers.h"


#include <assert.h>
#include <iomanip>
#include <time.h>
#include <vector>

class Mechanics
{
private:

	int KillCount{ 0 };

	double PlayerCoin{ 0 };

	std::vector<std::unique_ptr<Enemy>> m_Enemies;
	std::vector<std::unique_ptr<Towers>> m_Towers;

public:

	Mechanics();

	//Container Add Functions
	void AddEnemy(double health, double damage, double cost, EnemyType Style, ChemType Elemental);
	void AddHydroTower(double Health, double Damage, double UpgradeCost);
	void AddFireTower(double Health, double Damage, double UpgradeCost);

	//Remove enemies at command or via battles
	//Create Random Enemy After Killed
	void CheckForKilled();
	std::unique_ptr<Enemy> CreateRandomEnemy();

	//Change tower type at command
	void UpgradeTower();
	void ChangeTower();
	void RepairTower();

	//Compare and compute battles:
	//Compare towers stats with enemy stats including bonuses etc
	void ComputeBattle();
	void ComputeTowerShots(std::vector<std::unique_ptr<Towers>>& Towers, std::vector<std::unique_ptr<Enemy>>& Enemies);
	void ComputeEnemyShots(std::vector<std::unique_ptr<Towers>>& Towers, std::vector<std::unique_ptr<Enemy>>& Enemies);

	//Game Direction
	void Intro() const;
	void PrintActors()const;
	void GetPlayerChoice();

};

