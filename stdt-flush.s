	.global gdtFlush
gdtFlush:
	mov 4(%esp), %eax
	lgdt (%eax)

	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %ax, %ss

	jmp %cs:_ret
_ret:
	ret

	.global idtFlush
idtFlush:
	mov 4(%esp), %eax
	lidt (%eax)
	ret

  .extern isrHandler
isrCommon:
  pusha
  mov %ds, %ax
  push %eax
  mov $0x10, %ax
  mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs

  call isrHandler

  pop %eax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
  popa

  add $0x8, %esp
  sti
  iret

  .global isr0
isr0:
  cli
  pushl $0
	pushl $0
  jmp isrCommon

  .global isr1
isr1:
  cli
  pushl $0
  pushl $1
  jmp isrCommon

  .global isr2
isr2:
	cli
	pushl $0
  pushl $2
	jmp isrCommon
