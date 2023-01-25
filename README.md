# kfs
42 kernel from scratch

# Roadmap
## Current TODO list
- enable paging

## kfs-1
### Mandatory part
- [X] Install GRUB on an virtual image
- [X] Write an ASM boot code that handles multiboot header, and use GRUB to init and
call main function of the kernel itself.
- [X] Write basic kernel code of the choosen language.
- [X] Compile it with correct flags, and link it to make it bootable.
- [ ] Once all of those steps above are done, you can write some helpers like kernel types
or basic functions (strlen, strcmp, ...)
- [ ] Your work must not exceed 10 MB.
- [X] Code the interface between your kernel and the screen.
- [X] Display "42" on the screen.

### Bonus Part
- [X] Add scroll and cursor support to your I/O interface.
- [X] Add colors support to your I/O interface.
- [X] Add helpers like printf / printk in order to print information / debug easily.
- [ ] Handle keyboard entries and print them.
- [ ] Handle different screens, and keyboard shortcuts to switch easily between then.

## kfs-2
### Mandatory part
- [X] You must create a Global Descriptor Table.
- [X] Your GDT must contain:
	- Kernel Code
	- Kernel Data
	- Kernel stack
	- User code
	- User data
	- User stack
	- Your work should not exceed 10 MB.
- [ ] You must declare your GDT to the BIOS.
- [X] The GDT must be set at address 0x00000800.
- [ ] When this is done, you have to code a tool to print the kernel stack, in a human-friendly
way. (Tip: If you haven’t made a printk yet, now is a good time !)
### Bonus Part
- [ ] Assuming your keyboard work correctly in your Kernel, and you able to catch an entry,
let’s code a Shell !
Not a POSIX Shell, just a minimalistic shell with a few commands, for debugging pur-
poses.
For example, you could implement the print-kernel-stack-thing in this shell, and some
other things like reboot, halt and such.

## kfs-3
### Mandatory part
You must implement a complete, stable and functionnal memory system in your
kernel.
Let’s follow this task, point by point:
- [ ] You must enable memory paging in your Kernel
- [ ] You must code a memory structure that handle paging and memory rights (Careful,
you don’t have the tools yet to know who’s accessing the memory, so all of this is
theoric at the moment)
- [ ] You must define Kernel and User space
- [ ] You must implement a function to create / get memory pages
- [ ] You must implement functions to allocate, free and get size of a variable.
- [ ] You must implement those functions for virtual and physical memory
- [ ] You must handle "kernel panics" (Print, stop the kernel)
- [ ] Your work should not exceed 10 MB.
### Bonus Part
Since this subject is really, really hard, the bonuses are not really important.
Try to focus on the code itself, because the memory is most important part of your kernel,
by far. But if you are looking for some things to do after that, try to implement memory
dumping and debug in the last "mini-shell" subject.

## kfs-4
### Mandatory part
You will have to implement the following:
- [ ] Create an Interrupts Descriptor Table, fill it and register it
- [ ] A signal-callback system on your Kernel API
- [ ] An interface to schedule signals
- [ ] An interface to clean registers before a panic / halt
- [ ] An interface to save the stack before a panic
When you’re done with all of that, you’ll have to implement a IDT keyboard handling
system.
### Bonus Part
t has not been said, but syscalls are also handled by the IDT. You can’t implement them
now (No processus / Execution), but a good start could be coding the base functions for
it, it could save you some work.
Also, you can add some features to the keyboard handler, for example multi layouts
(qwerty, azerty), base functions like getline (just like read: waits for characters and
return them when \n is pressed).

## kfs-5
### Mandatory part
You will need to implement a complete interface for processes in your kernel.
Let’s list that, point by point:
- [ ] A full structure containing data about processes. That includes:
	- A PID.
	- Status (Run, zombie, thread)
	- Pointers to father and children
	- Stack and heap of a process. (More information below)
	- Currents signals (Queue list)
	- Owner id (User)
- [ ] With that structure filled and dusted, you will need to implement the followings
functions:
	- Function to queue a signal to a processus, delivered on the next CPU tick
	- Sockets communication helpers between processes
	- Functions to work on the memory of a process.
	- Function to copy an entire process (fork)
- [ ] On top of that, you will need to code the followings helpers, in order to prepare the
syscalls:
	- wait
	- exit
	- getuid
	- signal
	- kill
- [ ] All of the functions above meant to work like any UNIX system.
### Bonus Part
Implement the following:
- [ ] Functions like mmap, in order to a process to get his virtual memory.
- [ ] Link the IDT and the processes, in order to follow the futures syscalls signals.
- [ ] Create the BSS and data sectors in the process structure.

## kfs-6
### Mandatory part
For this subject, you will have to implement a complete and functional filesystem interface. Let’s see that, point by point:
- [ ] Write a complete interface to read / write an IDE.
- [ ] Write a complete interface to read an ext2 filesystem:
	- Read the ext2 headers.
	- Create and fill in an ext2 kernel-side structure with groups, super blocks,
blocks and inodes.
- [ ] Write a complete structure for a filesystem. That includes:
	- Name
	- Size
	- Type
	- Inode
	- Links
	- Master
	- Father
	- Children
	- Rights
	- Next of kin
- [ ] You will have to implement a cat command in your console, with the behavior of the
original cat. Now that you have a root directory, you need to code a directory change
too (pwd / cd) in your console. Keep in mind that a process needs to have its own pwd,
and two processes can have different pwds at the same time.
### Bonus Part
For the bonuses, you will have to handle multiple partitions, mount and demount.
You can, also, implement users (with passwords, logins, etc.).

## kfs-7
### Mandatory part
In this subject you will have to:
- [ ] Implement a functional and complete syscall interface:
	- A syscall table.
	- An ASM function for the IDT callback.
	- A kernel-side function that takes the number of the syscall, gets the arguments
of the call, places them in the register and pushes the call on the stack.
	- You must proove that your code works by creating a process, have it use a
syscall, and print the used syscall on the screen.
- [ ] Implement a working unix environment. (cf. Intro)
- [ ] Users accounts, with password protection by obscurity. (cf. Intro)
- [ ] Inter-Process Sockets, working via syscalls, with shared file descriptors.
- [ ] Implement a complete file Hierarchy, Unix-like (cf. Intro).
### Bonus Part
- [ ] Change your kernel console so that a user can use a console with their own environment,
like a real OS.
- [ ] Implement different ttys, with the appropriate files in /dev.

## kfs-8
### Mandatory part
In this subject, you will have to:
- [ ] Write an internal API to manage modules integration.
- [ ] Handle the creation and destruction of the modules.
- [ ] Write functions to communicate between the kernel and the module.
- [ ] Write callbacks between the kernel and the module.
- [ ] Make these callbacks configurable. For example, if a module wants a callback
function called at every CPU cycle, it must declare it so that the kernel calls the
function when the module is created.
- [ ] Give these modules access to the kernel functions for memory, sockets, process, etc.
In order to prove that your work is functional, you must implement 2 modules: a key-
board module and a time module.
- [ ] Keyboard Module
The keyboard module must get a callback from the Kernel every time a key is pressed /
realeased.
- [ ] Time Module
The time module must return a struct / value every time the kernel asks for it via function
/ ioctl / callback.
### Bonus Part
- [ ] Create special memory allocation functions, in order to create a memory ring dedicated to the modules.

## kfs-9
### Mandatory part
In this project, you will have to:
- [ ] Create a parser for ELF files.
- [ ] Create a loader for ELF files.
- [ ] Execute an ELF file.
- [ ] Implement these points in a execve (2)-like syscall.
- [ ] Make the syscall create a process associated with the ELF file.
- [ ] Rewrite your API modules, so that you can load modules in ELF at run time.
- [ ] Load the modules, list them and unload them.
### Bonus Part
- [ ] You must create a memory ring for the modules (specifically, built-in and run-time mod-
ules).

## kfs-x
### Mandatory part
You must install the following:
- [ ] A POSIX shell. sh will do.
- [ ] The complete libc.
- [ ] Basic Unix binaries:
	- cat
	- chmod
	- cp
	- date
	- dd
	- df
	- echo
	- hostname
	- kill
	- ln
	- ls
	- mkdir
	- mv
	- ps
	- pwd
	- rm
	- rmdir
	- sleep
