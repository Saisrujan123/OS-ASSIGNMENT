# Project 3, Chapter 3 from Operating Systems Concepts (10th Edition) by Silberschatz, Galvin, Gagne

## Task 1- Iterating over Tasks Linearly
Code is designed to read through the task struct structure in <linux/sched.h> linearly to obtain the names of all tasks in the system.

To verify that your code is working correctly, compare the contents of the kernel log buffer with the output of the following command, which lists all tasks in the system:

	ps -el

The two values should be very similar. Because tasks are dynamic, however, it is possible that a few tasks may appear in one listing but not the other.

## Task 2- Iterating over Tasks with a Depth-First Search Tree
Code is designed to read through the task struct structure in <linux/sched.h> using a DFS tree to obtain the names of all tasks in the system.

To check the output of the DFS tree, use the command 

	ps -eLf

This command lists all tasks—including threads—in the system.

<br/>

## Requirements

* This project can be implemented either using a laptop/desktop running on any Linux based Operating System or a Linux virtual machine. 
* Please make sure that the Linux kernel headers that match your current kernel version are installed. 

> If kernel headers are not installed, please follow the following two steps (for Ubuntu 20.04 lts):\
>`$ sudo apt update` \
>`$ sudo apt install linux-headers-$(uname -r)`

<br/>

## Instructions to load and use the Kernel Modules

* Clone the [OS-ASSIGNMENT](https://github.com/Saisrujan123/OS-ASSIGNMENT) repository using the following command:\
`$ git clone https://github.com/Saisrujan123/OS-ASSIGNMENT`

* Change your current working directory to either task1 or task2 depending on whether you want to iterate over all the current tasks in linear or dfs manner respectively.\
`$ cd task1`  or   `$ cd task2`

* Now run the make command which will compile your main.c file using the Makefile of the directory, and produce several files, one of them being the main.ko file which represents the compiled kernel module.\
`$ make`



* Load the kernel module using the following command:\
`$ sudo insmod main.ko`

>**Note**: To check if the module is indeed loaded you may run the **lsmod** command to list all the modules and search if the name "main" is listed in the output.

* The kernel module is now loaded and you may check the kernel log buffer for the list of tasks(iterated either linearly or in DFS manner based on the directory you are in).\
`$ dmesg`

>**Tip**: If your output looks messy or if the kernel log buffer is full, you might want to clear the buffer before loading the module using the following command:\
`$ sudo dmesg -c`

* To remove the module you just loaded, invoke the **rmmod** command as shown below:\
`$ sudo rmmod main`

<br/>

## References

* Operating System Concepts 10th Edition – Silberschatz, Galvin, Gagne
* Stackoverflow Discussion (https://stackoverflow.com/questions/19208487/kernel-module-that-iterates-over-all-tasks-using-depth-first-tree)
* https://tldp.org/LDP/lkmpg/2.6/html/index.html
