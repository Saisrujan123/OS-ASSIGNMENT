//header files required for the task
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/sched/signal.h>

//function to perform DFS traversal on all processes
void DFS_Search(struct task_struct *Task)
{
	struct task_struct *Next;
	struct list_head *List;
	printk("%-5d   %-4ld   %s\n",Task->pid,Task->state,Task->comm);
	// DFS Traversal on processes
	list_for_each(List, &Task->children)
	{
		Next = list_entry(List, struct task_struct, sibling);
		DFS_Search(Next);
	}
}

//function called when module is loaded
int Module_Entry(void)
{
	printk(KERN_INFO "Loading kernel module...");
    printk("PID   state     CMD\n");
	DFS_Search(&init_task);
	return 0;
}

//function called when module is removed
void Module_Exit(void)
{
	printk(KERN_INFO "Removing kernel module...");
}

module_init(Module_Entry);
module_exit(Module_Exit);
MODULE_DESCRIPTION("Process details Module(using DFS)");
MODULE_AUTHOR("SGG");
MODULE_LICENSE("GPL");
