#include <unistd.h>
#include <stdio.h>

#define MAX_ANGLE 180
#define MIN_ANGLE 0


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



    // Implementation that treats arduino connection as a file
    // may work, may need to be more complex
    // positive vs. negative angle determines left vs. right

int main() 
{
    int xCenter = 90;
    int yCenter = 90;
    while (1) 
    {
        int xAngle = xCenter;
        int yAngle = yCenter;
   
        yAngle = getYAngle();     // find out how much we need to turn the servo and set angle to this
        xAngle = getXAngle();
        
        FILE *file;
        
        if (xAngle != xCenter && xAngle <= MAX_ANGLE && xAngle >= MIN_ANGLE)
        {
            file = fopen("/dev/ttyUSB4", "w");      // "/dev/ttyUSB0" is just where the port is, will probably be different for us

            fprintf(file, "%d", xAngle);       // write the amount to turn to the "file" (actually arduino)

            fclose(file);       // close connection to arduino
        }
        
        if (yAngle != yCenter && yAngle <= MAX_ANGLE && yAngle >= MIN_ANGLE)
        {
            file = fopen("/dev/ttyUSB4", "w");
            
            fprintf(file, "%d", yAngle);
            
            fclose(file);
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




















            




