//
//  main.cpp
//  converter
//
//  Created by Tenzin Tashi on 1/18/19.
//  Copyright © 2019 Tenzin Tashi. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
using namespace std;

string input,inputFrom,inputTo,out;
int digit,converted,power,rem;

void menu(){
    cout << "Conveter"<<endl;
    cout << "1. Binary" << endl;
    cout << "2. Decimal" << endl;
    cout << "3. Octa" << endl;
    cout << "4. Hexa" << endl;
    cout << ">> ";
    cin >> inputFrom;
    cout <<endl;
    cout <<endl;
    
    system("ClS");
    
    cout << "To"<<endl;
    cout << "1. Binary" << endl;
    cout << "2. Decimal" << endl;
    cout << "3. Octa" << endl;
    cout << "4. Hexa" << endl;
    cout << ">> ";
    cin >> inputTo;
}

void binaryDecimal(){
    power = input.length() - 1;
    for (int i = 0; i < input.length(); i++){
        digit = (input[i] - '0') * pow(2,power);
        converted += digit;
        power--;
    }
}

void octaDecimal(){
    power = input.length() - 1;
    for (int i = 0; i < input.length(); i++){
        digit = (input[i] - '0') * pow(8,power);
        converted += digit;
        power--;
    }
}

void hexaDecimal(){
    power = input.length() - 1;
    for (int i = 0; i < input.length(); i++){
        if (input[i] == 'a' || input[i] == 'A'){
            digit = 10 * pow(16,power);
            goto down;
        }else if (input[i] == 'b' || input[i] == 'B'){
            digit = 11 * pow(16,power);
            goto down;
        }else if (input[i] == 'c' || input[i] == 'C'){
            digit = 12 * pow(16,power);
            goto down;
        }else if (input[i] == 'd' || input[i] == 'D'){
            digit = 13 * pow(16,power);
            goto down;
        }else if (input[i] == 'e' || input[i] == 'E'){
            digit = 14 * pow(16,power);
            goto down;
        }else if (input[i] == 'f' || input[i] == 'F'){
            digit = 15 * pow(16,power);
            goto down;
        }
        digit = (input[i] - '0') * pow(16,power);
    down:
        converted += digit;
        power--;
    }
}

void subBinary(){
    int i = 0;
    while (0 != converted){
        rem += (converted % 2) * pow(10,i);
        converted /= 2;
        i++;
    }
    converted = rem;
    
}

void subOcta(){
    int i = 0;
    while (0 != converted){
        rem += (converted % 8) * pow(10,i);
        converted /= 8;
        i++;
    }
    converted = rem;
}

void subHexa(){
    while (0 != converted){
        rem = converted % 16;
        if (rem == 10){
            out = 'A' + out;
            goto next;
        }else if (rem == 11){
            out = 'B' + out;
            goto next;
        }else if (rem == 12){
            out = 'C' + out;
            goto next;
        }else if (rem == 13){
            out = 'D' + out;
            goto next;
        }else if (rem == 14){
            out = 'E' + out;
            goto next;
        }else if (rem == 15){
            out = 'F' + out;
            goto next;
        }
        out = to_string(rem) + out;
    next:
        converted /= 16;
    }
    converted = rem;
}
int main(int argc, const char * argv[]) {

    menu();
    system("CLS");
    if (inputFrom == "2" || inputFrom == "Decimal" || inputFrom =="decimal" || inputFrom =="DECIMAL"){
        goto code;
    }
    cout << "Enter the expression: ";
    cin >> input;
    
    
    if(inputFrom == "1" || inputFrom == "Binary" || inputFrom =="binary" || inputFrom =="BINARY"){
        binaryDecimal();
    }else if(inputFrom == "2" || inputFrom == "Decimal" || inputFrom =="decimal" || inputFrom =="DECIMAL"){
        // enter here code
    code:
        cout << "Enter the expression: ";
        cin >> converted;
    }else if(inputFrom == "3" || inputFrom == "Octa" || inputFrom =="octa" || inputFrom =="octadecimal" || inputFrom =="OCTA" || inputFrom =="Octadecimal" || inputFrom =="OCTADECIMAL"){
        octaDecimal();
    }else if(inputFrom == "4" || inputFrom == "hexa" || inputFrom =="Hexa" || inputFrom =="hexadecimal" || inputFrom =="HEXA" || inputFrom =="Hexadecimal" || inputFrom == "HEXADECIMAL"){
        hexaDecimal();
    }else{
        cout << "You enter invalid number..."<<endl;
    }
    
    if(inputTo == "1" || inputTo == "Binary" || inputTo =="binary" || inputTo =="BINARY"){
        subBinary();
        cout << "\n"<<converted<<endl;
    }else if(inputTo == "2" || inputTo == "Decimal" || inputTo =="decimal" || inputTo =="DECIMAL"){
        // enter here code
        cout << "\n"<<converted<<endl;
        
    }else if(inputTo == "3" || inputTo == "Octa" || inputTo =="octa" || inputTo =="octadecimal" || inputTo =="OCTA" || inputTo =="Octadecimal" || inputTo =="OCTADECIMAL"){
        subOcta();
        cout << "\n"<<converted<<endl;
    }else if(inputTo == "4" || inputTo == "hexa" || inputTo =="Hexa" || inputTo =="hexadecimal" || inputTo =="HEXA" || inputTo =="Hexadecimal" || inputTo == "HEXADECIMAL"){
        subHexa();
        cout<<"\n"<< out<<endl;
    }else{
        cout << "You enter invalid number..."<<endl;
    }
    
    
    return 0;
}
