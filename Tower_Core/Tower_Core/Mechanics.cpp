#include "Mechanics.h"

Mechanics::Mechanics()
{
	AddHydroTower(HYDRO_HP_BASE, HYDRO_DAMAGE_BASE, HYDRO_UPCOST_BASE);
	AddHydroTower(HYDRO_HP_BASE, HYDRO_DAMAGE_BASE, HYDRO_UPCOST_BASE);
	AddHydroTower(HYDRO_HP_BASE, HYDRO_DAMAGE_BASE, HYDRO_UPCOST_BASE);
	AddEnemy(100, 5, 50, GOBLIN, WATER);
	AddEnemy(100, 5, 50, GOBLIN, FIRE);
	AddEnemy(100, 5, 50, GOBLIN, WATER);
}

//Container Add Functions
void Mechanics::AddEnemy(double Health, double Damage, double Worth, EnemyType Style, ChemType Elemental)
{
	assert((Health > 0) && (Damage > 0) && (Worth > 0));
	m_Enemies.push_back(
		std::make_unique<Enemy>(Health, Damage, Worth, Style, Elemental)
	);
	
}
void Mechanics::AddHydroTower(double Health, double Damage, double UpgradeCost)
{
	assert((Health > 0) && (Damage > 0) && (UpgradeCost > 0));
		m_Towers.push_back(
			std::make_unique<Hydro>(Health, Damage, UpgradeCost)
		);
}
void Mechanics::AddFireTower(double Health, double Damage, double UpgradeCost)
{
	assert((Health > 0) && (Damage > 0) && (UpgradeCost > 0));
	m_Towers.push_back(
		std::make_unique<Fire>(Health, Damage, UpgradeCost)
	);
}


void Mechanics::CheckForKilled()
{
	for (size_t index{ 0 }; index < m_Enemies.size(); ++index)
	{
		if (m_Towers[index]->GetHP() <= 0)
		{
			std::cout << "Tower " << index << " Destroyed! \n\n";
			m_Towers[index]->ResetStats();

		}
		if (m_Enemies[index]->GetHP() <= 0)
		{
			std::cout << "Enemy " << index << " Killed! \n\n";
			PlayerCoin += m_Enemies[index]->GetWorth();
			++KillCount;
			std::vector<std::unique_ptr<Enemy>>::iterator tit = m_Enemies.begin() + index;
			m_Enemies.erase(tit);
			std::vector<std::unique_ptr<Enemy>>::iterator tit2 = m_Enemies.begin() + index;
			m_Enemies.insert(tit2, CreateRandomEnemy());
		}

	}
}


std::unique_ptr<Enemy> Mechanics::CreateRandomEnemy()
{
	int TypeRef{ rand() % 3 };
	int ElementRef{ rand() % 3 };
	if (TypeRef == 0 && ElementRef == 0) { return std::make_unique<Enemy>(GOBLIN_HP_BASE, GOBLIN_DAMAGE_BASE, GOBLIN_WORTH_BASE, GOBLIN, WATER); }
	if (TypeRef == 0 && ElementRef == 1) { return std::make_unique<Enemy>(GOBLIN_HP_BASE, GOBLIN_DAMAGE_BASE, GOBLIN_WORTH_BASE, GOBLIN, FIRE); }
	if (TypeRef == 0 && ElementRef == 2) { return std::make_unique<Enemy>(GOBLIN_HP_BASE, GOBLIN_DAMAGE_BASE, GOBLIN_WORTH_BASE, GOBLIN, LEAF); }

	if (TypeRef == 1 && ElementRef == 0) { return std::make_unique<Enemy>(ORC_HP_BASE, ORC_DAMAGE_BASE, ORC_WORTH_BASE, ORC, WATER); }
	if (TypeRef == 1 && ElementRef == 1) { return std::make_unique<Enemy>(ORC_HP_BASE, ORC_DAMAGE_BASE, ORC_WORTH_BASE, ORC, FIRE); }
	if (TypeRef == 1 && ElementRef == 2) { return std::make_unique<Enemy>(ORC_HP_BASE, ORC_DAMAGE_BASE, ORC_WORTH_BASE, ORC, LEAF); }

	if (TypeRef == 2 && ElementRef == 0) { return std::make_unique<Enemy>(RAIDBOSS_HP_BASE, RAIDBOSS_DAMAGE_BASE, RAIDBOSS_WORTH_BASE, RAIDBOSS, WATER); }
	if (TypeRef == 2 && ElementRef == 1) { return std::make_unique<Enemy>(RAIDBOSS_HP_BASE, RAIDBOSS_DAMAGE_BASE, RAIDBOSS_WORTH_BASE, RAIDBOSS, FIRE); }
	if (TypeRef == 2 && ElementRef == 2) { return std::make_unique<Enemy>(RAIDBOSS_HP_BASE, RAIDBOSS_DAMAGE_BASE, RAIDBOSS_WORTH_BASE, RAIDBOSS, LEAF); }
	else { return nullptr; }
}

//Upgrade and Change Commands
void Mechanics::UpgradeTower()
{
	std::cout << "Which tower?\n\n";
	int TowerIndex; std::cin >> TowerIndex;
	if ((TowerIndex >= 0) && (static_cast<size_t>(TowerIndex) <= m_Towers.size() - 1))
	{
		if (m_Towers[TowerIndex]->GetUpCost() < PlayerCoin)
		{	
			PlayerCoin -= m_Towers[TowerIndex]->GetUpCost();
			m_Towers[TowerIndex]->Upgrade();
			
		}
		else
		{
			std::cout << "Not enough coins to upgrade \n" << std::endl;
		}
	}
	else
	{
		std::cout << "Could not find a tower to upgrade!" << std::endl;
	}
	
}
void Mechanics::ChangeTower()
{
	std::cout << "Which tower?\n\n";
	int TowerIndex; std::cin >> TowerIndex;
	std::cout << "Changed!\n\n";
	if ((TowerIndex >= 0) && (static_cast<size_t>(TowerIndex) <= m_Towers.size() - 1))
	{
		if (m_Towers[TowerIndex]->GetName() == "Hydro")
		{
			
			std::vector<std::unique_ptr<Towers>>::iterator tit = m_Towers.begin() + (TowerIndex);
			m_Towers.erase(tit);
			std::vector<std::unique_ptr<Towers>>::iterator tit2 = m_Towers.begin() + (TowerIndex);
			m_Towers.insert(tit2, std::make_unique<Fire>(FIRE_HP_BASE, FIRE_DAMAGE_BASE, FIRE_UPCOST_BASE));

		}
		else if (m_Towers[TowerIndex]->GetName() == "FireBall")
		{

			std::vector<std::unique_ptr<Towers>>::iterator tit = m_Towers.begin() + (TowerIndex);
			m_Towers.erase(tit);
			std::vector<std::unique_ptr<Towers>>::iterator tit2 = m_Towers.begin() + (TowerIndex);
			m_Towers.insert(tit2, std::make_unique<Hydro>(HYDRO_HP_BASE, HYDRO_DAMAGE_BASE, HYDRO_UPCOST_BASE));


		}
		else
		{
			std::cout << "Unknown Tower \n" << std::endl;
		}
	}
	else
	{
		std::cout << "Could not find a tower to change!" << std::endl;
	}
	
}
void Mechanics::RepairTower()
{
	std::cout << "Which tower?\n\n";
	int TowerIndex; std::cin >> TowerIndex;
	std::cout << "Repaired!\n\n";
	if ((TowerIndex >= 0) && (static_cast<size_t>(TowerIndex) <= m_Towers.size() - 1))
	{
		double HPDeficit = (m_Towers[TowerIndex]->GetCurrentLvl() * 100) - m_Towers[TowerIndex]->GetHP();
		//Player will lose coin equal to the amount of HP restored
		if (HPDeficit < PlayerCoin)
		{
			PlayerCoin -= HPDeficit;
			m_Towers[TowerIndex]->SetHP(m_Towers[TowerIndex]->GetCurrentLvl() * 100);
		}
		else
		{
			std::cout << "Not enough coin to repair! \n\n";
		}
	}
	else
	{
		std::cout << "Could not find a tower to change!" << std::endl;
	}
}


//Battle Functions
void Mechanics::ComputeBattle()
{
	std::cout << "Towers shoot!" << "\n";
	ComputeTowerShots(m_Towers, m_Enemies);
	std::cout << "Enemies shoot!" << "\n";
	ComputeEnemyShots(m_Towers, m_Enemies);
	std::cout << "\n";
	
}
void Mechanics::ComputeTowerShots(std::vector<std::unique_ptr<Towers>>& Towers, std::vector<std::unique_ptr<Enemy>>& Enemies)
{
	for (size_t index{ 0 }; index<Towers.size(); ++index)
	{

		double L_TowerDamage;
		if (Enemies[index]->GetChemType() == "Fire")
		{
			L_TowerDamage = Towers[index]->GetDamage() * Towers[index]->GetFireMulti();
		}
		else if (Enemies[index]->GetChemType() == "Water")
		{
			L_TowerDamage = Towers[index]->GetDamage() * Towers[index]->GetWaterMulti();
		}
		else if (Enemies[index]->GetChemType() == "Leaf")
		{
			L_TowerDamage = Towers[index]->GetDamage() * Towers[index]->GetGrassMulti();
		}
		else { L_TowerDamage = Towers[index]->GetDamage(); }
		
		if (Enemies[index]->GetHP() > 0)
		{
			Enemies[index]->SetHP(Enemies[index]->GetHP() - L_TowerDamage);
		}
		
	}
	
}
void Mechanics::ComputeEnemyShots(std::vector<std::unique_ptr<Towers>>& towers, std::vector<std::unique_ptr<Enemy>>& Enemies)
{
	for (size_t index{ 0 }; index < Enemies.size(); ++index)
	{
		if (towers[index]->GetHP() > 0)
		{
			towers[index]->SetHP(towers[index]->GetHP() - Enemies[index]->GetDamage());
		}
	}

}



//Messy Code But Outputs Correctly on Console
void Mechanics::Intro() const
{
	std::cout << "\t\t\tWelcome To Towers!" << "\n";
	std::cout << "\t\t\t DEFEAT THE HORDE" << "\n";
}
void Mechanics::PrintActors()const
{
	for (size_t index{ 0 }; index < m_Towers.size(); ++index)
	{
		std::cout << "       " << index << " Name   >> " << m_Towers[index]->GetName() << "\t\t" << m_Enemies[index]->GetEnemyType() << "-" << m_Enemies[index]->GetChemType() << "\t << Name/Type\n";
		std::cout <<"\t Health >> " << m_Towers[index]->GetHP() << "\t\t\t" << m_Enemies[index]->GetHP() << "\t\t << Health\n";
		std::cout <<"\t Damage >> " << m_Towers[index]->GetDamage() << "\t\t\t" << m_Enemies[index]->GetDamage() << "\t\t << Damage\n";
		std::cout <<"\t UpCost >> " << m_Towers[index]->GetUpCost() << "\t\t\t" << m_Enemies[index]->GetWorth() << "\t\t << Worth\n\n";
	}
}
void Mechanics::GetPlayerChoice()
{
	std::cout << "\t\t\tYou have  " <<  PlayerCoin << " coins! \n\n";
	std::cout << "\t\t\tEnemies killed:  " <<  KillCount << "! \n\n";
	std::cout << "\t Upgrade (u) \t Repair Tower (r) \t Fight (f) \n";
	char reply; std::cin >> reply;
	if (reply == 'f') { ComputeBattle(); }
	//else if (reply == 'c') { ChangeTower(); }
	else if (reply == 'r') { RepairTower(); }
	else if (reply == 'u') { UpgradeTower(); }

}

