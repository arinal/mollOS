ENTRY(_start)
SECTIONS {
         . = 1M;

         .text BLOCK(4K): ALIGN(4K) {
               _code = .;
               *(.text)
         }

         .data BLOCK(4K): ALIGN(4K) {
               _data = .;
               *(.data)
               *(.rodata)
         }

         .bss BLOCK(4K): ALIGN(4K) {
              _bss = .;
              *(.bss)
         }

         _end = .;
}
