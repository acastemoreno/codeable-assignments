#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_int_len(long value);
bool valid_base_luhn(long credit_card, int length_card);
int *list_digits(long value);
int sum_digits(long value);

int main(void)
{
  long card_number;
  bool valid;
  int length_card;

  do
  {
    card_number = get_long("Number: ");
  } while (card_number <= 0);

  //valid card number
  length_card = get_int_len(card_number);
  if (length_card == 15 || length_card == 13 || length_card == 16)
  {
    if (valid_base_luhn(card_number, length_card))
    {
    }
    else
    {
      printf("INVALID\n");
    }
  }
  else
  {
    printf("INVALID\n");
  }
}

int get_int_len(long value)
{
  int length = 1;
  while (value > 9)
  {
    length++;
    value = value / 10;
  }
  printf("%i\n", length);
  return length;
}

bool valid_base_luhn(long credit_card, int length_card)
{
  int *list_dig;

  list_dig = list_digits(credit_card);

  int suma_luhn = 0;

  for (int i = 0; i < length_card; i++)
  {
    if (i % 2 == 0)
    {
      suma_luhn += list_dig[i];
      printf("single: %i\n", list_dig[i]);
    }
    else
    {
      suma_luhn += (2 * list_dig[i]);
      printf("doble: %i\n", 2 * list_dig[i]);
    }
  }

  return suma_luhn % 10 == 0;
}

int *list_digits(long value)
{
  const int len = get_int_len(value);
  int temp[len];
  static int *ld;
  ld = temp;
  long tem = value;
  for (int i = 0; i < len; i++)
  {
    ld[i] = tem % 10;
    tem = (tem - ld[i]) / 10;
    printf("%i\n", ld[i]);
  }

  return ld;
}
