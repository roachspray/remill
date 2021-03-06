/* Copyright 2016 Peter Goodman (peter@trailofbits.com), all rights reserved. */

#ifndef REMILL_ARCH_X86_SEMANTICS_FLAGOP_H_
#define REMILL_ARCH_X86_SEMANTICS_FLAGOP_H_

DEF_ISEL_SEM(CLD) {
  FLAG_DF = false;
}

DEF_ISEL_SEM(STD) {
  FLAG_DF = true;
}

DEF_ISEL_SEM(CLC) {
  FLAG_CF = false;
}

DEF_ISEL_SEM(CMC) {
  FLAG_CF = BNot(FLAG_CF);
}

DEF_ISEL_SEM(STC) {
  FLAG_CF = BNot(FLAG_CF);
}

DEF_ISEL_SEM(SALC) {
  Write(REG_AL, Unsigned(FLAG_CF));
}

DEF_ISEL_SEM(SAHF) {
  Flags flags = {ZExtTo<uint64_t>(Read(REG_AH))};
  FLAG_CF = UCmpEq(1, flags.cf);
  FLAG_PF = UCmpEq(1, flags.pf);
  FLAG_AF = UCmpEq(1, flags.af);
  FLAG_SF = UCmpEq(1, flags.sf);
  FLAG_ZF = UCmpEq(1, flags.zf);
}

DEF_ISEL_SEM(LAHF) {
  Flags flags = {0};
  flags.cf = Unsigned(FLAG_CF);
  flags.must_be_1 = 1;
  flags.pf = Unsigned(FLAG_PF);
  flags.must_be_0a = 0;
  flags.af = Unsigned(FLAG_AF);
  flags.must_be_0b = 0;
  flags.zf = Unsigned(FLAG_ZF);
  flags.sf = Unsigned(FLAG_SF);
  Write(REG_AH, TruncTo<uint8_t>(flags.flat));
}

// TODO(pag): This is a ring-0 instruction.
DEF_ISEL_SEM(CLAC) {
  state.rflag.ac = false;
}

// TODO(pag): This is a ring-0 instruction.
DEF_ISEL_SEM(STAC) {
  state.rflag.ac = true;
}

// TODO(pag): This is a ring-0 instruction.
DEF_ISEL_SEM(CLI) {
  state.rflag._if = false;
}

// TODO(pag): This is a ring-0 instruction.
DEF_ISEL_SEM(STI) {
  state.rflag._if = true;
}

#endif  // REMILL_ARCH_X86_SEMANTICS_FLAGOP_H_
