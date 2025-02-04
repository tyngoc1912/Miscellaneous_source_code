#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Livestock {
protected:
    int count;
public:
    Livestock(int count) : count(count) {}

    virtual std::string getSound() const = 0;
    virtual int produceMilk() const = 0;
    virtual int produceOffspring() const = 0;

    int getCount() const {
        return count;
    }

    void increaseCount(int number) {
        count += number;
    }

    virtual ~Livestock() {}
};

class Cow : public Livestock {
public:
    Cow(int count) : Livestock(count) {}

    std::string getSound() const override {
        return "Moo";
    }

    int produceMilk() const override {
        return rand() % 21; // 0 to 20 liters
    }

    int produceOffspring() const override {
        return rand() % 5; // 0 to 4 offspring
    }
};

class Sheep : public Livestock {
public:
    Sheep(int count) : Livestock(count) {}

    std::string getSound() const override {
        return "Baa";
    }

    int produceMilk() const override {
        return rand() % 6; // 0 to 5 liters
    }

    int produceOffspring() const override {
        return rand() % 3; // 0 to 2 offspring
    }
};

class Goat : public Livestock {
public:
    Goat(int count) : Livestock(count) {}

    std::string getSound() const override {
        return "Bleat";
    }

    int produceMilk() const override {
        return rand() % 11; // 0 to 10 liters
    }

    int produceOffspring() const override {
        return rand() % 4; // 0 to 3 offspring
    }
};

void inputLivestock(std::vector<Livestock*>& livestock) {
    int count;

    std::cout << "Enter initial number of cows: ";
    std::cin >> count;
    livestock.push_back(new Cow(count));

    std::cout << "Enter initial number of sheep: ";
    std::cin >> count;
    livestock.push_back(new Sheep(count));

    std::cout << "Enter initial number of goats: ";
    std::cin >> count;
    livestock.push_back(new Goat(count));
}

void allLivestockHungry(const std::vector<Livestock*>& livestock) {
    for (const auto& animal : livestock) {
        for (int i = 0; i < animal->getCount(); ++i) {
            std::cout << animal->getSound() << " ";
        }
    }
    std::cout << std::endl;
}

void statistics(const std::vector<Livestock*>& livestock) {
    int totalMilk = 0;
    for (const auto& animal : livestock) {
        int offspring = animal->produceOffspring();
        animal->increaseCount(offspring);
        std::cout << "Type of livestock: " << typeid(*animal).name() << ", Count: " << animal->getCount() << std::endl;

        for (int i = 0; i < animal->getCount(); ++i) {
            totalMilk += animal->produceMilk();
        }
    }
    std::cout << "Total liters of milk produced by all livestock: " << totalMilk << " liters" << std::endl;
}

int main() {
    srand(time(0));
    std::vector<Livestock*> livestock;

    inputLivestock(livestock);

    std::cout << "\nWhen all livestock in the farm are hungry, the sounds heard:\n";
    allLivestockHungry(livestock);

    std::cout << "\nStatistics after one breeding and one milking session of all livestock:\n";
    statistics(livestock);

    for (auto animal : livestock) {
        delete animal;
    }

    return 0;
}
