/* header files required for the task */ 
#include<linux/init.h>		// for module_init and module_exit
#include<linux/kernel.h>	// for printk() and KERN_INFO
#include<linux/module.h>	// needed by all modules 
#include<linux/sched/signal.h> 

/* function to perform DFS traversal on all current tasks */
void DFS_Search(struct task_struct *Task)
{
	struct task_struct *Next;
	struct list_head *List;
	printk("%-5d   %-4ld   %s\n",Task->pid,Task->state,Task->comm);
	// traverse through the list of children of a task
	list_for_each(List, &Task->children)
	{
		Next = list_entry(List, struct task_struct, sibling); // Next points to one of the children of the task
		DFS_Search(Next);
	}
}

/* function called when module is loaded */ 
int Module_Entry(void)
{
	printk(KERN_INFO "Loading kernel module...");
    printk("PID   state     CMD\n");
	DFS_Search(&init_task);  // init_task: initial task of the system with pid = 0
	return 0;
}

/* function called when module is removed */
void Module_Exit(void)
{
	printk(KERN_INFO "Removing kernel module...");
}

module_init(Module_Entry);	
module_exit(Module_Exit);

/*  module identifiers */
MODULE_DESCRIPTION("Process details Module(using DFS)");
MODULE_AUTHOR("SGG");
MODULE_LICENSE("GPL");	// mandatory if the module uses other system libraries running under GPL license



/* 
	Some useful macro definitions:

* list_for_each
	#define list_for_each(pos, head) for(pos = (head)->next; pos != (head); pos = pos->next)
	where 'head' is a pointer to a circular doubly linked list of list_head structures

* list_entry
	#define list_entry(ptr, type, member) ((type *)((char *)(ptr) – offsetof(type, member))) 
	What is does: Gets the pointer to the structure when pointer to one of its member is given 

*/ 
