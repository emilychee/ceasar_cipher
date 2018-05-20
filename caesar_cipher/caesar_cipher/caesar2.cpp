//
//  caesar2.cpp
//  caesar_cipher
//
//  Created by Emily Denise Chatterjee on 12/3/16.
//  Copyright © 2016 Emily Denise Chatterjee. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_LETTERS = 26;
string encode_text(string user_input, char plain_alphabet[],
                   char cipher_alphabet[]);

int main () {
    
    string user_input = "";
    string plaintext = "";
    string ciphertext = "";
    int shift;
    char direction;
    
    cout << "What shift do you want? (Enter a number 1 through 26) ";
    cin >> shift;
    cout << "What direction do you want the shift? (Choose 'L' for left or" <<
            " 'R' for right) ";
    cin >> direction;
    
    char plain_alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                             'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                             'u', 'v', 'w', 'x', 'y', 'z'};
    char cipher_alphabet[NUM_LETTERS];
    
    if (toupper(direction) == 'L') {
        // initializing all values in ciphertext
        for (int i = 0; i < NUM_LETTERS; i++) {
            if (i >= shift) {
                cipher_alphabet[i] = plain_alphabet[i - shift];
            }
            else if (i < shift) {
                cipher_alphabet[i] = plain_alphabet[(NUM_LETTERS + i) - shift];
            }
        }
    }
    if (toupper(direction) == 'R') {
        // initializing all values in ciphertext
        for (int i = 0; i < NUM_LETTERS; i++) {
            if (i < NUM_LETTERS - shift) {
                cipher_alphabet[i] = plain_alphabet[i + shift];
            }
            else if (i < NUM_LETTERS) {
                cipher_alphabet[i] = plain_alphabet[i - (NUM_LETTERS - shift)];
            }
        }

    }
    
    // asks user for plaintext
    cout << "Enter the messsage you want encoded (all lower case letters please): ";
    getline(cin, user_input);
    plaintext += user_input;
    ciphertext += encode_text(user_input, plain_alphabet, cipher_alphabet);
    
    // keeps encoding lines of user entered text
    while (getline(cin, user_input) && user_input != "") {
        // might need spaces in between
        plaintext += user_input;
        ciphertext += encode_text(user_input, plain_alphabet, cipher_alphabet);
    }
    cout << endl;
    
    // prints out cipher text
    cout << "CIPHERTEXT: " << ciphertext << endl;
    
    return 0;
}

string encode_text(string user_input, char plain_alphabet[], char cipher_text[])
{
    string encodedtext = user_input;
    for (int i = 0; i < user_input.length(); i++) {
        for (int j = 0; j < NUM_LETTERS; j++) {
            if (plain_alphabet[j] == user_input[i]) {
                encodedtext[i] = cipher_text[j];
            }
        }
    }
    return encodedtext;
}

