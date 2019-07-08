//
//  main.cpp
//  PumpingLemma
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;
vector<char> parseVars(string inputString);
vector<char> parseExpo(string inputString2);


int main(int argc, const char * argv[]) {
    string inputString;
    vector <char> var;
    int i = 0;
    
//Takes in user input
    cout << "Enter up to three base variables seperated by commas.\n";
    cin >> inputString;
    var = parseVars(inputString);
    
    for(i = 0; i < var.size(); ++i){
        cout << var[i];
        cout << "\n";
    }
    
    
    cout << "Enter up to three exponents seperated by commas.\n";
    cin >> inputString;
    var = parseVars(inputString);
    
    for(i = 0; i < var.size(); ++i){
        cout << var[i];
        cout << "\n";
    }

    
    
    return 0;
}









//Function that parses the input based on commas returns a vector of variables
vector<char> parseVars(string inputString){
    char temp;
    char ch;
    
    stringstream ss;
    vector <char> var;
    // parses input
    ss.str (inputString);
    
    while (!ss.eof()){
        ss >> temp;
        var.push_back(temp);
        ss >> ch;
    }

    return var;
}
