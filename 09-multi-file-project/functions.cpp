double NegSum(double *myarray, int count)
{
	double sum = 0;
	for (int i = 0; i < count; i++)
	{
		if (myarray[i] < 0)
		{
			sum += myarray[i];
		}
	}
	return sum;
}

double * SortArray(double *myarray, int count)
{
	double * newarray = myarray;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - (i + 1); j++)
		{
			if (newarray[j] > newarray[j + 1])
			{
				double temp = newarray[j];
				newarray[j] = newarray[j + 1];
				newarray[j + 1] = temp;
			}
		}
	}
	return newarray;
}

double GetMultiple(double *myarray, int count) 
{
	double minel, maxel, multiple;
	int minindex, maxindex;

	multiple = 1;

	for (int i = 0; i < count; i++)
	{

		if (i == 0)
		{
			minel = myarray[i];
			maxel = myarray[i];
			minindex = 0;
			maxindex = 0;
		}

		if (myarray[i] > maxel)
		{
			maxel = myarray[i];
			maxindex = i;
		}

		if (myarray[i] < minel)
		{
			minel = myarray[i];
			minindex = i;
		}
	}

	for (int i = maxindex; i < minindex; i++)
	{
		multiple *= myarray[i];
	}
	return multiple;
}