#include <iostream>
#include <deque>
#include <memory.h>
using namespace std;

bool reversed;
deque<char> str;
int hashCount[1 << 20];

void pushBack(char x)
{
    str.push_back(x);

    int i = str.size() - 1;
    int cnt = 0;
    int hash = 0;
    int exp = 1;
    while (i > -1 && cnt < 4)
    {
        hash += exp * (str[i] - 'a' + 1);
        exp <<= 5;
        hashCount[hash]++;
        i--;
        cnt++;
    }
}

void pushFront(char x)
{
    str.push_front(x);
    int i = 0;
    int cnt = 0;
    int hash = 0;
    int exp = 1;
    while (str[i] && cnt < 4)
    {
        hash <<= 5;
        hash += (str[i] - 'a' + 1);
        hashCount[hash]++;
        i++;
        cnt++;
    }
}

void popBack()
{
    int i = str.size() - 1;
    int cnt = 0;
    int hash = 0;
    int exp = 1;
    while (i > -1 && cnt < 4)
    {
        hash += exp * (str[i] - 'a' + 1);
        exp <<= 5;
        hashCount[hash]--;
        i--;
        cnt++;
    }
    str.pop_back();
}

void popFront()
{
    int i = 0;
    int cnt = 0;
    int hash = 0;
    int exp = 1;
    while (str[i] && cnt < 4)
    {
        hash <<= 5;
        hash += (str[i] - 'a' + 1);
        hashCount[hash]--;
        i++;
        cnt++;
    }
    str.pop_front();
}

void init(char mStr[])
{
    str.clear();
    reversed = false;
    memset(hashCount, 0, sizeof(hashCount));

    int i = 0;
    while (mStr[i])
    {
        pushBack(mStr[i]);
        i++;
    }
}

void appendWord(char mWord[])
{
    int i = 0;
    if (reversed)
    {
        while (mWord[i])
        {
            pushFront(mWord[i]);
            i++;
        }
    }
    else
    {
        while (mWord[i])
        {
            pushBack(mWord[i]);
            i++;
        }
    }
}

void cut(int k)
{
    int i = 0;
    if (reversed)
    {
        while (i < k)
        {
            popFront();
            i++;
        }
    }
    else
    {
        while (i < k)
        {
            popBack();
            i++;
        }
    }
}

void reverse()
{
    reversed = !reversed;
}

int countOccurrence(char mWord[])
{
    int i = 0;
    int hash = 0;
    if (reversed)
    {
        int exp = 1;
        while (mWord[i])
        {
            hash += exp * (mWord[i] - 'a' + 1);
            exp <<= 5;
            i++;
        }
    }
    else
    {
        while (mWord[i])
        {
            hash <<= 5;
            hash += (mWord[i] - 'a' + 1);
            i++;
        }
    }
    return hashCount[hash];
}