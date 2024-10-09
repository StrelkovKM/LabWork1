
#define _CRT_SECURE_NO_WARNINGS
#define _CLOCK_PER_SEC

#include "func.h"



int main()
{
  // выделение пам€ти дл€ переменных,массива, файла и таймера
  double random_number = 0, min_ch = 0, max_ch = 0, result = 0, number = 0, time_spent = 0.0;
  int count_of_numbers = 0, counter = 0, index_of_massive = 0, dec_remain, index, len_of_array = 1000000;
  
  int* array_of_remains = (int*)malloc(sizeof(int) * len_of_array);
  double* array_of_numbers = (double*)malloc(sizeof(double) * len_of_array);

  for (counter = 0; counter < len_of_array; counter++)
  {
    array_of_remains[counter] = 0;
  }
  clock_t begin = 0, end = 0;

  // введение переменных пользовательем
  printf("Enter the minimum number to generate: ");
  scanf("%lf", &min_ch);
  printf("Enter the maximum number to generate: ");
  scanf("%lf", &max_ch);
  printf("Enter the count of generated numbers: ");
  scanf("%d", &count_of_numbers);

  begin = clock(); // начало работы таймера
  // создание рандомных чисел, разделение их на дробную и целую часть, заполнение ими файла и присвоение индекса
  for (counter = 0; counter < count_of_numbers; counter++)
  {
    random_number = make_random_number(min_ch, max_ch, counter); // создание рандомных чисел
    dec_remain = make_dec_remain(random_number); // разделение на дробную и целую часть
    // условие дл€ заполнение файла, т.к в double может хранитьс€ 6 знаков после з€п€той, то все числа, номер которых больше 1000000, мы не записываем в массив
    if (counter < len_of_array)
    {
      array_of_numbers[counter] = random_number;
    }
    else
    {
      result += random_number; // если индекс числа больше 1000000 то суммируем его
    }

    if (dec_remain < len_of_array)
    {
      array_of_remains[dec_remain] = 1; // присваение индекса числу "1" - "-" / "0" - "+"
    }
  }

  if (count_of_numbers > len_of_array)
    count_of_numbers = len_of_array;

  for (counter = 0; counter < count_of_numbers; counter++) // если индекс числа больше 1000000 то суммируем его
  {
    number = array_of_numbers[counter];
    index = array_of_remains[counter];
    if (index == 1)
    {
      result -= number;
      //printf("%d) -| %lf\n", counter, number);
    }

    else
    {
      result += number;
      //printf("%d) +| %lf\n", counter, number);
    }
  }
  free(array_of_numbers);
  free(array_of_remains);
  //окончание работы таймера
  end = clock();
  // вычисление времени работы программы
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  // ввывод времени работы программы и еЄ результат
  printf("Result: %lf.\nExcecution time: %lf seconds.", result, time_spent);

  return 0;
}