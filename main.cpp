#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "boardRecognition.h"
using namespace cv;
using namespace std;

int main()
{
	double x_degree, y_degree;
	detectObject(x_degree, y_degree);

	//while (1)
	{
		//check if camera needs to move
		/*if true, call Jeremy's function
			1: Person moved
			2: Pointed to board
		*/
	}
	cout << "end of presentation" << endl;
}