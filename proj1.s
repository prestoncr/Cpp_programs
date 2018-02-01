.data

arrayx: .word  -89, 19, 91, -23, -31, -96, 3, 67, 17, 13, -43, -74
sum: .word 0
average: .word 0
counter: .word 0
index: .word 0
newLine: .asciiz "\n"
message: .asciiz "Average of positve array elements: "

.text


main:
  la $s0, arrayx

  addi $t0, $zero, 0

  while:
      beq $t0, 48, exit
      lw $t1, arrayx($t0)
      addi $t0, $t0, 4

      #used for testing purposes
      #li $v0, 1
      #move $a0, $t1
      #syscall
      #li $v0, 4
      #la $a0, newLine
      #syscall

      bgez $t1, addtosum
      j while

      exit:

      #li $v0, 1
      #add $a0, $s1, $zero
      #syscall

      li $v0, 4
      la $a0, message
      syscall

      addi $t3, $zero, 6
      div $s2, $s1, $t3
      li $v0, 1
      add $a0, $s2, $zero
      syscall


      li $v0, 10
      syscall

      addtosum:
      add $s1, $s1, $t1
      j while
