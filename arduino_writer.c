#include <unistd.h>
#include <stdio.h>

#define MAX_ANGLE 180
#define MIN_ANGLE 0

#define ARRAY_LENGTH


    // Function to figure out how much to turn by


int getXAngle()
{
    return 45;
}

int getYAngle()
{
    // here we will use the date from the Lepton to determine how much we need to turn


    return 45;
}

int findAverage(int arr[])
{
    int total;
    int j = 0;
    
    for (j; j < ARRAY_LENGTH; j++)
    {
        total += arr[j];
    }
    
    return (total/ARRAY_LENGTH);
}



    // Implementation that treats arduino connection as a file
    // may work, may need to be more complex

int main() 
{
    int xCenter = 90;
    int yCenter = 90;
    while (1) 
    {
        int xData[ARRAY_LENGTH], yData[ARRAY_LENGTH];
        int i = 0;
        
        while (i < ARRAY_LENGTH)
        {
            int xAngle = xCenter;
            int yAngle = yCenter;
            
            yAngle = getYAngle();     // find out how much we need to turn the servo and set angle to this
            xAngle = getXAngle();
            
            xData[i] = xAngle;
            yData[i] = yAngle;
            
            delay(1);
        }
        
        int xAverage = findAverage(xData);
        int yAverage = findAverage(yData);
        
        FILE *file;
        
        if ((xAngle != xCenter || yAngle != yCenter) && xAverage <= MAX_ANGLE && xAverage >= MIN_ANGLE && yAverage <= MAX_ANGLE && yAverage >= MIN_ANGLE)
        {
            file = fopen("USB\VID_234&PID_0043\55330333930351718130", "w");      // "/dev/ttyUSB0" is just where the port is, will probably be different for us

            fprintf(file, "%03d%03d", xAverage, yAverage);       // write the amount to turn to the "file" (actually arduino)

            fclose(file);       // close connection to arduino
            
            xCenter = xAverage;
            yCenter = yAverage;
        }
    }
}


    // Implementation that treats arduino as a serial port
    // really not sure how good this is tbh

/*
int main()
{
    while (1)
    {
        int angle = 0;
        
        angle = getTurnAngle();
    
        if (serialport_init("COM4", 9600))
            fprintf(stderr, "Error initializing the serial port");
        else
        {
            int serial_fd;
            if ((serial_fd = open("/dev/USB4", O_WRONLY)))
                fprintf("Error finding file descriptor");
            else
            {
                if (serialport_write(serial_fd, "%d", angle))
                    fprintf("Error writing to serial port");
            }
            close(serial_fd);
        }
    }
}
*/



/*
 
 
 
 
*/




















            




