#include <iostream>
#include <string>
#include "GameEntities.h"

using namespace std;

bool is_number(const string& to_scan) {
	for (auto& i : to_scan)
		if (i < '0' || '9' < i) return true;
	return false;
}

int main()
{
	int size = 0, line_choice = 0, col_choice = 0;
	string str_size, str_line_choice, str_col_choice;

	cout << "Enter size of the field (from 3 to 20): " << endl << "> ";
	while (true) {
		cin >> str_size;
		if (!is_number(str_size)) {
			size = stoi(str_size);
			if (size >= 3 && size <= 20) break;
			else cout << "You should enter integer value from 3 to 20: " << endl << "> ";
		}
		else cout << "You should enter integer value from 3 to 20: " << endl << "> ";
	}
	PlayingField field(size);

	system("cls");

	while (true) {
		field.field_output();
		if (field.get_player()) {
			cout << "Turn of the player 1:" << endl << "> ";
		}
		if (!field.get_player()) {
			cout << "Turn of the player 2:" << endl << "> ";
		}

		while (true) {
			cin >> str_line_choice >> str_col_choice;
			if (!is_number(str_line_choice) && !is_number(str_col_choice)) {
				line_choice = stoi(str_line_choice);
				col_choice = stoi(str_col_choice);
				break;
			}
			else cout << "You should enter integer suitable for the size of the field:" << endl << "> ";
		}

		if (line_choice == 999 && col_choice == 999) {
			int cheat_line = 0, cheat_col = 0, cheat_figure;
			string str_cheat_line, str_cheat_col, str_cheat_figure;

			cout << "What figure do you want to place: 'x' or 'o' ?" << endl << "> ";
			while (true) {
				cin >> str_cheat_figure;
				if (str_cheat_figure == "x") {
					cheat_figure = 1;
					break;
				}
				if (str_cheat_figure == "o") {
					cheat_figure = 2;
					break;
				}
				else cout << "You shoold choose either 'x' or 'o'." << endl << "> ";
			}

			cout << "Choose the position of the figure: " << endl << "> ";
			while (true) {
				cin >> str_cheat_line >> str_cheat_col;
				if (!is_number(str_cheat_line) && !is_number(str_cheat_col)) {
					cheat_line = stoi(str_cheat_line);
					cheat_col = stoi(str_cheat_col);
					while (true) {
						if (!field.cheat(cheat_line, cheat_col, cheat_figure)) {
							cout << "Value of the coordinates must be suitable for the size of the field." << endl << "> ";
							cin >> cheat_line >> cheat_col;
						}
						else break;
					}
					break;
				}
				else cout << "You should enter integer values:" << endl << "> ";
			}

			system("cls");
		}

		else {
			if (!field.set_figure(line_choice, col_choice)) {
				system("cls");
				cout << "Position you choose must be empty and suitable for the size of the field." << endl;
			}
			else system("cls");
		}


		if (field.check() == 1) {
			system("cls");
			field.field_output();
			cout << "Player 1 wins!\n";
			break;
		}
		else if (field.check() == 2) {
			system("cls");
			field.field_output();
			cout << "Player 2 wins!\n";
			break;
		}


		if (field.draw_check()) {
			system("cls");
			field.field_output();
			cout << "Draw!";
			break;
		}
	}
}