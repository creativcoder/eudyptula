/**
 * @file    hello.c
 * @author  Rahul Sharma
 * @date    6 November 2015
 * @version 0.1
 * @brief  An introductory "Hello World!" loadable kernel module (LKM) that can display a message
 * in the /var/log/kern.log file when the module is loaded and removed. The module can accept an
 * argument when it is loaded -- the name, which appears in the kernel log files.
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rahul Sharma");
MODULE_DESCRIPTION("A simple kernel module for eudyptula challenge 1");
MODULE_VERSION("0.1");

 static int __init hello_mod_init(void) {
 	// KERNEL_INFO is the log level
 	printk(KERN_INFO "Hello World!");
 	return 0;
 }

 static void __exit hello_mod_exit(void) {
 	// KERNEL_INFO is the log level
 	printk(KERN_INFO "Goodbye!");
 }

module_init(hello_mod_init);
module_exit(hello_mod_exit);