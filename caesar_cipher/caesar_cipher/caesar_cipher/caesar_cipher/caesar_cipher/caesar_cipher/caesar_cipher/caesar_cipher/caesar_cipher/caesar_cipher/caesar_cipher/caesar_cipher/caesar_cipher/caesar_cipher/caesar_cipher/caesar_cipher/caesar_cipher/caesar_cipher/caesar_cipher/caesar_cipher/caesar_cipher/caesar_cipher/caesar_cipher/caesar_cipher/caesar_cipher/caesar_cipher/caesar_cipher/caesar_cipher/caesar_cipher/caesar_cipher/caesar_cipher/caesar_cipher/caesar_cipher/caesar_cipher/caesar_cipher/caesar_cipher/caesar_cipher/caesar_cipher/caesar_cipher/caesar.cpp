//
//  main.cpp
//  caesar_cipher
//
//  Created by Emily Denise Chatterjee on 12/2/16.
//  Copyright © 2016 Emily Denise Chatterjee. All rights reserved.
//
// first: Make program that asks for text (can be multiple sentences long),
// encodes the entered text using the traditional caesar cipher shift of left 3,
// and outputs PLAINTEXT: "plaintext" and
// CIPHERTEXT: "ciphertext"
//
// second: Allow user to pick the shift they want and in what direction they
// want the shift. Also don't output plaintext; only output ciphertext.
//
// third: Add menu to program.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_LETTERS = 26;
const int SHIFT = 3;
string encode_text(string user_input, char plain_alphabet[],
                   char cipher_alphabet[]);


int main() {
    
    string user_input = "";
    string plaintext = "";
    string ciphertext = "";
    
    char plain_alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                             'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                             'u', 'v', 'w', 'x', 'y', 'z'};
    char cipher_alphabet[NUM_LETTERS];
    
    // initializing all values in ciphertext
    for (int i = 0; i < NUM_LETTERS; i++) {
        if (i < NUM_LETTERS - SHIFT) {
            cipher_alphabet[i] = plain_alphabet[i + SHIFT];
        }
        else if (i < NUM_LETTERS) {
            cipher_alphabet[i] = plain_alphabet[i - 22];
        }
    }
    
    // asks user for plaintext
    cout << "Enter messsage you want encoded (all lower case letters please): ";
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
    
    // prints out plain and cipher text
    cout << "PLAINTEXT: " << plaintext << endl;
    cout << endl;
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






