/**
 * countDigits - counts the digits
 * @num: the number
 *
 * Return: returns number of digits
 */
int countDigits(int num)
{
	int count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
