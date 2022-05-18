// Copyright (c) 2022 Sarah All rights reserved.
//
// Created by: Sarah
// Created on: May, 17th, 2022
// This program asks the user to enter a decimal number & how many places,
// they'd like the decimal moved to. It then moves the decimal place & displays
// it the user.
#include <iostream>
#include <iomanip>
#include <cmath>

// this function rounds the user number.
void roundDecimal(float &numUser, int &decPlace) {
    numUser = numUser * (pow(10, decPlace));
    numUser = numUser + 0.5;
    numUser = static_cast<int>(numUser);
    numUser = numUser / (pow(10, decPlace));
}


int main() {
    // declare variables
    std::string decNumString, decNumPlaceString;
    float decNumFloat;
    int decPlacesInt;

    std::cout << "This program rounds a decimal to the number of places " \
                 "entered.";
    std::cout << std::endl;
    std::cout << std::endl;

    // get user input
    std::cout << "Enter a decimal number: ";
    std::cin >> decNumString;

    try {
        // convert from string to a float
        decNumFloat = std::stof(decNumString);

        // get user input
        std::cout << "Enter the number of decimal places: ";
        std::cin >> decNumPlaceString;

        try {
            // convert from string to integer
            decPlacesInt = std::stoi(decNumPlaceString);

            // sets a range, checks to see if input it valid.
            if (decPlacesInt < 0) {
                std::cout << decPlacesInt << " is not a postive integer.\n";
            } else {
                // call function
                roundDecimal(decNumFloat, decPlacesInt);

                // display the results to user
                std::cout << std::endl;
                std::cout << decNumString << " rounded to " << decPlacesInt;
                std::cout << " decimal places is " << decNumFloat << ".";
            }

        // handles the error case
        } catch (std::invalid_argument) {
            std::cout << decNumPlaceString << " is not a valid input.\n";
            std::cout << "" << std::endl;
        }

    // handles the error case
    } catch (std::invalid_argument) {
        std::cout << decNumString << " is not a decimal number. \n";
        std::cout << "" << std::endl;
    }
}
