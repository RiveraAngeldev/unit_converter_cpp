#include <iostream>
#include <limits>
#include <string>
#include "length.h"

enum class LengthUnit {
    Millimeters = 1,
    Centimeters,
    Meters,
    Kilometers,
    Inches,
    Feet,
    Yards,
    Miles,
    NauticalMiles
};

struct UnitInfo {
    std::string name;
    double metersPerUnit;
};

UnitInfo getUnitInfo(LengthUnit unit) {
    switch (unit) {
    case LengthUnit::Millimeters:
        return {"Millimeters", 0.001};
    
    case LengthUnit::Centimeters:
        return {"Centimeters", 0.01};

    case LengthUnit::Meters:
        return {"Meters", 1.0};

    case LengthUnit::Kilometers:
        return {"Kilometers", 1000.0};

    case LengthUnit::Inches:
        return {"Inches", 0.0254};

    case LengthUnit::Feet:
        return {"Feet", 0.3048};

    case LengthUnit::Yards:
        return {"Yards", 0.9144};

    case LengthUnit::Miles:
        return {"Miles", 1609.344};

    case LengthUnit::NauticalMiles:
        return {"Nautical Miles", 1852.0};
    }

    return {"Unknown", 1.0};
}

double convertLength(double value, LengthUnit from, LengthUnit to) {
    UnitInfo source = getUnitInfo(from);
    UnitInfo destination = getUnitInfo(to);

    double meters = value * source.metersPerUnit;
    
    return meters/destination.metersPerUnit;
}

void displayLengthUnits() {
    std::cout << "\n===== LENGTH UNITS =====\n";
    std::cout << "1. Millimeters\n";
    std::cout << "2. Centimeters\n";
    std::cout << "3. Meters\n";
    std::cout << "4. Kilometers\n";
    std::cout << "5. Inches\n";
    std::cout << "6. Feet\n";
    std::cout << "7. Yards\n";
    std::cout << "8. Miles\n";
    std::cout << "9. Nautical Miles\n";
}

void lengthMenu() {
    int fromChoice;
    int toChoice;
    double value;

    displayLengthUnits();

    std::cout << "\nConvert from (enter unit number): ";
    if(!(std::cin >> fromChoice) || fromChoice < 1 || fromChoice > 9) {
        std::cout << "Invalid source unit.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Convert to (enter unit number): ";
    if (!(std::cin >> toChoice) || toChoice < 1 || toChoice > 9) {
        std::cout << "Invalid destination unit.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout<< "Enter value: ";
    if(!(std::cin >> value)) {
        std::cout << "Invalid value.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    LengthUnit from = static_cast<LengthUnit>(fromChoice);
    LengthUnit to = static_cast<LengthUnit>(toChoice);

    double result = convertLength(value, from, to);
    std::cout << "\nResult: " << value << " " << getUnitInfo(from).name << " = " << result << " " << getUnitInfo(to).name << "\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}