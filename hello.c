
/**
* @file hello.c
* @brief 打印hello进行简单测试
* @author zshare
* @version v1.0
* @date 2022-02-11
* @history  
*/

#include <linux/module.h>//对应内核源码中include/linux/module.h
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>	//包含了module_init和module_exit的声明

#define _log_
#ifdef _log_
	#define kernel_print(format, arg...) printk(format,## arg)
#else
	#define kernel_print(format, arg...) do{}while(0)
#endif
#define VERSION "V1.0"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

static int __init hello_init(void){
	kernel_print("hello_init is called.\n");
	kernel_print("hello module.\n");
	return 0;
}

static void __exit hello_exit(void){
	kernel_print("hello_exit is called.\n");
	kernel_print("bye module.\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");//软件代码接受的许可协议General Public License
MODULE_AUTHOR("Share");//声明作者
MODULE_DESCRIPTION("Print hello module");//模块简单的描述
MODULE_VERSION(VERSION);//模块版本
MODULE_ALIAS("HELLO");//模块在用户空间的别名






















