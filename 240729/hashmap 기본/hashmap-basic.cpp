#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define CMD_INIT    1
#define CMD_APPEND  2
#define CMD_CUT     3
#define CMD_REVERSE 4
#define CMD_COUNT   5

extern void init(char mStr[]);
extern void appendWord(char mWord[]);
extern void cut(int k);
extern void reverse();
extern int countOccurrence(char mWord[]);

char str[150001];

void init(char mStr[])
{
    strcpy(str,mStr);
    return;
}

void appendWord(char mWord[])
{
    strcat(str,mWord);
    return;
}

void cut(int k)
{
    string temp=str;
    int ts=temp.size();
    temp=temp.substr(0,ts-k);
    strcpy(str,temp.c_str());
    return;
    
}

void reverse()
{
    string temp=str;
    reverse(temp.begin(),temp.end());
    strcpy(str,temp.c_str());
    return;

}


int countOccurrence(char mWord[])
{
	return 0;
}

/*
void pr(){
    for(int i=0;i<150001;i++){
        if(str[i]=='\0')break;
        cout<<str[i];
    }
    cout<<"\n";
    return;
}
*/

int main(){
    
    char a[6];
    char b[6];
    scanf("%s", a);
    
    init(a);
    pr();
    
    scanf("%s", b);
    appendWord(b);
    pr();

    cut(3);
    pr();
    reverse( );
    pr();


}



/*
static bool run()
{
	bool correct = false;
	int queryCnt;
	scanf("%d", &queryCnt);
	static char mStr[30001], mWord[5];

	while (queryCnt--)
	{
		int cmd;
		scanf("%d", &cmd);

		if (cmd == CMD_INIT)
		{
			scanf("%s", mStr);
			init(mStr);
			correct = true;
		}
		else if (cmd == CMD_APPEND)
		{
			scanf("%s", mWord);
			
			if (correct)
			{
				appendWord(mWord);
			}
		}
		else if (cmd == CMD_CUT)
		{
			int k;
			scanf("%d", &k);
			
			if (correct)
			{
				cut(k);
			}
		}
		else if (cmd == CMD_REVERSE)
		{
			if (correct)
			{
				reverse();
			}
		}
		else if (cmd == CMD_COUNT)
		{
			scanf("%s", mWord);

			int ret = -1;
			if (correct)
			{
				ret = countOccurrence(mWord);
			}

			int ans;
			scanf("%d", &ans);
			if(ret != ans)
			{
				correct = false;
			}
		}
	}
	return correct;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}
	return 0;
}
*/