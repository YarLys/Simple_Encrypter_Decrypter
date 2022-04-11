#include <iostream>
#include <string>

using namespace std;

string strin, key, strout, strinascii, keyascii, strout1;
char c;
int mode, i, curlit; 

string bin(int curlit) {
    int x, j;
    x = curlit;
    string str = "";
    while (x != 0) {
        j = x % 2;
        str = to_string(j) + str;
        x = x / 2;
    }
    if (str.size() < 8) {
        while (str.size() < 8) {
            str = '0' + str;
        }
    }
    return str;
}

int dec(string current) { //returns integer form of a number after convertation from bin to dec
    int i, x, j;
    x = j = 0;
    j = current.size()-1;
    for (i = 0; i < current.size(); i++) {
        if (current[i] == '1') {
            x = x + pow(2, j);
        }
        j--;
    }
    return x;
}

int main()
{
    cout << "Hello! Welcome to Encryptor by YarLys! Please choose the option you want to use: " << endl;
    do {
        cout << "1 - Ecrypt a message." << endl;
        cout << "2 - Decrypt a message." << endl;
        cout << "3 - Exit a programm." << endl;
        cin >> mode;

        strin = strout1 = strout = strinascii = key = keyascii = "";
        if (mode == 1) {
            cout << "Write a message you want to encrypt: " << endl;
            cin >> ws;
            getline(cin, strin);
            cout << "Well Done! Please write a Key with length like your message for encryption. It can be any word or other symbols. Also don't forget it!" << endl;
            cin >> ws;
            getline(cin, key);            
            //Encryption
            for (i = 0; i < strin.size(); i++) {
                curlit = (int)strin[i];
                strinascii = strinascii + bin(curlit);
                curlit = (int)key[i];
                keyascii = keyascii + bin(curlit);
            }
            strout1 = "";
            strout1 = "";
            int res;
            for (i = 0; i < strinascii.size(); i++) {
                res = strinascii[i] ^ keyascii[i];
                strout1 = strout1 + to_string(res);
                if (((i + 1) % 8 == 0) and (i != 0)) {
                    int temp;
                    temp = dec(strout1);
                    strout1 = "";
                    strout = strout + to_string(temp) + " ";
                }
            }
            cout << "Nice! There is your encrypted message:" << endl;
            cout << strout << endl;
        }
        else if (mode == 2) {
            cout << "Write a message you want to decrypt: " << endl;
            cin >> ws;
            getline(cin, strin);
            cout << "Please write a key which was used to encrypt your message: " << endl;
            cin >> ws;
            getline(cin, key);
            //Split strin and key in numbers, then convert them from dec to bin
            int num = 0;
            strin = strin + " "; //extra ws to avoid infinite loop
            while (strin != "") {
                num = stoi(strin);
                strin = strin.substr(strin.find(" ") + 1);
                strinascii = strinascii + bin(num);
            }
            for (i = 0; i < key.size(); i++) {
                curlit = (int)key[i];
                keyascii = keyascii + bin(curlit);
            }
            //Decryption
            strout = "";
            strout1 = "";
            int res;
            for (i = 0; i < strinascii.size(); i++) {
                res = strinascii[i] ^ keyascii[i];
                strout1 = strout1 + to_string(res);
                if (((i + 1) % 8 == 0) and (i != 0)) {
                    int temp;
                    temp = dec(strout1);
                    strout1 = "";
                    strout = strout + (char)temp;
                }
            }
            cout << "There is your decrypted message: " << endl;
            cout << strout << endl;
        }
    } while (mode != 3);
    cout << "Thanks for using! GoodBye! ";
    return 0;
}