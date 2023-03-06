 1. Write a bash script that accepts a directory path as an argument and prints the names of all files in that directory that have the '.txt' extension, sorted in alphabetical order. If no directory is provided, the script should use the current directory. The script should also handle cases where the provided directory does not exist or is not a directory. In these cases, the script should print an error message and exit with a non-zero exit code.

 2. Second Requirement  
    - Write a bash script that accepts a directory path and a string as arguments and outputs a list of all files in the directory (including subdirectories) that contain the given string in their contents. If the string isn't given use the word 'error'. 
    - If the directory is empty or doesn't contain any file that has the required string, the script should print a message and exit with a zero exit code. 
    - The script should also handle cases where the directory is not provided or is not a directory. In these cases, the script should print an error message and exit with a non-zero exit code."




 
Hints:

-   Check `find` command. 
-   Conditional Expressions: `-z`, `-d`
-   `exit N` exit the script with exit code N.
-   `grep` some flags can be useful in the second requirement.