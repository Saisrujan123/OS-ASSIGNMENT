#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/sched/signal.h>
struct task_struct *task;
int simple_init(void)
{
    printk(KERN_INFO "Loading kernel Module\n");
    printk("  PID   state     CMD\n");
 for_each_process(task)
 {

     printk("%5d   %4ld   %s\n",task_pid_nr(task),task->state,task->comm);
 }
return 0;
}
void simple_exit(void)
{
printk(KERN_INFO "Removing kernel Module\n");
}
module_init(simple_init);
module_exit(simple_exit);
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
MODULE_LICENSE("GPL");

