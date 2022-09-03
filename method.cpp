#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void encrypt_and_decrypt(string& user_text, string& user_key)
{
	int counter = 0;
	int counter_4 = 0;
	while (counter < user_text.length())
	{
		bool user_text_binary[8];
		bool user_key_binary[8];
		bool user_text_help[8];
		int counter_1, counter_2;
		char counter_3 = 0;
		if (user_text[counter] < 0)
			counter_1 = 256 + user_text[counter];
		else
			counter_1 = user_text[counter];
		for (int i = 7; i >= 0; i--)
		{
			user_text_binary[i] = counter_1 % 2;
			counter_1 = counter_1 / 2;
		}
		if (counter_4 == user_key.length())
			counter_4 = 0;
		if (user_key[counter_4] < 0)
			counter_2 = 256 + user_key[counter_4];
		else
			counter_2 = user_key[counter_4];
		for (int i = 7; i >= 0; i--)
		{
			user_key_binary[i] = counter_2 % 2;
			counter_2 = counter_2 / 2;
		}
		for (int i = 0; i < 8; i++)
		{
			if (user_text_binary[i] != user_key_binary[i])
				user_text_help[i] = 1;
			else
				user_text_help[i] = 0;
		}
		for (int i = 0; i < 8; i++)
		{
			counter_3 += user_text_help[i] * pow(2, 7 - i);
		}
		user_text[counter] = counter_3;

		counter++;
		counter_4++;
	}
	cout << user_text << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string user_text, user_key;

	cout << "Введите текст:";
	getline(cin, user_text);

	cout << "Введите ключ:";
	getline(cin, user_key);

	cout << "Encrypt_text:";
	encrypt_and_decrypt(user_text, user_key);
	cout << "Decrypt_text:";
	encrypt_and_decrypt(user_text, user_key);

	return 0;
}
