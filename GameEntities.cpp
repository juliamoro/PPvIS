#include <iostream>
#include "GameEntities.h"

using namespace std;

PlayingField::PlayingField(int size) {
	this->size_ = size;

	this->field_ = new int* [size];
	for (int i = 0; i < size; i++) {
		this->field_[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			this->field_[i][j] = 0;
		}
	}
}

PlayingField::~PlayingField() {
	for (int i = 0; i < this->size_; i++) {
		delete[] this->field_[i];
	}
	delete[] field_;
}

int* PlayingField::operator [] (int line)
{
	return field_[line];
}

bool PlayingField::set_figure(int line_choice, int col_choice) {

	if (figure_pres(line_choice, col_choice)) {
		return false;
	}
	else if (!figure_pres(line_choice, col_choice)) {
		if (this->player_) {
			field_[line_choice - 1][col_choice - 1] = 1;
		}
		else if (!this->player_) {
			field_[line_choice - 1][col_choice - 1] = 2;
		}
		this->player_ = !this->player_;
	}

	return true;

}

void PlayingField::cheat(int line_choice, int col_choice, int figure) {
	field_[line_choice - 1][col_choice - 1] = figure;
}

int PlayingField::horizontal_check() {
	int horizontal = 0;
	for (int i = 0; i < this->size_; i++) {
		horizontal = this->field_[i][0];
		for (int j = 0; j < this->size_; j++) {
			if (this->field_[i][j] != horizontal) {
				horizontal = 0;
				break;
			}
		}
		if (horizontal == 1) {
			return 1;
		}
		else if (horizontal == 2) {
			return 2;
		}
	}
	return 0;
}

int PlayingField::vertical_check() {
	int vertical = 0;
	for (int i = 0; i < this->size_; i++) {
		vertical = this->field_[0][i];
		for (int j = 0; j < this->size_; j++) {
			if (this->field_[j][i] != vertical && vertical != 0) {
				vertical = 0;
				break;
			}
		}
		if (vertical == 1) {
			return 1;
		}
		else if (vertical == 2) {
			return 2;
		}
	}
	return 0;
}

int PlayingField::diagonal_check() {
	int diagonal_1, diagonal_2;
	for (int i = 0; i < this->size_; i++) {
		diagonal_1 = field_[0][0];
		diagonal_2 = field_[0][this->size_ - 1];

		for (int i = 0; i < this->size_; i++) {

			if (field_[i][i] != diagonal_1) {
				diagonal_1 = 0;
				break;
			}
		}

		if (diagonal_1 == 1) {
			return 1;
		}

		else if (diagonal_1 == 2) {
			return 2;
		}

		for (int i = 0; i < this->size_; i++) {
			if (field_[i][this->size_ - 1 - i] != diagonal_2) {
				diagonal_2 = 0;
				break;
			}
		}
		if (diagonal_2 == 1) {
			return 1;
		}
		else if (diagonal_2 == 2) {
			return 2;
		}
	}
	return 0;
}

bool PlayingField::draw_check() {
	for (int i = 0; i < this->size_; i++) {
		for (int j = 0; j < this->size_; j++) {
			if (field_[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

int PlayingField::check() {
	if (horizontal_check() != 0) {
		return horizontal_check();
	}
	else if (vertical_check() != 0) {
		return vertical_check();
	}
	else if (diagonal_check() != 0) {
		return diagonal_check();
	}
	else return 0;
}

bool PlayingField::figure_pres(int line_choice, int col_choice) {
	if (this->field_[line_choice - 1][col_choice - 1] == 1 || this->field_[line_choice - 1][col_choice - 1] == 2) return true;
	else if (this->field_[line_choice - 1][col_choice - 1] == 0) return false;
}

bool PlayingField::field_boundaries(int line_choice, int col_choice) {
	if (line_choice - 1 >= this->size_ || line_choice - 1 < 0 || col_choice - 1 >= this->size_ || col_choice - 1 < 0) return false;
	else return true;
}

void PlayingField::field_output() {
	for (int i = 0; i < this->size_; ++i) {
		for (int j = 0; j < this->size_; ++j) {
			cout << "|";
			if (this->field_[i][j] == 0) cout << "_";
			else if (this->field_[i][j] == 1) cout << "x";
			else if (this->field_[i][j] == 2) cout << "o";
		}
		cout << "|" << endl;
	}
}