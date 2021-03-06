/* Copyright 2015 Peter Goodman (peter@trailofbits.com), all rights reserved. */

#ifndef REMILL_ARCH_X86_SEMANTICS_CALL_RET_H_
#define REMILL_ARCH_X86_SEMANTICS_CALL_RET_H_

namespace {

template <typename T>
DEF_SEM(CALL, T target_pc, PC return_pc) {
  if (IsRegister(target_pc) || IsMemory(target_pc)) {
    ClearArithFlags();  // TODO(pag): Is this too aggressive?
  }

  addr_t next_sp = USub(REG_XSP, ADDRESS_SIZE_BYTES);
  Write(WritePtr<addr_t>(next_sp _IF_32BIT(REG_SS_BASE)), Read(return_pc));
  Write(REG_XSP, next_sp);
  Write(REG_PC, ZExtTo<addr_t>(Read(target_pc)));
}

DEF_SEM(RET_IMM, I16 bytes) {
  ClearArithFlags();  // TODO(pag): Is this too aggressive?
  Write(REG_PC, Read(ReadPtr<addr_t>(REG_XSP _IF_32BIT(REG_SS_BASE))));
  Write(REG_XSP,
        UAdd(UAdd(REG_XSP, ZExtTo<addr_t>(Read(bytes))), ADDRESS_SIZE_BYTES));
}

DEF_SEM(RET) {
  ClearArithFlags();  // TODO(pag): Is this too aggressive?
  Write(REG_PC, Read(ReadPtr<addr_t>(REG_XSP _IF_32BIT(REG_SS_BASE))));
    Write(REG_XSP, UAdd(REG_XSP, ADDRESS_SIZE_BYTES));
}

}  // namespace

DEF_ISEL_32or64(CALL_NEAR_RELBRd, CALL<PC>);
DEF_ISEL_32or64(CALL_NEAR_RELBRz, CALL<PC>);

IF_32BIT( DEF_ISEL(CALL_NEAR_MEMv_16) = CALL<M16>; )
IF_32BIT( DEF_ISEL(CALL_NEAR_MEMv_32) = CALL<M32>; )
IF_64BIT( DEF_ISEL(CALL_NEAR_MEMv_64) = CALL<M64>; )

IF_32BIT( DEF_ISEL(CALL_NEAR_GPRv_16) = CALL<R16>; )
IF_32BIT( DEF_ISEL(CALL_NEAR_GPRv_32) = CALL<R32>; )
IF_64BIT( DEF_ISEL(CALL_NEAR_GPRv_64) = CALL<R64>; )

/*
352 CALL_FAR CALL_FAR_MEMp2 CALL BASE I86 ATTRIBUTES: FAR_XFER FIXED_BASE1 NOTSX SCALABLE STACKPUSH1
353 CALL_FAR CALL_FAR_PTRp_IMMw CALL BASE I86 ATTRIBUTES: FAR_XFER FIXED_BASE0 NOTSX SCALABLE STACKPUSH0

*/

DEF_ISEL_32or64(RET_NEAR_IMMw, RET_IMM);
DEF_ISEL_32or64(RET_NEAR, RET);

/*
1073 RET_FAR RET_FAR_IMMw RET BASE I86 ATTRIBUTES: FAR_XFER FIXED_BASE0 NOTSX SCALABLE STACKPOP0
1074 RET_FAR RET_FAR RET BASE I86 ATTRIBUTES: FAR_XFER FIXED_BASE0 NOTSX SCALABLE STACKPOP0
1666 IRETQ IRETQ RET LONGMODE LONGMODE ATTRIBUTES: FIXED_BASE0 NOTSX SCALABLE STACKPOP0
1784 IRET IRET RET BASE I86 ATTRIBUTES: FIXED_BASE0 NOTSX SCALABLE STACKPOP0
728 IRETD IRETD RET BASE I386 ATTRIBUTES: FIXED_BASE0 NOTSX SCALABLE STACKPOP0
*/
//
//DEF_ISEL_SEM(IRETD_32) {
//  W(state.gpr.rip) = __remill_create_program_counter(PopValue<uint32_t>(state));
//  W(state.seg.cs) = static_cast<uint16_t>(PopValue<uint32_t>(state));
//
//  Flags flags;
//  flags.flat = PopValue<uint32_t>(state);
//  state.aflag.af = flags.af;
//  state.aflag.cf = flags.cf;
//  state.aflag.df = flags.df;
//  state.aflag.of = flags.of;
//  state.aflag.pf = flags.pf;
//  state.aflag.sf = flags.sf;
//  state.aflag.zf = flags.zf;
//
//  // TODO(pag): Hrmmmm.
//}
//
//#if 64 == ADDRESS_SIZE_BITS
//DEF_ISEL_SEM(IRETQ_64) {
//  W(state.gpr.rip) = __remill_create_program_counter(PopValue<uint64_t>(state));
//  W(state.seg.cs) = static_cast<uint16_t>(PopValue<uint64_t>(state));
//
//  Flags flags;
//  flags.flat = PopValue<uint64_t>(state);
//  state.aflag.af = flags.af;
//  state.aflag.cf = flags.cf;
//  state.aflag.df = flags.df;
//  state.aflag.of = flags.of;
//  state.aflag.pf = flags.pf;
//  state.aflag.sf = flags.sf;
//  state.aflag.zf = flags.zf;
//
//  // TODO(pag): Hrmmmm.
//}
//#endif  // 64 == ADDRESS_SIZE_BITS

#endif  // REMILL_ARCH_X86_SEMANTICS_CALL_RET_H_
