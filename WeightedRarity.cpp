#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int GetTotalWeight(const unordered_map<string, int> events_weight) {
    int total_weight = 0;

    for (const auto & pair : events_weight) {
        string key = pair.first;
        int weight = pair.second;

        total_weight += weight;
    }
    
    return total_weight;
}

string WeightRandomizer(const unordered_map<string, int> events_weight) {
    int total_weight = GetTotalWeight(events_weight);
    int random_number = rand() % total_weight + 1;
    int counter = 0;

    for (const auto & pair : events_weight) {
        string key = pair.first;
        int weight = pair.second;
        
        counter += weight;
        if (random_number <= counter) {
            return key;
        }
    }
}

int main()
{
    unordered_map<string, int> rarity = {
        {"common", 80},
        {"uncommon", 70},
        {"rare", 25},
        {"legendary", 1},
    };
    
    for (int i = 0; i < 10; i++) {
        cout << WeightRandomizer(rarity) << endl;
    }
}