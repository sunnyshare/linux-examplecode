

obj-m :=hello.o
KERNELDIR =/lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	rm -f  *o  *.mod *.mod.o  *mod.c  *.symvers *.order



	
