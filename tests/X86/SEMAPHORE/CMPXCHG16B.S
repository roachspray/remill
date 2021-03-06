/* Copyright 2016 Peter Goodman (peter@trailofbits.com), all rights reserved. */

TEST_BEGIN_MEM_64(CMPXCHG16Bm64rdxrax_0, 3)
TEST_INPUTS(
    0, 0, 0,
    0, 0, 1,
    0, 1, 0,
    0, 1, 1,
    1, 0, 0,
    1, 0, 1,
    1, 1, 0,
    1, 1, 1)

    push ARG1_64
    push ARG2_64
    push ARG3_64
    mov edx, 0
    pop rax

    mov ebx, 0
    mov ecx, 0
    not rbx
    not rcx
    cmpxchg16b XMMWORD PTR [rsp]
TEST_END_MEM_64

TEST_BEGIN_MEM_64(CMPXCHG16Bm64rdxrax_1, 3)
TEST_INPUTS(
    0, 0, 0,
    0, 0, 1,
    0, 1, 0,
    0, 1, 1,
    1, 0, 0,
    1, 0, 1,
    1, 1, 0,
    1, 1, 1)

    push ARG1_64
    push ARG2_64
    push ARG3_64
    mov eax, 0
    pop rdx

    mov ebx, 0
    mov ecx, 0
    not rbx
    not rcx
    cmpxchg16b XMMWORD PTR [rsp]
TEST_END_MEM_64

