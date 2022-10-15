#include "EconomicSimulation.h"

#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>

void EconomicSimulation::init()
{
    initEntities();
}

void EconomicSimulation::simulate()
{
    runSpendingPhase();
    runBuyingPhase();
}
void EconomicSimulation::printEntities()
{
    for (int i = 0; i < entities.size(); i++)
    {
        if (i % 10 == 0)
            std::cout << '\n';

        std::cout << std::setw(8) << std::fixed << std::setprecision(2) << entities[i].GetSavings() << " ";
    }
}

void EconomicSimulation::initEntities()
{
    int numEntities = 0;
    float startingIncome = 0;
    float mpc = 0;
    float baseConsumption = 0;

    std::cout << "Enter number of entities in simluation: ";
    std::cin >> numEntities;
    entities.reserve(numEntities);

    std::cout << "Enter starting income: ";
    std::cin >> startingIncome;

    std::cout << "Enter base consumption (autonomous consumption): ";
    std::cin >> baseConsumption;

    // std::cout << "Enter marginal propensity to consume (usually between 0.5 - 1): ";
    // std::cin >> mpc;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    std::normal_distribution<float> mpcNormDist(MEAN_MPC, MPC_STD_DEV);
    std::normal_distribution<float> pebNormDist(MEAN_PEB, PEB_STD_DEV);

    for (int i = 0; i < numEntities; i++)
    {
        mpc = mpcNormDist(generator);
        float prodBias = pebNormDist(generator);
        EconomicEntity entity(baseConsumption, startingIncome, mpc, prodBias);
        entities.push_back(entity);
    }
}
void EconomicSimulation::runSpendingPhase()
{
    float amountSpent = 0;
    for (int i = 0; i < entities.size(); i++)
    {

        float individualSpending = entities[i].calculateConsumption();
        amountSpent += individualSpending;

        float leftoverCash = entities[i].GetIncomeLevel() - individualSpending;
        entities[i].AddSavings(leftoverCash);
    }
    amtSpendThisCycle = amountSpent;
}
void EconomicSimulation::runBuyingPhase()
{
    float amtSpentPerPerson = amtSpendThisCycle / entities.size();
    // assume even distribution of funds. TODO: overhaul.
    // this is socialism!!!!
    for (int i = 0; i < entities.size(); i++)
    {
        entities[i].SetIncomeLevel(amtSpentPerPerson);
    }
}
