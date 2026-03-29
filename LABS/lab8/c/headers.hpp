#pragma once

int** CreateMatr(int n, int m);
void FreeMatr(int** M, int n);

bool InputFileMatr(int** M, int n, int m);
void OutputFileMatr(int** M, int n, int m);
void InputDescMatr(int** M, int n, int m);
void OutputDescMatr(int** M, int n, int m);
void RandomMatr(int** M, int n, int m, int A, int B);
