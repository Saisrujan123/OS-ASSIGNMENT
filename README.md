# Chapter 3, Project 3 from Operating Systems Concepts by Silberschatz
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
