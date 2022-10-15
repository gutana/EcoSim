#include "EconomicEntity.h"

EconomicEntity::EconomicEntity(float autonomousConsumption, float incomeLevel, float mpc, float prodBias)
    : autonomousConsumption(autonomousConsumption), incomeLevel(incomeLevel), mpc(mpc), productivityBias(prodBias)
{
}

float EconomicEntity::calculateConsumption()
{
    float disposableIncome = GetIncomeLevel() - GetAutonomousConsumption();
    return GetAutonomousConsumption() + disposableIncome * GetMpc();
}

float EconomicEntity::GetAutonomousConsumption() const
{
    return autonomousConsumption;
}

void EconomicEntity::SetAutonomousConsumption(float autonomousConsumption)
{
    autonomousConsumption = autonomousConsumption;
}

float EconomicEntity::GetIncomeLevel() const
{
    return incomeLevel;
}

void EconomicEntity::SetIncomeLevel(float incomeLevel)
{
    incomeLevel = incomeLevel;
}

float EconomicEntity::GetMpc() const
{
    return mpc;
}

void EconomicEntity::SetMpc(float mpc)
{
    mpc = mpc;
}
float EconomicEntity::GetSavings() const
{
    return savings;
}

void EconomicEntity::SetSavings(float savings)
{
    savings = savings;
}
void EconomicEntity::AddSavings(float amount)
{
    savings = amount;
}