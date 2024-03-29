//
//  main.cpp
//  PumpingLemma

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

vector<string> readLine();
bool pumpingTest(vector <string> var, vector <string> expo, vector<int> min);
bool checkPumpedString (vector <string> var, vector <string> expo, vector<int> min, string x, string y, string z);

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
    
    cout << "Enter each exponent. If variable has no exponent enter 1.\n\n";
    
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
    
    cout << "\n\nYou entered: ";
    for (i = 0; i < var.size(); ++i)
    {
        cout << var[i] << "^" << expo[i] << " ";
    }
    
    
    
    
    isRegular = pumpingTest(var,expo,min);
    
    if (isRegular){
        cout << "\n\nThe language passed the pumping lemma test\n\n" << endl;
    }
    else{
        cout << "\nThe language is not regular\n\n" << endl;
    }
    return 0;
}

/****************************************************************************/
bool  pumpingTest(vector<string> var, vector<string> expo, vector<int> min){
    bool isRegular = false;
    int i = 0, j = 0, k = 0, l = 0, p = 0, varChange = 0;
    int intCount = 0;
    int stringPositionA = 0, stringPositionB = 0, stringPositionC = 0;
    int tempA = 0, tempB = 0, tempC = 0;
    char checkVar;
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
        isRegular = true;
        return isRegular;
    }
    /***************Checks for 1 variable*********************/
    if (var.size() == 1){
        isRegular = true;
        return isRegular;
    }
    /****************Checks for 2 variables******************/
    if(var.size() ==2){
        if (intCount == 1){
            isRegular = true;
            return isRegular;
        }
        for(i = 0; i < 3; ++i){
            
            //Checks if first variable's exponnent is an int or a variable
            if (isdigit(expo[0][0])){
                tempA = stoi(expo[0]);
            }
            else tempA = i + min[0];
            
            
            //Checks if second variable's exponnent is an int or a variable
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
        p = min[0];
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
        cout <<"\nCase 1: Because |XY| <= P we know that Y must be in section " << "\"" << var[0] << "\""  << endl;
        cout <<" P = " << min[0] << endl;
        cout <<"    X: " << x << endl;
        cout <<"    Y: " << y << endl;
        cout <<"    Z: " << z << endl;
        return checkPumpedString (var, expo, min, x, y, z);
    }
    
    /****************Checks for 3 variables******************/
    if(var.size() ==3){
            p = min[0] + min[1] + 1;
        //*******************Creats test string*************/
        for(i = 0; i < 3; ++i){
            //Checks if first variable's exponnent is an int or a variable
            if (isdigit(expo[0][0])){
                tempA = stoi(expo[0]);
            }
            else {
                tempA = i + p;
            }
            
            //Checks if second variable's exponnent is an int or a variable
            if (isdigit(expo[1][0])){
                tempB = stoi(expo[1]);
            }
            else {
                if (expo[0] == expo[1]){
                    tempB = tempA;
                }
                else if (isdigit(expo[0][0])){
                    tempB = i + p;
                }
                else{
                    tempB = i + min[1];
                    }
                }
            //Checks if second variable's exponnent is an int or a variable
            if (isdigit(expo[2][0])){
                tempC = stoi(expo[2]);
            }
            else {
                if (expo[2] == expo[1]){
                    tempC = tempB;
                }
                else if (expo[2] == expo[0]){
                    tempC = tempA;
                }
                else{
                    tempC = i + min[2];
                }
            }
            
            
            for(j = 0; j < tempA; ++j){
                testString = testString + var[0];
            }
            for(k = 0; k < tempB; ++k){
                testString = testString + var[1];
            }
            for(l = 0; l < tempC; ++l){
                testString = testString + var[2];
            }
            
            
            if (testString.size() >= 6){
                cout <<"\n\n***********************************************************" << endl;
                cout << "*             Test String: " << testString << endl;
                cout <<"***********************************************************" << endl;
                break;
            }
            testString = "";
        }
        
        if(intCount == 2){
            isRegular = true;
            return isRegular;
        }
        else{
            
    //**********************************************Case 1**********************************************
            /*if(!isdigit(expo[0][0])) {
                p = min[0];
            } else if(!isdigit(expo[1][0])) {
                p = min[0] + min[1];
            } else {
                p = min[0] + min[1] + 1;
            }*/
            
            x = testString[0];
            
            for (i = 0; i < p; ++i){
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
            for (i = 0; i < (p + stringPositionA); ++i){
                if (testString[i + 2 + stringPositionA] == y[0]){
                    y = y + testString[i + stringPositionA];
                    stringPositionB += 1;
                }
                else{
                    stringPositionB += 1;
                    break;
                }
            }
            //Find Z
            for (i = stringPositionB; i < testString.size(); ++i){
                z = z + testString[i];
            }
            cout <<"\n\n********************  Case: 1  Y = (a) *****************************" << endl;
            cout << "\nTest String: " << testString << endl;
            cout <<" P = " << p << endl;
            cout <<"    X: " << x << endl;
            cout <<"    Y: " << y << endl;
            cout <<"    Z: " << z << endl;
            if (checkPumpedString (var, expo, min, x, y, z)){
                cout << "     Case 1: Pass";
                isRegular = true;
            }
            else{
                cout << "     Case 1: Fail";
            }
            //Clear strings/ string positions
            x = y = z = "";
            stringPositionA = stringPositionB = stringPositionC = 0;
            
        //**********************************************Case 2**********************************************
            
            x = testString[0];
            for (i = 0; i < testString.size(); ++i){
                if (testString[i + 2] == x[0]){
                    x = x + testString[i];
                    stringPositionA += 1;
                }
                else{
                    if ((stringPositionA + 1) < p){
                    y = y + testString[i];
                    stringPositionA += 1;
                    }
                    break;
                }
            }
            //Find Y
            
            if ((stringPositionA + 1) < p){
            y = y + testString[stringPositionA + 1];
            }
            
            stringPositionB = stringPositionA;
            stringPositionB += 1;
            
            //Find Z
            for (i = stringPositionB; i < testString.size(); ++i){
                z = z + testString[i];
            }
            
            cout <<"\n\n*************************  Case: 2  Y = (ab) **********************************" << endl;
            cout << "\nTest String: " << testString << endl;
            cout <<" P = " << p << endl;
            cout <<"    X: " << x << endl;
            cout <<"    Y: " << y << endl;
            cout <<"    Z: " << z << endl;
            if (checkPumpedString (var, expo, min, x, y, z) && (y.size() == 2)){
                cout << "     Case 2: Pass";
                isRegular = true;
            }
            else{
                cout << "     Case 2: Fail";
            }
            
            
            //Clear strings/ string positions
            x = y = z = "";
            stringPositionA = stringPositionB = stringPositionC = 0;
            
        //**********************************************Case 3**********************************************
            checkVar = testString[0];
            //Find X
            for (i = 0; i < testString.size(); ++i){
                if (testString[i+1] != checkVar) {
                    checkVar = testString[i];
                    varChange = varChange + 1;
                }
                
                if (varChange <= 1){
                    if (stringPositionA > (p - 1)){
                        cout << "Greater Than P: " << p;
                        break;
                    }
                    else{
                        x = x + testString[i];
                        stringPositionA += 1;
                    }
                }
                
                else{
                    if (stringPositionA >= p){
                        cout << "Greater Than P: " << p;
                        break;
                    }
                    
                    else {
                        y = y + testString[i];
                        stringPositionA += 1;
                    }
                    
                    break;
                }
            }
            //Find Y
            stringPositionB = stringPositionA;
            
            //Find Z
            for (i = stringPositionB; i < testString.size(); ++i){
                z = z + testString[i];
            }
            
            
            cout <<"\n\n*************************  Case: 3 Y = (b) **********************************" << endl;
            cout << "\nTest String: " << testString << endl;
            cout <<" P = " << p << endl;
            cout <<"    X: " << x << endl;
            cout <<"    Y: " << y << endl;
            cout <<"    Z: " << z << endl;
            if (checkPumpedString (var, expo, min, x, y, z)){
                cout << "     Case 3: Pass";
                isRegular = true;
            }
            else{
                cout << "     Case 3: Fail";
            }
            
            //Clear strings/ string positions
            x = y = z = "";
            stringPositionA = 0;
            stringPositionB = 0;
            stringPositionC = 0;
            varChange =0;
            
        //**********************************************Case 4**********************************************
            checkVar = testString[0];
            for (i = 0; i < testString.size(); ++i){
                if (testString[i + 1] != checkVar) {
                    checkVar = testString[i];
                    varChange = varChange + 1;
                }
                
                if (varChange <= 2){
                    if (stringPositionA > (p - 1)){
                        //break;
                    }
                    else{
                        x = x + testString[i];
                        stringPositionA += 1;
                    }
                }
                
                else{
                    if (stringPositionA >= p){
                        //break;
                    }
                    
                    else {
                        y = testString[i];
                        stringPositionA += 1;
                    }
                    
                    break;
                }
            }
            //Find Y
            if (stringPositionA < p){
                y = y + testString[stringPositionA + 1];
            }
            
            
            stringPositionB = stringPositionA;
            //Find Z
            for (i = stringPositionB; i < testString.size(); ++i){
                z = z + testString[i];
            }
            
            
            cout <<"\n\n*************************  Case: 4  Y = (bc) **********************************" << endl;
            cout << "\nTest String: " << testString << endl;
            cout <<" P = " << p << endl;
            cout <<"    X: " << x << endl;
            cout <<"    Y: " << y << endl;
            cout <<"    Z: " << z << endl;
            if (checkPumpedString (var, expo, min, x, y, z) && (y.size() == 2)){
                cout << "     Case 4: Pass";
                isRegular = true;
            }
            else{
                cout << "     Case 4: Fail" << endl;
            }
            
            //Clear strings/ string positions
            x = y = z = "";
            stringPositionA = stringPositionB = stringPositionC = 0;
            varChange = 0;
            
            
    //**********************************************Case 5**********************************************
            
            checkVar = testString[0];
            //Find X
            for (i = 0; i < testString.size(); ++i){
                if (testString[i + 1] != checkVar) {
                    checkVar = testString[i];
                    varChange = varChange + 1;
                }
                
                if (varChange <= 2){
                    if (stringPositionA > (p - 1)){
                        cout << "Greater Than P: " << p;
                        break;
                    }
                    else{
                        x = x + testString[i];
                        stringPositionA += 1;
                    }
                }
                
                else{
                    if (stringPositionA >= p){
                        cout << "Greater Than P: " << p;
                        break;
                    }
                    
                    else {
                        x = x + testString[i];
                        stringPositionA += 1;
                    }
                    
                    break;
                }
            }
            //Find Y
            if (stringPositionA < p){
                y = y + testString[stringPositionA + 1];
            }
            else{
                cout << "Greater Than P: " << p;
            }
            
            stringPositionB = stringPositionA;
            //Find Z
            for (i = stringPositionB; i < testString.size(); ++i){
                z = z + testString[i];
            }
            
            cout <<"\n\n*************************  Case: 5  Y = (c) **********************************" << endl;
            cout << "\nTest String: " << testString << endl;
            cout <<" P = " << p << endl;
            cout <<"    X: " << x << endl;
            cout <<"    Y: " << y << endl;
            cout <<"    Z: " << z << endl;
            if (checkPumpedString (var, expo, min, x, y, z)){
                cout << "     Case 5: Pass";
                isRegular = true;
            }
            else{
                cout << "     Case 5: Fail" << endl;
            }
        }
    }
    
    if (isRegular){
        return isRegular;
    }
    else{
        cout << "\n\nGiven that \""<< testString << "\" is an ellement of our language and all possible test cases failed to produce a y which can be pumped this shows a contradication and therefor proves :" << endl;
        return isRegular;
    }
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

/*************************Checks if Pumped string is an ellement of input langage ***********************/
bool checkPumpedString (vector <string> var, vector <string> expo, vector<int> min, string x, string y, string z){
    int i = 0;
    int stringPositionA = 1, stringPositionB = 0, stringPositionC = 0;
    string printString = (x + y + z);
    string pumpedY = y;
    string testString;
    string A,B,C;
    string checkingString;
    
    if (y == ""){
        cout << "\n\n               ********   MISSING Y  *********\n\n";
        return false;
    }
    
    if (var.size() ==2){
        pumpedY = pumpedY + y;
        pumpedY = pumpedY + y;
        testString = x + pumpedY + z;
        cout << "\n\nPumped test string: " << testString << endl;
        
        //Parses the Data into the first and second variables
        A = testString[0];
        for (i = 1; i < testString.size(); ++i){
            if (testString[i] == x[0]){
                A = A + testString[i];
                stringPositionA += 1;
            }
            else{
                B = testString[i];
                stringPositionA += 1;
                break;
            }
        }
        //Find B
        stringPositionB = stringPositionA;
        for (i = 0; i < testString.size(); ++i){
            if (testString[i + stringPositionA] == B[0]){
                B = B + testString[i + stringPositionA];
                stringPositionB += 1;
            }
            else{
                break;
            }
        }
        
        cout << var[0] << "^" <<expo[0] << " (" << expo[0] << " >= " << min[0] << "): " << A << endl;
        cout << var[1] << "^" <<expo[1] << " (" << expo[1] << " >= " << min[1] << "): " << B << endl;
        //****************Checks if test string is an element of the language*/
        if (expo[0] == expo[1]){
            if (A.size() == B.size()){
                return true;
            }
            else{
                cout << "\n\nGiven that \"" << printString << "\" is part of our language and by pumping \"" << y << "\" we can show that the new pumped string \"" << testString <<"\" is not an ellement of our language, becasue we have two different values for \"" << expo[0] << "\" this shows a contradiction and therefor proves:\n";
                return false;
            }
        }
        else if ((A.size() >= min[0]) && (B.size() >= min[1])){
            return true;
        }
        else{
            return false;
        }
    }
    else if (var.size() ==3){
        pumpedY = pumpedY + y;
        pumpedY = pumpedY + y;
        testString = x + pumpedY + z;
        cout << "\n\nPumped test string: " << testString << endl;
        
        //Parses the Data into the first and second variables
        A = testString[0];
        
        for (i = 1; i < testString.size(); ++i){
            if (testString[i] == x[0]){
                A = A + testString[i];
                stringPositionA += 1;
            }
            else{
                B = testString[i];
                stringPositionA += 1;
                break;
            }
        }
        //Find B
        stringPositionB = stringPositionA;
        for (i = 0; i < testString.size(); ++i){
            if (testString[i + stringPositionA] == B[0]){
                B = B + testString[i + stringPositionA];
                stringPositionB += 1;
            }
            else{
                C = testString[i + stringPositionA];
                stringPositionB +=1;
                break;
            }
        }
        //Find C
        stringPositionC = stringPositionB;
        for(i = 0; i < testString.size(); ++i){
            if(testString[i + stringPositionB] == C[0]){
                C = C + testString[i + stringPositionB];
                stringPositionC +=1;
            }
            else{
                break;
            }
        }
        
        cout << var[0] << "^" <<expo[0] << " (" << expo[0] << " >= " << min[0] << "): " << A << endl;
        cout << var[1] << "^" <<expo[1] << " (" << expo[1] << " >= " << min[1] << "): " << B << endl;
        cout << var[2] << "^" <<expo[2] << " (" << expo[2] << " >= " << min[2] << "): " << C << endl;
        checkingString = A + B + C;
        //****************Checks if test string is an element of the language*/
        if (checkingString.size() != testString.size()){
            return false;
        }
        if((isdigit(expo[0][0]))){
            if (A.size() != stoi(expo[0])){
                return false;
            }
        }
        if((isdigit(expo[1][0]))){
            if (B.size() != stoi(expo[1])){
                return false;
            }
        }
        if((isdigit(expo[2][0]))){
            if (C.size() != stoi(expo[2])){
                return false;
            }
        }
        
        
        
        if (expo[0] == expo[1] && expo[1] == expo[2]){
            if (A.size() == B.size() && B.size() == C.size()){
                return true;
            }
            else{
                return false;
            }
        }
        else if(expo[0] == expo[1]){
            if (A.size() == B.size()){
                return true;
            }
            else{
                return false;
            }
        }
        else if(expo[0] == expo[2]){
            if (A.size() == C.size()){
                return true;
            }
            else{
                return false;
            }
        }
        else if(expo[1] == expo[2]){
            if (B.size() == C.size()){
                return true;
            }
            else{
                return false;
            }
        }
        else if ((A.size() >= min[0]) && (B.size() >= min[1]) && (C.size() >= min[2])){
            return true;
        }
        else{
            return false;
        }
    }
    
    return true;
}

