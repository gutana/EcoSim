#include <random>
#include <iostream>
#include <chrono>

void printNormalDist(float mean, float stdDev)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::normal_distribution<float> normDist(mean, stdDev);

    std::vector<float> nums;
    nums.reserve(500);

    for (int i = 0; i < 500; i++)
    {
        nums.push_back(normDist(generator));
    }

    int betweenpoint4andpoint5 = 0;
    int betweenpoint5andpoint6 = 0;
    int betweenpoint6andpoint7 = 0;
    int betweenpoint7andpoint8 = 0;
    int betweenpoint8andpoint9 = 0;
    int betweenpoint9and1 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 1)
        {
            std::cout << "spending too much my man\n";
            return;
        }

        if (nums[i] > 0.4 && nums[i] < 0.5)
        {
            betweenpoint4andpoint5++;
        }
        else if (nums[i] > 0.5 && nums[i] < 0.6)
        {
            betweenpoint5andpoint6++;
        }
        else if (nums[i] > 0.6 && nums[i] < 0.7)
        {
            betweenpoint6andpoint7++;
        }
        else if (nums[i] > 0.7 && nums[i] < 0.8)
        {
            betweenpoint7andpoint8++;
        }
        else if (nums[i] > 0.8 && nums[i] < 0.9)
        {
            betweenpoint8andpoint9++;
        }
        else if (nums[i] > 0.9 && nums[i] < 1.0)
        {
            betweenpoint9and1++;
        }
    }

    betweenpoint4andpoint5 /= 5;
    betweenpoint5andpoint6 /= 5;
    betweenpoint6andpoint7 /= 5;
    betweenpoint7andpoint8 /= 5;
    betweenpoint8andpoint9 /= 5;
    betweenpoint9and1 /= 5;

    for (int i = 0; i < betweenpoint4andpoint5; i++)
    {
        std::cout << "*";
    }
    std::cout << "\n";
    for (int i = 0; i < betweenpoint5andpoint6; i++)
    {
        std::cout << "*";
    }
    std::cout << "\n";
    for (int i = 0; i < betweenpoint6andpoint7; i++)
    {
        std::cout << "*";
    }
    std::cout << "\n";
    for (int i = 0; i < betweenpoint7andpoint8; i++)
    {
        std::cout << "*";
    }
    std::cout << "\n";
    for (int i = 0; i < betweenpoint8andpoint9; i++)
    {
        std::cout << "*";
    }
    std::cout << "\n";
    for (int i = 0; i < betweenpoint9and1; i++)
    {
        std::cout << "*";
    }
    std::cout << "\n";
}