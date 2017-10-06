#pragma once
#include "stdafx.h"
#include "fstream"
#include "exception"
#include "cassert"
#include "time.h"
using namespace std;

/*
@overview:The Sudoku class a mutable.It has a sudoku board of size 9x9 and can generate or solve a sudoku
*/
#define LEN 9
#define RANDOMHOLES 0
#define UPDOWNHOLES 1
#define EASYMODE 1
#define NORMALMODE 2
#define HARDMODE 3

enum ModeRange {
	EASYLOWER = 35,
	EASYUPPER = 45,
	NORMALLOWER = 45,
	NORMALUPPER = 55,
	HARDLOWER = 55,
	HARDUPPER = 64
};

class Sudoku
{
private:
	char board[LEN + 1][LEN + 1];
	void init();
	inline void trace_back_n(int i, int j, int n, int result[][LEN * LEN]);
	inline bool trace_back_solve(int i, int j);
	inline int get_block(int i);
	static long int count;
	//below is the fast code
	static char* out;
	static long int out_pos;
public:
	Sudoku();
	Sudoku(char **b);
	Sudoku(Sudoku &b);
	char* toString();
    void generate(int number, int lower, int upper, bool unique, int result[][LEN*LEN]);
	void digHoles(int count, int mode, int lower, int upper, int result[][LEN*LEN]);
	void generate(int number, int mode, int result[][LEN*LEN]);
	void generateCompleteN(int number, int result[][LEN*LEN]);
	void generateCompleteNAndOutput(int number, char * filename);
	void trace_back_write_file(int i,int j,int number, fstream& outFile);
	void set(char b[][LEN + 1]);
	int countSolutionNumber(int solution[],int bound);
	void trace_back_count_solution(int i, int j, int* solutionNumber,int bound);
	bool solve(int puzzle[], int solution[]);
	void convertToTwoDimension(int puzzle[]);
	void convertToOneDimension(int solution[]);
	bool check();
	bool check_pos(int i, int j);
	bool check_generate_pos(int i, int j, int k);
	bool check_solve_pos(int i, int j, int k);
};

class IllegalLengthException :public exception {
public:
    const char* what() const throw();
};

class SudokuCountException :public exception {
public:
    const char* what() const throw();
};

class ResultRowTooFewException :public exception {
public:
    const char* what() const throw();
};

class LowerUpperException :public exception {
public:
    const char* what() const throw();
};

class ModeRangeException :public exception {
public:
    const char* what() const throw();
};
