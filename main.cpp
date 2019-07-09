//
//  main.cpp
//  PumpingLemma

#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;
vector<string> readLine();
vector<string> combinations(vector <string> var, vector <string> expo);



int main(int argc, const char * argv[]) {
    string inputString;
    string temp;
    vector <string> var;
    vector <string> expo;
    vector <string> possibleCombinations;
    int p = 2;
    int i = 0;
    
    
    
/************************Takes in user input***************************/
    cout << "Enter up to three base variables seperated by commas.\n";
    
    var = readLine();
    
    cout << "Enter each exponents. If variable has no exponent enter 1.\n";
    
    for (i = 0; i < var.size(); ++i){
        cout << var[i] << " ^: ";
        cin >> temp;
        expo.push_back(temp);
    }
    
    cout << "You entered: ";
    for (i = 0; i < var.size(); ++i){
        cout << var[i] << "^" << expo[i] << " ";
    }
    possibleCombinations = combinations(var, expo);
    
    
    
    
    
    
    //possible combinations being checked
    for (i = 0; i < possibleCombinations.size(); ++i){
        cout << possibleCombinations[i];
    }
    
    return 0;
}























vector<string> combinations(vector <string> var, vector <string> expo){
    string temp;
    string temp1;
    string temp2;
    vector <string> possibleCombinations;
    int i = 0, j = 0, k = 0, tempExpo = 0;
    //creats possible strings to check
    
    for (i = 0; i < var.size(); ++i){
        //checks first variable
        if (isdigit(expo[i][0])){
            tempExpo= stoi(expo[0]);
            for (j = 0; j < tempExpo; ++j){
                temp = temp + var[i];
                }
        //check the second expo
            for (j = 0; j < (var.size() -1); ++j{
                if (expo.size() > 1){
                    if (isdigit(expo[1][0])){
                    tempExpo= stoi(expo[1]);
                    for (j = 0; j < tempExpo; ++j){
                        temp = temp + var[1];
        //check the three expo
                        if (expo.size() > 2){
                            if (isdigit(expo[2][0])){
                                tempExpo= stoi(expo[2]);
                                for (j = 0; j < tempExpo; ++j){
                                    temp = temp + var[2];
                                }
                            }
                        }
                        else{
                            cout << "\nFIXME\n";
                        }
                        
                        }
                    }
                    }
                    else{
                        cout << "\nFIXME\n";
                    }
        else{
            cout << "\nFIXME\n";
        }

    
    return possibleCombinations;
}



/****************************************************************************/


//Function that parses the input based on commas returns a vector of variables
vector<string> readLine(){
    char ch;
    int i = 0;
    string inputString;

    string tempString;
    vector <string> var;
    getline (cin, inputString);

    for (i = 0; i < inputString.size(); ++i){
        ch = inputString[i];
        if (ch != ','){
            tempString = tempString + ch;
        }
        else{
            var.push_back(tempString);
            tempString = "";
        }
    }
//catches last input not ending in comma
    if (tempString.size() > 0){
    var.push_back(tempString);
    }
    
    return var;
}
