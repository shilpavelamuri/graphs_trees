/*
 * valet_park.cpp
 *
 *  Created on: Jan 11, 2019
 *      Author: shilpakalla
 */

#include <set>
#include <map>
#include <stdio.h>

using namespace std;

typedef enum {
	SIZE_SMALL = 1,
	SIZE_MID   = 2,
	SIZE_LARGE = 3
} car_size_defs_enum;



int main()
{
	// 3 parking slot maps for the different sized cars
	// maps distance to parking slot number
	std::map<int, int> smallSizeMap;
	std::map<int, int> midSizeMap;
	std::map<int, int> largeSizeMap;
	std::map<int, int>::iterator itSmall;
	std::map<int, int>::iterator itMid;
	std::map<int, int>::iterator itLarge;

	// parking lot populate info
	int smallDist[] = {12, 6, 18, 3, 9};
	int smallParkNum[] = {1, 5, 10, 15, 20};
	int medDist[] = {35, 25, 45, 5, 15};
    int medParkNum[] = {3, 6, 9, 12, 18};
	int largeDist[] = {26, 8, 4, 2, 14};
	int largeParkNum[] = {4, 8, 14, 16, 22};

	// populate parking lot
	for (int i=0; i<5; i++)
	{
        smallSizeMap.insert(std::pair<int, int>(smallDist[i], smallParkNum[i]));
        midSizeMap.insert(std::pair<int, int>(medDist[i], medParkNum[i]));
        largeSizeMap.insert(std::pair<int, int>(largeDist[i], largeParkNum[i]));
	}

	int input_car_size[20] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
			1, 2, 3, 1, 2, 3, 1, 2, 3, 1
	};

	// park
    itSmall = smallSizeMap.begin();
    itMid = midSizeMap.begin();
    itLarge = largeSizeMap.begin();
    int valetTicketNum[20] = {0};

    for (int car = 0; car < 20; car++)
    {
		if (input_car_size[car] == SIZE_SMALL)
		{
			if (itSmall != smallSizeMap.end())
			{
				valetTicketNum[car] = itSmall->second;
				itSmall++;
			}
			else if (itMid != midSizeMap.end())
			{
				valetTicketNum[car] = itMid->second;
				itMid++;
			}
			else if (itLarge != largeSizeMap.end())
			{
				valetTicketNum[car] = itLarge->second;
				itLarge++;
			}
			else
			{
				printf("\nLot full!\n");
			}
		}
		else if (input_car_size[car] == SIZE_MID)
		{

			if (itMid != midSizeMap.end())
			{
				valetTicketNum[car] = itMid->second;
				itMid++;
			}
			else if (itSmall != smallSizeMap.end())
			{
				valetTicketNum[car] = itSmall->second;
				itSmall++;
			}
			else if (itLarge != largeSizeMap.end())
			{
				valetTicketNum[car] = itLarge->second;
				itLarge++;
			}
			else
			{
				printf("\nLot full!\n");
			}
		}
		else if (input_car_size[car] == SIZE_LARGE)
		{
			if (itLarge != largeSizeMap.end())
			{
				valetTicketNum[car] = itLarge->second;
				itLarge++;
			}
			else if (itMid != midSizeMap.end())
			{
				valetTicketNum[car] = itMid->second;
				itMid++;
			}
			else if (itSmall != smallSizeMap.end())
			{
				valetTicketNum[car] = itSmall->second;
				itSmall++;
			}
			else
			{
				printf("\nLot full!\n");
			}
		}

		printf("\nFor car:%d, Valet ticket num: %d", car, valetTicketNum[car]);
    }

	// retrieve
	// ticket number itself is the parking spot number
}
