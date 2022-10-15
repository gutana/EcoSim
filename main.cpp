#include "EconomicEntity.h"
#include "EconomicSimulation.h"

int main()
{
    EconomicSimulation ecoSim;
    ecoSim.init();

    for (int i = 0; i < 100; i++)
    {
        ecoSim.simulate();
    }
    ecoSim.printEntities();
}