#include "bananapim20-gpio.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <string.h>

/**
 * @brief Export GPIO pin
 *
 * @param id pin id
 * @return int 0 if success -1 if error
 */
int exportIO(const char *id)
{
    // File descriptor
    int fd;

    // Open export file
    if ((fd = open("/sys/class/gpio/export", O_WRONLY)))
    {
        fprintf(stderr, "Error exporting pin %s, could not open file.\n", id);
        return ERROR;
    }

    // Export pin
    if (write(fd, id, strlen(id)) != strlen(id))
    {
        fprintf(stderr, "Error exporting pin %s, could not write to file.\n", id);
        close(fd);
        return ERROR;
    }

    // Close file
    if (close(fd) == ERROR)
    {
        fprintf(stderr, "Error closing export file.\n");
        return ERROR;
    }

    return SUCCESS;
}

/**
 * @brief Un export GPIO port
 *
 * @param id pin id
 * @return int 0 if success -1 if error
 */
int unexportIO(const char *id)
{
    // File descriptor
    int fd;

    // Open export file
    if ((fd = open("/sys/class/gpio/unexport", O_WRONLY)))
    {
        fprintf(stderr, "Error unexporting pin %s, could not open file.\n", id);
        return ERROR;
    }

    // Export pin
    if (write(fd, id, strlen(id)) != strlen(id))
    {
        fprintf(stderr, "Error unexporting pin %s, could not write to file.\n", id);
        close(fd);
        return ERROR;
    }

    // Close file
    if (close(fd) == ERROR)
    {
        fprintf(stderr, "Error closing unexport file.\n");
        return ERROR;
    }

    return SUCCESS;
}

/**
 * @brief Set the Port Direction object
 *
 * @param id port id
 * @param direction 0 (in) or 1 (out)
 * @return int 0 if success -1 if error
 */
int setPortDirection(const char *id, unsigned int direction)
{
    int fd;              // File descriptor
    char path[PATH_MAX]; // File path

    if (direction > 1)
    {
        fprintf(stderr, "Direction %d not supported\n", direction);
        return ERROR;
    }

    // Generate path
    if (sprintf(path, "/sys/class/gpio/gpio%s/direction", id) == -1)
    {
        fprintf(stderr, "Error getting path\n");
        return ERROR;
    }

    // Open file
    if ((fd = open(path, O_WRONLY)) == -1)
    {
        fprintf(stderr, "Error getting 'direction' file descriptor.\n");
        close(fd);
        return ERROR;
    }

    // Set pin direction
    if (write(fd, "out", 3) != 3)
    {
        fprintf(stderr, "Error setting direction of pin.\n");
        close(fd);
        return ERROR;
    }

    // CLose file
    if (close(fd) == -1)
    {
        fprintf(stderr, "Error closing 'direction' file.\n");
        return ERROR;
    }

    return SUCCESS;
}

// TODO readIO
char *readIO(const char *id, void *callback)
{
}

// TODO writeIO
int writeIO(const char *id, const char *value)
{
}