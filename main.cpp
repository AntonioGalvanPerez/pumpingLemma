//
//  main.cpp
//  PumpingLemma

#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;
vector<string> readLine();
bool combinations(vector <string> var, vector <string> expo);

int main(int argc, const char *argv[])
{
    string inputString;
    string temp;
    int minTemp;
    vector<string> var;
    vector<string> expo;
    vector<int> min;
    
    int p = 2;
    int i = 0;
    
    /************************Takes in user input***************************/
    cout << "Enter up to three base variables seperated by commas.\n";
    
    var = readLine();
    
    cout << "Enter each exponents. If variable has no exponent enter 1.\n";
    
    for (i = 0; i < var.size(); ++i)
    {
        cout << var[i] << " ^: ";
        cin >> temp;
        if (isdigit(temp[0])){
            expo.push_back(temp);
            min.push_back(stoi(temp));
        }
        else if ((expo.size() == 2) && ((temp == expo[0]) || (temp == expo[1]) )){
            if (temp == expo[0]){
                min.push_back(min[0]);
                expo.push_back(temp);
            }
            else {
                min.push_back(min[1]);
                expo.push_back(temp);
            }
        }
        
        else if ((expo.size() == 1) && ((temp == expo[0]))){
            min.push_back(min[0]);
            expo.push_back(temp);
        }
        else{
            cout << temp << " >=: ";
            cin >> minTemp;
            min.push_back(minTemp);
            expo.push_back(temp);
        }
        
    }
    
    cout << "You entered: ";
    for (i = 0; i < var.size(); ++i)
    {
        cout << var[i] << "^" << expo[i] << " ";
    }
    
    
    return 0;
}

/****************************************************************************/
bool  combinations(vector<string> var, vector<string> expo, vector<int> min)
{
    bool isRegular = true;
    
    return isRegular;
}

/****************************************************************************/


//Function that parses the input based on commas returns a vector of variables
vector<string> readLine()
{
    char ch;
    int i = 0;
    string inputString;
    
    string tempString;
    vector<string> var;
    getline(cin, inputString);
    
    for (i = 0; i < inputString.size(); ++i)
    {
        ch = inputString[i];
        if (ch != ',')
        {
            tempString = tempString + ch;
        }
        else
        {
            var.push_back(tempString);
            tempString = "";
        }
    }
    //catches last input not ending in comma
    if (tempString.size() > 0)
    {
        var.push_back(tempString);
    }
    
    return var;
}

