// Warning: this code was not tested. Probably contains small mistakes.

#pragma once
#include<string>
#include<stack>
#include<queue>
#include"LList.h"
using std::string;
using std::stack;
using std::queue;

struct Plant {
    string name;
    int minT;
    int maxT;

    Plant(const string& _name = "", int _minT = 0, int _maxT = 0) {
        name = _name;
        minT = _minT;
        maxT = _maxT;
    }
    Plant(const Plant& other) {
        name = other.name;
        minT = other.minT;
        maxT = other.maxT;
    }

    bool survivesAt(int t) const {
        return minT <= t && t <= maxT;
    }
};

typedef stack<Plant> PlantStack;
typedef stack<int> IntStack;

LList<PlantStack> distribution(PlantStack plants, IntStack temperatures) {
    LList<PlantStack> list;
    int currentT;
    Plant currentPlant;

    while (!temperatures.empty()) {
        currentT = temperatures.top();
        temperatures.pop();

        PlantStack plantStack;
        PlantStack copyOfPlants = plants;
        
        while (!copyOfPlants.empty()) {
            currentPlant = copyOfPlants.top();
            copyOfPlants.pop();
            if (currentPlant.survivesAt(currentT)) {
                plantStack.push(currentPlant);
            }
        }
        list.ToEnd(plantStack);
    }
    return list;
}
