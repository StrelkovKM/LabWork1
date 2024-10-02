#include "func.h"



int main()
{
  double random_number = 0, min_ch = 0, max_ch = 0, result = 0, number = 0;
  int count_of_numbers = 0, counter = 0, index_of_massive = 0, dec_remain, index;
  char first_massive_of_remains[250000], second_massive_of_remains[250000];
  char third_massive_of_remains[250000], fourth_massive_of_remains[250000];
  double time_spent = 0.0;
  clock_t begin = 0, end = 0;
  FILE* file_of_numbers;

  for (counter; counter < 250000; counter++)
  {
    first_massive_of_remains[counter] = 0;
    second_massive_of_remains[counter] = 0;
    third_massive_of_remains[counter] = 0;
    fourth_massive_of_remains[counter] = 0;
  }

  printf("Enter the minimum number to generate: ");
  scanf("%lf", &min_ch);
  printf("Enter the maximum number to generate: ");
  scanf("%lf", &max_ch);
  printf("Enter the count of generated numbers: ");
  scanf("%d", &count_of_numbers);

  begin = clock();
  file_of_numbers = fopen("stor.txt", "w");
  for (counter = 0; counter < count_of_numbers; counter++)
  {
    random_number = make_random_number(min_ch, max_ch, counter);
    dec_remain = make_dec_remain(random_number);

    if (counter < 1000000)
    {
      if (file_of_numbers != NULL)
        fprintf(file_of_numbers, "%lf\n", random_number);
      else
        printf("IDIOT");
    }
    else
    {
      result += random_number;
    }

    if (dec_remain >= 0 && dec_remain < 250000)
    {
      first_massive_of_remains[dec_remain] = 1;
    }
    else if (dec_remain >= 250000 && dec_remain < 500000)
    {
      second_massive_of_remains[dec_remain - 250000] = 1;
    }
    else if (dec_remain >= 500000 && dec_remain < 750000)
    {
      third_massive_of_remains[dec_remain - 500000] = 1;
    }
    else
    {
      fourth_massive_of_remains[dec_remain - 750000] = 1;
    }
  }
  fclose(file_of_numbers);

  file_of_numbers = fopen("stor.txt", "r");
  if (count_of_numbers > 1000000)
    count_of_numbers = 1000000;
  for (counter = 0; counter < count_of_numbers; counter++)
  {
    fscanf(file_of_numbers, "%lf\n", &number);

    if (counter >= 0 && counter < 250000)
    {
      index = first_massive_of_remains[counter];
    }
    else if (counter >= 250000 && counter < 500000)
    {
      index = second_massive_of_remains[counter - 250000];
    }
    else if (counter >= 500000 && counter < 750000)
    {
      index = third_massive_of_remains[counter - 500000];
    }
    else
    {
      index = fourth_massive_of_remains[counter - 750000];
    }
    if (index == 1)
    {
      result -= number;
    }

    else
    {
      result += number;
    }
  }

  fclose(file_of_numbers);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

  printf("Result: %lf.\nExcecution time: %lf seconds.", result, time_spent);
}