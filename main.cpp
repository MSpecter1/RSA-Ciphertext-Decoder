#include <iostream>
#include <sstream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

void decodeCipherText(string ciphertext, int d, int n);
void decodeToPlainText(string ciphertext, int d, int n, int NCoffset);
int decrypt(int c, int d, int n);
char numToChar(int n, int offset);

int main() {
    int p = 5;
    int q = 11;
    int n = p*q;
    int e  = 23;
    int d = 7;
    int offset = 2;

    string EncodedMessage = 
    "19    14    51    20     7    10    21 "
    "7    10    25     7    26    27    12 "
    "10    26    33    25     7    21    14 "
    "8    21     7    21    14    51     7 "
    "17    26     8    52    25     7     9 "
    "8     20    20    26    21     7    27 "
    "51     7    39    51     8     9    14 "
    "51    15     7    15    26     7    20 "
    "26    21     7     8    15    11    33 "
    "25    21     7    21    14    51     7 "
    "17    26     8    52    25     7     8 "
    "15    11    33    25    21     7    21 "
    "14    51     7     8     9    21    10 "
    "26    20     7    25    21    51    18 "
    "25";
    
    decodeCipherText(EncodedMessage, d, n);
    cout<<endl;
    decodeToPlainText(EncodedMessage, d, n, offset);

    return 0;
}

void decodeCipherText(string ciphertext, int d, int n)
{
    //decode a string into the unencrypted numbers
    std::stringstream stream;
    stream << ciphertext;
    string tempc;
    
    cout<<"DECODED MESSAGE: ";
    while (!stream.eof())
    {
        if(stream>>tempc)
        {
            int tempnum = 0;
            tempnum = std::stoi(tempc);
            cout<< decrypt(tempnum, d, n)<<", ";
        }
    }
    cout<<endl;
}

void decodeToPlainText(string ciphertext, int d, int n, int NCoffset)
{
    //decode a string and conver it to letters (using offset if required)
    std::stringstream stream;
    stream << ciphertext;
    string tempc;
    
    cout<<"PLAINTEXT MESSAGE: ";
    while (!stream.eof())
    {
        if(stream>>tempc)
        {
            int tempnum = 0;
            tempnum = std::stoi(tempc);
            cout<< numToChar(decrypt(tempnum, d, n), NCoffset);
        }
    }
    cout<<endl;
}

int decrypt(int c, int d , int n)
{
    //calculate decoded message without overflow
    unsigned int result=1;
    for (int i = 0; i< 7; i++)
    {
        result*=c;
        if (result>d)
        {
            result = result%n;
        }
    }
    return result;
}

char numToChar(int n, int offset)
{   // convert a number to a letter with adjustable integer offset
    //ascii 65 - 90 = A - Z
    char result = 0;
    result = n+65-offset;
    if (n == 28 )
    {
        result =' ';
    }
    return result;
}
