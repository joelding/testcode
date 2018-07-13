#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>

#define dbg(s, b...) printk("[dbg %s] " s, __func__, ##b)
#define err(s, b...) printk("[err %s] " s, __func__, ##b)

#define DEVNAME "miscdev"
#define DEVNAME_0 "miscdev-0"
#define DEVNAME_1 "miscdev-1"

static unsigned char minor;

static long misc_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	dbg("\n");
	return 0;
}

static int misc_open(struct inode *inode, struct file *file)
{
	dbg("\n");
	return 0;
}

static int misc_close(struct inode *inode, struct file *file)
{
	dbg("\n");
	return 0;
}

ssize_t misc_read(struct file *file, char __user *buf, size_t size, loff_t *offset)
{
	dbg("\n");
	return 0;
}

ssize_t misc_write(struct file *file, const char __user *buf, size_t size, loff_t *offset)
{
	dbg("\n");
	return 0;
}

static struct file_operations misc_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = misc_ioctl,
	.open = misc_open,
	.release = misc_close,
	.read = misc_read,
	.write = misc_write,
};

#if 0
static struct miscdevice misc_dev0 = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEVNAME_0,
	.fops = &misc_fops,
};

static struct miscdevice misc_dev1 = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEVNAME_1,
	.fops = &misc_fops,
};
#endif

#define MAX 10
static struct miscdevice misc_dev[MAX];



static const char *devname[MAX] = {
	"miscdev-0",
	"miscdev-1",
	"miscdev-2",
	"miscdev-3",
	"miscdev-4",
	"miscdev-5",
	"miscdev-6",
	"miscdev-7",
	"miscdev-8",
	"miscdev-9",
};

static int __init misc_init(void)
{
	int ret;
	int i;
	
//	if (minor)
//		misc_dev.minor = minor;

	for (i = 0; i < MAX; ++i) {
		misc_dev[i].minor = MISC_DYNAMIC_MINOR;
		misc_dev[i].name = devname[i];
		misc_dev[i].fops = &misc_fops;
	
		ret = misc_register(&(misc_dev[i]));
		if (ret) {
			err("cannot register\n");
			return -1;
		}
	}

#if 0
	ret = misc_register(&misc_dev0);
	if (ret) {
		err("cannot register\n");
		return -1;
	}

	ret = misc_register(&misc_dev1);
	if (ret) {
		err("cannot register\n");
		return -1;
	}
#endif

	dbg("\n");

	return 0;
}

static void __exit misc_exit(void)
{
	int i;
#if 0
	misc_deregister(&misc_dev0);
	misc_deregister(&misc_dev1);
#endif
	for (i = 0; i < MAX; ++i) 
		misc_deregister(&(misc_dev[i]));

	dbg("\n");
}

module_init(misc_init);
module_exit(misc_exit);
module_param(minor, byte, S_IRWXU);
MODULE_LICENSE("GPL");
MODULE_PARM_DESC(minor, "the minor number");

