# Itoa_and_Atoi
This project was completed by Malhar Kulkarni as a course assignment for the course 'Introduction to Embedded Systems Software and Development Environments' by Alex Fosdick, offered by UC Boulder on Coursera.

The aim of the project is to make a build system which would convert input integers in any base to ASCII and vice-versa; memory-efficiently. That is, this project would convert integers to and fro ASCII in the MSP432 embedded system, which cannot run heavy header files like std.

This build system would be able to compile a set of programs in both the host machine and the target MSP432 embedded platform. MSP432 compiles its code using the GNU-based Arm compiler arm-none-eabi-gcc.

The build system comprises a makefile which has MSP432 as its only platfrom override other than the Host.

To run the atoi and itoa conversion, there are tests and executions present in the 'course1.c' file inside the 'include' folder, which will execute all these operations.
