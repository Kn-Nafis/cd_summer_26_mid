#include <iostream>
#include <string>
using namespace std;

string keywords[] = {"int","float","char","double","if","else","for","while","return","void","cout","cin","endl"};
string operators[] = {"+","-","*","/","=","<<",">>","<",">","<=",">=","==","!=","%","++","--"};
string symbols[]={";",",","(",")","{","}","[","]","\""};

bool isKeyword(string str)
{
    for(int i=0;i<13;i++)
    {
        if(str==keywords[i])
            return true;
    }
    return false;
}

bool isOperator(string str)
{
    for(int i=0;i<16;i++)
    {
        if(str==operators[i])
            return true;
    }
    return false;
}

bool isSymbol(string str)
{
    for(int i=0;i<8;i++)
    {
        if(str==symbols[i])
            return true;
    }
    return false;
}

bool isConstant(string str)
{
    if(str.length()==0)
        return false;

    for(int i=0;i<str.length();i++)
    {
        if(!(str[i]>='0' && str[i]<='9'))
            return false;
    }
    return true;
}

bool identifierChecker(string str)
{
    if(str.length()==0)
        return false;

    if(!((str[0]>=65 && str[0]<=90) ||
         (str[0]>=97 && str[0]<=122) ||
          str[0]==95))
    {
        return false;
    }

    for(int i=1;i<str.length();i++)
    {
        if(!((str[i]>=65 && str[i]<=90) ||
             (str[i]>=97 && str[i]<=122) ||
             (str[i]>=48 && str[i]<=57) ||
              str[i]==95))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string exp;

    cout << "Enter Expression: ";
    getline(cin, exp);

    exp = exp + " ";

    int i = 0;
    int j = 0;

    bool insideString = false;

    while(j < exp.length())
    {
        if(exp[j] == ' ')
        {
            string token = "";

            for(int k = i; k < j; k++)
            {
                token += exp[k];
            }

            if(token != "")
            {
                cout << token << "  ";

                if(token == "\"")
                {
                    cout << "Punctuation";
                    insideString = !insideString;
                }
                else if(insideString)
                {
                    cout << "Constant";
                }
                else if(isKeyword(token))
                {
                    cout << "Keyword";
                }
                else if(isOperator(token))
                {
                    cout << "Operator";
                }
                else if(isSymbol(token))
                {
                    cout << "Punctuation ";
                }
                else if(isConstant(token))
                {
                    cout << "Constant";
                }
                else if(identifierChecker(token))
                {
                    cout << "Valid Identifier";
                }
                else
                {
                    cout << "Invalid Identifier";
                }

                cout << endl;
            }

            i = j + 1;
        }

        j++;
    }

    return 0;
}
