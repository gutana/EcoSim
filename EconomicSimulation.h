#pragma once

#include "EconomicEntity.h"
#include <vector>

const float MEAN_MPC = 0.7;
const float MEAN_PEB = 0.7;
const float MPC_STD_DEV = 0.1;
const float PEB_STD_DEV = 0.1;

class EconomicSimulation
{
public:
    void init();
    void simulate();
    void printEntities();

private:
    std::vector<EconomicEntity> entities;
    void initEntities();
    void runSpendingPhase();
    void runBuyingPhase();

private:
    float amtSpendThisCycle;
};