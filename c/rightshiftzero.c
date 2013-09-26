/*
 * This program segregate noz zero values from zeroes and push zeroes to the right(end) of an array.
 * Copyright (C) <year>  <name of author>

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
# include<stdio.h>
int main(int argc, char const *argv[])
{
	int arr[]={0,0,0,1,2,0,0,3,4,0,14,19,0,0,0,5,6,0,0,0,7,8,0,9,0};
	int arrLength = sizeof(arr)/sizeof(int);
	int firstZero = -1;
	int i;

	for (i = 0; i < arrLength; ++i)
	{
		if(arr[i]==0 && firstZero == -1)firstZero = i;
		else if(arr[i]!=0 && firstZero != -1){
			arr[firstZero++] = arr[i];
			arr[i] = 0;
		}
	}
	for (i = 0; i < firstZero; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
