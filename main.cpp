//
//  main.cpp
//  PumpingLemma

#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;
vector<string> readLine();
bool pumpingTest(vector <string> var, vector <string> expo, vector<int> min);

int main(int argc, const char *argv[])
{
    string inputString;
    string temp;
    int minTemp;
    bool isRegular;
    vector<string> var;
    vector<string> expo;
    vector<int> min;
    
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
    
    
    
    
    isRegular = pumpingTest(var,expo,min);
    
    if (isRegular){
        cout << "\nThe language passed the pumping lemma test" << endl;
    }
    else{
        cout << "\nThe language is not regular" << endl;
    }
    return 0;
}

/****************************************************************************/
bool  pumpingTest(vector<string> var, vector<string> expo, vector<int> min){
    bool isRegular = true;
    int i = 0, j = 0, k = 0, l = 0, n = 0, p = 0;
    int intCount = 0;
    int stringPositionA = 0, stringPositionB = 0, stringPositionC = 0;
    int tempA = 0, tempB = 0, tempC = 0;
    string testString;
    string x;
    string y;
    string z;

/***********Checks if all exponents are ints Always regular ***************/
    for(i = 0; i < var.size(); ++i){
        if (isdigit(expo[i][0])){
            intCount = intCount + 1;
        }
    }
    if (intCount == var.size()){
        return isRegular;
    }
/***************Checks for 1 variable*********************/
    if (var.size() == 1){
        return isRegular;
    }
/****************Checks for 2 variables******************/
    if(var.size() ==2){
        //if ((var.size() - intCount) == 1){
    //Finds temp string of at at least length 4
            for(i = 0; i < 3; ++i){
                
                if (isdigit(expo[0][0])){
                tempA = stoi(expo[0]);
                }
                else tempA = i + min[0];
                
                if (isdigit(expo[1][0])){
                    tempB = stoi(expo[1]);
                }
                else tempB = i + min[1];
                
                for(j = 0; j < tempA; ++j){
                    testString = testString + var[0];
                }
                for(k = 0; k < tempB; ++k){
                    testString = testString + var[1];
                }
                if (testString.size() >= 4){
                    cout << "\n\nTest String: " << testString << endl;
                    break;
                }
                testString = "";
            }
        //}

    // Parses data into XYZ ******(Y >= 1)****(|XY| <= p)***(XY^NZ E L)
        p = int(testString.size());
    //Left Parse
        //Find X
        x = testString[0];
        for (i = 0; i < testString.size(); ++i){
            if (testString[i + 2] == x[0]){
                x = x + testString[i];
                stringPositionA += 1;
            }
            else{
                y = testString[i];
                stringPositionA += 1;
                break;
            }
        }
        //Find Y
        stringPositionB = stringPositionA;
        for (i = 0; i < testString.size(); ++i){
            if (testString[i + 2 + stringPositionA] == y[0]){
                y = y + testString[i + stringPositionA];
                stringPositionB += 1;
            }
            else{
                z = z + testString[i + stringPositionA + 1];
                stringPositionB += 1;
                cout << stringPositionB;
                break;
            }
        }
        //Find Z
        for (i = 1; i < testString.size(); ++i){
            z = z + testString[i + stringPositionB];
        }
        cout <<"\n****Case 1: Left Parse " << "****" << endl;
        cout <<"    X: " << x << endl;
        cout <<"    Y: " << y << endl;
        cout <<"    Z: " << z << endl;
    }

/****************Checks for 2 variables******************/
    if(var.size() ==3){
        cout << "\nFIXME 3 Variables" << endl;
    }
    return false;
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

