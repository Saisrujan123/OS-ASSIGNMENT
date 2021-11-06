#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/sched/signal.h>

void dfs_search(struct task_struct *task)
{
	struct task_struct *next;
	struct list_head *list;
	printk("%d   %d   %d	%s\n",task->pid,task->parent->pid,task->state,task->comm);
	
	list_for_each(list, &task->children)
	{
		next = list_entry(list, struct task_struct, sibling);
		
		dfs_search(next);
	}
	
}

int module_entry(void)
{
	printk(KERN_INFO "Loading kernel module...");
	printk(" PID \tState \tCMD\n");
	dfs_search(&init_task);
	return 0;
}

void module_Exit(void)
{
	printk(KERN_INFO "Removing kernel module...");
}

module_init(module_entry);
module_exit(module_Exit);
MODULE_DESCRIPTION("Process details Module");
MODULE_AUTHOR("SGG");
MODULE_LICENSE("GPL");
