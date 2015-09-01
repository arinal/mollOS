  .set PAGE_ALIGN, 1 << 0
  .set MEM_INFO, 1 << 1
  .set MAGIC, 0x1badb002

  .set FLAGS, PAGE_ALIGN | MEM_INFO
  .set CHECKSUM, -(MAGIC + FLAGS)

  .global _mboot
  .extern _code
  .extern _bss
  .extern _end
_mboot:
  .long MAGIC
  .long FLAGS
  .long CHECKSUM
  .long _mboot
  .long _code
  .long _bss
  .long _end
  .long _start

  .global _start
  .extern main
_start:
  push %ebx
  cli
  call main
_hang:
  jmp _hang
