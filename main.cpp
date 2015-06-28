#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "boardRecognition.h"
#include "arduinoWrite.h"
using namespace cv;
using namespace std;


#define MAX_ANGLE 180
#define MIN_ANGLE 0

// define the number of angles for the average (also determines delay time)



int main()
{
	double x_degree, y_degree;
	detectObject(x_degree, y_degree);

	while (1)
	{
		//check if camera needs to move
		/*if true, call Jeremy's function
			1: Person moved
			2: Pointed to board
		*/
		// things to add to master function

		// arduino can only deal with values between 0 and 180
		
		int xCenter = 90;       // default camera angle is at the complete center
		int yCenter = 90;

		int xData[ARRAY_LENGTH], yData[ARRAY_LENGTH];
		int i = 0;

		while (i < ARRAY_LENGTH)
		{
			int xAngle = xCenter;       // sets base case of original center if we get nothing from function
			int yAngle = yCenter;

			yAngle = getYAngle();     // find out how much we need to turn the servo and set angles to this
			xAngle = getXAngle();

			xData[i] = xAngle;      // store data in our array that will be averaged
			yData[i] = yAngle;

			Sleep(1);
		}

		int xAverage = findAverage(xData);      // finds averages of the data
		int yAverage = findAverage(yData);


		if ((xAverage != xCenter || yAverage != yCenter) && xAverage <= MAX_ANGLE && xAverage >= MIN_ANGLE && yAverage <= MAX_ANGLE && yAverage >= MIN_ANGLE)
		{
			writeToArduino(xAverage, yAverage);
		}

		xCenter = xAverage;     // set the new center
		yCenter = yAverage;




	}
	cout << "end of presentation" << endl;
}