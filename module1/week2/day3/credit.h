#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_int_len(long value);
bool valid_base_luhn(long credit_card, int length_card);
int sum_luhn(long value, int length_card);

int main(void)
{
  long card_number;
  bool valid;
  int length_card;
  int two_di;

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
      two_di = card_number / pow(10, length_card - 2);
      if (two_di == 34 || two_di == 37)
      {
        printf("AMEX\n");
      }
      else if (two_di == 51 || two_di == 52 || two_di == 53 || two_di == 54 || two_di == 55)
      {
        printf("MASTERCARD\n");
      }
      else if (two_di >= 40 && two_di <= 49)
      {
        printf("VISA\n");
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
  return length;
}

bool valid_base_luhn(long credit_card, int length_card)
{
  int sum;

  sum = sum_luhn(credit_card, length_card);

  return sum % 10 == 0;
}

int sum_luhn(long value, int length_card)
{
  int sum = 0;
  int digit;
  int dob;
  for (int i = 0; i < length_card; i++)
  {
    digit = value % 10;
    value = (value - digit) / 10;
    if (i % 2 == 0)
    {
      sum += digit;
    }
    else
    {
      dob = digit * 2;
      if (dob > 9)
      {
        sum += dob - 9;
      }
      else
      {
        sum += dob;
      }
    }
  }

  return sum;
}
