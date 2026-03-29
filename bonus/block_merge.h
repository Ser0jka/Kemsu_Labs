#ifndef BLOCK_MERGE_H_INCLUDED
#define BLOCK_MERGE_H_INCLUDED

// Обмен двух блоков данных длиной size (без использования доп. памяти)
void swap_blocks(int *a, int i, int j, int size);

// Сортировка блоков массива как единых сущностей (вагонов)
// Сравнивает первые и последние элементы блоков (лексикографически)
void sort_blocks_metadata(int *a, int count, int size);

// Алгоритм слияния за O(N) без использования оператора new (temp массива)
// Использует корень из N как размер внутреннего буфера
void f_block_merge(int *a, int n);

#endif