#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Sudoku_GUI.h"

class QStackedWidget;
class QWidget;
class QPushButton;
class Sudoku;
class QTime;
class QTimer;
class QLabel;


class Sudoku_GUI : public QMainWindow
{
	Q_OBJECT

public:
	Sudoku_GUI(QWidget *parent = Q_NULLPTR);
	void pressButtonWelcome();
	void pressButtonDifficulty();
	void pressButtonPuzzle();
	void pressButtonChoice();
	void pressButtonHint();


private:
	Ui::Sudoku_GUIClass ui;
	QStackedWidget* mainWindow;
	QStackedWidget* welcomeWindow;
	QWidget* gameWindow;
	QPushButton*** puzzleButtons;
	Sudoku* sudoku;
	QTimer* timer;
	QTime* timeRecord;
	QLabel* timeLabel;
	bool begin;

	void gameSet(int degOfDiffculty);
	void currentPositionSet(int x, int y);
	int checkGame();
	void gameCompleted(int flag);
	void timeUpdate();
	void newGameMenuClicked();
	void resetTimer();
	void checkTimeRecord();
	void initRecord();
};
