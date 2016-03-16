#include <iostream>
 #include <string.h>

using namespace std;

char** AllocArrayOfWords(int);
void CharSwap(char* &, char* &);
void Display(int*, char**, int n);
char** ObtainWords(char*, int &);
int* SearchAndCalculateRightWords(char** str, int k, char **words, int n);
void ShakerSort(int *a, int n, char**words);
void Swap(int &x, int &y);
void Swap(char* &x, char* &y);

const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";




int main()
 {
	
		while (true)
		 {
		cout.width(50);
		cout << endl << "Welcome to the programm!";
		cout << endl << endl << "*******************************************************************************" << endl << endl;
		
			char *str = new char[256];
		cout << "Enter the string: ";
		cin.getline(str, 255, '\n');
		cout << "How many words do you want to search? ";
		int n = 0;
		cin >> n;
		char **words = AllocArrayOfWords(n);
		system("cls");
		system("cls");
		int m = 0;
		char **WordsString = ObtainWords(str, m);
		int *a = SearchAndCalculateRightWords(WordsString, m, words, n);
		ShakerSort(a, n, words);
		Display(a, words, n);
		system("pause");
		system("cls");
		char s;
		cout << "Would you like to countinie? " << endl;
		cout << "Yes- y or Y " << endl;
		cout << "No- other symbols" << endl;
		cout << "Waiting for Enter: " << endl;
		cin >> s;
		system("cls");
		if (s == 'y' || s == 'Y') continue;
		break;
		
			}
	
		return 0;
	}

int* SearchAndCalculateRightWords(char** str, int k, char **words, int n)
 {
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		 {
		a[i] = 0;
		for (int j = 0; j < k; j++)
			 {
			if (strcoll(str[j], words[i]) == 0)
				 {
				a[i]++;
				}
			}
		}
	return a;
	}

char** AllocArrayOfWords(int n)
 {
	char**arr = new char*[n];
	getchar();
	for (int i = 0; i < n; i++)
		 {
		cout << "Enter " << i + 1 << " word: ";
		arr[i] = new char[256];
		cin.getline(arr[i], 255, '\n');
		}
	return arr;
	}


void ShakerSort(int *a, int n, char** words)
 {
	int leftMark = 1;
	int rightMark = n - 1;
	char* tmp;
	while (leftMark <= rightMark)
		 {
		for (int i = rightMark; i >= leftMark; i--)
			 if (a[i - 1] > a[i])
			 {
			Swap(a[i], a[i - 1]);
			Swap(words[i], words[i - 1]);
			
				}
		leftMark++;
		
			
			for (int i = leftMark; i <= rightMark; i++)
			 if (a[i - 1] > a[i])
			 {
			Swap(a[i], a[i - 1]);
			Swap(words[i], words[i - 1]);
			}
		rightMark--;
		
			}
	}


void Display(int*k, char** str, int n)
 {
	
		for (int i = 0; i < n; i++)
		 {
		cout << str[i] << " - " << k[i] << " times" << endl;
		}
	}
char** ObtainWords(char* str, int &k)
 {
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char** words = new char*[strlen(str) / 2];
	k = 0;
	char* pword = strpbrk(str, symbols);
	while (pword)
		{
		int length = strspn(pword, symbols);
		words[k] = new char[length + 1];
		strncpy(words[k], pword, length);
		words[k][length] = '\0';
		pword += length;
		pword = strpbrk(pword, symbols);
		k++;
		}
	return words;
	}

void Swap(int &x, int &y)
 {
	int temp;
	temp = x;
	x = y;
	y = temp;
	}

void Swap(char* &x, char* &y)
{
	char* temp;
	temp = x;
	x = y;
	y = temp;
}

