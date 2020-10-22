#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
    for(int i = 0;i<NO_OF_CHARS;i++)
        badchar[i] = -1;

    for (int i = 0; i<size;i++){
        badchar[(int) str[i]] = i;
    }
}
void search(string txt, string pat)
{
    int m = pat.size;
    int n = txt.size;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
