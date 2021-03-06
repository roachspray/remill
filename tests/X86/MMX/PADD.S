/* Copyright 2016 Akshay Kumar (iit.akshay@gmail.com), all rights reserved. */

TEST_BEGIN_64(PADDBr64r64, 2)
TEST_INPUTS_MMX_2()
    movq mm0, ARG1_64
    movq mm1, ARG2_64
    paddb mm0, mm1
TEST_END_64

TEST_BEGIN_64(PADDBr64m64, 2)
TEST_INPUTS_MMX_2()
    push ARG2_64
    movq mm0, ARG1_64
    paddb mm0, qword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PADDBv128v128, 2)
TEST_INPUTS_MMX_2()
    movq xmm0, ARG1_64
    movq xmm1, ARG2_64
    paddb xmm0, xmm1
TEST_END_64

TEST_BEGIN_64(PADDBv128m128, 2)
TEST_INPUTS_MMX_2()
    push 0
    push ARG2_64
    movq xmm0, ARG1_64
    paddb xmm0, xmmword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PADDWr64r64, 2)
TEST_INPUTS_MMX_2()
    movq mm0, ARG1_64
    movq mm1, ARG2_64
    paddw mm0, mm1
TEST_END_64

TEST_BEGIN_64(PADDWr64m64, 2)
TEST_INPUTS_MMX_2()
    push ARG2_64
    movq mm0, ARG1_64
    paddw mm0, qword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PADDWv128v128, 2)
TEST_INPUTS_MMX_2()
    movq xmm0, ARG1_64
    movq xmm1, ARG2_64
    paddw xmm0, xmm1
TEST_END_64

TEST_BEGIN_64(PADDWv128m128, 2)
TEST_INPUTS_MMX_2()
    push 0
    push ARG2_64
    movq xmm0, ARG1_64
    paddw xmm0, xmmword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PADDDr64r64, 2)
TEST_INPUTS_MMX_2()
    movq mm0, ARG1_64
    movq mm1, ARG2_64
    paddd mm0, mm1
TEST_END_64

TEST_BEGIN_64(PADDDr64m64, 2)
TEST_INPUTS_MMX_2()
    push ARG2_64
    movq mm0, ARG1_64
    paddd mm0, qword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PADDDv128v128, 2)
TEST_INPUTS_MMX_2()
    movq xmm0, ARG1_64
    movq xmm1, ARG2_64
    paddd xmm0, xmm1
TEST_END_64

TEST_BEGIN_64(PADDDv128m128, 2)
TEST_INPUTS_MMX_2()
    push 0
    push ARG2_64
    movq xmm0, ARG1_64
    paddd xmm0, xmmword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PADDQr64r64, 2)
TEST_INPUTS_MMX_2()
    movq mm0, ARG1_64
    movq mm1, ARG2_64
    paddq mm0, mm1
TEST_END_64

TEST_BEGIN_64(PADDQr64m64, 2)
TEST_INPUTS_MMX_2()
    push ARG2_64
    movq mm0, ARG1_64
    paddq mm0, qword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PADDQv128v128, 2)
TEST_INPUTS_MMX_2()
    movq xmm0, ARG1_64
    movq xmm1, ARG2_64
    paddq xmm0, xmm1
TEST_END_64

TEST_BEGIN_64(PADDQv128m128, 2)
TEST_INPUTS_MMX_2()
    push 0
    push ARG2_64
    movq xmm0, ARG1_64
    paddq xmm0, xmmword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PADDSBr64r64, 2)
TEST_INPUTS_MMX_2()
    movq mm0, ARG1_64
    movq mm1, ARG2_64
    paddsb mm0, mm1
TEST_END_64

TEST_BEGIN_64(PADDSBr64m64, 2)
TEST_INPUTS_MMX_2()
    push ARG2_64
    movq mm0, ARG1_64
    paddsb mm0, qword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PADDSBv128v128, 2)
TEST_INPUTS_MMX_2()
    movq xmm0, ARG1_64
    movq xmm1, ARG2_64
    paddsb xmm0, xmm1
TEST_END_64

TEST_BEGIN_64(PADDSBv128m128, 2)
TEST_INPUTS_MMX_2()
    push 0
    push ARG2_64
    movq xmm0, ARG1_64
    paddsb xmm0, xmmword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PADDSWr64r64, 2)
TEST_INPUTS_MMX_2()
    movq mm0, ARG1_64
    movq mm1, ARG2_64
    paddsw mm0, mm1
TEST_END_64

TEST_BEGIN_64(PADDSWr64m64, 2)
TEST_INPUTS_MMX_2()
    push ARG2_64
    movq mm0, ARG1_64
    paddsw mm0, qword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PADDSWv128v128, 2)
TEST_INPUTS_MMX_2()
    movq xmm0, ARG1_64
    movq xmm1, ARG2_64
    paddsw xmm0, xmm1
TEST_END_64

TEST_BEGIN_64(PADDSWv128m128, 2)
TEST_INPUTS_MMX_2()
    push 0
    push ARG2_64
    movq xmm0, ARG1_64
    paddsw xmm0, xmmword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PHADDWr64r64, 2)
TEST_INPUTS_MMX_2()
    movq mm0, ARG1_64
    movq mm1, ARG2_64
    phaddw mm0, mm1
TEST_END_64

TEST_BEGIN_64(PHADDWr64m64, 2)
TEST_INPUTS_MMX_2()
    push ARG2_64
    movq mm0, ARG1_64
    phaddw mm0, qword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PHADDWv128v128, 2)
TEST_INPUTS_MMX_2()
    movq xmm0, ARG1_64
    movq xmm1, ARG2_64
    phaddw xmm0, xmm1
TEST_END_64

TEST_BEGIN_64(PHADDWv128m128, 2)
TEST_INPUTS_MMX_2()
    push 0
    push ARG2_64
    movq xmm0, ARG1_64
    phaddw xmm0, xmmword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PHADDDr64r64, 2)
TEST_INPUTS_MMX_2()
    movq mm0, ARG1_64
    movq mm1, ARG2_64
    phaddd mm0, mm1
TEST_END_64

TEST_BEGIN_64(PHADDDr64m64, 2)
TEST_INPUTS_MMX_2()
    push ARG2_64
    movq mm0, ARG1_64
    phaddd mm0, qword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PHADDDv128v128, 2)
TEST_INPUTS_MMX_2()
    movq xmm0, ARG1_64
    movq xmm1, ARG2_64
    phaddd xmm0, xmm1
TEST_END_64

TEST_BEGIN_64(PHADDDv128m128, 2)
TEST_INPUTS_MMX_2()
    push 0
    push ARG2_64
    movq xmm0, ARG1_64
    phaddd xmm0, xmmword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PHADDSWr64r64, 2)
TEST_INPUTS_MMX_2()
    movq mm0, ARG1_64
    movq mm1, ARG2_64
    phaddsw mm0, mm1
TEST_END_64

TEST_BEGIN_64(PHADDSWr64m64, 2)
TEST_INPUTS_MMX_2()
    push ARG2_64
    movq mm0, ARG1_64
    phaddsw mm0, qword ptr [rsp]
TEST_END_64

TEST_BEGIN_64(PHADDSWv128v128, 2)
TEST_INPUTS_MMX_2()
    movq xmm0, ARG1_64
    movq xmm1, ARG2_64
    phaddsw xmm0, xmm1
TEST_END_64

TEST_BEGIN_64(PHADDSWv128m128, 2)
TEST_INPUTS_MMX_2()
    push 0
    push ARG2_64
    movq xmm0, ARG1_64
    phaddsw xmm0, xmmword ptr [rsp]
TEST_END_64
