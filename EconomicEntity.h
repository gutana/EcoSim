#pragma once

enum TRAIT
{
    HAPPY,
    SAD,
    HORNY
};

class EconomicEntity
{
public:
    EconomicEntity(float autonomousConsumption = 0, float incomeLevel = 0, float mpc = 0, float prodBias = 0);
    float calculateConsumption();

    float GetAutonomousConsumption() const;
    void SetAutonomousConsumption(float);

    float GetIncomeLevel() const;
    void SetIncomeLevel(float);

    float GetMpc() const;
    void SetMpc(float);

    float GetSavings() const;
    void SetSavings(float savings);
    void AddSavings(float amount);

private:
    float autonomousConsumption;
    float incomeLevel;
    float savings = 0;
    float mpc;
    float productivityBias; // TODO: Do something with this
};