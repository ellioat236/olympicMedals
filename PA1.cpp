/// File Name: olympicMedalProject.cpp
//
// Author: Elliot Sonoqui
// Collaborators: None
// Date: 1/26/2024
// Assignment Number: 1
// CS 2308 Spring 2024
//
// This program tracks the medals won by countries participating at the Olympic Games.
 

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_COUNTRIES = 8;

struct Country{
    string name;
    int gold;
    int silver;
    int bronze;
};

//***********************************************************
// showResults: displays the table of countries, given the array of Countries.
//
// takes countries array as a parameter
//
//first section of code outputs table header
//second section of code outputs table data
//***********************************************************

void showResults(Country countries[]){
    cout << left
    << setw(3) << "N"
    << setw(15) << "Country"
    << right
    << setw(10) << "Gold"
    << setw (10) << "Silver"
    << setw (10) << "Bronze"
    << setw(10) << "Total"
    << endl;

    for(int i=0; i<NUM_COUNTRIES; i++){
        cout << left << setw(3) << i + 1
        << setw(15) << countries[i].name
        << right
        << setw(10) << countries[i].gold
        << setw (10) << countries[i].silver
        << setw (10) << countries[i].bronze
        << setw(10) << countries[i].gold + countries[i].silver + countries[i].bronze
        << endl;
    }
}

//***********************************************************
// totalMedals: determines the total number of medals awarded, given the array of Countries.
//
// takes countries array as a parameter
// returns: dint value total number of medals for a given country
//***********************************************************

int totalMedals(Country countries[]){
    int total = 0;
    for(int i = 0; i < NUM_COUNTRIES; i++){
        total += countries[i].gold + countries[i].silver + countries[i].bronze;
    }

    return total;
}

//***********************************************************
// mostTotalMedals: determines which country has the most total medals, given the array of Countries
//
// takes countries array as a parameter
// returns: int value of the index of the country with the most medals
//***********************************************************

int mostTotalMedals(Country countries[]){
    int maxTotal = 0;
    int maxIndex = 0;

    for(int i = 0; i < NUM_COUNTRIES; i++){
        int total = countries[i].gold + countries[i].silver + countries[i].bronze;

        if(total > maxTotal){
            maxTotal = total;
            maxIndex = i;
        }
    }

    return maxIndex;
}

//***********************************************************
// addMedal: updates the medal counts: it increments the appropriate medal count.
//
// countries array is used as a parameter
// countryNum is an int used to assign the medal type to a certain country
// medalType is a char parameter for the type of medal to count
//***********************************************************

void addMedal(Country countries[], int countryNum, char medalType){

    if(countryNum >= 1 && countryNum <= NUM_COUNTRIES){
        int index = countryNum - 1;
        switch(medalType){
            case 'G': 
                countries[index].gold++;
                break;
            case 'S':
                countries[index].silver++;
                break;
            case 'B':
                countries[index].bronze++;
                break;
            default:
                break;
        }
    }
}


int main(){

    Country countries[NUM_COUNTRIES] = {

        {"Australia", 11, 14, 12},
        {"Canada", 5, 0, 1},
        {"China", 9, 14, 11},
        {"Great Britain", 8, 4, 8},
        {"Japan", 8, 10, 10},
        {"Netherlands", 7, 6, 7},
        {"Russia", 6, 10, 8},
        {"USA", 10, 6, 7}

    };

    showResults(countries);

    int countryNum;
    char medalType;

    do{
        cout << "Enter the country number (0 to quit):" << endl;
        cin >> countryNum;

        if(countryNum != 0) {
            cout << "Enter the medal type (G,S, or B):" << endl;
            cin >> medalType;
            
            addMedal(countries, countryNum, medalType);
            showResults(countries);
        }
    } while (countryNum != 0);

    int total = totalMedals(countries);
    cout << "Total medals awarded: " << total << endl; 

    int mostMedalsIndex = mostTotalMedals(countries);
    cout << "Country with the most total medals: " << countries[mostMedalsIndex].name << endl;

    return 0;
}