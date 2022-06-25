#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static __attribute__ ((noinline)) unsigned long long rdtsc(void)
{
    unsigned hi, lo;
    asm volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long) lo | (unsigned long long) hi << 32);
}

int main (void)
{
    // nice(0x1);
    
    int pid = getpid();
    unsigned long new_brk;
    int nice_value;
    printf ("pid: %d. \n", pid);

    unsigned long long t, t0, t1;


    asm volatile (
            // "movq $39, %%rax; \n\t"
            // "syscall; \n\t"
            // "movq %%rax, %0; \n\t"
            "movq $0xabababababababab, %%rax; \n\t"
            "vmcall; \n\t"
            :::"%rax");
            // :"=m"(pid)::"%rax");

    // nice(1);

    // sleep(0x10);
    sleep(0x5);

    /* This is to issue an onsite analysis request */
    asm volatile("movq $0xcdcdcdcd, %%rax; \n\t"
            "leaq 0x5(%%rip), %%rdi; \n\t"
            //"pushq %%rdi; \n\t "
            // "movq %%rsp, %%rdi \n\t"
            "movq $2, %%rdi; \n\t"
            "cmp $1, %%rdi; \n\t"
            "vmcall; \n\t"
            // "jne l1;"
            // "movq $0xfff, %%rax; \n\t"
            // "l1: \n\t"
            // "movq $0xaa, %%rax; \n\t"
            // // "retq; \n\t"
            // // "movq 0x8(%%rip), %%rax; \n\t"
            // "jmp *0x13(%%rip); \n\t"
            // // // "callq *0x2(%%rip); \n\t"
            // // // "leaq 0x5(%%rip), %%rdi; \n\t "
            // // // "movq $0xf1f1f11, %%rdi; \n\t"
            // "jmp check_l; \n\t"
            // "movq %%rsp, %%rdi \n\t"
            // "check_l: \n\t"
            // "movq $1, %%rdi; \n\t"
            // "retq; \n\t"
            //test starts from here
            // "movq %%fs:0x18, %%rdi; \n\t"
            // "movq (%%r15, %%rdi, 0x4), %%rax; \n\t"
            // "movq 0x0(%%rip), %%rdi; \n\t"
            // "movq 0x0(%%r15), %%rdi; \n\t"
            // "movq 0x8(%%rip), %%rdi; \n\t"
            // "movq 0x8(%%r15), %%rdi; \n\t"
            // "movq 0x010f(%%rip), %%rdi; \n\t"
            // "movq 0x010f(%%r15), %%rdi; \n\t"
            // "cmpq 0x0(%%rip), %%rdi; \n\t"
            // "cmpq 0x0(%%r15), %%rdi; \n\t"
            // "cmpq 0x8(%%rip), %%rdi; \n\t"
            // "cmpq 0x8(%%r15), %%rdi; \n\t"
            // "cmpq 0x79f10f(%%rip), %%rdi; \n\t"
            // "cmpq 0x79f10f(%%r15), %%rdi; \n\t"
            // "leaq 0x0(%%rip), %%rdi; \n\t"
            // "leaq 0x0(%%r15), %%rdi; \n\t"
            // "leaq 0x8(%%rip), %%rdi; \n\t"
            // "leaq 0x8(%%r15), %%rdi; \n\t"
            // "leaq 0x79f10f(%%rip), %%rdi; \n\t"
            // "leaq 0x79f10f(%%r15), %%rdi; \n\t"
            // "subq 0x0(%%rip), %%rdi; \n\t"
            // "subq 0x0(%%r15), %%rdi; \n\t"
            // "subq 0x8(%%rip), %%rdi; \n\t"
            // "subq 0x8(%%r15), %%rdi; \n\t"
            // "subq 0x79f10f(%%rip), %%rdi; \n\t"
            // "subq 0x79f10f(%%r15), %%rdi; \n\t"
            // "addq 0x0(%%rip), %%rdi; \n\t"
            // "addq 0x0(%%r15), %%rdi; \n\t"
            // "addq 0x8(%%rip), %%rdi; \n\t"
            // "addq 0x8(%%r15), %%rdi; \n\t"
            // "addq 0x79f10f(%%rip), %%rdi; \n\t"
            // "addq 0x79f10f(%%r15), %%rdi; \n\t"
            // "pop %%rax; \n\t"
            // "push %%rax; \n\t"
            // "movq 0x8(%%rcx, %%rdx, 4), %%rcx; \n\t"
            :::"%rax", "%rdi");

    // malloc(0x100);
    // alarm(30);
    
    // nice(1);
    // int pid = getpid();
    
    // asm volatile("movq $140, %%rax; \n\t"
    //         "movq $0, %%rdi; \n\t"
    //         "movq $0, %%rsi; \n\t"
    //         "syscall; \n\t"
    //         "movq %%rax, %0; \n\t"
    //         :"=m"(nice_value)::"%rax","%rdi","%rsi");
    // printf ("nice value: %lx. \n", nice_value);

    // t0 = rdtsc();

    asm volatile("movq $141, %%rax; \n\t"
            "movq $0, %%rdi; \n\t"
            "movq $0, %%rsi; \n\t"
            "movq $19, %%rdx; \n\t"
            // "movq $1, %%rdx; \n\t"
            "syscall; \n\t"
            "movq %%rax, %0; \n\t"
            :"=m"(nice_value)::"%rax","%rdi","%rsi");
    
    // t1 = rdtsc();
    // printf ("t0: %llx, t1: %llx, t: %llx. \n", t0, t1, t1-t0); 
    printf ("ret of nice: %lx. \n", nice_value);

    // asm volatile("movq $140, %%rax; \n\t"
    //         "movq $0, %%rdi; \n\t"
    //         "movq $0, %%rsi; \n\t"
    //         "syscall; \n\t"
    //         "movq %%rax, %0; \n\t"
    //         :"=m"(nice_value)::"%rax","%rdi","%rsi");
    // printf ("nice: %lx. \n", nice_value);
   
    // // asm volatile("movq $12, %%rax; \n\t"
    // //         "movq $0x555557780000, %%rdi; \n\t"
    // //         "syscall; \n\t"
    // //         "movq %%rax, %0; \n\t"
    // //         :"=m"(new_brk)::"%rax");
    // // printf ("new_brk: %lx. \n", new_brk);

    // asm volatile("movq $39, %%rax; \n\t"
    //         "syscall; \n\t"
    //         "movq %%rax, %0; \n\t"
    //         "vmcall; \n\t"
    //         :"=m"(pid)::"%rax");

    asm volatile("movq $37, %%rax; \n\t"
            "movq $12, %%rdi; \n\t"
            "syscall; \n\t"
            "movq %%rax, %0; \n\t"
            "vmcall; \n\t"
            :"=m"(pid)::"%rax");
    
    printf ("pid: %d. \n", pid);
    
    // sleep(0x1000);
    
    return 1;
}

