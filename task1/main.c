//header files required for the task
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/sched/signal.h>

//declaring a global task pointer for accessing processes
struct task_struct *Task;

//function called when module is loaded
int Module_Entry(void)
{
    printk(KERN_INFO "Loading kernel Module\n");
    printk("  PID   state     CMD\n");
    //iterating linearly over all processes
    for_each_process(Task)
    {
        printk("%5d   %4ld   %s\n",Task->pid,Task->state,Task->comm);
    }
    return 0;
}

//function called when module is removed
void Module_Exit(void)
{
    printk(KERN_INFO "Removing kernel Module\n");
}

module_init(Module_Entry);
module_exit(Module_Exit);
MODULE_DESCRIPTION("Process details Module");
MODULE_AUTHOR("SGG");
MODULE_LICENSE("GPL");

