#include <unistd.h>
#include <stdio.h>

#define MAX_TURN_ANGLE 180
#define MIN_TURN_ANGLE 0


    // Function to figure out how much to turn by


getTurnAngle()
{
    // here we will use the date from the Lepton to determine how much we need to turn


    return 45;
}



    // Implementation that treats arduino connection as a file
    // may work, may need to be more complex
    // positive vs. negative angle determines left vs. right

int main() 
{
    int center = 90;
    while (1) 
    {
        int angle = center;
   
        angle = getTurnAngle();     // find out how much we need to turn the servo and set angle to this
        
        if (angle != center)
        {
            FILE *file;
            file = fopen("/dev/ttyUSB4", "w");      // "/dev/ttyUSB0" is just where the port is, will probably be different for us

            fprintf(file, "%d", angle);       // write the amount to turn to the "file" (actually arduino)

            fclose(file);       // close connection to arduino
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




















            




