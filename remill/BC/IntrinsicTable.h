/* Copyright 2015 Peter Goodman (peter@trailofbits.com), all rights reserved. */

#ifndef REMILL_BC_INTRINSICTABLE_H_
#define REMILL_BC_INTRINSICTABLE_H_

namespace llvm {
class ConstantArray;
class Function;
class Module;
class Value;
}  // namespace llvm
namespace remill {

class IntrinsicTable {
 public:
  IntrinsicTable(const llvm::Module *M);

  llvm::Function * const error;

  // Control-flow.
  llvm::Function * const function_call;
  llvm::Function * const function_return;
  llvm::Function * const jump;

  // OS interaction.
  llvm::Function * const async_hyper_call;

  // Transition to/from native/lifted code.
  //
  // TODO(pag): This is not really the best abstraction as it covers less than
  //            it implies. For example, there is no representation for the
  //            case where you detach on a function call, and want to attach
  //            on return.
  llvm::Function * const detach;
//  llvm::Function * const attach;

  // Memory read intrinsics.
  llvm::Function * const read_memory_8;
  llvm::Function * const read_memory_16;
  llvm::Function * const read_memory_32;
  llvm::Function * const read_memory_64;

  // Memory write intrinsics.
  llvm::Function * const write_memory_8;
  llvm::Function * const write_memory_16;
  llvm::Function * const write_memory_32;
  llvm::Function * const write_memory_64;

  llvm::Function * const read_memory_f32;
  llvm::Function * const read_memory_f64;
  llvm::Function * const read_memory_f80;

  llvm::Function * const write_memory_f32;
  llvm::Function * const write_memory_f64;
  llvm::Function * const write_memory_f80;

  // Memory barriers.
  llvm::Function * const barrier_load_load;
  llvm::Function * const barrier_load_store;
  llvm::Function * const barrier_store_load;
  llvm::Function * const barrier_store_store;

  llvm::Function * const atomic_begin;
  llvm::Function * const atomic_end;

  // Optimization control.
  llvm::Function * const defer_inlining;

  // Optimization enabling.
  llvm::Function *undefined_8;
  llvm::Function *undefined_16;
  llvm::Function *undefined_32;
  llvm::Function *undefined_64;
  llvm::Function *undefined_f32;
  llvm::Function *undefined_f64;
//
//  llvm::ConstantArray *indirect_blocks;
//  llvm::ConstantArray *exported_blocks;
 private:
  IntrinsicTable(void) = delete;
};

}  // namespace remill

#endif  // REMILL_BC_INTRINSICTABLE_H_
